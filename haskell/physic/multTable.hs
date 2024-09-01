main :: IO ()
main =  mapM_ print [[x*y | x <- [1..10]] | y <- [1..10]]
