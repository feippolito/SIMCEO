import numpy as np
cimport numpy as np

assert sizeof(int) == sizeof(np.int32_t)

ctypedef double type_c
ctypedef int type_i

cdef extern from "model.h":
  cdef cppclass Driver:
    Driver()
    # Main methods from C++
    # driver class
    void Init(type_i*, type_c*, type_c*, type_c*, type_c*)
    void Start()
    void Update(type_c*)
    type_c* Output()

cdef class PyDriver:
  '''
    This is the python wrapper responsible
    to interface the python and C++ driver.
  '''
  cdef Driver *thisptr    # Pointer to C++ driver class
  cdef int nx, ny, nu     # SS model dimensions
  cdef type_c* cinputs    # Pointer to C++ input variable
  cdef type_c* coutputs   # Pointer to C++ output variable
  cdef outputs            # Python output numpy array
  cdef float_type         # The default float type
  cdef int_type           # The default int type
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
      A_matrix=None, 
      B_matrix=None, 
      C_matrix=None, 
      D_matrix=None,
      def_int_type=np.int32,
      def_float_type=np.float64):
    # Defining the model variables
    self.int_type, self.float_type = def_int_type, def_float_type
    # Defining the model dimensions
    cdef np.ndarray[int, ndim=1, mode="c"] cdimensions
    cdimensions = np.ndarray((3,), buffer=dimensions, order='C', dtype=self.int_type)
    self.nx, self.nu, self.ny = cdimensions[0], cdimensions[1], cdimensions[2]
    # Defining the model matrices variables
    cdef np.ndarray[type_c, ndim=2, mode="c"] cA_
    cdef np.ndarray[type_c, ndim=2, mode="c"] cB_
    cdef np.ndarray[type_c, ndim=2, mode="c"] cC_
    cdef np.ndarray[type_c, ndim=2, mode="c"] cD_
    # Allocate the values of the model matrices variables
    cA_ = np.ndarray(A_matrix.shape, buffer=A_matrix, order='C', dtype=self.float_type)
    cB_ = np.ndarray(B_matrix.shape, buffer=B_matrix, order='C', dtype=self.float_type)
    cC_ = np.ndarray(C_matrix.shape, buffer=C_matrix, order='C', dtype=self.float_type)
    cD_ = np.ndarray(D_matrix.shape, buffer=D_matrix, order='C', dtype=self.float_type)
    # Initialize the cpp model passing the state space model and 
    # the model dimensions
    self.thisptr.Init(&cdimensions[0], &cA_[0,0], &cB_[0,0], &cC_[0,0], &cD_[0,0])
    # Allocating the input variable for the state space model
    cdef np.ndarray[type_c, ndim=1, mode="c"] initial_inputs
    initial_buffer = np.zeros((self.nu,), dtype=self.float_type)
    initial_inputs = np.ndarray((self.nu,), buffer=initial_buffer, order='C', dtype=self.float_type)
    self.cinputs = &initial_inputs[0]
    # Allocating the output variable for the state space model
    self.outputs = np.zeros((self.ny,), dtype=self.float_type)
  
  def cStart(self):
    # Starting the cpp model and setting all the GPU
    # variables, allocating and attributing device variables
    self.thisptr.Start()
  
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