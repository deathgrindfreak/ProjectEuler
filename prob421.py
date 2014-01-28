#Project Euler Problem: 421
#Goal: find the sum of all s(n, 10^8) for all numbers of the from n**15 + 1
#Author: Cooper Bell

from sieve_of_atkin import sieve_of_atkin

lim = 100000
primes = sieve_of_atkin(lim)

def prime_factors(num):
	p_fac = []
	
	for i in primes:
		if num%i == 0:
			p_fac.append(i)
			num = num/i
			
	return p_fac
	
def s(n, m):
	p_fac = prime_factors(n**15 + 1)
	temp = []
	for i in p_fac:
		if i < m:
			temp.append(i)
			
	return sum(temp)

n = summ = 0	
while n <= 10**11:
	summ += s(n, 10**8)
	n += 1
	
print summ