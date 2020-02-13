cdef extern from "M1LocalControl_wBM0.h":
	ctypedef double real_T
	ctypedef struct ExtU_M1LocalControl_wBM0_T:
		real_T Feedback[231]   #              /* '<Root>/Feedback' */
	ctypedef struct ExtY_M1LocalControl_wBM0_T:
		real_T Output[2316]     #              /* '<Root>/Output' */
	ExtU_M1LocalControl_wBM0_T M1LocalControl_wBM0_U
	ExtY_M1LocalControl_wBM0_T M1LocalControl_wBM0_Y
	void M1LocalControl_wBM0_initialize()
	void M1LocalControl_wBM0_step()
	void M1LocalControl_wBM0_terminate()

cimport numpy as np
import numpy as np

class M1LocalControl_wBM0: 
	'''
	This class was automatically generated from the simulink subsystem 'M1LocalControl_wBM0'.

	For more information on how this code was generated access:
	https://github.com/feippolito/NSEElib/tree/master/MATLAB/%2Bcompile - pycreate.m

	Generated on 12-Feb-2020.
	'''

	def __init__(self):
		self.__yout = np.zeros(0)

	def init(self):
		M1LocalControl_wBM0_initialize()
		self.__yout = np.zeros(2316)

	def update(self, np.ndarray u):
		cdef double[:] __u
		cdef int k
		__u = np.ravel(np.asarray(u))
		for k in range(231):
			M1LocalControl_wBM0_U.Feedback[k] = __u[k]
		M1LocalControl_wBM0_step()

	def output(self):
		cdef int k
		for k in range(2316):
			self.__yout[k] = M1LocalControl_wBM0_Y.Output[k]
		return np.atleast_2d(self.__yout)

	def terminate():
		M1LocalControl_wBM0_terminate()