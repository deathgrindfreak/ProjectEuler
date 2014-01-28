/************************************************************************ 
 * Primality testing using the Miller-Rabin primality test.             *
 * More Info: https://en.wikipedia.org/wiki/Miller-Rabin_primality_test *
 *                                                                      *
 * INPUT: n > 3 is the number to test for primality                     *
 *        k is the number of times to test for primality (this is       *
 *        directly related to how accurate the test is)                 *
 *                                                                      *
 * OUTPUT: true if n is prime, false if n is composite                  *
 * **********************************************************************/

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

bool mr_test(int n, int k) {   
    srand(time(NULL));  /* seed for random number generation */
    
    if (n % 2 == 0)     /* n must be odd */
        return false;

    /* write n - 1 as d*2^s */
    int d = (n - 1), s = 0;
    while (d % 2 == 0) {
        ++s;
        d /= 2;
    }

    int i;
    for (i = 0; i < k; i++) {
        int a = (rand() % (n - 3)) + 2,     /* random number between [2, n-1] */
            x = ipow(a, d) % n;
        if (x != 1 && x != (n - 1)) {
            for (i = 0; i < s-1; i++) {
                x = (x * x) % n;
                if (x == 1)
                    return false;
                if (x == (n - 1))
                    break;
            }
        }
    }
    return true;
}

int ipow(int base, int exp) {
    int result = 1;
    while (exp) {
        if (exp & 1) /* bit hack even/odd test */
            result *= base;
        exp >>= 1;   /* bit hack divide by two (num is even) */
        base *= base;
    }
    return result;
}
