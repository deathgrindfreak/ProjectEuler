# Project Euler Problem: 21
# Goal: find the sum of all amicable numbers under 10000
# Author: Cooper Bell

limit = 28123 # Any number greater than this can be expressed as the sum of two abundant numbers

def sum_divisors(n):
	l = []
	for i in range(1,n):
		if n%i == 0:
			l += [i]
	return l, sum(l)
	
d = sum_divisors 

abundant = []
for i in range(2,limit + 1):
	if i < d(i)[1]:
		abundant += [i]
		
temp =[]
for j in abundant:
	for k in abundant:
		if (k + j) <= limit:
			temp += [k + j]

summage = 0
for l in range(1,limit + 1):
	if l not in temp:
		summage += l
		
print summage
