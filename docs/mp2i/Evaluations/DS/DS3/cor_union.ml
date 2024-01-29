let rec insere n l =
  match l with
  | [] -> [n]
  | h::t -> if h<n then h::(insere n t) else 
            if h=n then h::t else n::l;;

let rec union l1 l2 =
  match l1 with
  | [] -> l2
  | h::t -> union t (insere h l2);;

  let rec union l1 l2 =
    match l1, l2 with
    | l1, [] -> l1
    | [], l2 -> l2
    | h1::t1, h2::t2 -> if h1<h2 then h1::(union t1 l2) else
                        if h1=h2 then h1::(union t1 t2) else
                        h2::(union l1 t2);;
    