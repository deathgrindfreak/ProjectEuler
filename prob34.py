# Project Euler Problem: 30
# Goal: find the sum of all numbers that can be written as the sum of the factorials of their digits
# Author: Cooper Bell
from math import factorial

n = 5000000 # limit of numbers to try

def dig_list(num):
	num_list = []
	lim = num_length(num)
	for n in range(lim):
		num_list += [(num%(10**(n+1)) - num%(10**n))/(10**n)]
	num_list.reverse()
	return num_list
		
def num_length(num):
	length = 1
	while True:
		if num/(10**length) != 0:
			length += 1
		else:
			break	
	return length

def sum_fact(num):
	num_list = dig_list(num)
	facts = [factorial(i) for i in num_list]
	return sum(facts)
	
fact_list = []	
for i in range(3,n):
	if i == sum_fact(i):
		fact_list += [i]
		
print fact_list, sum(fact_list)