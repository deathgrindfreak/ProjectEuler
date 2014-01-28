# Project Euler Problem: 45
# Goal: find the number greater than 40755 that is a triangle, pentagonal and hexagonal number
# Author: Cooper Bell

lim = 100000

tris  = [n*(n+1)/2 for n in range(1, lim+1)]
pents = [n*(3*n-1)/2 for n in range(1, lim+1)]
hex   = [n*(2*n-1) for n in range(1, lim+1)]

intersection = set(tris)&set(pents)&set(hex)

print intersection