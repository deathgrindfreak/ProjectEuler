// Generates a list of primes using the "Sieve of Atkin."
// More on this algorithm can be found at:
// http://en.wikipedia.org/wiki/Sieve_of_Atkin

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void sieve_of_atkin(int lim, int primes[])
{

    if (lim < 16) { /* Limit must be greater than 16 */
        printf("Limit is too small (must be greater than 16)\n");
        
        exit 1;
    }


	bool is_Prime[lim + 1];             /* boolean array for sieve */
	const int root = sqrt(lim) + 1;     /* limit for quadratics */
    int i, x, y, n;                     /* iterative elements */

	for(i = 0; i < lim + 1; ++i) {      /* initialize boolean array */
	    is_Prime[i] = false;              
	}
	
	for(x = 1; x != root; ++x){         /* sieve */
	    for(y = 1; y != root; ++y){

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

    int j, f;
	for(j = 5; j != root; ++j)      /* eliminate squares of primes */
	    if(is_Prime[j] == true)
	        for(f = j*j; f <= lim; f += j*j)
	            is_Prime[f] = false;


	int primes[lim + 1] = {2, 3, 5};    /* initialize prime array with 2, 3 and 5 */

    int k;
	for(k = 7; k <= lim; k += 2)        /* fill array with primes */ 
	    if (is_Prime[k] == true) 
            primes[k] = k;
}
