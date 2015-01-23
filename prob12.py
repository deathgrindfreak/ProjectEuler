#Project Euler: Problem 12
#Goal: Find the value of the first triangle number to have over five hundred factors
#Author: Cooper Bell
def tri_num(n):
	# Generates the Nth triangle number.
	x = 0
	for i in range(n+1):
		x = x + i
	return x
	
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

def num_divs(n, plist):
	# finds the number of divisors of N using the list of primes PLIST.
	pdivs = []
	O = []
	m = 1
	for i in plist:
		while n%i == 0:
			pdivs.append(i)
			n = n/i
		else:
			continue
	for k in range(len(pdivs)):
		if pdivs[k] != pdivs[k-1]:
			O.append(pdivs.count(pdivs[k]))
		else:
			continue
	numdivs = [j + 1 for j in O]
	for l in numdivs:
		m = l*m
	return m
		
plist = primegen(10000)
lim = 500
n = 2
while True:
	a = tri_num(n)
	b = num_divs(a, plist)
	print "triangle number: %s\nNumber of divisors: %s" % (a, b)
	if b > lim:
		print "%s has more than %s divisors!\nIn fact its exactly %s divisors." % (a, lim, b)
		break
	else:
		n += 1
		continue