module ProjectEuler (sieveOfEratosthenes) where

sieveOfEratosthenes :: Int -> [Int]
sieveOfEratosthenes n = 2 : sieve [3, 5..n] where
  sieve [] = []
  sieve (x:xs) = x : sieve (filter (\y -> mod y x /= 0) xs)
  
