module Lsystem where

import Turtle (Position, Heading, Turtle, Move(Forward,TurnLeft,TurnRight), moveTurtle)

rulesKoch :: Char -> String
rulesKoch 'F' = "F+F--F+F" --curva de koch

rulesKochCuad :: Char -> String
rulesKochCuad 'F' = "F+F-F-F+F" --curva de koch cuadrada

rulesArrowhead :: Char -> String
rulesArrowhead 'F' = "G-F-G" --arrowhead
rulesArrowhead 'G' = "F+G+F"

lsystem :: (Char -> String) -> String -> Int -> String
lsystem _ axioma 0 = axioma 
lsystem rules axioma num = lsystem rules axioma (num-1)