#Project Euler: Problem 8
#Goal: Find the greatest product of five consecutive digits in the 1000-digit number.
#Author: Cooper Bell

num = open('prob8num.txt', 'r+')
num = num.read()
num = " ".join(num[i:i+1] for i in range(0, len(num)))

def num_to_list(num):
	"""Puts the digits of NUM into a list."""
	numlist = []
	num = num.split()
	for i in num:
		i = int(i)
		numlist.append(i)
	return numlist
	
def dig_prod(numlist):
	init = 0
	final = 5
	product = numlist[init]
	prodlist = []	
	while final <= len(numlist):
		for i in range(init+1,final):
			if i <= final:
				product = numlist[i]*product
			else:
				break
		prodlist.append(product)
		init += 1
		final += 1
		product = numlist[init]
	return prodlist
	
def list_supremum(numlist):
	sup = numlist[0]
	for i in numlist:
		if i > sup:
			sup = i
		else:
			continue
	return sup

a = num_to_list(num)
b = dig_prod(a)
print dig_prod(a)
print list_supremum(b)