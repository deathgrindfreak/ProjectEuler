module ProjectEuler (sieveOfEratosthenes) where

sieveOfEratosthenes :: Int -> [Int]
sieveOfEratosthenes n = 2 : sieve intLst where
  intLst = [3, 5..n]
  sieve [] = []
  sieve (x:xs) = x : sieve (filter (\y -> mod y x /= 0) xs)
  
