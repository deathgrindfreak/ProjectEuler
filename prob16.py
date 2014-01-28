# Project Euler Problem: 16
# Goal: find the sum of the digits of 2^1000
# Author: Cooper Bell

num = 2**1000

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

print "The sum of the digits of 2^1000 is %s." % add_digits(num)