# Project Euler Problem: 41
# Goal: find the largest known pandigital prime.
# Author: Cooper Bell

import itertools
import prime_funs
 
digs = ['1', '2', '3', '4', '5', '6', '7']
prime_pans = []

nums = itertools.permutations(digs)
num = [int(''.join(i)) for i in nums]
		
for n in num:
	if prime_funs.isprime(n) == True:
		prime_pans.append(n)

if prime_pans != []:		
	print max(prime_pans)