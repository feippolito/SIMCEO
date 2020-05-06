# Instalation

## Local Machine

**Install dependencies**


 - Cuda 10.1
 - Python 3.7


```
sudo apt install libcurl4-openssl-dev
sudo apt install noweb
sudo apt install graphviz
sudo apt install cython
sudo apt install python3-sphinx
```

**Python dependencies**
```
pip install boto3
pip install scipy
pip install scikit-image
pip install numpydoc
pip install Cython
pip install cupy-cuda101
```

### CEO Installation
___
Download the latest version from github

```
git clone --single-branch --branch devel_cuda10.1_python3.7 https://github.com/rconan/CEO.git

cd CEO
make all
```
Be sure that **PYTHONPATH** and **CUDAPATH** in the **<span>commom.mk<span>** file point to the right respected installed directories.
```
make cython
```

Add the CEO/python/ directory to the python path.

In the .bashrc file export PYTHONPATH="${PYTHONPATH}:/home/user/CEO/python"

For anaconda it is possible to link site-packages directory to the CEO/python/ creating a file .pth that points to the ceo/python directory:

```bash
cd /home/anaconda3/lib/python3.7/site-packages/
touch my_paths.pth
```
Include the CEO/python directory path to my_paths.pth file:
#### **`my_paths.pth`**
```
/home/user/Documents/GMTO/CEO/python
```

To test if ceo library was successfully installed run the following code in python.

```python
import ceo
```
if no error messages are shown ceo was installed successfully!

**CEO Documentation**
```
cd CEO
mkdir python/docs/html
make pydoc
```

### SIMCEO Installation
___



..

..

..

# Folder structure

