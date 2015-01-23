// Project Euler Problem: 44
// Goal: Find the minimum difference of pentagonal numbers that is still pentagonal
// Author: Cooper Bell

#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;

double D(int n, int m)  // Calculates the index for the difference of two pents
{
  return (1+sqrt(1 + 12*(n-m)*(3*(n+m)-1)))/6;
}

double S(int n, int m)  // Calculates the index for the sum of two pents
{
  return (1+sqrt(1 + 12*(n*(3*n-1) + m*(3*m-1))))/6;
}

int main()
{
  cout.setf(ios_base::fixed, ios_base::floatfield);

  const int lim = 10000;     // Maximum index to try for pents
  double minimum = 100000.0; // Initialization to determine minimum difference

   for(int n=1; n<=lim; ++n){
     for(int m=1; m<=lim; ++m){

       if(n > m){
	 double k = D(n, m);
	 double l = S(n, m);

	 if(fmod(k,1) == 0.0 && fmod(l,1) == 0.0){  // Checks if integer

	   if(k < minimum){  // Checks if index is less than minimum
	     cout << k*(3*k-1)/2 << " k: " << k << " l: " << l; 
	     cout << " n: " << n << " m: " << m << endl;
	     minimum = k;
	   }
	 }
       }
     }
   }
   return 0;
}
