
#include "model.h"

#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <cublas_v2.h>

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

// Macro to transform row-major arrays to 
// column major arrays - C++ def to CUDA def
#define IDX2C(i,j,ld) (((j)*(ld))+(i))

// Initialize the cuBLAS handle for further
// use.
cublasHandle_t handle;


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
  cout << "   |- A: "; showarray_device(this->hmodel.A, this->hmodel.nx * this->hmodel.nx);
  cout << "   |- B: "; showarray_device(this->hmodel.B, this->hmodel.nx * this->hmodel.nu);
  cout << "   |- C: "; showarray_device(this->hmodel.C, this->hmodel.ny * this->hmodel.nx);
  
  // Show the Device matrices
  type_c* A_host; type_c* B_host; type_c* C_host;
  A_host = (type_c*)malloc(this->hmodel.b_size[0]);
  B_host = (type_c*)malloc(this->hmodel.b_size[1]);
  C_host = (type_c*)malloc(this->hmodel.b_size[2]);
  cudaMemcpy(A_host, this->dmodel.A, this->hmodel.b_size[0], cudaMemcpyDeviceToHost);
  cudaMemcpy(B_host, this->dmodel.B, this->hmodel.b_size[1], cudaMemcpyDeviceToHost);
  cudaMemcpy(C_host, this->dmodel.C, this->hmodel.b_size[2], cudaMemcpyDeviceToHost);
  cout << " * Device matrices..." << endl;
  cout << "   |- A: "; showarray_device(A_host, this->hmodel.nx * this->hmodel.nx);
  cout << "   |- B: "; showarray_device(B_host, this->hmodel.nx * this->hmodel.nu);
  cout << "   |- C: "; showarray_device(C_host, this->hmodel.nx * this->hmodel.ny);
};


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

  // Set the host model dimensions
  this->hmodel.nx = dimensions[0];
  this->hmodel.nu = dimensions[1];
  this->hmodel.ny = dimensions[2];
  
  // Compute each matrix byte size
  this->hmodel.b_size = (type_i*)malloc(4*sizeof(type_i));
  this->hmodel.b_size[0] = this->hmodel.nx * this->hmodel.nx * sizeof(type_c);
  this->hmodel.b_size[1] = this->hmodel.nx * this->hmodel.nu * sizeof(type_c);
  this->hmodel.b_size[2] = this->hmodel.ny * this->hmodel.nx * sizeof(type_c);
  this->hmodel.b_size[3] = this->hmodel.ny * this->hmodel.nu * sizeof(type_c);

  // Allocate space for each model matrix
  this->hmodel.A = (type_c*)malloc(this->hmodel.b_size[0]);
  this->hmodel.B = (type_c*)malloc(this->hmodel.b_size[1]);
  this->hmodel.C = (type_c*)malloc(this->hmodel.b_size[2]);
  this->hmodel.D = (type_c*)malloc(this->hmodel.b_size[3]);
  
  // Attribute the values for each provided matrix in a
  // column major format, to be used in cuBLAS library
  for (int nx = 0; nx < this->hmodel.nx; nx++) {
    for (int nxi = 0; nxi < this->hmodel.nx; nxi++) 
      this->hmodel.A[IDX2C(nx,nxi,this->hmodel.nx)] = A_matrix[nx*this->hmodel.nx + nxi];
    for (int nu = 0; nu < this->hmodel.nu; nu++) 
      this->hmodel.B[IDX2C(nx,nu,this->hmodel.nx)] = B_matrix[nx*this->hmodel.nu + nu];
    for (int ny = 0; ny < this->hmodel.ny; ny++)
      this->hmodel.C[IDX2C(ny,nx,this->hmodel.ny)] = C_matrix[ny*this->hmodel.nx + nx];
  }
  
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
  for (int k = 0; k < this->hmodel.nx; k++) {
    this->hstate.x[k] = 0.0;
    this->hstate.x_n[k] = 0.0;
  }
  for (int k = 0; k < this->hmodel.nu; k++)
    this->hstate.u[k] = 0.0;
  for (int k = 0; k < this->hmodel.ny; k++)
    this->hstate.y[k] = 0.0;

  cout << "Driver initialized..." << endl;
};

