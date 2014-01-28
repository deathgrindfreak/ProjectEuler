#Project Euler: Problem 12
#Goal: Find the value of the first triangle number to have over five hundred factors
#Author: Cooper Bell
import math

def tri_num(n):
	# Generates the Nth triangle number.
	x = 0
	for i in range(n+1):
		x = x + i
	return x

def primegen(limit):
	# Generates a list of primes less than LIMIT using the Sieve of Eratosthenes algorithm.
	numlist = [i for i in range(2, limit)]
	p = 2
	while True:
		sublist = [i*p for i in range(2, limit/p + 1)] # list of multiples of p that are less than LIMIT.
		for j in sublist:
			if numlist.count(j) != 0:
				numlist.remove(j)
		del sublist # re-initialize the integer multiple list.
		if p < numlist[-1]:
			p = numlist[numlist.index(p) + 1] # finds the next number greater than p.
		else:
			break
	return numlist
		

print primegen(10000)			