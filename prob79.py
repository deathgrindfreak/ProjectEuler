# Project Euler Problem: 79
# Goal: find the shortest possible key login for the successful key attemps
# Author: Cooper Bell

import string
import itertools

def split_num(num):
	n = []
	for i in str(num):
		n.append(i)
	return n

keylog = open('keylog.txt', 'r')

keys = []
for key in keylog:
	key = key.strip(string.punctuation + string.whitespace)
	keys.append(key)

num_digs = []	
for k in keys:
	digs = split_num(k)
	for d in digs:
		if d not in num_digs:
			num_digs.append(d)

for d in keys:
	j = split_num(d)
	