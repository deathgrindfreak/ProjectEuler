# Project Euler Problem: 37
# Goal: find the sum of all 11 left and right truncatable primes
# Author: Cooper Bell

import prime_funs

n = 1000000

primes = prime_funs.sieve_of_atkin(n)
primes[:] = [str(x) for x in primes]		# convert all primes to strings to facilitate slicing

def truncate(prime):
	trunc = []
	copy = prime
	
	trunc.append(prime)
	for _ in xrange(len(prime)):
		tr = prime[1:]
		tru = copy[:-1]
		if tr == '' or tru == '':
			break
			
		trunc.append(tr)
		trunc.append(tru)
		prime = tr
		copy = tru
		
	return trunc

prime_set = set(primes)
sum = 0
for prime in primes:
	rot = set(truncate(prime))
	if rot <= prime_set:
		sum += int(prime)
		
sum = sum - 2 - 3 - 5 - 7
print sum