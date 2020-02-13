
import os
import scipy.sparse as ssp
import scipy.linalg as sli

import scipy.io as sio
import numpy as np

import matplotlib.pyplot as plt
import matplotlib.tri as mtri   
import matplotlib.animation as animation
import matplotlib as mpl
import scipy.spatial as ssp

try:
    import cupy as cp
    GPU_AVAILABLE = True
except:
    GPU_AVAILABLE = False

_cudaSettingsDefault = {
    'n_bins': 2000,
    'vartype': np.float64
}

_cpuSettingsDefault = {
    'n_bins': 2000,
    'vartype': np.float64
}


class plot_bendingModes:

    def __init__(self):
        pass


class LargeCompute:

    '''
        Library to compute large matrices.
    '''

    def __init__(self, 
                 cpuSettings=None,
                 savePath='./LargeComputeLogs/',
                 onCuda=False, cudaSettings=None):
        
        self._savePath = savePath

        # Create CPU setup
        self._cpuSettings = _cpuSettingsDefault
        if cpuSettings is not None:
            for item in cpuSettings:
                self._cpuSettings[item] = cpuSettings[item]

        # Check GPU availability
        self._onCuda = onCuda
        if self._onCuda and not GPU_AVAILABLE:
            print('There is no GPU library available.')
            self._onCuda = False
        
        # Create GPU setup
        if self._onCuda:
            self._cudaSettings = _cudaSettingsDefault
            if cudaSettings is not None:
                for item in cudaSettings:
                    self._cudaSettings[item] = cudaSettings[item]

        self._create_directory(self._savePath)

    def load_disp(self, states_path, dos_path, duration):
        import yaml
        with open(dos_path + '/FEM.yaml') as file:
            cfg = yaml.load(file, Loader=yaml.FullLoader)
        fem_ss = cfg['FEM']['build']['state_space_filename']
        fem_io = cfg['FEM']['build']['fem_io_filename']

        C = sio.loadmat(fem_ss)['C']
        shape_st_ = (C.shape[1],duration*2000+1)
        states = np.memmap(states_path, dtype=np.float32, mode='r+', shape=shape_st_)

        data = sio.loadmat(fem_io)
        fem_outputs=[(x[0][0],y[0]) for x,y in zip(data['FEM_IO']['outputs_name'][0,0],
                                                data['FEM_IO']['outputs_size'][0][0])]

        i_sum = 0
        i_, ii_ = 0, 0
        for k in fem_outputs:
            if k[0] != 'M1_surfaces_d':
                i_sum += k[1]
            else:
                ref_size = k[1]
                i_, ii_ = i_sum, i_sum + ref_size
        C = C[i_:ii_,:]
        indexes = range(2,C.shape[0],3)
        C = C[indexes, :]

        return self.dot_time(C, states)


    def _create_directory(self, dir_name):
        if not os.path.exists(dir_name):
            os.makedirs(dir_name)

    
    def remove_ptt(self, Q, displacements, vartype = np.float64):

        # get the shape of the displacements
        _size = displacements.shape
        # Create the directory for results
        self._create_directory(self._savePath+'remove_ptt_from_disp/')
        # Create the results variable
        _Resultvarname =  'remove_ptt_from_disp/result.dat'
        _Pttvarname =  'remove_ptt_from_disp/ptt.dat'
        result = np.memmap(self._savePath + _Resultvarname, dtype=vartype, mode='w+', shape=_size)
        ptt = np.memmap(self._savePath + _Pttvarname, dtype=vartype, mode='w+', shape=_size) 
        # If CUDA is available
        if self._onCuda:
            _vartype = self._cudaSettings['vartype']
            # Create the GPU matrices
            _const_Q = cp.asarray(Q, dtype=_vartype)
            # Create some constants
            _packSize = self._cudaSettings['n_bins']
            _packs = _size[1] // self._cudaSettings['n_bins']
            # for each time packages
            for k in range(_packs + 1):
                ki = k * _packSize
                kii = (k+1)*_packSize 
                if kii > _size[1]:
                    kii = _size[1]
                _disp_pack = cp.asarray(displacements[:,ki:kii], dtype=_vartype)
                _aux = np.linalg.lstsq(Q, displacements[:,ki:kii])[0]
                _aux_cp = cp.asarray(_aux, dtype=_vartype)
                ptt_cp = cp.dot(_const_Q, _aux_cp)
                _result = _disp_pack - ptt_cp
                result[:,ki:kii] = _result[:,:].get()
                ptt[:,ki:kii]= ptt_cp.get()
        else:
            print("remove ptt not suported on cpu")
            """
            #result = np.zeros(_size)
            for k in range(_size[1]):
                _auxiliar = displacements[:,k]
                _ptt = sli.lstsq(ptt, _auxiliar)[0]
                _auxiliar_ = np.dot(ptt, _ptt)
                result[:,k] = _auxiliar - _auxiliar_
            """
        return result, ptt 


    def bm_to_disp_time(self, U, bending_modes,
                    varname=None,
                    vartype=np.float32):
        # check if the variables exists
        if U is None:
            print("Please provide the proper U parameter.")
            pass
        if bending_modes is None:
            print("Please provide the bending_modes parameter.")
            pass
        # create the directory for results
        self._create_directory(self._savePath+'bm_to_disp_time/')
        # determine the bending mode shape
        _time = bending_modes.shape[1]
        _shape = (U.shape[0], _time)
        # create the results variable
        if varname is not None:
            _varname = varname + '.dat'
        else:
            _varname = 'result.dat'
        result = np.memmap(self._savePath+'bm_to_disp_time/' + _varname, 
                        dtype=vartype, mode='w+', shape=_shape) 
        # Compute the displacements
        for k in range(_time):
            # create the bending modes diagonal
            _disp = np.dot(U, bending_modes[:,k])
            result[:,k] = _disp[:]

        return result[:,:]

    def dot_time(self, b, a_t,
                 varname=None,
                 vartype=np.float32):

        # Create the directory for results
        _savePath = self._savePath + 'dot_time/'
        self._create_directory(_savePath)
        # Create the variable name
        if varname is not None:
            _varName = _savePath + varname + '.dat'
        else:
            _varName = _savePath + 'result.dat'

        if self._onCuda:
            _varType = self._cudaSettings['vartype']
            # Create the constants for simulation
            _prop = a_t.shape[1] // self._cudaSettings['n_bins']
            _shape = (b.shape[0], a_t.shape[1])
            # Create the result variable
            result = np.memmap(_varName, dtype=_varType, mode='w+', shape=_shape)
            # Create the necessary GPU variables
            _gpu_b = cp.asarray(b, dtype=_varType)
            # For for each data pack
            for k in range(_prop):                
                ki = k * self._cudaSettings['n_bins']
                if k != (_prop - 1):
                    kii = (k + 1) * self._cudaSettings['n_bins']
                else:
                    kii = a_t.shape[1]
                # Create the proper a_t on GPU
                _gpu_a = cp.asarray(a_t[:,ki:kii], dtype=_varType)
                # Compute the dot product
                _gpu_result = cp.dot(_gpu_b, _gpu_a)
                # Retrieve the data
                result[:,ki:kii] = _gpu_result.get()[:,:]
        else:
            print("dot_time not available on cpu")
            pass
            """ 
            # Create constants
            _prop = a_t.shape[1] // self.horizon
            _shape = (b.shape[0], a_t.shape[1])
            # Create constants
            _prop = a_t.shape[1] // self.horizon
            _shape = (b.shape[0], a_t.shape[1])
            # Create the results variable
            result = np.memmap(self.savepath+'dot_time/result.dat', dtype=vartype, mode='w+', shape=_shape)
            for k in range(_prop):
                ki = k * self.horizon
                if k != (_prop - 1):
                    kii = (k + 1) * self.horizon
                else:
                    kii = a_t.shape[1]
                result[:,ki:kii] = np.dot(b[:,:], a_t[:,ki:kii])
            """        
        return result
