# Project Euler Problem: 20
# Goal: find the sum of the digits of 100!
# Author: Cooper Bell
from math import factorial

num = factorial(100)

def digits(num):
	list = []
	while True:
		if num != 0:
			list.append(num%10)
			num = num/10
		else:
			break
	list.reverse()
	return list
	
def add_digits(num):
	list = digits(num)
	i_in = 0
	for i in list:
		i = i + i_in
		i_in = i
	return i
	
print add_digits(num)