-- Function to compute Euler's Totient Function
eulerTotient :: Int -> Int
eulerTotient n = length [k | k <- [1..n-1], gcd k n == 1]

-- Function to print Euler's Totient Function for specific values
printTotients :: [Int] -> IO ()
printTotients = mapM_ printTotient 
  where
    printTotient d = putStrLn $ "φ(" ++ show d ++ ") = " ++ show (eulerTotient d)

-- Function to check if two numbers are relatively prime
areRelativelyPrime :: Int -> Int -> Bool
areRelativelyPrime a b = gcd a b == 1

-- Main function to test the areRelativelyPrime function and print totients
main :: IO ()
main = do
    -- Print Euler's Totient Function values for specific numbers
    printTotients [10, 20, 50, 100, 200]
    
    -- Read and process user input for checking relative primality
    putStrLn "Enter the first integer:"
    num1 <- readInteger
    
    putStrLn "Enter the second integer:"
    num2 <- readInteger
    
    putStrLn $ "The numbers " ++ show num1 ++ " and " ++ show num2 ++
               " are relatively prime: " ++ show (areRelativelyPrime num1 num2)

-- Function to read an integer from user input
readInteger :: IO Int
readInteger = do
    input <- getLine
    return (read input)