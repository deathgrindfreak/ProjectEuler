# Project Euler Problem: 49
# Goal: find another four digit sequence of numbers that are both prime and permutations of one another
# Author: Cooper Bell
from math import sqrt, fabs
from itertools import permutations
from sieve_of_atkin import *

temp = sieve_of_atkin(10000)
primes = []

for prime in temp:							# generates list of all four-digit primes
	if prime > 1000:
		primes += [prime]
		
def prime_permutations(prime, prime_list):
	permlist = list(permutations(str(prime)))
	iterations = []
	
	for i in permlist:
		b = int(''.join(i))
		if (b in prime_list) and (b not in iterations):
			iterations += [b]
	
	iterations.sort()
	
	return iterations
	
def arithmetic_test(perm_list):
	diff_list = []
	
	for i in xrange(len(perm_list)):
		for j in range(len(perm_list)):
			for k in range(len(perm_list)):
				if (i <= len(perm_list) - 1) and (j <= len(perm_list) - 1) and (k <= len(perm_list) - 1):
					if (i != j) and (i != k) and (j != k):
			
						uno = int(fabs((perm_list[j] - perm_list[i]))) 
						dos = int(fabs((perm_list[k] - perm_list[i])))
					
						if (uno == dos) and (uno != 0):
							final = [perm_list[i], perm_list[j], perm_list[k]]
							final.sort()
							return final
			
	return None
	
prime_perms = []

for p in primes:
	perms = prime_permutations(p, primes)
	
	if len(perms) < 3:
		continue
	else:
		prime_perms += [perms]
	
for perm in prime_perms:
	test = arithmetic_test(perm)
	
	if test == None:
		continue
	else:
		print test