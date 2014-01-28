from math import sqrt
import random

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

def isprime(n):
   """Returns True if n is prime"""
   if n == 2: return True
   if n == 3: return True
   if n % 2 == 0: return False
   if n % 3 == 0: return False

   i = 5
   w = 2
   while i * i <= n:
      if n % i == 0:
         return False

      i += w
      w = 6 - w

   return True
	
def Miller_Rabin_primality(n, k=1000):
	"""Tests primality of n by implementing the Miller-Rabin primality test
	
	k determines its' accuracy
	
	"""
	if n == 2: return True
	if n == 3: return True
	if n % 2 == 0: return False
	if n % 3 == 0: return False
	
	s = 1
	while True:
		if (n-1)%2**s == 0:
			s += 1
		else:
			d = (n-1)/2**(s-1)
			break
	s -= 1
	
	witness_loop(n, d, k, s)
	
def witness_loop(n, d, k, s):	
	for _ in xrange(k):
		a = random.uniform(2, n-2)
		x = (a**d)%n
		
		if x == 1 or x == n - 1:
			witness_loop(n, d, k, s)
		
		for _ in xrange(s-1):
			x = (x**2)%n
			if x == 1:
				return False
			if x == n-1:
				witness_loop(n, d, k, s)
		return False
	return True
	
# print Miller_Rabin_primality(393217)
		