# Project Euler Problem: 48
# Goal: find the last ten digits of the sum of i^i from 1 to 1000
# Author: Cooper Bell

sum = 0
for i in range(1,1000):
	b = i**i
	sum = sum + b
	
tendigits = sum%10000000000

print "The sum of i^i from 1 to 1000 is %s.\nIts last ten digits are %s." % (sum, tendigits)