# Project Euler Problem: 52
# Goal: find the smallest number that can be seen as a permuation of 2x, 3x, 4x, 5x and 6x that number0
# Author: Cooper Bell

import itertools

lim = 1000000

def mult_check(num):
	temp = itertools.permutations(str(num))
	perm = [int(''.join(x)) for x in temp]
	mult = [n*num for n in range(2,7)]
	
	if set(mult) <= set(perm):
		return True
	return False
	
	
for n in range(lim):
	if mult_check(n):
		print n