sinCheck :: Double -> Bool
sinCheck outPut = outPut > 0 
      
-- Main function to test if sum of sin is positive
main :: IO ()
main = do
    print (sinCheck (sin 1))
    print (sinCheck (sin (-1)))