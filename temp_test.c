#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "sieve.h"
#include "fermat.h"

main() {
    unsigned long long size = 5000000, numarr[size];
    unsigned long long len = sieve_of_atkin(size, numarr);
    
    //int i;
    //for (i = 2; i < 10; i++) {
    //    int n = numarr[i];
    //    printf("%d %s\n", n, mr_test(n, 7) ? "true " : "false");
    //}
    unsigned long long i;
    for (i = 0; i < len; i++)
        printf("%llu ", numarr[i]);
}
