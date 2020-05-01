import logging
import numpy as np
from Telescope.driver import mainFEMDriver

logging.basicConfig()

from Telescope.model_wrapper import PyDriver

class FEM(mainFEMDriver):
  """
  This is the FEM model template. It has the basics functionalities
  such as .mat reading methods, discretization procedures, CEO in-
  terfaces and so on. So it is only necessary to include the neces-
  sary code to compute the model already prepared by this interface.
  """

  def __init__(self, verbose=logging.INFO, **kwargs):
    super().__init__(verbose=verbose, **kwargs)

  def Start(self, **kwargs):
    self.driver_Start(**kwargs)
    ##########################
    ##  INCLUDE YOUR START  ##
    ##     CODE HERE        ##
    ##########################
    self.c_model = PyDriver()
    ##########################
    return "FEM"

  """
          ======= INITIALIZING THE SIMULATION =======
  From here you have access of a structure called states accessible
  with self.state, this structure has the following variables:
    - "A", "B", "C" and "D":
      Those are the state space model matrices, already treated and
      considering only the inports and outports used subsystems, ie
      the reduced state space model.
    - "u", "y", "x": 
      Respectivelly, the input vector (all inports data concatenated)
      the output vector (all outports data concatenated) and the 
      model states vector, already reduced.
  """

  def Init(self, **kwargs):
    self.driver_Init(**kwargs)
    ##########################
    ##  INCLUDE YOUR INIT   ##
    ##     CODE HERE        ##
    ##########################
    print(" ***** DEBUG *****")
    print(type(self.state['u'][0]))
    print(type(self.state['y'][0]))
    print("******************")

    self.logger.info("Initializing C++ simulation elements...")
    sizes, groups = [], [0,0]
    for item in self.INPUTS:
      sizes.append(item[1])
      groups[0] += 1
    for item in self.OUTPUTS:
      sizes.append(item[1])
      groups[1] += 1
    nx = self.state['A'].shape[0]
    ny = self.state['C'].shape[0]
    nu = self.state['B'].shape[1]
    dim_info = np.array([nx,nu,ny], dtype=np.int32)
    sizes_info = np.array(sizes, dtype=np.int32)
    group_info = np.array(groups, dtype=np.int32)
    dim_values = np.ndarray(dim_info.shape, buffer=dim_info, order='C', dtype=np.int32)
    sizes_values = np.ndarray(sizes_info.shape, buffer=sizes_info, order='C', dtype=np.int32)
    group_values = np.ndarray(group_info.shape, buffer=group_info, order='C', dtype=np.int32)

    print(" ***** DEBUG *****")
    print(dim_values)
    print(sizes_values)
    print(group_values)
    print("******************")

    self.c_model.cInit(dim_values, sizes_values, group_values)
    # 
    self.logger.info("Starting C++ simulation elements...")
    self.state["A"] = self.state["A"].todense()
    self.state["C"] = self.state["C"].todense()
    self.state["D"] = self.state["D"].todense()

    print(" ***** DEBUG *****")
    print(type(self.state['A'][0,0]))
    print(type(self.state['B'][0,0]))
    print(type(self.state['C'][0,0]))
    print(type(self.state['D'][0]))
    print("******************")

    self.state["A"] = self.state["A"].astype(np.float64)
    self.state["B"] = self.state["B"].astype(np.float64)
    self.state["C"] = self.state["C"].astype(np.float64)
    self.state["D"] = self.state["D"].astype(np.float64)

    self.c_model.cStart(self.state["A"], self.state["B"], self.state["C"], self.state["D"])
    #
    self.state['cu'] = np.ndarray((nu,), buffer=self.state['u'], order='C', dtype=np.float64)
    self.state['cy'] = np.ndarray((ny,), buffer=self.state['y'], order='C', dtype=np.float64)
    ##########################
    self.logger.info("Running simulation...")

  def Update(self, **kwargs):
    a, b = 0, 0
    for t, s in self.INPUTS:
      b += s
      if t in kwargs:
        self.state['u'][a:b] = kwargs[t]

      a += s
    ##########################
    ## INCLUDE YOUR UPDATE  ##
    ##     CODE HERE        ##
    ##########################
    
    self.c_model.cUpdate(self.state["u"])
    
    ##########################

  def Outputs(self, **kwargs):
    ##########################
    ## INCLUDE YOUR OUTPUT  ##
    ##     CODE HERE        ##
    ##########################

    self.state["y"] = self.c_model.cOutput()
    
    ##########################
    d = {}
    if kwargs:
      outputs = kwargs['outputs']
      a, b = 0, 0
      for t,s in self.OUTPUTS:
        b += s
        if t in outputs:
          d[t] = self.state['y'][a:b]
        a += s
    return d