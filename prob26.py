# Project Euler Problem: 26
# Goal: fidn the unit fraction with the longest repeating cycle for d < 1000
# Author: Cooper Bell

from sieve_of_atkin import sieve_of_atkin

def ord_ten(num):
    k = 1
    count = 0
    while (10**k)%num != 1:
        k += 1
        count += 1
    return k

def term(num):
    while num % 2 == 0:
        num /= 2

    while num % 5 == 0:
        num /=5

    if num != 1:
        return True
    return False


lim = 1000  # for all denoms under 1000
primes = sieve_of_atkin(lim)
p_squares = [a**2 for a in primes]
max_k = 0

for i in range(2, 1000):

    if not term(i):
        print "%s\t%s\t%s" % (i, "n/a", 1.0/float(i))
    else:
        if i in primes:
            k = ord_ten(i)
            if k > max_k:
                max_k = k
                max_frac = i
            print "%s\t%s\t%s" % (i, k, 1.0/float(i))


print "Longest cycle: %s for %s." % (max_k, max_frac)
