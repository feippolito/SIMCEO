#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION

#include "model.h"

#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <cusparse.h>

/*
** Macros and support code before really 
** defining the main modules functionality.
*/

// Show the arrays in fashion manner
void showarray_device(type_c* x, int size) {
  cout << "[ ";
  for (int k = 0; k < size; k++)
    cout << *(x + k) << " ";
  cout << "]" << endl;
};

void showarray_device2(type_i* x, int size) {
  cout << "[ ";
  for (int k = 0; k < size; k++)
    cout << *(x + k) << " ";
  cout << "]" << endl;
};

// Macro to transform row-major arrays to 
// column major arrays - C++ def to CUDA def
#define IDX2C(i,j,ld) (((j)*(ld))+(i))

// Initialize the cuBLAS handle for further
// use.
cusparseHandle_t handle;
cusparseMatDescr_t descr;

// Support methods

void Driver::Info(void) {
  cout << "Driver informations" << endl;
  // Show the dimensions
  cout << " * Dimensions..." << endl;
  cout << "   |- nx: " << this->hmodel.nx << " and " << this->dmodel.nx << endl;
  cout << "   |- nu: " << this->hmodel.nu << " and " << this->dmodel.nu << endl;
  cout << "   |- ny: " << this->hmodel.ny << " and " << this->dmodel.ny << endl;

  // Show the Host matrices
  cout << " * Host matrices..." << endl;
  cout << "   |- A values: "; showarray_device(this->hmodel.A.values, this->hmodel.A.nnz);
  cout << "   |- A colInd: "; showarray_device2(this->hmodel.A.colInd, this->hmodel.A.nnz);
  cout << "   |- A rowPtr: "; showarray_device2(this->hmodel.A.rowPtr, this->hmodel.nx+1);
  cout << endl;
  
  cout << "   |- B values: "; showarray_device(this->hmodel.B.values, this->hmodel.B.nnz);
  cout << "   |- B colInd: "; showarray_device2(this->hmodel.B.colInd, this->hmodel.B.nnz);
  cout << "   |- B rowPtr: "; showarray_device2(this->hmodel.B.rowPtr, this->hmodel.nx+1);
  cout << endl;

  cout << "   |- C values: "; showarray_device(this->hmodel.C.values, this->hmodel.C.nnz);
  cout << "   |- C colInd: "; showarray_device2(this->hmodel.C.colInd, this->hmodel.C.nnz);
  cout << "   |- C rowPtr: "; showarray_device2(this->hmodel.C.rowPtr, this->hmodel.ny+1);
  cout << endl;

  // Show the Device matrices
  
  cout << " * Device matrices..." << endl;
  type_c* A_host_val; type_i* A_host_cInd; type_i* A_host_rPtr;
  A_host_val = (type_c*)malloc(this->hmodel.A.nnz*sizeof(type_c));
  A_host_cInd = (type_i*)malloc(this->hmodel.A.nnz*sizeof(type_i));
  A_host_rPtr = (type_i*)malloc((this->hmodel.nx+1)*sizeof(type_i));
  cudaMemcpy(A_host_val, this->dmodel.A.values, this->dmodel.A.nnz*sizeof(type_c), cudaMemcpyDeviceToHost);
  cudaMemcpy(A_host_cInd, this->dmodel.A.colInd, this->dmodel.A.nnz*sizeof(type_i), cudaMemcpyDeviceToHost);
  cudaMemcpy(A_host_rPtr, this->dmodel.A.rowPtr, (this->dmodel.nx+1)*sizeof(type_i), cudaMemcpyDeviceToHost);
  cout << "   |- A values: "; showarray_device(A_host_val, this->dmodel.A.nnz);
  cout << "   |- A colInd: "; showarray_device2(A_host_cInd, this->dmodel.A.nnz);
  cout << "   |- A rowPtr: "; showarray_device2(A_host_rPtr, this->dmodel.nx+1);
  cout << endl;
  
  type_c* B_host_val; type_i* B_host_cInd; type_i* B_host_rPtr;
  B_host_val = (type_c*)malloc(this->hmodel.B.nnz*sizeof(type_c));
  B_host_cInd = (type_i*)malloc(this->hmodel.B.nnz*sizeof(type_i));
  B_host_rPtr = (type_i*)malloc((this->hmodel.nx+1)*sizeof(type_i));
  cudaMemcpy(B_host_val, this->dmodel.B.values, this->dmodel.B.nnz*sizeof(type_c), cudaMemcpyDeviceToHost);
  cudaMemcpy(B_host_cInd, this->dmodel.B.colInd, this->dmodel.B.nnz*sizeof(type_i), cudaMemcpyDeviceToHost);
  cudaMemcpy(B_host_rPtr, this->dmodel.B.rowPtr, (this->dmodel.nx+1)*sizeof(type_i), cudaMemcpyDeviceToHost);
  cout << "   |- B values: "; showarray_device(B_host_val, this->dmodel.B.nnz);
  cout << "   |- B colInd: "; showarray_device2(B_host_cInd, this->dmodel.B.nnz);
  cout << "   |- B rowPtr: "; showarray_device2(B_host_rPtr, this->dmodel.nx+1);
  cout << endl;

  type_c* C_host_val; type_i* C_host_cInd; type_i* C_host_rPtr;
  C_host_cInd = (type_i*)malloc(this->hmodel.C.nnz*sizeof(type_i));
  C_host_rPtr = (type_i*)malloc((this->hmodel.ny+1)*sizeof(type_i));
  C_host_val = (type_c*)malloc(this->hmodel.C.nnz*sizeof(type_c));
  cudaMemcpy(C_host_val, this->dmodel.C.values, this->dmodel.C.nnz*sizeof(type_c), cudaMemcpyDeviceToHost);
  cudaMemcpy(C_host_cInd, this->dmodel.C.colInd, this->dmodel.C.nnz*sizeof(type_i), cudaMemcpyDeviceToHost);
  cudaMemcpy(C_host_rPtr, this->dmodel.C.rowPtr, (this->dmodel.ny+1)*sizeof(type_i), cudaMemcpyDeviceToHost);
  cout << "   |- C values: "; showarray_device(C_host_val, this->dmodel.C.nnz);
  cout << "   |- C colInd: "; showarray_device2(C_host_cInd, this->dmodel.C.nnz);
  cout << "   |- C rowPtr: "; showarray_device2(C_host_rPtr, this->dmodel.ny+1);
  cout << endl;
};


