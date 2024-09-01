main :: IO ()
main = print (map(5 *)[1..10])    
    -- mapM_ print [5 * x | x <- [1..10]]
