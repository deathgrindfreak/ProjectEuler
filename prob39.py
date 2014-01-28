# Project Euler Problem: 39
# Goal: find the perimeter p <= 1000 that has the most right triangle solutions
# Author: Cooper Bell

import math

def p_triples(lim):
	trips = []
	
	for i in range(1,lim):
		for j in range(1,lim):
			if i + j < lim:
				trips.append([i, j, math.sqrt(i**2 + j**2)])
				
	return trips
	
p_dict = dict()
for p in range(2, 1001):
	trips = p_triples(p)
	p_dict[p] = 0
	for k in trips:
		if sum(k) == float(p):
			p_dict[p] += 1
	
for k in p_dict:
	if p_dict[k] == max(p_dict.values()):
		print k		