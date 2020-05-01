
import os
import sys
import time
import logging

from scipy import sparse, linalg as slinalg

import numpy as np
import scipy.linalg as salg
import scipy.io as sio
import h5py


def readInOutFile(
    filename=None ):
  """
    Read the .mat file with the Input and 
    Output Tables, and build the IO Driver
    structure variables.
    =======================================
    Parameters:
      - filename (String): 
        Path to the InOut Map (.mat) file.
    Outputs:
      - inputs list(String, int):
        The list of inports names and sizes.
      - outputs list(String, int):
        The list of outports names and sizes.
  """
  print('LOADING {}'.format(filename))
  data = sio.loadmat(filename)
  inputs=[(x[0][0],y[0]) for x,y in
    zip(data['FEM_IO']['inputs_name'][0,0],
      data['FEM_IO']['inputs_size'][0][0])]
  outputs=[(x[0][0],y[0]) for x,y in 
    zip(data['FEM_IO']['outputs_name'][0,0],
      data['FEM_IO']['outputs_size'][0][0])]
  return inputs, outputs


def readStateSpace(
    filename=None,
    ABC=None, 
    verbose=False ):
  """
  Load the A, B and C matrix of a state 
  space model. The matrix are either in 
  a mat-file with A as a sparse matrix
  or in a list.
  ========================================
  Parameters
    - filename (String):
      The name of the .mat file with the 
      state space model matrices.
    - ABC (list):
      The list containing the A, B and 
      C matrices.
  Outputs
    - A, B, C (Tuple): 
      Containing the A, B, C and D=None 
      state space model matrices.
  """
  print('LOADING {}'.format(filename))
  if filename is not None:
    try:
      f = h5py.File(filename, 'r')
      AG=f['A']
      A = sparse.csr_matrix((np.array(AG['data']),AG['ir'],AG['jc']))
      A = A.transpose()
      B,C,D = [sparse.csr_matrix(np.array(f[x]).T) for x in list('BCD')]
    except:
      f = sio.loadmat(filename, variable_names=('A','B','C','D'))
      A = sparse.csr_matrix(f['A'])
      B = sparse.csr_matrix(f['B'])
      C = sparse.csr_matrix(f['C'])
      D = sparse.csr_matrix(f['D'])
  if ABC is not None:
    A = sparse.csr_matrix(ABC[0])
    B = sparse.csr_matrix(ABC[1])
    C = sparse.csr_matrix(ABC[2])
    D = np.zeros((1,1), dtype=np.float64)
  h = int(A.shape[0]/2)
  if verbose:
    print('State space synopsis:')
    print(' * A shape: {0} ; Block diagonal test (0,{5:d},1,1): {1} {2} {3} {4}'.format(A.shape,
      round(A[:h,:h].diagonal().sum(),2),
      round(A[:h,h:].diagonal().sum(),2),
      round(A[h:,:h].diagonal().sum()/A[h:,:h].sum(),2),
      round(A[h:,h:].diagonal().sum()/A[h:,h:].sum(),2), 
      int(A.shape[0]/2)))
    print(' * B shape:',B.shape)
    print(' * C shape:',C.shape)
    print(' * D shape:',D.shape)
  return (A,B,C,D)

def ss2fem( *args ):
  """
  Convert a FEM continuous state space model 
  into second order form
  ==========================================
  Parameters
    - A (numpy ndarray):
      The state space A matrix.
    - B (numpy ndarray):
      The state space B matrix.
    - C (numpy ndarray):
      The state space C matrix.
  Outputs:
    - O, Z, Phim, Phi, Phid (Tuple): 
      The eigen frequencies, the damping 
      coefficients, the inputs to modes, 
      modes to outputs matrix transforms, 
      and the respective residual matrix.
  """
  A,B,C,D = args[:4]
  h = int(A.shape[0]/2)
  O = np.sqrt(-A[h:,:h].diagonal())
  Z = -0.5*A[h:,h:].diagonal()/O
  Phi  = C[:,:-h]
  Phim = B[h:,:].T
  Phid = D[:,:]
  return O,Z,Phim.toarray(),Phi.toarray(),Phid.toarray()


