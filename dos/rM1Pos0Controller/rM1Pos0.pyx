cdef extern from "rM1Pos0.h":
	ctypedef double real_T
	ctypedef struct ExtU_rM1Pos0_T:
		real_T Feedback[42]   #              /* '<Root>/Feedback' */
	ctypedef struct ExtY_rM1Pos0_T:
		real_T Output[42]     #              /* '<Root>/Output' */
	ExtU_rM1Pos0_T rM1Pos0_U
	ExtY_rM1Pos0_T rM1Pos0_Y
	void rM1Pos0_initialize()
	void rM1Pos0_step()
	void rM1Pos0_terminate()

cimport numpy as np
import numpy as np

class rM1Pos0: 
	'''
	This class was automatically generated from the simulink subsystem 'rM1Pos0'.

	For more information on how this code was generated access:
	https://github.com/feippolito/NSEElib/tree/master/MATLAB/%2Bcompile - pycreate.m

	Generated on 13-Jan-2020.
	'''

	def __init__(self):
		self.__yout = np.zeros(0)

	def init(self):
		rM1Pos0_initialize()
		self.__yout = np.zeros(42)

	def update(self, np.ndarray u):
		cdef double[:] __u
		cdef int k
		__u = np.ravel(np.asarray(u))
		for k in range(42):
			rM1Pos0_U.Feedback[k] = __u[k]
		rM1Pos0_step()

	def output(self):
		cdef int k
		for k in range(42):
			self.__yout[k] = rM1Pos0_Y.Output[k]
		return np.atleast_2d(self.__yout)

	def terminate():
		rM1Pos0_terminate()