void Driver::Start(void) {
  /*
  ** Start all the device variables and respective
  ** values. It uses the already defined host variables
  ** to set all devices modules.
  */

  // Define the device dimensions
  this->dmodel.nx = this->hmodel.nx;
  this->dmodel.nu = this->hmodel.nu;
  this->dmodel.ny = this->hmodel.ny;

  // Define the device sizes
  this->dmodel.b_size = this->hmodel.b_size;
  this->dstate.b_size = this->hstate.b_size;

  // Allocate cuda memory for the model matrices
  cudaMalloc(&this->dmodel.A, this->dmodel.b_size[0]);
  cudaMalloc(&this->dmodel.B, this->dmodel.b_size[1]);
  cudaMalloc(&this->dmodel.C, this->dmodel.b_size[2]);
  cudaMalloc(&this->dmodel.D, this->dmodel.b_size[3]);

  // Attribute the device model matrices values 
  cudaMemcpy(this->dmodel.A, this->hmodel.A, this->dmodel.b_size[0], cudaMemcpyHostToDevice);
  cudaMemcpy(this->dmodel.B, this->hmodel.B, this->dmodel.b_size[1], cudaMemcpyHostToDevice);
  cudaMemcpy(this->dmodel.C, this->hmodel.C, this->dmodel.b_size[2], cudaMemcpyHostToDevice);
  cudaMemcpy(this->dmodel.D, this->hmodel.D, this->dmodel.b_size[3], cudaMemcpyHostToDevice);

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

  // Starting the cuBLAS computation module
  cublasCreate(&handle);

  // Setting the enable and disable gains
  this->enable = 1.0; this->disable = 0.0;

  cout << "Driver started..." << endl;
};

type_c* Driver::Update(type_c* inputs) {
  /*
  **
  */

  cudaMemcpy(this->dstate.u, inputs, this->dstate.b_size[1], cudaMemcpyHostToDevice);

  // Compute: x(k+1) = (1 * A) * x(k) + 0 * x(k+1);
  //  |- Dimensions (m X n) * (n X k) = (m X k) => m, k, n
  //  |- Dimensions (nx X nx) * (nx X 1) = (nx X 1) => nx, 1, nx
  cublasDgemm(handle, CUBLAS_OP_N, CUBLAS_OP_N, 
    this->dmodel.nx, 1, this->dmodel.nx,
    &this->enable, this->dmodel.A, this->dmodel.nx, 
    this->dstate.x, this->dmodel.nx,
    &this->disable, this->dstate.x_n, this->dmodel.nx);
  
  // Compute: x(k+1) = (1 * B) * u(k) + 1 * x(k+1);
  //  |- Dimensions (m X n) * (n X k) = (m X k) => m, k, n
  //  |- Dimensions (nx X nu) * (nu X 1) = (nx X 1) => nx, 1, nu
  cublasDgemm(handle, CUBLAS_OP_N, CUBLAS_OP_N, 
    this->dmodel.nx, 1, this->dmodel.nu, 
    &this->enable, this->dmodel.B, this->dmodel.nx, 
    this->dstate.u, this->dmodel.nu,
    &this->enable, this->dstate.x_n, this->dmodel.nx);

  // Compute: x(k) = x(k+1)
  // Update the state variable...
  this->dstate.x = this->dstate.x_n;

  // Compute: y(k) = (1*C) * x(k) + 0 * y(k)
  //  |- Dimensions (m X n) * (n X k) = (m X k) => m, k, n
  //  |- Dimensions (ny X nx) * (nx X 1) = (ny X 1) => ny, 1, nx
  cublasDgemm(handle, CUBLAS_OP_N, CUBLAS_OP_N, 
    this->dmodel.ny, 1, this->dmodel.nx,
    &this->enable, this->dmodel.C, this->dmodel.ny, 
    this->dstate.x, this->dmodel.nx,
    &this->disable, this->dstate.y, this->dmodel.ny);


};

type_c* Driver::Output(void) {
  /*
  ** Computes the output state on GPU, copies the 
  ** the values from device to host and returns the 
  ** type_c pointer with the output values.
  */

  
  // Copy values from device to host
  cudaMemcpy(this->hstate.y, this->dstate.y, this->dstate.b_size[2], cudaMemcpyDeviceToHost);

  return this->hstate.y;
}
