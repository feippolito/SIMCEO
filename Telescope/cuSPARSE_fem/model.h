#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION

#pragma once

#include <iostream>
using namespace std;

// Type definitions
typedef double type_c;
typedef int type_i;

// Sparse matrix
typedef struct {
  type_c* values;
  type_i* rowPtr;
  type_i* colInd;
  type_i nnz;
} CSRmatrix;

typedef struct {
  // Model matrices pointers
  CSRmatrix A; CSRmatrix B;
  CSRmatrix C; CSRmatrix D;
  // Dimension and support
  // variables
  type_i* nnz;
  type_i nx;  type_i nu;
  type_i ny; type_i* b_size;
} Model;

typedef struct {
  // x(k+1) and x(k)
  type_c* x_n; type_c* x;
  // inputs and outputs
  type_c* u; type_c* y;
  // Size variable
  type_i* b_size;
} State;

class Driver {

  public:
  /*
  ** MAIN ATTRIBUTES
  */
  Model hmodel;       // Host state space model
  State hstate;       // Host state variables
  Model dmodel;       // Device state space model
  State dstate;       // Device state variables
  type_c enable;      // Enable device support flag
  type_c disable;     // Disable device support flag

  /*
  ** MAIN METHODS
  */
  void Init(type_i*, type_c*, type_c*, type_c*, type_c*);
  void Start(void);
  void Update(type_c*);
  type_c* Output(void);
  void Terminate(void);
  /*
  **  SUPPORT METHODS
  */
  void Info(void);

  private:
  /*
  **  PRIVATE METHODS
  */
  void buildHostSparseModel(type_c*,type_c*,type_c*,type_c*);
  void buildDeviceSparseModel(void);
  void hdense2csr(type_c*, type_i);
  void ddense2csr();

  void driverCleanUp(void);
};
