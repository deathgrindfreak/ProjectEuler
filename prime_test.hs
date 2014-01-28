-- Tests the primality of an integer based on the
-- ______ algorithm.  More on this algorithm at:
-- ______

isPrime :: Integer -> Bool
isPrime num
	| num <= 3 = error "Number must be GT 3"
	| even num = False
	|