# Project Euler Problem: 24
# Goal: Find the millionth lexicographic permutation of the digits 0-9
# Author: Cooper Bell
from itertools import permutations

n = 10 # Number of digits to permutate
digs = [x for x in range(n)]

perms = list(permutations(digs))
perms.sort()

print perms[999999]
