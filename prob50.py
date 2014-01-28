# Project Euler Problem: 50
# Goal: find the sum of consecutive primes below one-million
# Author: Cooper Bell
from math import sqrt
from sieve_of_atkin import *

n = 100000
		
def p_sum_test(start, plist):
	clist = []
	psum, count, pmax, maxcount = plist[start], 1, 0, 0
	
	for i in xrange(start+1, len(plist)):
		psum += plist[i]
		count += 1
		if psum > n:
			break
		if psum in plist:
			pmax, maxcount = psum, count
			
	return (maxcount, pmax)
	
plist = sieve_of_atkin(n)
maxi = []

for start in xrange(0, len(plist)-1):
	maxi += [p_sum_test(start, plist)]
		
maxi.sort(reverse = True)

print maxi[0][1]