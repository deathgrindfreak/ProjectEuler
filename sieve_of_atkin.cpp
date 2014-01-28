// Generates a list of primes using the "Sieve of Atkin."
// More on this algorithm can be found at:
// http://en.wikipedia.org/wiki/Sieve_of_Atkin

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> sieve_of_atkin(int lim)
{

        if (lim < 16) {      // Limit must be greater than 16

	  cout << "Limit is too small (must be greater than";
	  cout << " 16)." << endl;
	  cout << "Please enter a new limit: ";

	  cin >> lim;
	  sieve_of_atkin(lim);

        }

	bool is_Prime[lim + 1];
	const int root = sqrt(lim) + 1;
	int n;

	for(int i = 0; i != lim + 1; ++i){
	  is_Prime[i] = false;              // initialize boolean array
	}
	
	for(int x = 1; x != root; ++x){
	  for(int y = 1; y != root; ++y){

	    n = 4*x*x + y*y;
	    if( (n <= lim) && (n%12 == 1 || n%12 == 5) )
	      is_Prime[n] = !is_Prime[n];

	    n = 3*x*x + y*y;
	    if( (n <= lim) && (n%12 == 7) )
	      is_Prime[n] = !is_Prime[n];

	    n = 3*x*x - y*y;
	    if( (x > y) && (n <= lim) && (n%12 == 11) )
	      is_Prime[n] = !is_Prime[n];
	  }
	}

	for(int j = 5; j != root; ++j){    // eliminate squares of primes

	  if(is_Prime[j] == true){

	    for(int f = j*j; f <= lim; f += j*j){
	      is_Prime[f] = false;
	    }
	  }
	}

	vector<int> primes;   // initialize prime vector with 2, 3 and 5
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);

	for(int k = 7; k <= lim; k += 2){

	  if (is_Prime[k] == true) 
	      primes.push_back(k);
	  
	}

	return primes;
}
