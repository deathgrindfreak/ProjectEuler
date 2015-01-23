// Project Euler Problem: 58
// Goal: find the side length where the ratio of spiral numbers to spiral primes is less than 10%
// Author: Cooper Bell

#include <stdio.h>
#include <stdbool.h>
#include "sieve_of_atkin.h"

int TR (int k) {
    return (k - 2)*(k - 1) + 1;
}

int TL (int k) {
    return (k - 1)*(k - 1) + 1;
}

int LL (int k) {
    return k*(k - 1) + 1;
}

bool is_prime(int num, int * primes, int size) {
    int i;
    for (i=0; i < size; i++) {
        if (num == primes[i])
            return true;
    }
    return false;
}

int main()
{
    int limit = 100006000;
    int * primes = sieve(limit);
    int size = size_of_sieve(primes);

    int count = 0;
    int k = 5;  // Initial side length.
    double spiral_prime = 3.0, spiral_num = 5.0;    // Three spiral nums are prime at k = 3.
    while (spiral_prime/spiral_num > .1) {
        int ll = LL(k), tl = TL(k), tr = TR(k);
        if (is_prime(ll, primes, size))
            spiral_prime += 1.0;
        if (is_prime(tl, primes, size))
            spiral_prime += 1.0;
        if (is_prime(tr, primes, size))
            spiral_prime += 1.0;

        spiral_num += 4.0;

        if (count % 10 == 0)
            printf("k = %d, p# = %f, sp# = %f, ratio = %f\n", k, spiral_prime, spiral_num, spiral_prime/spiral_num);               
        k += 2;
        count++;
    }
    printf("primes/spirals = %f for k = %d", spiral_prime/spiral_num, k-2);

    return 0;
}
