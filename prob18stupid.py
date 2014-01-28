# Project Euler Problem: 18
# Goal: find the maximum path sum of a triangle of numbers
# Author: Cooper Bell

import string

tri = open('prob18num.txt', 'r')
tri_nums = []

for row in tri:
	row.strip(string.punctuation + string.whitespace)
	tri_nums.append(row.split())

for j in tri_nums:
	j[:] = [int(i) for i in j]
	
def max_list(tri_nums):
	maxx = []
	
	for rows in tri_nums:
		m = max(rows)
		max_index = []
		if rows.count(m) > 1:
			for i in range(len(rows)):
				if rows[i] == m:
					max_index.append(i)
			maxx.append( (m, max_index) )
		else:
			maxx.append( (m, rows.index(max(rows)) ) )
	return maxx
	
def max_path(max_tup, pos, tris):
	copy = max_tup
	path = [0]*len(tris)
	path[pos] = max_tup[0]
	
	for b in range(pos-1, -1, -1):
		if max_tup[1] == 0:
			m = tris[b][0]
			path[b] = m
			max_tup = (m, tris[b].index(m))
				
		elif max_tup[1] == len(tris[b]):
			m = tris[b][len(tris[b])-1]
			path[b] = m
			max_tup = (m, tris[b].index(m))
				
		else:
			m = max( tris[b][max_tup[1]-1], tris[b][max_tup[1]] )
			path[b] = m
			max_tup = (m, tris[b].index(m))
				
	for f in range(pos+1, len(tris)):
		m = max( tris[f][copy[1]], tris[f][copy[1]+1] )
		path[f] = m
		copy = (m, tris[f].index(m)) 
			
	return sum(path)

def total_list(tri_nums):
	tots = []
	for tri in tri_nums:
		for i in range(len(tri)):
			tots.append( ( (tri[i], i), tri_nums.index(tri)))
	return tots
			
max_paths = []
#v = max_list(tri_nums)
tot = total_list(tri_nums)
for maxx in tot:
	# if type(maxx[1]) is list:
		# for ind in maxx[1]:
			# tup = (maxx[0], ind)
			# max_paths.append(max_path(tup, v.index(maxx), tri_nums))
	
	#else:
		max_paths.append(max_path(maxx[0], maxx[1], tri_nums))

print max_paths, max(max_paths)
