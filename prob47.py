# Project Euler Problem: 47
# Goal: find the first four consecutive integers to have four distinct prime factors
# Author: Cooper Bell

from math import sqrt
from sieve_of_atkin import *

n = 1000000
primes = sieve_of_atkin(n)

def prime_factorization(num, prime_list):
	factors = []
	
	for prime in prime_list:
		if num%prime == 0 and (prime not in factors):
			factors += [prime]
			
	return factors
	
quad_factor_ints = []

for i in range(n):

	factors = prime_factorization(i, primes)
	
	if len(factors) == 4:
		quad_factor_ints += [i] 
		
quad_factor_ints.sort()
		
for j in range(len(quad_factor_ints) - 3):

	if (quad_factor_ints[j] == quad_factor_ints[j+1] - 1) and (quad_factor_ints[j+1] == quad_factor_ints[j+2] - 1) and (quad_factor_ints[j+2] == quad_factor_ints[j+3] - 1):
	
		print quad_factor_ints[j], quad_factor_ints[j+1], quad_factor_ints[j+2], quad_factor_ints[j+3]
		print prime_factorization(quad_factor_ints[j], primes), prime_factorization(quad_factor_ints[j+1], primes), prime_factorization(quad_factor_ints[j+2], primes), prime_factorization(quad_factor_ints[j+3], primes)
	
