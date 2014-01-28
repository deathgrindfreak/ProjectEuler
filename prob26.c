// Project Euler Problem: 26
// Goal: find the value for d < 1000 for which 1/d has the longest recurring cycle.
// Author: Cooper Bell

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <gmp.h>
#include "sieve_of_atkin.h"

// Function prototypes
bool term_test(int num);                        
bool is_prime(int num, int * primes, int size);
int ord_ten(int num);                          
mpz_t ipow(int base, int exp);
   
int main() {
    int lim = 1000;
    int * primes = sieve(lim);
    int size = size_of_sieve(primes);

    int i=17;
    //for (i=2; i < 100; i++) {
        //if (term_test(i)) {
            //if(is_prime(i, primes, size)) {
                int l = ord_ten(i);
                printf("%d\t%d\t%5.12f\n", i, l, 1.0/((double) i));
            //}
        //}
    //}

    return 0;
}

// Tests if a number is a terminating fraction.
bool term_test(int num) {
    while(num % 2 == 0) {
        num /= 2;
    }

    while(num % 5 == 0) {
        num /= 5;
    }

    if (num != 1)
        return true;    // Fraction doesn't terminate.
    return false;       // Fraction terminates
}

// Simple primality test using a list of primes.
bool is_prime(int num, int * primes, int size) {
    int i;
    for (i=0; i < size; i++) {
        if (num == primes[i])
            return true;
    }
    return false;
}

// Finds the order 10 of a prime (i.e. 10^k = 1 (mod p)).
int ord_ten(int num) {
    int k = 1;
    int count = 0;
    while ((ipow(10, k) % num) != 1) {
        printf("ord: %d\n",(ipow(10, k) % num));
        printf("pow: %d\n", ipow(10,k));
        k++;
        count++;
        if (count == 20)
            break;
    }
    return k;
}

// Exponentiation by squaring.
mpz_t ipow(int base, int exp) {
    mpz_t result = 1;
    while (exp) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}
