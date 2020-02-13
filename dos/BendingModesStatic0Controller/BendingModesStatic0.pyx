cdef extern from "BendingModesStatic0.h":
	ctypedef double real_T
	ctypedef struct ExtU_BendingModesStatic0_T:
		real_T Feedback[2316]   #              /* '<Root>/Feedback' */
	ctypedef struct ExtY_BendingModesStatic0_T:
		real_T Output[189]     #              /* '<Root>/Output' */
	ExtU_BendingModesStatic0_T BendingModesStatic0_U
	ExtY_BendingModesStatic0_T BendingModesStatic0_Y
	void BendingModesStatic0_initialize()
	void BendingModesStatic0_step()
	void BendingModesStatic0_terminate()

cimport numpy as np
import numpy as np

class BendingModesStatic0: 
	'''
	This class was automatically generated from the simulink subsystem 'BendingModesStatic0'.

	For more information on how this code was generated access:
	https://github.com/feippolito/NSEElib/tree/master/MATLAB/%2Bcompile - pycreate.m

	Generated on 11-Feb-2020.
	'''

	def __init__(self):
		self.__yout = np.zeros(0)

	def init(self):
		BendingModesStatic0_initialize()
		self.__yout = np.zeros(189)

	def update(self, np.ndarray u):
		cdef double[:] __u
		cdef int k
		__u = np.ravel(np.asarray(u))
		for k in range(2316):
			BendingModesStatic0_U.Feedback[k] = __u[k]
		BendingModesStatic0_step()

	def output(self):
		cdef int k
		for k in range(189):
			self.__yout[k] = BendingModesStatic0_Y.Output[k]
		return np.atleast_2d(self.__yout)

	def terminate():
		BendingModesStatic0_terminate()