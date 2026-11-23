type elt = V of int | Add | Sub | Mul;;



let string_to_npi expr=
  let lexpr = String.split_on_char ' ' expr in
  let rec lstring_to_npi lexpr =
    match lexpr with
    | [] -> []
    | "+" :: t -> Add :: lstring_to_npi t
    | "-" :: t -> Sub :: lstring_to_npi t
    | "*" :: t -> Mul :: lstring_to_npi t
    | h :: t -> V (int_of_string h) :: lstring_to_npi t in
  lstring_to_npi lexpr;;



let evalue_npi enpi =
  let rec aux enpi st =
    match enpi with
    | [] -> Stack.pop st
    | V n :: t -> Stack.push n st; aux t st 
    | Add :: t -> let a = Stack.pop st in let b = Stack.pop st in Stack.push (a+b) st; aux t st
    | Sub :: t -> let a = Stack.pop st in let b = Stack.pop st in Stack.push (b-a) st; aux t st
    | Mul :: t -> let a = Stack.pop st in let b = Stack.pop st in Stack.push (a*b) st; aux t st in
  let ms = Stack.create () in
  aux enpi ms;;

let eval expr =
  let enpi = string_to_npi expr in
  evalue_npi enpi;;
