FEM
  inputs:
    OSS_Harpoint_delta_F
      size: 42

# Description
#input OSS_Hardpoint_delta_F
#seg1 HP1: Force on cell, force on mirror
#seg1 HP1: ...
#...  ...
#seg1 HP6:
# **7 x 6 x 2 = 84 **
#Actual size is **42**

  outputs:
    OSS_M1_lcl
      size: 42

#output OSS_M1_lcl
# seg1: Txyz Rxyz seg2: Txyz Rxyz ...
# **7 x 3 x 2  = 42** 
# seg - x,y,z - R,T  

 M1:
    delay: 0
    sampling_rate: 1
    inputs:
      Txyz:
        size: [7, 3]
      Rxyz:
        size: [7, 3]
      modes:
        size: [7, 27]

  M2:
    delay: 0
    sampling_rate: 1
    inputs:
      Txyz:
        size: [7, 3]
      Rxyz:
        size: [7, 3]

