type 'a tree =
  | Node of 'a * 'a tree list

let rec  size mytree =
   let  Node (root, forest) = mytree in
  1 + size_forest forest
  and
  size_forest forest = 
  match forest with
  | [] -> 0
  | f :: fs -> size f + size_forest fs;;

  