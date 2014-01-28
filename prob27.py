# Project Euler Problem: 28
# Goal: find a*b such that n^2 + a*n + b produces the most primes
# Author: Cooper Bell

import prime_funs

lim = 1000

primes = prime_funs.sieve_of_atkin(lim)	# produces all primes under n
negs = [-p for p in primes]
primes.extend(negs)
del negs
primes.sort()

quad = dict()
for a in range(-lim, lim+1):
	for b in primes:
		n, count = 0, 0
		while True:
			q = n**2 + a*n + b
			if q in primes:
				count += 1
				quad[(a, b, a*b)] = count
			else:
				break
			n += 1
			
maxx = max(quad.values())

for q in quad:
	if quad[q] == maxx:
		print q, maxx
