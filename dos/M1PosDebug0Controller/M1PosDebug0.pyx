cdef extern from "M1PosDebug0.h":
	ctypedef double real_T
	ctypedef struct ExtU_M1PosDebug0_T:
		real_T Feedback[42]   #              /* '<Root>/Feedback' */
	ctypedef struct ExtY_M1PosDebug0_T:
		real_T Output[84]     #              /* '<Root>/Output' */
	ExtU_M1PosDebug0_T M1PosDebug0_U
	ExtY_M1PosDebug0_T M1PosDebug0_Y
	void M1PosDebug0_initialize()
	void M1PosDebug0_step()
	void M1PosDebug0_terminate()

cimport numpy as np
import numpy as np

class M1PosDebug0: 
	'''
	This class was automatically generated from the simulink subsystem 'M1PosDebug0'.

	For more information on how this code was generated access:
	https://github.com/feippolito/NSEElib/tree/master/MATLAB/%2Bcompile - pycreate.m

	Generated on 21-Jan-2020.
	'''

	def __init__(self):
		self.__yout = np.zeros(0)

	def init(self):
		M1PosDebug0_initialize()
		self.__yout = np.zeros(84)

	def update(self, np.ndarray u):
		cdef double[:] __u
		cdef int k
		__u = np.ravel(np.asarray(u))
		for k in range(42):
			M1PosDebug0_U.Feedback[k] = __u[k]
		M1PosDebug0_step()

	def output(self):
		cdef int k
		for k in range(84):
			self.__yout[k] = M1PosDebug0_Y.Output[k]
		return np.atleast_2d(self.__yout)

	def terminate():
		M1PosDebug0_terminate()