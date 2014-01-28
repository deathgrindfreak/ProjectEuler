# Project Euler Problem: 13
# Goal: find the first ten digits of the sum of a list of one-hundred 50 digit numbers.
# Author: Cooper Bell

nums = open('50_digit_num.txt')
num_list = []

for num in nums:
	num = int(num.strip())
	num_list += [num]
	
summage = sum(num_list)

print summage, summage%(10**10)