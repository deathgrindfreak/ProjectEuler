# Project Euler Problem: 57
# Goal: find all of the fractions that have numerators exceeding denominators in the expansion of sqrt(2)
# Author: Cooper Bell

import math
import fractions

lim = 1000

count = 0
start = fractions.Fraction(1 + 1/2)
for _ in xrange(lim):
	start = fractions.Fraction(1 + 1/(1 + start))
	#print start
	num, denom = start.numerator, start.denominator
	if len(str(num)) > len(str(denom)):
		count += 1
		
print count
