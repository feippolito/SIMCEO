"""
    This driver is the one that will be inherited by the FEM model
    and from here one may proram all the functionalities necessary
    for increment the 
"""

import numpy as np
import logging
import Telescope.utils as utils

from scipy import sparse

class mainFEMDriver:

  def __init__(self,
      verbose=logging.INFO, 
      **kwargs ):
    self.logger = logging.getLogger(self.__class__.__name__)
    self.logger.setLevel(verbose)
    self.logger.info('Instantiate')
    if kwargs:
      self.Start(**kwargs)
  
  def driver_Start(self,
      state_space_filename=None,
      second_order_filename=None,
      fem_io_filename=None,
      state_space_ABC=None,
      second_order=None,
      fem_inputs=None, fem_outputs=None,
      reorder_RBM=False, duration = None ):
    """
    This is the main start method responsible 
    for reading the input and output tables and
    defining the main state variables and class
    properties.
    """
    self.logger.info('Start')
    if fem_io_filename is not None:
      fem_inputs, fem_outputs = utils.readInOutFile(fem_io_filename)
    if state_space_filename is not None:
      ss_model = utils.readStateSpace(filename=state_space_filename)
      self.O,self.Z,self.Phim,self.Phi,self.Phid = utils.ss2fem(*ss_model)
    if second_order_filename is not None:
      second_order = utils.loadFEM2ndOrder(filename=second_order_filename)
    if state_space_ABC is not None:
      ss_model = utils.readStateSpace(ABC=state_space_ABC)
      self.O,self.Z,self.Phim,self.Phi,self.Phid = utils.ss2fem(*ss_model)
    if second_order is not None:
      self.O,self.Z,self.Phim,self.Phi = second_order
      self.O *= 2*np.pi
      self.O = np.ravel(self.O)
      self.Z = np.ravel(self.Z)
    self.INPUTS  = fem_inputs
    self.OUTPUTS = fem_outputs
    self.state = {
      'u':None,'y':None,
      'A':None,'B':None,
      'C':None,'D':None,
      'x':None,'step':0
    }
    self.__setprop__()
    if reorder_RBM:
      self.reorder_rbm()
    self.info()

  def __setprop__(self):
    """
    The __setprop__ dunder method is used to 
    attribute the values to each inport and 
    outport state space sub system. Considering 
    only the used inports and outports.
    """
    self.N = self.O.size
    c = np.cumsum([x[1] for x in self.INPUTS])
    self.N_INPUTS = c[-1]
    self.ins_idx = c[:-1]
    c = np.cumsum([x[1] for x in self.OUTPUTS])
    self.N_OUTPUTS = c[-1]
    self.outs_idx = c[:-1]
    if self.Phid.shape[0] > 1:
      self.residues = True
      self.__Phid__ = {x:y for y,x in zip(np.split(self.Phid,self.ins_idx, axis = 1),[x[0] for x in self.INPUTS])}
    else:
      self.residues = False
    self.__Phim__ = {x:y for y,x in zip(np.split(self.Phim,self.ins_idx),[x[0] for x in self.INPUTS])}
    self.__Phi__ = {x:y for y,x in zip(np.split(self.Phi,self.outs_idx),[x[0] for x in self.OUTPUTS])}
    m = self.O==0
    if np.any(m):
      self.hsv     = np.ones_like(self.O)*np.Inf
      self.H2_norm = np.zeros_like(self.O)
      m=~m
      self.hsv[m]     = 0.25 * np.sqrt(np.sum(self.Phim[:,m]**2,0)) * np.sqrt(np.sum(self.Phi[:,m]**2,0)) / self.O[m] / self.Z[m]
      self.H2_norm[m] = 2*self.hsv[m]*np.sqrt(self.O[m]*self.Z[m]/2/np.pi)
    else:
      self.hsv     = 0.25 * np.sqrt(np.sum(self.Phim**2,0)) * np.sqrt(np.sum(self.Phi**2,0)) / self.O / self.Z
      self.H2_norm = 2*self.hsv*np.sqrt(self.O*self.Z/2/np.pi)

  def reorder_rbm(self):
    """
    Properlly reorder the Rigid Body Motion 
    (RBM) outputs of the state space model, 
    by changing the respective lines of the 
    output matrix.
    """
    p = np.zeros((3,42))
    p[:3,:3] =  np.eye(3)
    PT = np.vstack([np.roll(p,k,axis=1) for k in range(0,42,6)])
    PR = np.roll(PT,3,axis=1)
    Q = np.vstack([PT,PR])
    self.P = {'OSS_M1_lcl':Q,'MC_M2_lcl_6D':Q}
    for k in self.P:
      self.__Phi__[k] = self.P[k]@self.__Phi__[k]

  def info(self):
    """
    Create a detailed logging information of
    the current state of the FEM driver.
    """
    self.logger.info('FEM synopsis:')
    self.logger.info('  * # of inputs: {}'.format(self.N_INPUTS))
    self.logger.info('  * # of outputs: {}'.format(self.N_OUTPUTS))
    self.logger.info('  * # of modes: {}'.format(self.O.size))
    self.logger.info('  * $Phi_m$ shape: %s',self.Phim.shape)
    self.logger.info('  * $Phi$ shape: %s',self.Phi.shape)
    self.logger.info('  * eigen frequencies range: [{0:.3f},{1:.3f}]Hz'.format(self.O.min()/2/np.pi,self.O.max()/2/np.pi))
    self.logger.info('  * damping ratio min-max: [{0:.1f},{1:.1f}]%'.format(self.Z.min()*1e2,self.Z.max()*1e2))
    self.logger.info('  * Hankel singular values min-max: [{0:g},{1:g}]'.format(self.hsv.min(),self.hsv.max()))
    self.logger.info('  * mode H2 norm min-max: [{0:g},{1:g}]'.format(self.H2_norm.min(),self.H2_norm.max()))
    self.logger.info('  * system H2 norm: {0:g}'.format(np.sqrt(np.sum(self.H2_norm**2))))


  def driver_Init(self,
      dt=0.5e-3,
      inputs=None,
      outputs=None,
      hsv_rel_threshold=None,
      n_mode_max=None,
      start_idx=0, duration = None):
    """
    The init function initializes the simulation
    environment by setting the matrices and alocating
    the state variables.
    """
    self.logger.info('Init')
    #self.hsv_sort(start_idx=start_idx)
    self.model_reduce(
      inputs=inputs,
      outputs=outputs,
      hsv_rel_threshold=hsv_rel_threshold,
      n_mode_max=n_mode_max )
    A,B,C,D = self.state_space(dt=dt)
    self.state.update(
      {
        'u':np.zeros(self.N_INPUTS),
        'y':np.zeros(self.N_OUTPUTS),
        'A':A, 'B':B, 'C':C, 'D':D,
        'x':np.zeros(A.shape[1]),
        'step':0
      })

  def model_reduce(self,
      inputs=None,
      outputs=None,
      hsv_rel_threshold=None,
      n_mode_max=None,
      outputs_mapping=None):
    """
    Reduces the models according to the given
      . inputs
      . outputs
      . Hankel singular value threshold
      . number of modes
    By considering only the inport and outport
    used subsystems. Also considering the states
    dynamical influence on the output.
    ===============================================
    Parameters:
      - inputs list(String,int):
        The list of model used inport names.
      - outputs list(String,int):
        The list of model used outport names.
      - hsv_rel_threshold (float):
        Hankel singular value threshold.
      - n_mode_max (int):
        Number of modes.
    """
    self.logger.info(' => Model reduction')
    x_size, in_size, out_size = self.O.size, self.Phim.shape[0], self.Phi.shape[0]
    if self.residues:
      total_complexity = x_size * (x_size+2*in_size+out_size)
    else:
      total_complexity = x_size * (x_size+in_size+out_size)
    if inputs is not None:
      self.INPUTS = [(x,self.__Phim__[x].shape[0]) for x in inputs]
      self.Phim = np.vstack([self.__Phim__[x] for x in inputs])
      if self.residues:
        self.Phid = np.hstack([self.__Phid__[x] for x in inputs])
    if outputs is not None:
      if len(outputs) > 0:
        self.OUTPUTS = [(x,self.__Phi__[x].shape[0]) for x in outputs]
        self.Phi = np.vstack([self.__Phi__[x] for x in outputs])
    if outputs_mapping is not None:
      (old_outputs,new_output,T) = outputs_mapping
      O = np.vstack([self.__Phi__[x] for x in old_outputs])
      Q = T@O
      outputs_name = [x[0] for x in self.OUTPUTS]
      for k in old_outputs:
        self.OUTPUTS.pop(outputs_name.index(k))
        self.__Phi__.pop(k)
      self.__Phi__[new_output] = Q
      self.OUTPUTS += (new_output,T.shape[0])
      self.Phi = np.vstack([self.__Phi__[x] for x in self.OUTPUTS])
    if hsv_rel_threshold is not None:
      hsv_max = np.max(self.hsv[~np.isinf(self.hsv)])
      hsvn = self.hsv/hsv_max
      n_mode_max = np.sum(hsvn>hsv_rel_threshold)
    if n_mode_max is not None:
      self.Phim = self.Phim[:,:n_mode_max]
      self.Phi  = self.Phi[:,:n_mode_max]
      self.O = self.O[:n_mode_max]
      self.Z = self.Z[:n_mode_max]
    self.__setprop__()
    x_size, in_size, out_size = self.O.size, self.Phim.shape[0], self.Phi.shape[0]
    if self.residues:
      final_complexity = x_size * (x_size+2*in_size+out_size)
    else:
      final_complexity = x_size * (x_size+in_size+out_size)
    factor = round(100*( 1-(final_complexity/total_complexity)),2)
    self.logger.info('   |- Model reduced in: ' + str(factor) + '% of complexity.')
    self.logger.info(' <= Reduction procedure finished!')
    self.info()

  def hsv_sort(self, 
      start_idx=0):
    """
    Sort the eigen modes according the Hankel
    singular values.
    =============================================
    Parameters:
      - start_idx (int):
        The start index to ...
    """
    idx = np.argsort(self.hsv[start_idx:])[::-1]
    idx = np.hstack([np.arange(start_idx),idx+start_idx])
    self.hsv_idx = idx
    self.O, self.Z = self.O[idx], self.Z[idx]
    self.Phim = self.Phim[:,idx]
    self.Phi = self.Phi[:,idx]
    self.__setprop__()

  def state_space(self,
      dt=None, 
      verbose=False ):
    """
    Build the state space model from the second 
    order model, if dt is given returns the 
    discrete state space otherwise returns the 
    continuous state space model.
    ============================================
    Parameters
      - dt (float):
        The discrete model sampling time.
    Output
      - A,B,C,D (Tuple): 
        The state space A, B, C and D matrices.
    """
    s = self.N,self.N
    OZ = self.O*self.Z
    OZ[np.isnan(OZ)] = 0
    A = sparse.bmat( [[sparse.coo_matrix(s,dtype=np.float),sparse.eye(self.N,dtype=np.float)],
      [sparse.diags(-self.O**2),sparse.diags(-2*OZ)]],format='csr')
    B = sparse.bmat( [[sparse.coo_matrix((self.N,self.Phim.shape[0]),dtype=np.float)],
      [self.Phim.T]],format='csr')
    C = sparse.bmat( [[self.Phi,sparse.coo_matrix((self.Phi.shape[0],self.N),dtype=np.float)]],format='csr')
    D = sparse.bmat( self.Phid, format='csr')
    h = int(A.shape[0]/2)
    if verbose:
      print('State space synopsis:')
      print(' * A shape: {0} ; Block diagonal test (0,{5:d},1,1): {1} {2} {3} {4}'.format(
        A.shape,
        round(A[:h,:h].diagonal().sum(),2),
        round(A[:h,h:].diagonal().sum(),2),
        round(A[h:,:h].diagonal().sum()/A[h:,:h].sum(),2),
        round(A[h:,h:].diagonal().sum()/A[h:,h:].sum(),2),
        int(A.shape[0]/2)))
      print(' * B shape:',B.shape)
      print(' * C shape:',C.shape)
      print(' * D shape:',D.shape)
    if dt is not None:
      Ad,Bd = utils.c2d(A,B,dt)
      return Ad,Bd,C,D
    else:
      return A,B,C,D

  def Terminate(self,**kwargs):
    return "FEM deleted..."
