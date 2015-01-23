// Sieve of Atkin: Generates a list of primes under a set limit.
// more info at: http://en.wikipedia.org/wiki/Sieve_of_Atkin

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int * sieve(int lim) {
	
	bool *is_prime = malloc(sizeof(bool)*(lim+1));
	int root = (int)sqrt(lim)+1;
	int i;

	for(i=0; i < lim+1; ++i) // set all numbers to false
		is_prime[i] = false;

	int x,y,n;

	for(x=1; x < root; ++x) { // Perform sieve
		for(y=1; y < root; ++y) {

			n = 4*x*x + y*y;
			if( (n <= lim) && (n % 12 == 1 || n % 12 == 5) )
				is_prime[n] = !is_prime[n];

			n = 3*x*x + y*y;
			if ( (n <= lim) && (n % 12 == 7) ) 
				is_prime[n] = !is_prime[n];
			n = 3*x*x - y*y;
			if ( (x > y) && (n <= lim) && (n % 12 == 11) )
				is_prime[n] = !is_prime[n];
		}
	}

	for(n=5; n < root; ++n) { // Set all multiples of primes
		if(is_prime[n]) { // equal to false

			int k;
			for(k=n*n; k < lim+1; k += n*n)
				is_prime[k] = false;
		}
	}

	// Create list of actual prime numbers
	int *primes = malloc(sizeof(int)*(lim+1)); 
	primes[0] = 2;
	primes[1] = 3;

	int j = 2;
	for(i=0; i < lim+1; ++i) {

		if(is_prime[i]) {
			primes[j] = i;
			++j;
		}
	}

	return primes;
}

// Returns the size of the prime array
int size_of_sieve(int * sieve) {
   int count = 0;
   int i = 0;
   while(sieve[i] != 0) {
       count++;
       i++;
   }
   return count;
}
