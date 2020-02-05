def remove_ptt_time(seg_displacements_ptt, Q, vartype = np.float64):
    n_samples = seg_displacements_ptt.shape[1]
    n_nodes = seg_displacements_ptt.shape[0]

    displacements_noptt_ = np.empty([n_nodes, n_samples], dtype=vartype)
    ptt = np.empty([n_nodes, n_samples], dtype=vartype)
    
    for k in range(displacements_noptt_.shape[1]):
        _aux = np.linalg.lstsq(Q, seg_displacements_ptt[:,k])[0]
        ptt[:,k] = np.dot(Q, _aux)
        displacements_noptt_[:,k] = seg_displacements_ptt[:,k] - ptt[:,k]
    return displacements_noptt_, ptt

def disp_to_bm(disp_noPTT, U):
    return np.dot(U.T, disp_noPTT) # returns bm

def bm_to_disp(bm, U):
    return np.dot(U, bm) 

def plot_surface(displacements ,Ts ,seg, Q):
    
    import matplotlib.pyplot as plt
    import matplotlib.tri as mtri   
    import matplotlib.animation as animation
    import matplotlib as mpl
    import scipy.spatial as ssp
    
    resolution = 100

    tri = ssp.Delaunay(Q[seg][:,[0,1]])

    xi = Q[seg][:,0]
    yi = Q[seg][:,1]
    
    z = displacements[seg][:,Ts]

    triang = mtri.Triangulation(xi, yi, tri.simplices.copy())
    z_values = z

    interp_cubic_geom = mtri.CubicTriInterpolator(triang, z_values, kind='geom')
    xi = np.linspace(xi.min(), xi.max(), resolution)
    yi = np.linspace(yi.min(), yi.max(), resolution)
    xii, yii = np.meshgrid(xi, yi)
    zi_cubic_geom = interp_cubic_geom(xii, yii)

    z_min, z_max = z.min(), z.max()

    plt.figure(figsize=(8,8))
    plt.contourf(xii, yii, zi_cubic_geom)
    plt.show()