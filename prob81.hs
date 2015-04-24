module Main (main) where

import System.IO
import Data.List
import Data.List.Split


-- Find the minimum sum path
minPath :: [[Int]] -> Int
minPath matrix =
  let l = length matrix
      left = reverse $ take (quot (l - 1) 2) matrix
      center = matrix !! quot (l - 1) 2
      right = drop (quot (l + 1) 2) matrix
  in iterPath left center right

iterPath [] [c] [] = c
iterPath (l:ls) c (r:rs) = iterPath ls (addMins l c r) rs

addMins _ [c] _ = []
addMins (l:ls) (fc:sc:c) (r:rs)
  | fc < sc   = (l + fc + r) : addMins ls (sc:c) rs
  | otherwise = (l + sc + r) : addMins ls (sc:c) rs


-- Produces a matrix of diagonals as rows
rotateMatrix rms [] = rms
rotateMatrix rms (m:ms) =
  let zp = zipRow m rms in
   (head zp) : rotateMatrix (tail zp) ms


-- Zips a list onto a list of lists
zipRow :: [Int] -> [[Int]] -> [[Int]]
zipRow [] ys = ys
zipRow (x:xs) [] = [x] : zipRow xs []
zipRow (x:xs) (y:ys)= (x : y) : zipRow xs ys


-- Parse the matrix into a proper array
parseMatrix :: String -> [[Int]]
parseMatrix = map (map (\num -> read num :: Int) . splitOn ",") . lines


-- Get the result
getResult :: String -> Int
getResult = minPath . rotateMatrix [] . parseMatrix


main :: IO ()
main = withFile "p081_matrix.txt" ReadMode
       (\handle -> do
           contents <- hGetContents handle
           print $ getResult contents)
