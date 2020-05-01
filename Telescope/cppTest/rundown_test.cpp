#include "model.h"

void showarray(type_c* x, int size) {
  cout << "[ ";
  for (int k = 0; k < size; k++)
    cout << *(x + k) << " ";
  cout << "]" << endl;
}

int main(void) {

  type_i dimensions[3] = {2, 3, 4};

  type_c A[2][2] = { {2,2}, {1,3} };
  type_c B[2][3] = { {2,3,4}, {3,1,4} };
  type_c C[4][2] = { {2,3}, {4,5}, {6,7}, {8,9} };
  type_c D[3][2] = { {4,5}, {6,7}, {8,9} };

  Driver driver;
  driver.Init(dimensions, *A, *B, *C, *D);
  driver.Start();

  driver.Info();

  type_c* output; type_c* inputs;
  inputs = (type_c*)malloc(3*sizeof(type_c));
  output = (type_c*)malloc(4*sizeof(type_c));

  inputs[0] = 0.1; inputs[1] = 0.1; inputs[2] = 0.1;
  output = driver.Update(inputs);
  cout << " => Output testing: iter (1)" <<endl;
  cout << "    |- result: "; showarray(output, 4);

  inputs[0] = 0.2; inputs[1] = 0.2; inputs[2] = 0.1;
  output = driver.Update(inputs);
  cout << " => Output testing: iter (2)" <<endl;
  cout << "    |- result: "; showarray(output, 4);

  cout << "Finished!!" << endl;
}