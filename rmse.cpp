#include <iostream>
#include "math.h"
using namespace std;

// function to calculate RMSE
float f_rmse(float *x, float *y, int N) {
  float total = 0.0;
  for (int i = 0; i < N; i++) {
    total = total + pow(x[i]-y[i], 2);
  }
  return pow(total/(float)N, 0.5);
}

int main(int argc, char* argv[]) {
  // get command line arguments
  if (argc < 2) { 
    cout << "Usage: " << argv[0] << " [SIZE]" << endl;
    return 1;
  }
  int SIZE = atoi(argv[1]);
  cout << "Size of problem is " << SIZE << endl;

  // create vectors
  float *x = new float[SIZE];
  float *y = new float[SIZE];
  
  // init x and y
  for (int i = 0; i < SIZE; i++) {
    x[i] = (float)i;
    y[i] = x[i]*0.999;
  }
 
  // calculate RMSE
  float err = 0.0;
  err = f_rmse(x, y, SIZE); 

  // print RMSE value
  cout << "Calculated RMSE value is " << err << endl;

  return 0;
}
