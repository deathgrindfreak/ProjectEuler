#Project Euler: Problem 10
#Goal: Find the sum of all primes less than 2 million
#Author: Cooper Bell
def add_digits(num):
	"""Sums the digits of NUM."""
	i_in = 0
	list = []
	while True:
		if num != 0:
			list.append(num%10)
			num = num/10
		else:
			break
	for i in list:
		i = i + i_in
		i_in = i
	return i

def prime_test(num):
	"""Tests if NUM is prime or not."""
	a = add_digits(num)
	if (num%10)%2 == 0:
		return False 
	elif a%3 == 0:
		return False
	elif num%10 == 0 or num%10 == 5:
		return False
	elif (num/10 - 2*(num%10))%7 == 0:
		return False
	elif (num%1000)%8 == 0:
		return False 
	else:
		for i in range(11,num):
			if num%i == 0:
				return False
				break
			else:
				continue
		else:
			return True
		
n = 13
prime_sum = 28	
lim = 2000000	
while True:
	if prime_test(n) == True:
		print n
		if n >= lim:
			print "The sum of all primes less than %s is %s." % (lim, prime_sum)
			break
		prime_sum = prime_sum + n
	n += 1
	
		
	

