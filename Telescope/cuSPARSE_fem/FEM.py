import logging
import numpy as np
from Telescope.driver import mainFEMDriver

logging.basicConfig()

from Telescope.lib.driver import PyDriver

class FEM(mainFEMDriver):
  """
  This is the FEM model template. It has the basics functionalities
  such as .mat reading methods, discretization procedures, CEO in-
  terfaces and so on. So it is only necessary to include the neces-
  sary code to compute the model already prepared by this interface.
  """

  def __init__(self, 
      verbose=logging.INFO, 
      size_c=np.float64,
      size_i=np.int32,
      **kwargs):
    self.size_c, self.size_i = size_c, size_i
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

  def Init(self, **kwargs):
    self.driver_Init(**kwargs)
    ##########################
    ##  INCLUDE YOUR INIT   ##
    ##     CODE HERE        ##
    ##########################
    self.logger.info("Initializing C++ simulation elements...")
    nx = self.state['A'].shape[0]
    ny = self.state['C'].shape[0]
    nu = self.state['B'].shape[1]
    dim_info = np.array([nx,nu,ny], dtype=self.size_i)
    dim_values = np.ndarray(dim_info.shape, buffer=dim_info, order='C', dtype=self.size_i)
    # Refactor the state space matrices for the Cpp computation module
    self.logger.info("Starting C++ simulation elements...")
    self.state["A"], self.state["C"], self.state["D"] = self.state["A"].todense(), self.state["C"].todense(), self.state["D"].todense()
    self.state["A"], self.state["B"] = self.state["A"].astype(self.size_c), self.state["B"].astype(self.size_c)
    self.state["C"], self.state["D"] = self.state["C"].astype(self.size_c), self.state["D"].astype(self.size_c)
    # Initialize and start the cpp model
    self.c_model.cInit(dim_values, self.state["A"], self.state["B"], self.state["C"], self.state["D"])
    self.c_model.cStart()
    ##########################
    self.logger.info("Running simulation...")

  """
          ======= INITIALIZING THE SIMULATION =======
  From here you have access of a structure called states accessible
  with self.states, this structure has the following variables:
    - "A", "B", "C" and "D":
      Those are the state space model matrices, already treated and
      considering only the inports and outports used subsystems, ie
      the reduced state space model.
    - "u", "y", "x": 
      Respectivelly, the input vector (all inports data concatenated)
      the output vector (all outports data concatenated) and the 
      model states vector, already reduced.
  """

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