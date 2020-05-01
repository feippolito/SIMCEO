#include "model.hpp"

namespace drivers
{ 
  Driver::Driver() { }
  Driver::~Driver() { }
  
  void Driver::setValues(int* vals) {
    this->x0 = vals[0]; this->y0 = vals[1];
    this->x1 = vals[2]; this->y1 = vals[3];
  }

  int Driver::getLength() { return (x1 - x0); } 
  int Driver::getHeight() { return (y1 - y0); } 
  int Driver::getArea() { return (x1 - x0) * (y1 - y0); } 
  void Driver::move(int dx, int dy) { x0 += dx; y0 += dy; x1 += dx; y1 += dy; }

  /*
  **
  **  MAIN METHODS
  */
  void Driver::Init(int* dim, int* sizes, int* groups) {
    /*
    **
    */
    this->n_x = dim[0]; this->n_u = dim[1]; this->n_y = dim[2];
    this->inports = groups[0]; this->outports = groups[1];
    this->in_sizes = (int*)malloc(groups[0]*sizeof(int));
    this->out_sizes = (int*)malloc(groups[1]*sizeof(int));
    for (int k = 0; k < this->inports; k++)
      this->in_sizes[k] = sizes[k];
    for (int k = 0; k < this->outports; k++)
      this->out_sizes[k] = sizes[groups[0]+k];
    this->trafic_out = (double*)malloc(this->n_y*sizeof(double));
  }

  void Driver::Start(double* A_matrix, double* B_matrix, double* C_matrix, double* D_matrix) {
    /*
    **
    */
    
    this->A = A_matrix; this->B = B_matrix;
    this->C = C_matrix; this->D = D_matrix;

    this->setStateSpaceModel();
  }

  void Driver::Update(double* input) {
    /*
    **
    */
    for (int k = 0; k < this->n_u; k++)
      this->state.u(k) = *(input + k);
    this->state.x = this->model.A * this->state.x + this->model.B * this->state.u;
  }

  double* Driver::Output(void) {
    /*
    **
    */
    this->state.y = this->model.C * this->state.x;
    for (int k = 0; k < this->n_y; k++)
      trafic_out[k] = this->state.y(k);
    return trafic_out;
  }

  /*
  ** SET & GET METHODS
  */
  int* Driver::getSizes(void) {
    /*
    **
    */
    int ports = this->inports + this->outports;
    int* output = (int*)malloc(ports * sizeof(int));
    for (int k = 0; k < this->inports; k++)
      output[k] = this->in_sizes[k];
    for (int k = 0; k < this->outports; k++)
      output[k+this->inports] = this->out_sizes[k];
    return output;
  }

  double* Driver::getSSmodel(int item) {
    /*
    **
    */
    double* output = (double*)malloc(sizeof(double));
    switch (item)
    {
    case 0:
      output = this->A;
      break;
    case 1:
      output = this->B;
      break;
    case 2:
      output = this->C;
      break;
    case 3:
      output = this->D;
      break;
    default:
      break;
    }
    return output;
  }

  double* Driver::getStates(void) {
    /*
    **
    */
    double* states = (double*)malloc(this->n_x*sizeof(double));
    for (int k = 0; k < this->n_x; k++)
      states[k] = this->state.x(k);
    return states;
  }

  /*
  **  PRIVATE METHODS
  */
  void Driver::setStateSpaceModel(void) {
    /*
    **
    */
    this->model.A = MatrixXd::Zero(this->n_x,this->n_x);
    this->model.B = MatrixXd::Zero(this->n_x,this->n_u);
    this->model.C = MatrixXd::Zero(this->n_y,this->n_x);
    this->model.D = MatrixXd::Zero(this->n_y,this->n_u);

    this->state.x = VectorXd::Zero(this->n_x);
    this->state.u = VectorXd::Zero(this->n_u);
    this->state.y = VectorXd::Zero(this->n_y);

    // Assign the model variables
    for (int k = 0; k < this->n_x; k++) {
      for (int nx = 0; nx < this->n_x; nx++)
        this->model.A(k,nx) = *(this->A + (k * this->n_x) + nx);
      for (int nu = 0; nu < this->n_u; nu++)
        this->model.B(k,nu) = *(this->B + (k * this->n_u) + nu);
      for (int ny = 0; ny < this->n_y; ny++)
        this->model.C(ny,k) = *(this->C + (ny * this->n_x) + k);
    }
  }

}