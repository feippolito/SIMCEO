#include "model.h"

void showarray(type_c* x, int size) {
  cout << "[ ";
  for (int k = 0; k < size; k++)
    cout << *(x + k) << " ";
  cout << "]" << endl;
}

int main(void) {

  type_i dimensions[3] = {4, 3, 4};

  type_c A[4][4] ={ {2,0,1,0}, {0,1,0,3} , {1,0,1,0}, {0,2,0,4} }; //  { {2,1}, {1,3} }
  type_c B[4][3] = { {0,0,0}, {0,0,0}, {3,1,4}, {3,1,1} };
  type_c C[4][4] = { {2,1,0,0}, {4,1,0,0}, {6,1,0,0}, {8,1,0,0} };
  type_c D[4][3] = { {4,5,1}, {6,7,1}, {8,1,1}, {1,1,1} };

  Driver driver;
  driver.Init(dimensions, *A, *B, *C, *D);
  driver.Start();

  driver.Info();

  cout << "Driver out of info..." << endl;

  type_c* output; 
  type_c* inputs;
  cout << "Created..." << endl; 
  inputs = (type_c*)malloc(3*sizeof(type_c));
  cout << "Input allocated..." << endl;
  output = (type_c*)malloc(4*sizeof(type_c));
  cout << "Output allocated..." << endl;

  cout << "Driver on update..." << endl;
  inputs[0] = 0.1; inputs[1] = 0.1;
  inputs[2] = 0.1; //inputs[3] = 0.3;
  driver.Update(inputs);
  output = driver.Output();
  cout << " => Output testing: iter (1)" <<endl;
  cout << "    |- result: "; showarray(output, 4);

  inputs[0] = 0.2; inputs[1] = 0.2;
  inputs[2] = 0.1; //inputs[3] = 0.1;
  driver.Update(inputs);
  output = driver.Output();
  cout << " => Output testing: iter (2)" <<endl;
  cout << "    |- result: "; showarray(output, 4);

  inputs[0] = 0.2; inputs[1] = 0.1;
  inputs[2] = 0.1; //inputs[3] = 0.1;
  driver.Update(inputs);
  output = driver.Output();
  cout << " => Output testing: iter (3)" <<endl;
  cout << "    |- result: "; showarray(output, 4);

  driver.Terminate();

  cout << "Finished!!" << endl;
}