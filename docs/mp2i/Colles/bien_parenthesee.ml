open Stack;;

type parenthese = {ouvrante : char; fermante : char}

let couples = [
    {ouvrante = '('; fermante=')'};
    {ouvrante = '['; fermante=']'};
    {ouvrante = '{'; fermante='}'}
    ];;

let rec list_of_string str =
  if str = "" then [] else str.[0]::list_of_string (String.sub str 1 ((String.length str) -1));;


let bien_parenthesee expr =
  let my_stack = Stack.create() in
  let lexp = list_of_string expr in
  let rec aux_bp lexp stack = 
    match lexp with
    | [] -> Stack.is_empty my_stack
    | a :: t -> if List.mem a (List.map (fun x -> x.ouvrante) couples) then (Stack.push a my_stack; aux_bp t stack)  else 
                if List.mem a (List.map (fun x -> x.fermante) couples) then (
                  if Stack.is_empty my_stack then false else 
                    let s = Stack.pop my_stack in
                    List.mem {ouvrante = s; fermante = a} couples && aux_bp t stack
                )
                  else aux_bp t stack
  in
  aux_bp lexp my_stack;;
