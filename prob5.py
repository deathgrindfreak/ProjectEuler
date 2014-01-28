#Project Euler: Problem 5
#Goal: Find the smallest number that is divisible by all numbers 1-20
#Author: Cooper Bell

def div_check(num):
	div_count = 0
	for i in range(2,20):
		if num%i == 0:
			div_count += 1
		else:
			continue
			
	if div_count == 18:
		return True
	else:
		return False
		
list = []
init = 1
final = 10000
while True:
	for i in range(init,final):
		check = div_check(i)
		if check == True:
			list.append(i)
		else:
			continue
	if list == []:
		init += 10000
		final += 10000
	else:
		break
		
print list


