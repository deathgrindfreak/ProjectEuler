from math import sqrt

def sieve_of_atkin(limit):
	# Generates a list of primes by employing the Sieve of Atkin
	
	isPrime = (limit + 1)*[False]
	root = int(sqrt(limit)) + 1
	
	for x in xrange(1, root):
		for y in xrange(1, root):
		
			n = 4*x**2 + y**2
			if (n <= limit) and (n%12 == 1 or n%12 == 5):
				isPrime[n] = not isPrime[n] 
			n = 3*x**2 + y**2
			if (n <= limit) and (n%12 == 7):
				isPrime[n] = not isPrime[n]
			n = 3*x**2 - y**2
			if (x > y) and (n <= limit)  and (n%12 == 11):
				isPrime[n] = not isPrime[n]
		
	for i in xrange(5, root):
		if isPrime[i]:
			for j in xrange(i**2 , limit, i**2):
				isPrime[j] = False
					
	primes = [2, 3, 5]		
			
	for i in xrange(7, limit, 2):
		if isPrime[i]:
			primes += [i]
				 
	return primes