void Driver::buildHostSparseModel(type_c* A_matrix, type_c* B_matrix, 
    type_c* C_matrix, type_c* D_matrix) {
  
  // Build the host State Space model 
  this->hdense2csr(A_matrix, 0);     //
  this->hdense2csr(B_matrix, 1);     //
  this->hdense2csr(C_matrix, 2);     //
  this->hdense2csr(D_matrix, 3);     //

  // Build the host states as dense
  // Compute each state byte size
  this->hstate.b_size = (type_i*)malloc(3*sizeof(type_i));
  this->hstate.b_size[0] = this->hmodel.nx * sizeof(type_c);
  this->hstate.b_size[1] = this->hmodel.nu * sizeof(type_c);
  this->hstate.b_size[2] = this->hmodel.ny * sizeof(type_c);
  
  // Allocate space for each state
  this->hstate.x_n = (type_c*)malloc(this->hstate.b_size[0]);
  this->hstate.x = (type_c*)malloc(this->hstate.b_size[0]);
  this->hstate.u = (type_c*)malloc(this->hstate.b_size[1]);
  this->hstate.y = (type_c*)malloc(this->hstate.b_size[2]);

  // Attribute the values for each state
  for (int k = 0; k < this->hmodel.nu; k++)
    this->hstate.u[k] = 0.0;
  for (int k = 0; k < this->hmodel.ny; k++)
    this->hstate.y[k] = 0.0;
  for (int k = 0; k < this->hmodel.nx; k++) {
    this->hstate.x[k]   = 0.0;
    this->hstate.x_n[k] = 0.0;
  }
};

