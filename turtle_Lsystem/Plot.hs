module Plot where

import Turtle (Position, Heading, Turtle, Move(Forward,TurnLeft,TurnRight), moveTurtle)
import Data.Char (isUpper)

moveIt :: Turtle -> Char -> Turtle
moveIt (paso,giro,(x,y),orn) c = case c of
                                '>' -> moveTurtle (paso,giro,(x,y),orn) Forward
                                c | isUpper c -> moveTurtle (paso,giro,(x,y),orn) Forward
                                '+' -> moveTurtle (paso,giro,(x,y), orn) TurnRight
                                '-' -> moveTurtle (paso,giro,(x,y),orn) TurnLeft


--Utiliza la función tplot para generar distintas figuras geométricas (triángulo, cuadrado, círculo) y grábalas en formato SVG
--mediante las funciones dadas
tplot :: Turtle -> String -> [Position]
tplot (paso,giro,(x,y),orn) [] = [(x,y)] 
tplot (paso,giro,(x,y),orn) (c:cs) = (x,y) : tplot( moveIt (paso,giro,(x,y),orn) c ) cs

