import os
import numpy as np

dim_info = np.array([2, 4, 5], dtype=np.int32)
A_info = np.array([[2.0, 3.3], [5.2, 4.1]], dtype=np.float64)
B_info = np.array([[1.1, 1.1, 2.1, 2.3], [5.2, 4.1, 5.2, 4.1]], dtype=np.float64)
C_info = np.array([[.0, .2], [.1, .1], [.2, .5], [.7, .1], [.3, .2]], dtype=np.float64)
D_info = np.array([[.0, .3, .0, .3], [.2, .1, .0, .3], [.1, .0, .0, .3],
  [.1, .0, .0, .7], [.1, .9, .0, .3]], dtype=np.float64)

res_1 = np.array([0.3720,0.2520,1.0620,0.6480,0.5700],dtype=np.float64)
res_2 = np.array([2.8736,2.3036,8.9176,7.5044,5.4740],dtype=np.float64)
expected_results = [res_1, res_2] 

def test_build():
  assert os.path.isdir("./lib")

def test_import():
  error = False
  try:
    from lib import driver
  except:
    error = True
  assert not error

def test_driver_init():
  error_log = False
  from lib import driver
  try:
    myDriver = driver.PyDriver()
    myDriver.cInit(dim_info, A_info, B_info, C_info, D_info)
  except:
    error_log = True
  assert not error_log

def test_driver_start():
  error_log = False
  from lib import driver
  myDriver = driver.PyDriver()
  myDriver.cInit(dim_info, A_info, B_info, C_info, D_info)
  try:
    myDriver.cStart()
  except:
    error_log = True
  assert not error_log

def test_driver_update():
  error_log = False
  from lib import driver
  myDriver = driver.PyDriver()
  myDriver.cInit(dim_info, A_info, B_info, C_info, D_info)
  myDriver.cStart()
  try:
    u_info = np.array([0.1, 0.1, 0.1, 0.1], dtype=np.float64)
    u_values = np.ndarray((4,), buffer=u_info, order='C', dtype=np.float64)
    myDriver.cUpdate(u_values)
  except:
    error_log = True
  assert not error_log

def test_driver_output():
  error_log = False
  from lib import driver
  myDriver = driver.PyDriver()
  myDriver.cInit(dim_info, A_info, B_info, C_info, D_info)
  myDriver.cStart()
  results = []
  try:
    u_info = np.array([0.1, 0.1, 0.1, 0.1], dtype=np.float64)
    u_values = np.ndarray((4,), buffer=u_info, order='C', dtype=np.float64)
    myDriver.cUpdate(u_values)
    res_diff = myDriver.cOutput() - expected_results[0]
    error_log = (np.abs(np.mean(res_diff)) < 10**-9 )
    u_info = np.array([0.2, 0.1, 0.2, 0.2], dtype=np.float64)
    u_values = np.ndarray((4,), buffer=u_info, order='C', dtype=np.float64)
    myDriver.cUpdate(u_values)
    myDriver.cOutput()
    res_diff = myDriver.cOutput() - expected_results[1]
    error_log = error_log & (np.abs(np.mean(res_diff)) < 10**-9 )
  except:
    error_log = False
  assert error_log
