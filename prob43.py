# Project Euler Problem: 43
# Goal: find all 0-9 pandigital numbers that are completely sub-string divisible
# Author: Cooper Bell

import itertools

pans = itertools.permutations('0123456789')
pandigitals = [''.join(a) for a in pans]

def sub_string_divis(num):
	div_list = [2,3,5,7,11,13,17]
	count = 0
	for i in range(1,8):
		if int(num[i:i+3])%div_list[i-1] == 0:
			count += 1
			
	if count == 7:
		return True
	
	return False
	
panlist = []
for pan in pandigitals:
	if sub_string_divis(pan):
		panlist.append(pan)
		
panlist[:] = [int(x) for x in panlist]
print panlist, sum(panlist)