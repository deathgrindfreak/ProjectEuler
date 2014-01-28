# Project Euler Problem: 35
# Goal: find the number of circular primes under one-million
# Author: Cooper Bell

import prime_funs

n = 1000000

primes = prime_funs.sieve_of_atkin(n)
primes[:] = [str(x) for x in primes]		# convert all primes to strings to facilitate slicing

def rotate(prime):
	rotated = []
	
	for i in range(len(prime)):
		rot = prime[1:] + prime[0]
		rotated.append(rot)
		prime = rot
		
	return rotated
	
prime_set = set(primes)	
big_count = 0
for prime in primes:
	rot = set(rotate(prime))
	if rot <= prime_set:
		print prime
		big_count += 1

print big_count