void Driver::hdense2csr(type_c* matrix, type_i type) {
  /*
  **
  */

  // ---- A matrix ----
  if ( type == 0 ) {
    // Count the non zero values 
    this->hmodel.A.nnz = 2 * this->hmodel.nx;
    // Allocate memory for the csr parameters
    this->hmodel.A.values = (type_c*)malloc(this->hmodel.A.nnz*sizeof(type_c));
    this->hmodel.A.rowPtr = (type_i*)malloc((this->hmodel.nx+1)*sizeof(type_i));
    this->hmodel.A.colInd = (type_i*)malloc(this->hmodel.A.nnz*sizeof(type_i));
    // Attribute the csr values
    int item_count = 0; int col_index = 0;
    for (int k = 0; k < this->hmodel.nx; k++) {
      // Get the start column index
      col_index = k;
      if (k >= this->hmodel.nx/2)
        col_index = col_index - this->hmodel.nx/2;
      // Define the row start pointer
      this->hmodel.A.rowPtr[k] = item_count;
      // Add the first value
      this->hmodel.A.values[item_count] = matrix[k*this->hmodel.nx+col_index];
      this->hmodel.A.colInd[item_count] = col_index;
      item_count += 1;
      // Add the second value
      col_index = col_index + this->hmodel.nx/2;
      this->hmodel.A.values[item_count] = matrix[k*this->hmodel.nx+col_index];
      this->hmodel.A.colInd[item_count] = col_index;
      item_count += 1;
    }
    this->hmodel.A.rowPtr[this->hmodel.nx] = this->hmodel.A.nnz;
  }

  // ---- B matrix ----
  if ( type == 1 ) {
    // Count the non zero values
    this->hmodel.B.nnz = this->hmodel.nx * this->hmodel.nu / 2;
    // Allocate memory for the csr parameters
    this->hmodel.B.values = (type_c*)malloc(this->hmodel.B.nnz*sizeof(type_c));
    this->hmodel.B.rowPtr = (type_i*)malloc((this->hmodel.nx+1)*sizeof(type_i));
    this->hmodel.B.colInd = (type_i*)malloc(this->hmodel.B.nnz*sizeof(type_i));
    // Attribute the csr values
    int item_count = 0; int col_index = 0;
    for (int k = 0; k < this->hmodel.nx; k++) {
      if ( k >= this->hmodel.nx/2 ) {
        // Define the pointer to where this 
        // row starts in the values
        this->hmodel.B.rowPtr[k] = item_count;
        // Include values on the csr matrix
        for (int j = 0; j < this->hmodel.nu; j++) {
          // Add the new value to the csr values
          // attribute and define the column id
          this->hmodel.B.values[item_count] = matrix[k*this->hmodel.nu+j];
          this->hmodel.B.colInd[item_count] = j;
          item_count += 1;
        }
      } else {
        this->hmodel.B.rowPtr[k] = 0;
      }
    }
    this->hmodel.B.rowPtr[this->hmodel.nx] = this->hmodel.B.nnz;
  }

  // ---- C matrix ----
  if ( type == 2 ) {
    // Count the non zero values
    this->hmodel.C.nnz = this->hmodel.ny * this->hmodel.nx / 2;
    // Allocate memory for the csr parameters
    this->hmodel.C.values = (type_c*)malloc(this->hmodel.C.nnz*sizeof(type_c));
    this->hmodel.C.rowPtr = (type_i*)malloc((this->hmodel.ny+1)*sizeof(type_i));
    this->hmodel.C.colInd = (type_i*)malloc(this->hmodel.C.nnz*sizeof(type_i));
    // Attribute the csr values
    int item_count = 0; int col_index = 0;
    for (int k = 0; k < this->hmodel.ny; k++) {
      // Define the initialization pointer 
      // for this row
      this->hmodel.C.rowPtr[k] = item_count;
      // Include values on the csr matrix
      for (int j = 0; j < this->hmodel.nx/2; j++) {
        // Add the new value to the csr values
        // attribute and define the column id
        this->hmodel.C.values[item_count] = matrix[k*this->hmodel.nx+j];
        this->hmodel.C.colInd[item_count] = j;
        item_count += 1;
      }
    }
    this->hmodel.C.rowPtr[this->hmodel.ny] = this->hmodel.C.nnz;
  }
};

