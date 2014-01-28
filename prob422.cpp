// Project Euler Problem: 422
// Goal: Find a point on the hyperbola that is parallel to two lines
// Author: Cooper Bell

#include <iostream>
#include <math>
using namespace std;

bool parallel(double  Pi-1[2], double Pi-2[2], double X[2])
{
  const double a = 7 / 12;
  const double c = 625 / 12;
  double m = (Pi-2[1] - X[1]) / (Pi-2[0] - X[0]);
  double b = Pi-1[1] - m*P-1[0];

  double x = ( -b*(2*m+a)+sqrt(b*b*(2*m+a)

}

int main()
{
  const X[2] = {1, 7};

  cout << H(4.0, 4.0) << endl;
  return 0;
}


