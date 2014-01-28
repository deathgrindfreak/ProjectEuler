# Project Euler Problem: 67
# Goal: find the maximum path sum of a triangle of numbers
# Author: Cooper Bell

import string

tri = open('prob67num.txt', 'r')
tri_nums = []

for row in tri:
	row.strip(string.punctuation + string.whitespace)
	tri_nums.append(row.split())

for j in tri_nums:
	j[:] = [int(i) for i in j]
	
def row_reduce(tris):
	new_row = []
	for i in range(len(tris[-2])):
		new_row.append( tris[-2][i] + max( tris[-1][i], tris[-1][i+1] ) )
	
	tris[-2] = new_row
	tris[:] = tris[:-1]
	
	return tris
	
for _ in xrange(len(tri_nums)-1):
	print row_reduce(tri_nums)