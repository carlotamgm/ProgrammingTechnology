module Main where

import SVG
import Plot(moveIt, tplot)
import Lsystem(rulesKoch, rulesKochCuad, rulesArrowhead, lsystem)

figura1 = tplot (1,90,(0,0),90) ">+>+>+>+"

figura2 = tplot (1,30,(0,0),0) ">++++>++++>+++++"

figura3 = tplot (1,30,(0,0),30) ">+>+>+>+>+>+>+>+>+>+>+>"

figura4 = tplot (1, 60, (0,0), 0) (lsystem (rulesKoch) "F" 1)

figura5 = tplot (1, 90, (0,0), 0) (lsystem (rulesKochCuad) "F" 1)

figura6 = tplot (1, 60, (0,0), 0) (lsystem (rulesArrowhead) "F" 3)

main = do
    savesvg "cuadrado" figura1
    savesvg "triángulo" figura2
    savesvg "círculo" figura3
    savesvg "kolch" figura4
    savesvg "kolchCuad" figura5
    savesvg "arrowHead" figura6
