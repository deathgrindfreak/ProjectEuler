#Project Euler: Problem 3
#Goal: Find the largest prime factor of 600851475143
#Author: Cooper Bell

lg_number = 600851475143
	
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
	
		
def list_of_primes(length):
	"""Generate a list of primes LENGTH long."""
	list = []
	for i in range(11,length):
		a = prime_test(i)
		if a == True:
			list.append(i)
		else:
			continue
	return list
	
def list_supremum(list):
	sup = list[0]
	for i in list:
		if i > sup:
			sup = i
		else:
			continue
	return sup
			

prime_list = list_of_primes(10000)  #Generated a large list of prime numbers to use as divisors.
list_of_divisors = []
lg_num = lg_number

for i in prime_list:
	if lg_num%i == 0:
		lg_num = lg_num/i
		list_of_divisors.append(i)
	else:
		continue

print "Largest prime factor of %s is %s." % (lg_number,list_supremum(list_of_divisors))