void Driver::buildDeviceSparseModel(void) {
  /*
  **
  */

  // Build the device State Space model
  // --- A matrix ---
  this->dmodel.A.nnz = this->hmodel.A.nnz;
  // Allocate the device memory
  cudaMalloc(&this->dmodel.A.values, this->dmodel.A.nnz*sizeof(type_c));
  cudaMalloc(&this->dmodel.A.colInd, this->dmodel.A.nnz*sizeof(type_i));
  cudaMalloc(&this->dmodel.A.rowPtr, (this->dmodel.nx+1)*sizeof(type_i));
  // Copy csr attributes values to the device
  cudaMemcpy(this->dmodel.A.values, this->hmodel.A.values, 
    this->dmodel.A.nnz*sizeof(type_c), cudaMemcpyHostToDevice);
  cudaMemcpy(this->dmodel.A.colInd, this->hmodel.A.colInd, 
    this->dmodel.A.nnz*sizeof(type_i), cudaMemcpyHostToDevice);
  cudaMemcpy(this->dmodel.A.rowPtr, this->hmodel.A.rowPtr, 
    (this->dmodel.nx+1)*sizeof(type_i), cudaMemcpyHostToDevice);

  // --- B matrix ---
  this->dmodel.B.nnz = this->hmodel.B.nnz;
  // Allocate the device memory
  cudaMalloc(&this->dmodel.B.values, this->dmodel.B.nnz*sizeof(type_c));
  cudaMalloc(&this->dmodel.B.colInd, this->dmodel.B.nnz*sizeof(type_i));
  cudaMalloc(&this->dmodel.B.rowPtr, (this->dmodel.nx+1)*sizeof(type_i));
  // Copy csr attributes values to the device
  cudaMemcpy(this->dmodel.B.values, this->hmodel.B.values, 
    this->dmodel.B.nnz*sizeof(type_c), cudaMemcpyHostToDevice);
  cudaMemcpy(this->dmodel.B.colInd, this->hmodel.B.colInd, 
    this->dmodel.B.nnz*sizeof(type_i), cudaMemcpyHostToDevice);
  cudaMemcpy(this->dmodel.B.rowPtr, this->hmodel.B.rowPtr, 
    (this->dmodel.nx+1)*sizeof(type_i), cudaMemcpyHostToDevice);

  // --- C matrix ---
  this->dmodel.C.nnz = this->hmodel.C.nnz;
  // Allocate the device memory

  cudaMalloc(&this->dmodel.C.values, this->dmodel.C.nnz*sizeof(type_c));
  cudaMalloc(&this->dmodel.C.colInd, this->dmodel.C.nnz*sizeof(type_i));
  cudaMalloc(&this->dmodel.C.rowPtr, (this->dmodel.ny+1)*sizeof(type_i));
  // // Copy csr attributes values to the device
  cudaMemcpy(this->dmodel.C.values, this->hmodel.C.values, 
    this->dmodel.C.nnz*sizeof(type_c), cudaMemcpyHostToDevice);
  cudaMemcpy(this->dmodel.C.colInd, this->hmodel.C.colInd, 
    this->dmodel.C.nnz*sizeof(type_i), cudaMemcpyHostToDevice);
  cudaMemcpy(this->dmodel.C.rowPtr, this->hmodel.C.rowPtr, 
    (this->dmodel.ny+1)*sizeof(type_i), cudaMemcpyHostToDevice);

  // Build the device states as dense
  this->dstate.b_size = this->hstate.b_size;
  // Allocate cuda memory for the states
  cudaMalloc(&this->dstate.x_n, this->dstate.b_size[0]);
  cudaMalloc(&this->dstate.x, this->dstate.b_size[0]);
  cudaMalloc(&this->dstate.u, this->dstate.b_size[1]);
  cudaMalloc(&this->dstate.y, this->dstate.b_size[2]);

  // Attribute the device state values
  cudaMemcpy(this->dstate.x_n, this->hstate.x_n, this->dstate.b_size[0], cudaMemcpyHostToDevice);
  cudaMemcpy(this->dstate.x, this->hstate.x, this->dstate.b_size[0], cudaMemcpyHostToDevice);
  cudaMemcpy(this->dstate.u, this->hstate.u, this->dstate.b_size[1], cudaMemcpyHostToDevice);
  cudaMemcpy(this->dstate.y, this->hstate.y, this->dstate.b_size[2], cudaMemcpyHostToDevice);
}

