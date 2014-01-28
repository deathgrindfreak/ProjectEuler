# Project Euler Problem: 14
# Goal: find the longest Collatz sequence for a starting number under one million
# Author: Cooper Bell

def collatz(n):
	# Generates the collatz sequence for the starting number of N.
	collatz_list = [n]
	while n > 1:
		if n%2 == 0:
			n = n/2
			collatz_list.append(n)
		else:
			n = 3*n + 1
			collatz_list.append(n)
	
	return collatz_list, len(collatz_list)
	
max = 1

for i in range(1, 999999):
	if collatz(i)[1] > max:
		max = collatz(i)[1]
		maxi = i
	else:
		continue
		
print "The starting number under one million with the longest collatz sequence is %s.\nIts length is %s terms and its sequence is %s." % (maxi, max, collatz(maxi)[0])