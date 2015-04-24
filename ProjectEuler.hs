module ProjectEuler (sieveOfEratosthenes) where

sieveOfEratosthenes :: Int -> [Int]
sieveOfEratosthenes n = 2 : sieve [3, 5..n] where
  sieve [] = []
  sieve (x:xs) = x : sieve (filter (\y -> mod y x /= 0) xs)
  

-- millerRabin :: Int -> Int -> Bool
-- millerRabin n k
--   | n < 3     = n == 2
--   | otherwise = witnessLoop 0
--   where witnessLoop = undefined
        -- factorN m = factorLoop 0 (m - 1)
        -- factorLoop x y 
        --   | mod y 2 == 0 = factorLoop (x + 1) (y / 2)
        --   | otherwise    = (x, y)
        
millerRabin :: Int -> Int -> Bool
millerRabin n k
  | n < 3     = n == 2
  | otherwise = let factorN m = factorLoop 0 (m - 1)
                    factorLoop x y 
                      | mod y 2 == 0 = factorLoop (x + 1) (y / 2)
                      | otherwise    = (x, y)
                in witnessLoop 0
  where witnessLoop w = let (s, d) = factorN n
                      in if w < k then
                           let a = undefined
