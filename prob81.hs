module Main (main) where

import System.IO
import Data.List.Split


parseMatrix :: String -> [[Int]]
parseMatrix = map (map (\num -> read num :: Int) . splitOn ",") . lines

main = do
  withFile "p081_matrix.txt" ReadMode
    (\handle -> do
        contents <- hGetContents handle
        print $ parseMatrix contents)
