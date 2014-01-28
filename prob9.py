#Project Euler: Problem 9
#Goal: There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.
#Author: Cooper Bell

b = 1.0

while True:
	c = ((1000.0**2.0)/2.0 -1000.0*b + b**2.0)/(1000.0 - b) # simply eliminated a from a^2 + b^2 = c^2 and solved for c
	if c%1 == 0.0:
		break
	else:
		b += 1
		
print "a = %s, b = %s, c = %s and abc = %s." % (1000 - b - c, b, c, (1000 - b - c)*b*c)
