/**********************************************************
 *                                                        *
 * Generates a list of primes using the "Sieve of Atkin." *
 * and returns the length of the list containing the      *
 * primes.                                                *
 *                                                        *
 * More on this algorithm can be found at:                *
 * http://en.wikipedia.org/wiki/Sieve_of_Atkin            *
 *                                                        *
 * Note that the size of 'primes' must be that of 'lim'!  *
 *                                                        *
 **********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

unsigned long long sieve_of_atkin(unsigned long long lim, 
                                  unsigned long long primes[]) {

    if (lim < 16) { /* Limit must be greater than 16 */
        printf("Limit is too small (must be greater than 16)\n");
        exit(1);
    }


	bool is_Prime[lim + 1];                         /* boolean array for sieve */
	const unsigned long long root = sqrt(lim) + 1;  /* limit for quadratics */
    unsigned long long i, j, x, y, n;               /* iterative elements */

	for (i = 0; i < lim + 1; ++i) {     /* initialize boolean array */
	    is_Prime[i] = false;              
	}
	
	for (x = 1; x < root; ++x) {        /* sieve */
	    for (y = 1; y < root; ++y) {

	        n = 4*x*x + y*y;
	        if ( (n < lim+1) && ((n % 12 == 1) || (n % 12 == 5)) )
	            is_Prime[n] = !is_Prime[n];

	        n = 3*x*x + y*y;
	        if ( (n < lim+1) && (n % 12 == 7) )
	            is_Prime[n] = !is_Prime[n];

	        n = 3*x*x - y*y;
	        if ( (x > y) && (n < lim+1) && (n % 12 == 11) )
	            is_Prime[n] = !is_Prime[n];
	    }
	}

	for (i = 5; i < root; ++i)          /* eliminate squares of primes */
	    if (is_Prime[i] == true)
	        for (j = i*i; j < lim+1; j += i*i)
	            is_Prime[j] = false;


	/* initialize prime array with 2, 3 and 5 */
    primes[0] = 2;
    primes[1] = 3;
    primes[2] = 5;

    unsigned long long k = 3;
	for(i = 7; i <= lim; i += 2) {  /* fill array with primes */ 
	    if (is_Prime[i] == true) 
            primes[k++] = i;
    }
    primes[k] = '\0'; /* end of array */

    return k;
}
