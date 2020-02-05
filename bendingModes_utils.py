import scipy.io as sio
import numpy as np

import matplotlib.pyplot as plt
import matplotlib.tri as mtri   
import matplotlib.animation as animation
import matplotlib as mpl
import scipy.spatial as ssp
    

class bending_modes:
    def __init__(self, transformation_path):
        self.Q = np.squeeze(sio.loadmat(transformation_path)['Q_incell'])
        self.U = np.squeeze(sio.loadmat(transformation_path)['U_incell'])
        self.S = np.squeeze(sio.loadmat(transformation_path)['Sz_incell'])
        self.V = np.squeeze(sio.loadmat(transformation_path)['Vz_incell'])
        
    def load_displacements(self, states_path, C_path, duration):
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

        displacements_ptt = np.dot(C, states)

        indc1 = [x*742 for x in range(1,7)]
        seg_displacements_ptt = np.array(np.split(displacements_ptt,
                                        indices_or_sections = indc1,
                                        axis = 0), dtype = object)
        return seg_displacements_ptt

    def bm2d(self, bm, seg = 7):
        rec_d = np.empty(seg,dtype=object)
        nModes = bm.shape[1]
        for s in range(seg):
            rec_d[s] = np.dot(self.U[s][:,0:nModes], bm[:,:,s].T)
        return rec_d

    def d2bm(self, disp, seg = 7):
        rec_bm = np.empty(seg,dtype=object)
        for s in range(seg):
            rec_bm[s] = np.dot(self.U[s], disp[s,:,:])
        return rec_bm

    """
    def remove_ptt_time(seg_displacements_ptt, Q, vartype = np.float64):
        n_samples = seg_displacements_ptt.shape[1]
        n_nodes = seg_displacements_ptt.shape[0]

        displacements_noptt_ = np.empty([seg ,n_nodes, n_samples], dtype=vartype)
        ptt = np.empty([seg, n_nodes, n_samples], dtype=vartype)
        
        for s in range(seg):
            for k in range(displacements_noptt_.shape[2]):
                _aux = np.linalg.lstsq(self.Q[s], seg_displacements_ptt[:,k])[0]
                ptt[:,k] = np.dot(Q, _aux)
                displacements_noptt_[:,k] = seg_displacements_ptt[:,k] - ptt[:,k]

        return displacements_noptt_, ptt
    """

    def return_surface(self, seg, disp ,Ts , zmin, zmax, ax, fig):
    
        resolution = 100
        Q = self.Q[seg]
        tri = ssp.Delaunay(Q[:,[0,1]])

        xi = Q[:,0]
        yi = Q[:,1]
        
        z = disp[seg][:,Ts]

        triang = mtri.Triangulation(xi, yi, tri.simplices.copy())
        
        z_values = z

        interp_cubic_geom = mtri.CubicTriInterpolator(triang, z_values, kind='geom')
        xi = np.linspace(xi.min(), xi.max(), resolution)
        yi = np.linspace(yi.min(), yi.max(), resolution)
        xii, yii = np.meshgrid(xi, yi)
        zi_cubic_geom = interp_cubic_geom(xii, yii)

        z_min, z_max = z.min(), z.max()
        
        graph = ax.contourf(xii, yii, zi_cubic_geom, vmin = zmin, vmax = zmax)
        return graph

    def plot_surf(self, disp, seg, Ts, figsize = (10,12)):
        
        z_max = np.amax(disp[seg])
        z_min = np.amin(disp[seg])

        fig = plt.figure(figsize = figsize)
        ax = fig.subplots(1,1)
        graph = self.return_surface(seg, disp, Ts, z_min, z_max, ax, fig)
        fig.colorbar(graph, orientation='vertical')
        ax.set_title('Segment ' + str(seg + 1) + ' - Time: ' + str(Ts/2000) + ' sec' )

        return ax


    """
    def plot_diff(self, bm, disp, seg, Ts, rec_disp = None, figsize = (30,12)):

        if rec_disp is None:
            rec_disp = bm2d(bm)

        fig, axes =  plt.subplots(1 ,3 ,figsize = figsize)
        ax1, ax2, ax3 = axes

        z_max = np.amax(rec_disp[seg])
        z_min = np.amin(rec_disp[seg])
        z_step = (z_max - z_min)/10

        error = disp_noPTT[seg] - rec_disp[seg]
        e_max = np.amax(error)
        e_min = np.amin(error)
    """
    
    def animation(self):
        pass

    def create_video(self):
        pass