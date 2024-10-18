module Main where
import BinaryTree

testTree = tree "R" (tree "HI" (leaf "NII") (leaf "NID")) (tree "HD" (leaf "NDI") (leaf "NDD"))
testTree2 = tree 1 (tree 2 (leaf 3) (leaf 4)) (tree 5 empty (leaf 6))
names = build ["Adolfo","Diego","Juan","Pedro","Tomas"]

main = 
    print testTree 
    print $ build [3,2,2,5,1,4,4]
    print $ buildBalanced [1..6] 
    print names 
    print $ postorder testTree 
    print $ inorder names 
    print $ postorder names 
    print (balance names)
    print $ between testTree 2 4
          