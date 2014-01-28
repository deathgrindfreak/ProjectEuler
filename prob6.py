#Project Euler: Problem 6
#Goal: Find the difference between the square of the sum and the sum of the square of the first hundred natural numbers.
#Author: Cooper Bell

def sum_of_squares(init,final):
	list = []
	for i in range(init,final+1):
		a = i*i
		list.append(a)
	summage = sum(list)
	return summage

def square_of_sum(init,final):
	summage = sum(range(init,final+1))
	summage = summage*summage
	return summage
	
a = sum_of_squares(1,100)
b = square_of_sum(1,100)
c = b - a
print c
		
