# Project Euler Problem: 53
# Goal: find the values of nCr for 1 <= n <= 100 that are greater than one-million
# Author: Cooper Bell

import math

lim = 1000000

def nCr(n,r):
	return math.factorial(n)/(math.factorial(r)*math.factorial(n-r))
	
count = 0
for n in range(1, 101):
	for r in range(1, 101):
		if n >= r and nCr(n, r) > lim:
			count += 1
			
print count