```
SIMCEO/
.
│
├── calibration_dbs
├── doc
├── dos
│   ├── control.py
│   ├── dos.py
│   ├── driver.py
│   ├── source.py
│   ├── tools.py
├── Telescope
│   ├── FEM.py
│   ├── __init__.py
│   ├── __pycache__
│   ├── windload_colored.py
│   └── windload_simulink.py
├── Simulation_config
│   ├── Simulation_01
│   │   ├── dos.yaml
│   │   ├── driver1.yaml
│   │   ├── driver2.yaml
│   │   └── FEM.yaml
├── Simulation_archive
|   ├── ArchivedNotebookSimulation.ipynb
├── drivers
│   ├── SimulinkCompiledDrivers
├── ActiveNotebookSimulation.ipynb
├── simceo.py
└── setup.py
```
- **. /** -  Notebook simulations (.ipynb) should run from the SIMCEO root folder.
- **Simulation_archives** -  Notebook simulations (.ipynb) when not active should be stored in this directory.
- **Calibration_dbs** - This folder is requeried for the wavefront sensor driver.
- **Simulation_config** - This directory contains the simulations configuration folders requeried for simceo.
  - **Simulation_01** - Each simulation must have it's own configuration directory. This folder can be named as desired and contains all the drivers (driver.yaml) and simulation (dos.yaml) configuration files.
- **Telescope** - Main driver folder - FEM and windowloads


# Setup Simulation

Every simulation condiguration must be containted insde a directory in SIMCEO/dos/. This directory can be named as desired and has to contain the **```dos.yaml```** file, this will define the simulation sampling frequency, conection between subsystems, desired subsystems logging, and other configurations.


**```dos.yaml```**
```yaml
simulation:
  sampling_frequency: # [Hertz]
  duration: # [seconds]
  server:
    IP: # 127.0.0.1
drivers:
  device_name:
    server: true
    delay: 0 # [sample]
    sampling_rate: 1 # [sample]
    inputs:
      input_name:
        size: 0
        lien: [device, device output name]
    outputs:
      output_name:
        sampling_rate: 1 # [sample]
        size: 0
        lien: [device, device input name]
        logs:
          decimation: 1 #[sample]
```

Some of the drivers specific configurations, such as **```M1.yaml```** and  **```FEM.yaml```** can be found below.

# Run Simulation

To start the server, first make sure you're inside the SIMCEO.
Once you're at the correct path, running the simceo.py will start the simceo server.
```bash
cd SIMCEO
python simceo.py
```
After running the previous commands the following message should appear:

```bash
*********************************
**   STARTING SIMCEO SERVER    **
*********************************
```

Once the server is running, you can start the python compiler, preferbilly a notebook and run the following commands.

```python
import dos
path = '.dos/SimulationConfigurationDir'
sim = dos.DOS(path, 20, show_timing = 2)
```
the path should point to the configuration directory you created. This should contain all the driver configuration files and the simulation configuration file - **```dos.yaml```**.

If no error messages appear a diagrame of the simulation will be created insde the configuration directory. 

To start the simulation run the following command:

```python
sim.start()
```

It is possible to know how far the simulation is while running with:
```python
sim.pctComplete
```

Once the simulation is finished run the following command to terminate all the drivers.
```python
sim.terminate()
```

All the logged variables can be accessed with 
```python
sim.logs.entries['\<Driver Name>']['\<Output Name>'].timeSeries
```

## SIMCEO specific drivers setups

---
### FEM

##### **```FEM.yaml```** 
```yaml
FEM:
  build:
    fem_io_filename: ../database/matmodels/old_consolidated/old_consolidated_rbm_FEM_IO_WSSBM.mat
    state_space_filename: ../database/matmodels/old_consolidated/old_consolidated_rbm_withSSBM.mat
    log_states: true
    
  reduction:
    start_idx: 3
```

**fem_io_filename**: path for the .mat file containing FEM Input/ Output table.

**state_space_filename**: path for the .mat file containg the state-space A,B,C and D matrices.

**log_states**: [boolean] - if true for each iteration all the FEM states will be saved inside /SIMCEO/variables/states.dat

**reduction**: ?
    
-  **start_idx**: ?

---
### wfs48

##### **```wfs48.yaml```** 
```yaml
source:
  photometric_band: R+I
  zenith:
    value: [8, 8, 8]
    units: arcmin
  azimuth:
    value: [0, 120, 240]
    units: degree
  magnitude: [0, 0, 0]
  fwhm: 3.16
  rays_box_size: 25.5
  rays_box_sampling: 769
  rays_origin: [0, 0, 25]
sensor:
  class: GeometricShackHartmann #ShackHartmann
  args: {N_SIDE_LENSLET: 48, N_PX_LENSLET: 16, d: 0.53125, DFT_osf: 2, N_PX_IMAGE: 24,
    BIN_IMAGE: 3, N_GS: 3, readOutNoiseRms: 0.0, noiseFactor: 1.4142, photoElectronGain: 0.63,
    exposureTime: 30, intensityThreshold: 0.0}
  calibrate_args: {threshold: 0.0}
```
The wavefront sensor driver estimates the telescope states (Translation, Rotation and Surfaces Displacements for each segment - M1 and M2), this is done with a pre-calibrated *D* matrix. If the matrix does not exists inside /SIMCEO/calibration_dbs/ CEO will run the calibration methode(?) with the configuration insde the wfs48 configuration file:

##### **```wfs48.yaml```**
```yaml
interaction matrices:
  calibrations:
    M12_RBM:
      method_id: AGWS_calibrate
      args:
        decoupled: true
        withM1: true
        withM2: true
        filterMirrorRotation: false
        stroke: [ 1e-06, 1e-06, 1e-06, 1e-06, 1e-06]
        fluxThreshold: 0.5
        includeBM: true
  pseudo_inverse:
    nThreshold: [ 2, 2, 2, 2, 2, 2, 0]
    insertZeros:
    - 
    - 
    - 
    - 
    - 
    - 
    - [ 2, 7]
  filename: CalibrationMatrixName
```

---
### Mirrors

##### **```M1.yaml```** 

##### **```M2.yaml```** 
```yaml
mirror: M1 # M1 or M1
mirror_args: { mirror_modes: bending modes, N_MODE: 27}

state:
  Txyz:
  Rxyz:
  modes:
```

**mirror_modes**: name of the .ceo file that contains the transformation matrices for the modes.

**N_MODE**: Number of modes used

**state**: Loads applied to the mirror during the simulation

 - **Txyz**: (3 x 7) array
 
 - **Rxyz**: (3 x 7) array
 
 - **modes**: (N_MODE x 7) array