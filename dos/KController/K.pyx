cdef extern from "K.h":
	ctypedef double real_T
	ctypedef struct ExtU_K_T:
		real_T Feedback[1144]   #              /* '<Root>/Feedback' */
	ctypedef struct ExtY_K_T:
		real_T Output[1078]     #              /* '<Root>/Output' */
	ExtU_K_T K_U
	ExtY_K_T K_Y
	void K_initialize()
	void K_step()
	void K_terminate()

cimport numpy as np
import numpy as np

class K: 
	'''
	This class was automatically generated from the simulink subsystem 'K'.

	For more information on how this code was generated access:
	https://github.com/feippolito/NSEElib/tree/master/MATLAB/%2Bcompile - pycreate.m

	Generated on 21-Feb-2020.
	'''

	def __init__(self):
		self.__yout = np.zeros(0)

	def init(self):
		K_initialize()
		self.__yout = np.zeros(1078)

	def update(self, np.ndarray u):
		cdef double[:] __u
		cdef int k
		__u = np.ravel(np.asarray(u))
		for k in range(1144):
			K_U.Feedback[k] = __u[k]
		K_step()

	def output(self):
		cdef int k
		for k in range(1078):
			self.__yout[k] = K_Y.Output[k]
		return np.atleast_2d(self.__yout)

	def terminate():
		K_terminate()