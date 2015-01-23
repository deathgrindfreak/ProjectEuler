// Project Euler Problem: 92
// Goal: find the number of number chains under 10,000,000 that end with 89
// Author: Cooper Bell

#include <stdio.h>

// Prototypes
int sum_square_digs(int num);


int main() {
    int count = 0, limit = 10000000;

    int i;
    for (i=1; i < limit; i++) {

        int s = sum_square_digs(i);

        while ((s != 1) && (s != 89)) {
            s = sum_square_digs(s);
        }

        if (s == 89)
            count++;
    }

    printf("Number of chains ending with 89: %d", count);

    return 0;
}


// Returns the sum of the square of the digits of NUM.
int sum_square_digs(int num) {
    int sum = 0;
    while (num != 0) {
        sum += (num%10)*(num%10);
        num /= 10;
    }
    return sum;
}
