# Project Euler Problem: 21
# Goal: find all distinct a^b such that 2<=a<=100 and 2<=b<=100
# Author: Cooper Bell

lim = 100
terms = []

for a in xrange(2,lim+1):
	for b in xrange(2,lim+1):
		if a**b in terms:
			continue
		else:
			terms += [a**b]
		
terms.sort()

print len(terms)