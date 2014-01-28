#Project Euler: Problem 11
#Goal: Find the largest product of any consecutive four numbers in a grid.
#Author: Cooper Bell
x = open('grid.txt', 'r+').read().split('\n')
sup = 0 # initializes largest number at 0

for i in range(0, len(x)):	# turns grid of text into an actual grid
	x[i] = x[i].split(' ')
	for j in x[i]:
		x[i][x[i].index(j)] = int(j)

for i in range(0, 20):	# multiplies every element sidways, down and diagonally.
	for j in range(0, 20):
		mult_list = []
		if i <= 16 and j <= 16:
			mult_list.append(x[i][j]*x[i+1][j+1]*x[i+2][j+2]*x[i+3][j+3])
		if i <= 16 and j >= 3:
			mult_list.append(x[i][j]*x[i+1][j-1]*x[i+2][j-2]*x[i+3][j-3])
		if j <= 16:
			mult_list.append(x[i][j]*x[i][j+1]*x[i][j+2]*x[i][j+3])
		if i <= 16:
			mult_list.append(x[i][j]*x[i+1][j]*x[i+2][j]*x[i+3][j])
		for l in mult_list:
			if l > sup:
				sup = l
			else:
				continue
		
print "Largest is %s." % sup
