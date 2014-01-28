# Project Euler Problem: 32
# Goal: find the sum of all products whose multiplicand/multiplier
# and product identity can be written as 1-9 pandigital
# Author: Cooper Bell

import itertools

pans = itertools.permutations('123456789')
perms = []

for i in pans:
    perms.append(''.join(i))

count = 0
mults = []

# two X three products
for perm in perms:
    if (int(perm[0:2]) * int(perm[2:5]) == int(perm[5:9])) and (int(perm[5:9]) not in mults):
        count += 1
        mults.append(int(perm[5:9]))
        print perm[0:2], perm[2:5], perm[5:9]

# one X four products
for perm in perms:
    if (int(perm[0:1]) * int(perm[1:5]) == int(perm[5:9])) and (int(perm[5:9]) not in mults):
        count += 1
        mults.append(int(perm[5:9]))
        print perm[0:1], perm[1:5], perm[5:9]

print count, sum(mults)
