cdef extern from "BM2F.h":
	ctypedef double real_T
	ctypedef struct ExtU_BM2F_T:
		real_T Feedback[189]   #              /* '<Root>/Feedback' */
	ctypedef struct ExtY_BM2F_T:
		real_T Output[1144]     #              /* '<Root>/Output' */
	ExtU_BM2F_T BM2F_U
	ExtY_BM2F_T BM2F_Y
	void BM2F_initialize()
	void BM2F_step()
	void BM2F_terminate()

cimport numpy as np
import numpy as np

class BM2F: 
	'''
	This class was automatically generated from the simulink subsystem 'BM2F'.

	For more information on how this code was generated access:
	https://github.com/feippolito/NSEElib/tree/master/MATLAB/%2Bcompile - pycreate.m

	Generated on 21-Feb-2020.
	'''

	def __init__(self):
		self.__yout = np.zeros(0)

	def init(self):
		BM2F_initialize()
		self.__yout = np.zeros(1144)

	def update(self, np.ndarray u):
		cdef double[:] __u
		cdef int k
		__u = np.ravel(np.asarray(u))
		for k in range(189):
			BM2F_U.Feedback[k] = __u[k]
		BM2F_step()

	def output(self):
		cdef int k
		for k in range(1144):
			self.__yout[k] = BM2F_Y.Output[k]
		return np.atleast_2d(self.__yout)

	def terminate():
		BM2F_terminate()