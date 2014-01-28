# Project Euler Problem: 30
# Goal: find the sum of all numbers that can be written as the sum of fifth powers of their digits
# Author: Cooper Bell

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

def sum_fifths(num):
	num_list = dig_list(num)
	fifths = [i**5 for i in num_list]
	return sum(fifths)

fifths = []	
for num in xrange(2,n):
	t = sum_fifths(num)
	if num == t:
		fifths += [t]
	else:
		continue
		
print fifths, sum(fifths)