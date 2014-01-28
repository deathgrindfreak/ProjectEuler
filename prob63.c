// Problem Euler Problem: 63
// Goal: find all n-digit positive doubleegers which are also an n-th power.
// Author: Cooper Bell

#include <stdio.h>
#include <math.h>

int num_digs(unsigned long long num) {
	int digs = 0;

	while (num != 0) {
		digs++;
		num = num / 10;
	}

	return digs;
}

int main() {
	int i,j;
	int count = 0;
	int max_base = 9;
	int max = 25;

	for (i=1; i <= max; ++i) {
		for (j=1; j <= max_base; ++j) {
			unsigned long long num = pow(j,i);
			int digs = num_digs(num);
			
			if (digs == i) {
				printf("digs: %d j: %d i: %d num: %llu\n", digs, j, i, num);
				count++;
			}
		}
	}

	printf("\ncount: %d\n", count);

	return 0;
}
