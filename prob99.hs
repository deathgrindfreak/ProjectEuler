module Prob99 where

import Data.List

main = do content <- readFile "p099_base_exp.txt"
          print $ "Line number: " ++ (show $ maxExp content)
          
maxExp :: String -> Int
maxExp c = i + 1
    where l = logs c
          m = maximum l
          Just i = elemIndex m l
          
logs :: String -> [Float]
logs = map (logMult . readTup . split) . lines
             
split :: String -> (String, String)
split s = case elemIndex ',' s of
    Just n  -> let (l, m) = splitAt n s in (l, drop 1 m)
    
readTup :: (String, String) -> (Int, Int)
readTup (f, s) = (read f :: Int, read s :: Int)

logMult :: (Int, Int) -> Float
logMult (f, s) = (fromIntegral s) * log (fromIntegral f)