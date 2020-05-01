#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION

#include <array>
#include <iostream>
using namespace std;

#include "Eigen/Dense"
using namespace Eigen;

typedef struct {
  MatrixXd A;
  MatrixXd B;
  MatrixXd C;
  MatrixXd D;
} SsModel;

typedef struct {
  VectorXd x;
  VectorXd u;
  VectorXd y;
} State;

namespace drivers
{ 
  class Driver
  { 
    public: 
    
    int x0, y0, x1, y1; 
    
    Driver(); 
    ~Driver();
    
    void setValues( int* );
    int getLength(); 
    int getHeight(); 
    int getArea(); 
    void move(int dx, int dy); 

    /*
    **  MAIN ATTRIBUTES
    */
    int n_x, n_u, n_y;               // State variable sizes
    int* in_sizes; int* out_sizes;   // The inport sizes
    int inports; int outports;       // The outport sizes
    double* A; double* B;              // The State Space 
    double* C; double* D;              // model matrices
    double* trafic_out;
    SsModel model; 
    State state;

    /*
    **  MAIN METHODS
    */
    void Init(int*, int*, int*);
    void Start(double*, double*, double*, double*);
    void Update(double*);
    double* Output(void);
    
    /*
    **  SET & GET METHODS
    */

    int* getSizes(void);
    double* getSSmodel(int);
    double* getStates(void);

    private:

    void setStateSpaceModel(void);
  }; 
}