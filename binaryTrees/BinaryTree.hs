-- PRÁCTICA 6
-- Autoras: E.Lilai Naranjo, 840091
--          Carlota Moncasi, 839841

module BinaryTree where

import Data.List

data Tree x = Empty | Node x (Tree x) (Tree x)

--devuelve un árbol vacío, sin ningún elemento
empty :: Tree x
empty = Empty

-- devuelve un árbol que consta de una única hoja que contiene el elemento x.
leaf :: x -> Tree x
leaf x = Node x Empty Empty

--devuelve un árbol que contiene en la raíz el elemento x, con hijo izquierdo
-- lc e hijo derecho rc
tree :: x -> Tree x -> Tree x -> Tree x
tree x Empty Empty = leaf x
tree x lc Empty = Node x lc Empty
tree x Empty rc = Node x Empty rc
tree x lc rc = Node x lc rc

-- devuelve el número de elementos del árbol
size :: Tree x -> Int
size Empty = 0
size (Node _ lc rc) = 1 + size lc + size rc

-- devuelve el string " " tabulado el número de veces indicado
indent :: Int -> String
indent 0 = ""
indent n = "  " ++ indent (n-1)

-- imprime el árbol en forma de string
mostrar :: Show x => Tree x -> Int -> String
mostrar Empty _ = "<>"
mostrar (Node x Empty Empty) _ = show x
mostrar (Node x lc rc) tab = show x ++ "\n" ++ indent tab ++ " |-" 
        ++ mostrar lc (tab + 1) ++ "\n" ++ indent tab ++ " |-" ++ mostrar rc (tab+1)

instance (Show x) => Show (Tree x) where
    show x = mostrar x 0

-- añade un elemento al árbol 
add :: (Ord t) => Tree t -> t -> Tree t
add Empty x = leaf x
add (Node t Empty Empty) x = if (x < t) then (Node t (leaf x) Empty)
                            else (Node t Empty (leaf x))
add (Node t lc rc) x = if (x < t) then (Node t (add lc x) rc)
                        else (Node t lc (add rc x))

-- función auxiliar de build
buildAux :: (Ord t) => Tree t -> [t] -> Tree t
buildAux t [] = t
buildAux t (x:xs) = buildAux (add t x) xs

-- construye un árbol binario de búsqueda, comenzando con un árbol vacío 
-- e insertando sucesivamente los elementos de la lista xs
build :: (Ord t) => [t] -> Tree t
build [] = Empty
build (t:ts) = buildAux (leaf t) ts

-- construye un árbol equilibrado, ordenando la lista y dividiéndola en dos por la
-- mediana.
buildBalanced :: (Ord t) => [t] -> Tree t
buildBalanced [] = empty
buildBalanced list =  Node listD (buildBalanced listI) (buildBalanced listDs) --listD es nodo raíz
    where
    ordenada = sort list -- ordeno la lista
    x = length ordenada `div` 2 -- calculo la mediana
    (listI, listD:listDs) = splitAt (x) ordenada -- divido la lista en dos por la mediana

-- devuelve lista recorriendo el árbol siguiendo el orden: raíz, izquierdo, derecho
preorder :: (Ord t) => Tree t -> [t]
preorder Empty = []
preorder (Node x Empty Empty) = [x]
preorder (Node x lc rc) = [x] ++ preorder lc ++ preorder rc

-- devuelve lista recorriendo el árbol siguiendo el orden: izquierdo, derecho, raíz
postorder :: (Ord t) => Tree t -> [t]
postorder Empty = []
postorder (Node x Empty Empty) = [x]
postorder (Node x lc rc) = postorder lc ++ postorder rc ++ [x]

-- devuelve lista recorriendo el árbol siguiendo el orden: izquierdo, raíz, derecho
inorder :: (Ord t) => Tree t -> [t]
inorder Empty = []
inorder (Node x Empty Empty) = [x]
inorder (Node x lc rc) = inorder lc ++ [x] ++ inorder rc

-- construye un árbol equilibrado (es decir, de altura mínima) a partir de otro cualquiera
balance :: (Ord t) => Tree t -> Tree t
balance Empty = Empty
balance t = buildBalanced (preorder t)
            --buildBalanced (inorden t)
            --buildBalanced (postorden t)

-- devuelve una lista con todos los elementos del árbol t que están entre los valores xmin y xmax 
-- (ambos inclusive).
between :: (Ord t) => Tree t -> t -> t -> [t]
--between t xmin xmax = filter (\x -> x >= xmin && x <= xmax) (preorder t)
--between t xmin xmax =  filter (\x -> x >= xmin && x <= xmax) (inorder t)
between t xmin xmax =  filter (\x -> x >= xmin && x <= xmax) (postorder t) 

