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

def build_test():
  assert os.path.isdir("./lib")

def import_test():
  error = False
  try:
    from lib import driver
  except:
    error = True
  assert not error

def driver_init_test():
  error_log = False
  from lib import driver
  try:
    myDriver = driver.PyDriver()
    myDriver.cInit(dim_info, A_info, B_info, C_info, D_info)
  except:
    error_log = True
  assert not error_log

def driver_start_test():
  error_log = False
  from lib import driver
  myDriver = driver.PyDriver()
  myDriver.cInit(dim_info, A_info, B_info, C_info, D_info)
  try:
    myDriver.cStart()
  except:
    error_log = True
  assert not error_log

def driver_update_test():
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

def driver_output_test():
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
    results.append( myDriver.Output() )
    u_info = np.array([0.2, 0.1, 0.2, 0.2], dtype=np.float64)
    u_values = np.ndarray((4,), buffer=u_info, order='C', dtype=np.float64)
    myDriver.cUpdate(u_values)
    results.append( myDriver.Output() )
  except:
    error_log = True
  error_log = (not error_log) & (expected_results == results)
  assert error_log
