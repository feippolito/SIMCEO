from scipy import signal
import pickle
from .mpc_driver import MPC
from .sh_aco_driver import SHAcO
from .sh_aco_debug_driver import SHAcO_debug
from .MountController import Mount
from .M1LocalControl0Controller import M1LocalControl0
from .M1HPloadcells0Controller import M1HPloadcells0
from .M1Pos0Controller import M1Pos0
from .M1PosDebug0Controller import M1PosDebug0
from .source import Source
import numpy as np

class System:
    def __init__(self,**kwargs):
        self.system = signal.dlti(*tuple(kwargs['parameters'].values()))
        self.__xout = np.zeros(0)
        self.__yout = np.zeros(0)

    def init(self):
        self.system = self.system._as_ss()
        self.__xout = np.zeros((self.system.A.shape[1],1))
        self.__yout = np.zeros((self.system.C.shape[0],1))

    def update(self,u):
        try:
            self.__xout = self.system.A @ self.__xout + self.system.B @ u
            self.__yout = self.system.C @ self.__xout + self.system.D @ u
            
        except ValueError:
            u = u.reshape(self.system.B.shape[1],1)
            self.__xout = self.system.A @ self.__xout + self.system.B @ u
            self.__yout = self.system.C @ self.__xout + self.system.D @ u
            

    def output(self):
        return np.atleast_2d(self.__yout.ravel())
