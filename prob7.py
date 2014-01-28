#Project Euler: Problem 7
#Goal: Find the 10001st prime number.
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
		
def nth_prime(n):
	"""Generate a list of primes LENGTH long."""
	prime_num = 2
	prime_num_test = 0
	while prime_num <= n:
		a = prime_test(prime_num)
		if a == True:
			prime_num_test += 1
		else:
			continue
		prime_num += 1
	return 
	
length = 2
final_val = 10001
while len(list_of_primes(length)) <= (final_val - 5):
	list_of_primes(length)
	length += 1

a = list_of_primes(length)
print a[-1]

