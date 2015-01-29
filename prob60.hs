import ProjectEuler (sieveOfEratosthenes)

numDigs :: Int -> Int
numDigs 0 = 0
numDigs n = 1 + numDigs (quot n 10)

testConcat :: Int -> Int -> [Int] -> Bool
testConcat m n lst = comElem m n lst && comElem n m lst
  where
    comElem x y = elem (x * 10^(numDigs y) + y)

    
main :: IO ()
main = undefined
