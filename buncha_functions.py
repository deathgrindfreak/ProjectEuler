#Some functions that might be of use at a later point and time.
def primegen(limit):
	# Generates a list of primes less than LIMIT using the Sieve of Eratosthenes algorithm.
	numlist = [i for i in range(2, limit)]
	p = 2
	while True:
		sublist = [i*p for i in range(2, limit/p + 1)] # list of multiples of p that are less than LIMIT.
		for j in sublist:
			if numlist.count(j) != 0:
				numlist.remove(j)
		del sublist # re-initialize the integer multiple list.
		if p < numlist[-1]:
			p = numlist[numlist.index(p) + 1] # finds the next number greater than p.
		else:
			break
	return numlist

def prime_test(num):
	prime_test = 0
	
	for i in range(2,num):
		
		if num%i == 0:
			prime_test += 1
		else:
			continue
		
	if prime_test == 0:
		return True
	else:
		return False

def divides_by_2(num):
	"""Divides input number by 2 until it can no longer do so, then returns number."""
	while True:
		if (num%10)%2 == 0:
			num = num/2
		else:
			break
	return num

def digits(num):
	list = []
	while True:
		if num != 0:
			list.append(num%10)
			num = num/10
		else:
			break
	list.reverse()
	return list
	
def add_digits(num):
	list = digits(num)
	i_in = 0
	for i in list:
		i = i + i_in
		i_in = i
	return i
	
def divides_by_3(num):
	"""Divides input number by 3 until it can no longer do so, then returns number."""
	while True:
		a = add_digits(num) 
		if a%3 == 0:
			num = num/3
		else:
			break
	return num
	
def divides_by_5(num):
	while True:
		if num%10 == 0 or num%10 == 5:
			num = num/5
		else:
			break
	return num
			
def divides_by_7(num):
	while True:
		if (num/10 - 2*(num%10))%7 == 0:
			num = num/7
		else:
			break
	return num
	
def list_supremum(list):
	sup = list[0]
	for i in list:
		if i > sup:
			sup = i
		else:
			continue
	return sup