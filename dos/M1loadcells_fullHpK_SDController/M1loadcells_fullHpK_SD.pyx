cdef extern from "M1loadcells_fullHpK_SD.h":
	ctypedef double real_T
	ctypedef struct ExtU_M1loadcells_fullHpK_SD_T:
		real_T Feedback[126]   #              /* '<Root>/Feedback' */
	ctypedef struct ExtY_M1loadcells_fullHpK_SD_T:
		real_T Output[42]     #              /* '<Root>/Output' */
	ExtU_M1loadcells_fullHpK_SD_T M1loadcells_fullHpK_SD_U
	ExtY_M1loadcells_fullHpK_SD_T M1loadcells_fullHpK_SD_Y
	void M1loadcells_fullHpK_SD_initialize()
	void M1loadcells_fullHpK_SD_step()
	void M1loadcells_fullHpK_SD_terminate()

cimport numpy as np
import numpy as np

class M1loadcells_fullHpK_SD: 
	'''
	This class was automatically generated from the simulink subsystem 'M1loadcells_fullHpK_SD'.

	For more information on how this code was generated access:
	https://github.com/feippolito/NSEElib/tree/master/MATLAB/%2Bcompile - pycreate.m

	Generated on 14-Feb-2020.
	'''

	def __init__(self):
		self.__yout = np.zeros(0)

	def init(self):
		M1loadcells_fullHpK_SD_initialize()
		self.__yout = np.zeros(42)

	def update(self, np.ndarray u):
		cdef double[:] __u
		cdef int k
		__u = np.ravel(np.asarray(u))
		for k in range(126):
			M1loadcells_fullHpK_SD_U.Feedback[k] = __u[k]
		M1loadcells_fullHpK_SD_step()

	def output(self):
		cdef int k
		for k in range(42):
			self.__yout[k] = M1loadcells_fullHpK_SD_Y.Output[k]
		return np.atleast_2d(self.__yout)

	def terminate():
		M1loadcells_fullHpK_SD_terminate()