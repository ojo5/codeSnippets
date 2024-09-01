-- Function to check if a number is prime
isPrime :: Int -> Bool
isPrime n
    | n <= 1    = False
    | otherwise = null [ x | x <- [2..sqrtN], n `mod` x == 0]
  where
    sqrtN = floor (sqrt (fromIntegral n))

-- Function to find the next smallest prime factor of a number
nextPrimeFactor :: Int -> Int
nextPrimeFactor n
    | n <= 1    = error "No prime factors for numbers less than or equal to 1"
    | otherwise = head [x | x <- [2..n], n `mod` x == 0, isPrime x]

-- Function to compute the prime factorization of a number
primeFactors :: Int -> [Int]
primeFactors n
    | n <= 1    = []
    | otherwise = factorize n (nextPrimeFactor n)
  where
    factorize num prime
        | num `mod` prime == 0 = prime : factorize (num `div` prime) prime
        | otherwise = primeFactors num

-- Function to print the prime factorization of a number
printPrimeFactors :: Int -> IO ()
printPrimeFactors n = putStrLn (show n ++ " can be factorized into: " ++ show (primeFactors n))

-- Function to find all factors of a number
findFactors :: Int -> [Int]
findFactors n = [x | x <- [2..n-1], n `mod` x == 0]

-- Function to print composite numbers and their factors
printCompositeNumbers :: [Int] -> IO ()
printCompositeNumbers = mapM_ printComposite 
  where
    printComposite n
      | not (isPrime n) && n > 1 = putStrLn (show n ++ " is a composite number with factors: " ++ show (findFactors n))
      | otherwise = return ()  -- Do nothing for prime numbers or numbers less than or equal to 1

-- Function to print information about a single number if it is composite
printCompositeNumber :: Int -> IO ()
printCompositeNumber n
    | not (isPrime n) && n > 1 = putStrLn (show n ++ " is a composite number with factors: " ++ show (findFactors n))
    | otherwise = return ()  -- Do nothing for prime numbers or numbers less than or equal to 1

-- Main function
main :: IO ()
main = do
    -- Print prime numbers
    let primes = filter isPrime [1..100]
    mapM_ (putStrLn . (\n -> show n ++ " is a prime number.")) primes
    
    printPrimeFactors 5525612
    

