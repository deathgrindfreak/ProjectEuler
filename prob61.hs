-- Project Euler Problem: 61
-- Goal: Find the sum of the six 4-digit numbers that are either triangular
--       square, pentagonal, hexagonal, heptagonal or octagonal.
-- Author: Cooper Bell


-- generate lists of figurative numbers
triangle :: Int -> Int -> [Int]
triangle beg end = map (\n -> (quot (n * (n + 1))  2)) [beg.. (end-1)]

square :: Int -> Int -> [Int]
square beg end = map (\n -> n * n) [beg..(end-1)] 

pentagonal :: Int -> Int -> [Int]
pentagonal beg end = map (\n -> (quot (n * (3 * n - 1)) 2)) [beg..(end-1)]

hexagonal :: Int -> Int -> [Int]
hexagonal beg end = map (\n -> n * (2 * n - 1)) [beg..(end-1)]

heptagonal :: Int -> Int -> [Int]
heptagonal beg end = map (\n -> quot (n * (5 * n - 3))  2) [beg..(end-1)]

octagonal :: Int -> Int -> [Int]
octagonal beg end = map (\n -> n * (3 * n - 2)) [beg..(end-1)]


-- list of all 4-digit figurative numbers
figNums = [(triangle   45 141), 
           (square     32 100), 
           (pentagonal 26 82 ), 
           (hexagonal  23 71 ), 
           (heptagonal 21 64 ), 
           (octagonal  19 59 )]


-- determine if pair of numbers is cyclical
cycPair a b = if ((mod a 100) == (quot b 100)) then True else False

resPairs = [[(n, m)
            | n <- (figNums !! i), m <- (figNums !! j), (cycPair n m) ]
            | i <- [0..5], j <- [0..5], i < j ]

retTrip :: (Int, Int) -> (Int, Int) -> (Int, Int, Int)
retTrip (n, o) (p, m)
                  | (o == p)  = (n, o, m) 
                  | otherwise = (0, 0, 0)
                                
resTrips = [filter (/= (0, 0, 0)) (map (retTrip a) c) | b <- resPairs, c <- resPairs, a <- b, b /= c]

--resTrips = [retTrip n m 
--                  | i <- [0..((length resPairs) - 1)], j <- [0..((length resPairs) - 1)],
--                    n <- (resPairs !! i), m <- (resPairs !! j), ((retTrip n m) /= (0, 0, 0)) ]


--retQuint :: (Int, Int, Int) -> (Int, Int, Int) -> (Int, Int, Int, Int, Int)
--retQuint (n, q, o) (p, s, m) = if (o == p) then (n, q, o, s, m) else (0, 0, 0, 0, 0)
--
--resQuints = [retQuint n m 
--                    | i <- [0..((length resTrips) - 1)], j <- [0..((length resTrips) - 1)],
--                      n <- (resTrips !! i), m <- (resTrips !! j), ((retQuint n m) /= (0, 0, 0, 0, 0)) ]
