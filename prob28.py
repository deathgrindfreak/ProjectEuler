# Project Euler Problem: 28
# Goal: find the sum of the numbers on the diagonals of a 1001 by 1001 number spiral
# Author: Cooper Bell

n = 1001

spiral = [1]
for i in range(3,n+2,2):
	j = i - 1
	spiral.append(i**2)
	for k in xrange(1,4):
		x = i**2 - j*k
		spiral.append(x)
	
spiral.sort()	
print spiral, sum(spiral)