void Driver::driverCleanUp(void) {
  /*
  **
  */

  // Clean the device/host model matrices
  // --- A matrix ---
  cudaFree(this->dmodel.A.values);
  cudaFree(this->dmodel.A.colInd);
  cudaFree(this->dmodel.A.rowPtr);
  free(this->hmodel.A.values);
  free(this->hmodel.A.colInd);
  free(this->hmodel.A.rowPtr);

  // --- B matrix ---
  cudaFree(this->dmodel.B.values);
  cudaFree(this->dmodel.B.colInd);
  cudaFree(this->dmodel.B.rowPtr);
  free(this->hmodel.B.values);
  free(this->hmodel.B.colInd);
  free(this->hmodel.B.rowPtr);

  // --- C matrix ---
  cudaFree(this->dmodel.C.values);
  cudaFree(this->dmodel.C.colInd);
  cudaFree(this->dmodel.C.rowPtr);
  free(this->hmodel.C.values);
  free(this->hmodel.C.colInd);
  free(this->hmodel.C.rowPtr);

  // Clean the device/host states
  cudaFree(this->dstate.x_n);
  free(this->hstate.x_n);
  cudaFree(this->dstate.x);
  free(this->hstate.x);
  cudaFree(this->dstate.u);
  free(this->hstate.u);
  cudaFree(this->dstate.y);
  free(this->hstate.y);

  cout << "All memory spaces freed..." << endl;
  cout << "Driver terminated." << endl;
}

// Main methods

void Driver::Init(int* dimensions, 
    type_c* A_matrix, type_c* B_matrix, 
    type_c* C_matrix, type_c* D_matrix ) {
  /*
  **  This is the initialization method of the cpp 
  ** fem library. It will define and initialize all
  ** host variables, such as model matrices and 
  ** simulation states.
  */

  // Set the host/device model dimensions
  this->hmodel.nx = dimensions[0];  this->dmodel.nx = dimensions[0];
  this->hmodel.nu = dimensions[1];  this->dmodel.nu = dimensions[1];
  this->hmodel.ny = dimensions[2];  this->dmodel.ny = dimensions[2];

  // Setup host simulation environment
  this->buildHostSparseModel(A_matrix, B_matrix, C_matrix, D_matrix);
  this->buildDeviceSparseModel();

  cout << "Driver initialized..." << endl;
};

void Driver::Start(void) {
  /*
  ** Start all the device variables and respective
  ** values. It uses the already defined host variables
  ** to set all devices modules.
  */
  
  // Starting the cuBLAS computation module
  cusparseCreate(&handle);
  cusparseCreateMatDescr(&descr);
  cusparseSetMatType(descr,CUSPARSE_MATRIX_TYPE_GENERAL);
  cusparseSetMatIndexBase(descr,CUSPARSE_INDEX_BASE_ZERO);

  // Setting the enable and disable gains
  this->enable = 1.0; this->disable = 0.0;

  cout << "Driver started..." << endl;
};