def loadFEM2ndOrder(
    filename=None ):
  """
  Load a second order model from a 
  mat-file. The mat-file contains the 
  following variables:
    . eigenfrequencies
    . proportionalDampingVec
    . Phim
    . Phi
  ===========================================
  Parameters
    - filename (String):
      The name of the .mat file with the
      state space model matrices.
  Outputs:
    - O, Z, Phim, Phi, Phid (Tuple): 
      The eigen frequencies, the damping 
      coefficients, the inputs to modes, 
      modes to outputs matrix transforms, 
      and the respective residual matrix.
  """
  print('LOADING {}'.format(filename))
  data = sio.loadmat(filename)
  var = ['eigenfrequencies','proportionalDampingVec','Phim','Phi']
  return tuple(data[x] for x in var)

def c2d(
      A=None, 
      B=None,
      dt=None ):
    """
    This module computes the discrete 
    representation of the state space A and 
    B matrices for a sample time of dt. It 
    returns the discretized version of A and
    B, called here as Ad and Bd. 
    ========================================
    Parameters
      - A (numpy ndarray):
        The state space model state matrix.
      - B (numpy ndarray):
        The state space model input matrix.
      - dt (float):
        The desired discretization sample time.
    Outputs
      - Ad, Bd (Tuple):
        The discretized A and B matrices.
    """
    ss = A.shape[0] // 2
    I_2 = A[ss:,:ss].diagonal()
    I_3 = A[ss:,ss:].diagonal()
    Ad = np.zeros(A.shape, dtype=np.float32)
    Bd = np.zeros(B.shape, dtype=np.float32)
    A_ = np.zeros((3,3))
    B_ = np.zeros((2,B.shape[1]))
    A_[0,1], A_[1,2] = 1, 1
    phiGamma = np.zeros((3,3))
    for k in range(ss):
      ki = ss + k
      A_[1,0], A_[1,1] = I_2[k], I_3[k]
      B_[0,:] = B[k, :].toarray()
      B_[1,:] = B[ki,:].toarray()
      phiGamma = salg.expm(A_ * dt)
      Ad[k,k], Ad[k,ki] = phiGamma[0,0], phiGamma[0,1]
      Ad[ki,k], Ad[ki,ki] = phiGamma[1,0], phiGamma[1,1]
      Bd[k,:] = phiGamma[0,2] * B[ki,:].toarray()
      Bd[ki,:] = phiGamma[1,2] * B[ki,:].toarray()
    return sparse.csr_matrix(Ad), Bd








def freqrep(nu,Phi,Phim,O,Z,n_mode_max=None):
  """
  Computes the FEM transfer function

  Parameters
  ----------
  nu: ndarray
      The frequency vector in Hz
  Phi: ndarray
      The  modes to outputs matrix transform
  Phi: ndarray
      The inputs to modes matrix transform
  O: ndarray
      The eigen frequencies
  Z: ndarray
      The damping coefficients
  n_mode_max: int
      The number of modes, default: None (all the modes)
  """
  s = 2*1j*np.pi*nu
  if n_mode_max is None:
    q = s**2 + 2*s*Z*O + O**2
    iQ = sparse.diags(1/q)
    return Phi@iQ@Phim.T
  else:
    q = s**2 + 2*s*Z[:n_mode_max]*O[:n_mode_max] + O[:n_mode_max]**2
    iQ = sparse.diags(1/q)
    return Phi[:,:n_mode_max]@iQ@Phim[:,:n_mode_max].T


def save_variable_on_disk(info):
  '''
      Function that is parallelized to save process variables on disk,
      on simulation time.
  '''
  
  # Create variable directory
  if not os.path.exists(info['savepath']):
      os.makedirs(info['savepath'])
  var_name = info['savepath'] + info['varname'] + '.dat'
  # Create the memory map
  variable = np.memmap(var_name, dtype=np.float32, mode='w+', shape=info['shape'])
  print(' * Variable created...' )
  print('    |- keeping log of: ', info['shape'])
  print('    |- in:', var_name)
  # Create queue
  q = info['queue']
  while True: # start Deamon
    # remove one task from Queue
    ninfo = q.get()
    # check if is alive
    if ninfo['alive']:
      variable[:,ninfo['index']] = ninfo['data'][:]
    else:
      del variable  # flush and save output memory map
      break         # kill Deamon

