# Project Euler Problem: 38
# Goal: Find the largest 1-9 pandigital number formed by the product of an integer and (1,2, ... ,n) for n>1
# Author: Cooper Bell

import itertools

def mult_cat(num, num_list):
	mult, pan = [], ''
	for n in num_list:
		mult.append(n*num)
	
	for m in mult:
		pan += str(m)
		
	return pan
	
def n_dig_list(n):
	"""Produces all numbers n and n-1 digits in length
	"""
	assert n > 0
	start, finish = int(n*'1'), int(n*'9')
	return [x for x in range(start, finish+1)]

pans = itertools.permutations('123456789')
pandigitals = [''.join(a) for a in pans]

num_list = [1]
for n in range(2, 10):
	num_list.append(n)
	dlist = n_dig_list(k)
	for d in dlist:
		if mult_cat(d, num_list) in pandigitals:
			print d, num_list, mult_cat(d, num_list)