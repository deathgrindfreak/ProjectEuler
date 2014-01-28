# Project Euler Problem: 31
# Goal: How many ways can 2 pounds be written for the coins available in the british currency?
# Author: Cooper Bell

def h(a, b, c, d, e, f, g):
	return a + b*2 + c*5 + d*10 + e*20 + f*50 + g*100
	
