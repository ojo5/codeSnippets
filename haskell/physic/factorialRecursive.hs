-- Recursive function to calculate the factorial of a number
factorialCustom :: Integer -> Integer
factorialCustom 0 = 1               -- Base case: 0! = 1
factorialCustom n = n * factorialCustom (n - 1)  -- Recursive case: n! = n * (n-1)!

-- Main function to test the factorial function
main :: IO ()
main = print (factorialCustom 3)  -- This will print 6
