sumFirstN :: Int -> Int
sumFirstN n = sum [1..n]

sumFirstN2 :: Int -> Int
sumFirstN2 x = x * (x + 1) `div` 2


main :: IO ()
main = do
    print (sumFirstN 5)  -- This will print 15
    print (sumFirstN2 5)