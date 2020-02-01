cdef extern from "M1HPloadcells0.h":
	ctypedef double real_T
	ctypedef struct ExtU_M1HPloadcells0_T:
		real_T Feedback[126]   #              /* '<Root>/Feedback' */
	ctypedef struct ExtY_M1HPloadcells0_T:
		real_T Output[42]     #              /* '<Root>/Output' */
	ExtU_M1HPloadcells0_T M1HPloadcells0_U
	ExtY_M1HPloadcells0_T M1HPloadcells0_Y
	void M1HPloadcells0_initialize()
	void M1HPloadcells0_step()
	void M1HPloadcells0_terminate()

cimport numpy as np
import numpy as np

class M1HPloadcells0: 
	'''
	This class was automatically generated from the simulink subsystem 'M1HPloadcells0'.

	For more information on how this code was generated access:
	https://github.com/feippolito/NSEElib/tree/master/MATLAB/%2Bcompile - pycreate.m

	Generated on 24-Jan-2020.
	'''

	def __init__(self):
		self.__yout = np.zeros(0)

	def init(self):
		M1HPloadcells0_initialize()
		self.__yout = np.zeros(42)

	def update(self, np.ndarray u):
		cdef double[:] __u
		cdef int k
		__u = np.ravel(np.asarray(u))
		for k in range(126):
			M1HPloadcells0_U.Feedback[k] = __u[k]
		M1HPloadcells0_step()

	def output(self):
		cdef int k
		for k in range(42):
			self.__yout[k] = M1HPloadcells0_Y.Output[k]
		return np.atleast_2d(self.__yout)

	def terminate():
		M1HPloadcells0_terminate()