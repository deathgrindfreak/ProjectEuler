# Project Euler Problem: 56
# Goal: find the number of the form a^b for a, b < 100 that has maximum digital sum
# Author: Cooper Bell

def sum_digs(num):
	digs = [int(a) for a in str(num)]
	return sum(digs)
	
dig_sum_list = []
for a in range(1, 100):
	for b in range(1, 100):
		dig_sum_list.append(sum_digs(a**b))
		
print max(dig_sum_list)		