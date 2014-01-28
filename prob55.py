# Project Euler Problem: 55
# Goal: find the number of Lychrel numbers below ten-thousand
# Author: Cooper Bell

lim = 10000
iter = 50

def flip_add(num):
	return num + int(str(num)[::-1])
	
def palindrome(num):
	if num == int(str(num)[::-1]):
		return True
	return False
	
count = 0
for num in range(lim):
	for _ in xrange(iter):
		if palindrome(flip_add(num)):
			count += 1
			break
		else:
			num = flip_add(num)
			
print 10000 - count