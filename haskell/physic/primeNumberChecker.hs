-- Check if a number is prime
isPrime :: Int -> Bool
isPrime n
    | n <= 1    = False  -- Numbers less than or equal to 1 are not prime
    | otherwise = null [ x | x <- [2..sqrtN], n `mod` x == 0]
  where
    sqrtN = floor (sqrt (fromIntegral n))  -- Calculate the square root of n