void Driver::Update(type_c* inputs) {
  /*
  **
  */

  cudaMemcpy(this->dstate.u, inputs, this->dstate.b_size[1], cudaMemcpyHostToDevice);

  // Compute: x(k+1) = (1 * A) * x(k) + 0 * x(k+1);
  //  |- Dimensions (m X n) * (n X k) = (m X k) => m, k, n
  //  |- Dimensions (nx X nx) * (nx X 1) = (nx X 1) => nx, 1, nx
  cusparseDcsrmv(handle,CUSPARSE_OPERATION_NON_TRANSPOSE, 
    this->dmodel.nx, this->dmodel.nx, this->dmodel.A.nnz,
    &this->enable, descr, 
    this->dmodel.A.values, this->dmodel.A.rowPtr, this->dmodel.A.colInd,
    this->dstate.x, 
    &this->disable, this->dstate.x_n);
  // cublasDgemm(handle, CUBLAS_OP_N, CUBLAS_OP_N, 
  //   this->dmodel.nx, 1, this->dmodel.nx,
  //   &this->enable, this->dmodel.A, this->dmodel.nx, 
  //   this->dstate.x, this->dmodel.nx,
  //   &this->disable, this->dstate.x_n, this->dmodel.nx);
  
  // Compute: x(k+1) = (1 * B) * u(k) + 1 * x(k+1);
  //  |- Dimensions (m X n) * (n X k) = (m X k) => m, k, n
  //  |- Dimensions (nx X nu) * (nu X 1) = (nx X 1) => nx, 1, nu
  cusparseDcsrmv(handle,CUSPARSE_OPERATION_NON_TRANSPOSE, 
    this->dmodel.nx, this->dmodel.nu, this->dmodel.B.nnz,
    &this->enable, descr, 
    this->dmodel.B.values, this->dmodel.B.rowPtr, this->dmodel.B.colInd,
    this->dstate.u, 
    &this->enable, this->dstate.x_n);
  // cublasDgemm(handle, CUBLAS_OP_N, CUBLAS_OP_N, 
  //   this->dmodel.nx, 1, this->dmodel.nu, 
  //   &this->enable, this->dmodel.B, this->dmodel.nx, 
  //   this->dstate.u, this->dmodel.nu,
  //   &this->enable, this->dstate.x_n, this->dmodel.nx);

  // Compute: x(k) = x(k+1)
  // Update the state variable...
  this->dstate.x = this->dstate.x_n;

  // Compute: y(k) = (1*C) * x(k) + 0 * y(k)
  //  |- Dimensions (m X n) * (n X k) = (m X k) => m, k, n
  //  |- Dimensions (ny X nx) * (nx X 1) = (ny X 1) => ny, 1, nx
  cusparseDcsrmv(handle,CUSPARSE_OPERATION_NON_TRANSPOSE, 
    this->dmodel.ny, this->dmodel.nx, this->dmodel.C.nnz,
    &this->enable, descr, 
    this->dmodel.C.values, this->dmodel.C.rowPtr, this->dmodel.C.colInd,
    this->dstate.x, 
    &this->disable, this->dstate.y);
  // cublasDgemm(handle, CUBLAS_OP_N, CUBLAS_OP_N, 
  //   this->dmodel.ny, 1, this->dmodel.nx,
  //   &this->enable, this->dmodel.C, this->dmodel.ny, 
  //   this->dstate.x, this->dmodel.nx,
  //   &this->disable, this->dstate.y, this->dmodel.ny);

};

type_c* Driver::Output(void) {
  /*
  ** Computes the output state on GPU, copies the 
  ** the values from device to host and returns the 
  ** type_c pointer with the output values.
  */

  // Copy values from device to host
  // cudaMemcpy(this->hstate.x_n, this->dstate.x_n, this->dstate.b_size[0], cudaMemcpyDeviceToHost);
  cudaMemcpy(this->hstate.y, this->dstate.y, this->dstate.b_size[2], cudaMemcpyDeviceToHost);

  return this->hstate.y;
}

void Driver::Terminate(void) {
  /*
  **
  */
  this->driverCleanUp();
}
