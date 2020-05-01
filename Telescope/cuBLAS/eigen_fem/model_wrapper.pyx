#This is a Cython file and extracts the relevant classes from the C++ header file.

# distutils: language = c++
# distutils: sources = model.cpp

cdef extern from "model.hpp" namespace "drivers":
    cdef cppclass Driver:
        Driver()
        # Main methods form C++ 
        # driver class
        void Init(int*, int*, int*)
        void Start(double*, double*, double*, double*)
        void Update(double*)
        double* Output()
        # Support methods from C++
        # driver class
        int* getSizes()
        double* getSSmodel(int)
        double* getStates()

cimport numpy as np
import numpy as np

cdef class PyDriver:
  '''
    This is the python wrapper responsible
    to interface the python and C++ driver.
  '''
  cdef Driver *thisptr  # Pointer to C++ driver class
  cdef int nx, ny, nu   # SS model dimensions
  cdef double* cinputs   # Pointer to C++ input variable
  cdef double* coutputs  # Pointer to C++ output variable
  cdef outputs          # Python output numpy array
  cdef float_type       # The default float type
  cdef int_type         # The default int type
  '''
    The main and necessary methods used
    for the simulation process
  '''
  def __cinit__(self):
    self.thisptr = new Driver()
  
  def __dealloc__(self):
    del self.thisptr
  
  def cInit(self,
      dimensions=None,
      sizes=None,
      groups=None,
      def_int_type=np.int32,
      def_float_type=np.float64):
    self.int_type = def_int_type
    self.float_type = def_float_type
    cdef np.ndarray[int, ndim=1, mode="c"] cdimensions
    cdef np.ndarray[int, ndim=1, mode="c"] csizes
    cdef np.ndarray[int, ndim=1, mode="c"] cgroups
    cdimensions = np.ndarray((3,), buffer=dimensions, order='C', dtype=self.int_type)
    csizes = np.ndarray((sizes.shape[0],), buffer=sizes, order='C', dtype=self.int_type)
    cgroups = np.ndarray((2,), buffer=groups, order='C', dtype=self.int_type)
    self.nx, self.nu, self.ny = cdimensions[0], cdimensions[1], cdimensions[2]
    self.thisptr.Init(&cdimensions[0], &csizes[0], &cgroups[0])
  
  def cStart(self,
      A_matrix=None, B_matrix=None, 
      C_matrix=None, D_matrix=None ):
    # Defining the model matrices variables
    cdef np.ndarray[double, ndim=2, mode="c"] cA_
    cdef np.ndarray[double, ndim=2, mode="c"] cB_
    cdef np.ndarray[double, ndim=2, mode="c"] cC_
    cdef np.ndarray[double, ndim=2, mode="c"] cD_
    # Allocate the values of the model matrices variables
    cA_ = np.ndarray((self.nx, self.nx), buffer=A_matrix, order='C', dtype=self.float_type)
    cB_ = np.ndarray((self.nx, self.nu), buffer=B_matrix, order='C', dtype=self.float_type)
    cC_ = np.ndarray((self.ny, self.nx), buffer=C_matrix, order='C', dtype=self.float_type)
    cD_ = np.ndarray(D_matrix.shape, buffer=D_matrix, order='C', dtype=self.float_type)
    self.thisptr.Start(&cA_[0,0], &cB_[0,0], &cC_[0,0], &cD_[0,0])
    # Allocating the input variable for the state space model
    cdef np.ndarray[double, ndim=1, mode="c"] initial_inputs
    initial_inputs = np.ndarray((self.nu,), buffer=np.zeros((self.nu,), dtype=self.float_type), order='C', dtype=self.float_type)
    self.cinputs = &initial_inputs[0]
    # Allocating the output variable for the state space model
    self.outputs = np.zeros((self.ny,), dtype=self.float_type)
  
  def cUpdate(self, 
      input_values=None ):
    cdef int k
    # Write the python variable
    # values into C++ variable
    for k in range(self.nu):
      self.cinputs[k] = input_values[k]
    self.thisptr.Update(self.cinputs)

  def cOutput(self):
    cdef int k
    self.coutputs = self.thisptr.Output()
    # Write the C++ values into
    # python variable
    for k in range(self.ny):
      self.outputs[k] = self.coutputs[k]
    return self.outputs

  '''
    Support methods to retrieve variables
    and validate the C++ driver
  '''
  def getSizes(self):
    cdef int* result
    result = self.thisptr.getSizes()
    output = np.zeros((5,), dtype=np.int32)
    for k in range(5):
      output[k] = result[k]
    return output

  def getSSmodel(self, ss_ind):
    cdef int ss_cind = ss_ind
    A_matrix = np.zeros((2,2), dtype=self.float_type)
    B_matrix = np.zeros((2,4), dtype=self.float_type)
    C_matrix = np.zeros((5,2), dtype=self.float_type)
    D_matrix = np.zeros((5,4), dtype=self.float_type)
    cdef double* result = self.thisptr.getSSmodel(ss_cind)
    if ss_ind == 0:
      for i in range(2):
        for j in range(2):
          A_matrix[i,j] = result[j+2*i]
      output = A_matrix
    if ss_ind == 1:
      for i in range(2):
        for j in range(4):
          B_matrix[i,j] = result[j+4*i]
      output = B_matrix
    if ss_ind == 2:
      for i in range(5):
        for j in range(2):
          C_matrix[i,j] = result[j+2*i]
      output = C_matrix
    if ss_ind == 3:
      for i in range(5):
        for j in range(4):
          D_matrix[i,j] = result[j+4*i]
      output = D_matrix
    return output
  
  def getStates(self):
    states = np.zeros((2,), dtype=self.float_type)
    cdef double* result = self.thisptr.getStates()
    for k in range(2):
      states[k] = result[k]
    return states