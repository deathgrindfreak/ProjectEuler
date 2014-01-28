# Project Euler Problem: 36
# Goal: find the sum of all numbers less than one-million that are palindromic in both decimal and binary bases
# Author: Cooper Bell

n = 1000000 

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
	
def reverse_num(num):
	a = dig_list(num)
	a.reverse()
	return int(''.join(str(x) for x in a))

pals = []	
for num in xrange(1,n):
	bin_num = bin(num)[2:]
	if (num == reverse_num(num)) and (bin_num == bin_num[::-1]):
		pals += [num]
		
print sum(pals)		