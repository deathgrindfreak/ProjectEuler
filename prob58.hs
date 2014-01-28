-- Project Euler Problem: 58
-- Goal: Find the side length in a number spiral where the ratio of primes on the diagonals falls below 10%
-- Author: Cooper Bell 


-- calculate diagonal numbers for side length k (k must be odd)

diags :: Integer -> [Integer]
diags k = [(k - 2) * (k - 1) + 1,
      	   (k - 1) * (k - 1) + 1,
	         k * (k - 1) + 1,
	   (k + 1) * (k - 1) + 1]

-- prime test

 

probCheck k
	| p / np <= 0.1 = 
	| 