# Project Euler Problem: 44
# Goal: find the minimum difference of two pentagonal numbers that is still a pentagonal number
# Author: Cooper Bell

import math

lim = 10000

pents = [n*(3*n-1)/2 for n in range(1,lim+1)]

