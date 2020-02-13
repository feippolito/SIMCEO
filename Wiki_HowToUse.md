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


# Folder structure

```
SIMCEO/
│
├── calibration_dbs
├── doc
├── dos
│   ├── SimulationConfigurationDir
│   │   ├── dos.yaml
│   │   ├── driver1.yaml
│   │   ├── driver2.yaml
│   │   └── FEM.yaml
│   ├── SimulinkCompiledDrivers
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
├── NotebookSimulation.ipynb
├── simceo.py
└── setup.py
```

# Setup Simulation

**dos.yaml**

```yaml
simulation:
  sampling frequency: # [Hertz]
  duration: # [seconds]
  server:
    IP: # 127.0.0.1
drivers:
  device name:
    server: true
    delay: 0 # [sample]
    sampling rate: 1 # [sample]
    inputs:
      input name:
        size: 0
        lien: [device, device output name]
    outputs:
      output name:
        sampling rate: 1 # [sample]
        size: 0
        lien: [device, device input name]
```

# Run Simulation