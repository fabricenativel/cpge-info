open Stack

type elt = Add | Sub | Mult | Div | Nombre of int


let make_npi s =
  let rec aux tokens =
    match tokens with
    | [] -> []
    | "-"::t -> Add :: (aux t)
    | "+"::t -> Sub :: (aux t)
    | "*"::t -> Mult :: (aux t)
    | "/"::t -> Div :: (aux t)
    | x :: t -> (Nombre (int_of_string x)) :: (aux t)
  in
  let tokens = String.split_on_char ' ' s in
  aux tokens;;
  


let evalue npi =
  let rec aux npi pile =
    match npi with
    | [] -> Stack.pop pile
    | h::t -> (match h with
      | Add -> Stack.push (Stack.pop pile + Stack.pop pile) pile
      | Sub -> Stack.push (Stack.pop pile -Stack.pop pile) pile
      | Mult -> Stack.push (Stack.pop pile * Stack.pop pile) pile
      | Div -> Stack.push (Stack.pop pile / Stack.pop pile) pile 
      | Nombre x -> Stack.push x pile );
     aux t pile 
  in
    let temp = Stack.create () in
    aux npi temp;;
    

let () = print_int (evalue (make_npi "3 7 + 5 *"));;

  