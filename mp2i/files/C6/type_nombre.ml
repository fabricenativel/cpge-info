type nombre = Int of int | Float of float;;

let addition n1 n2 =
  match n1, n2 with
  | Int x, Int y -> Int (x + y) 
  | Float x, Float y -> Float (x +. y)
  | Int x, Float y -> Float (float_of_int (x) +. y)
  | Float x, Int y -> Float (x +. float_of_int(y))

type couleur = int * int * int;;

let negatif c = 
  let x,y,z = c in 
    255-x,255-y, 255-z;;

let pur c =
  match c with
  | x, 0, 0 -> if x>0 then print_string("Rouge pur")
  | 0, x, 0 -> if x>0 then print_string("Vert pur")
  | 0, 0, x -> if x>0 then print_string("Bleu pur")
  | _,_,_ -> print_string("Mélange");;