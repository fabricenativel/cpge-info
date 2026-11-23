let entiers n =
  List.init n (fun i ->i+1);;

let somme_magique n = n*(n*n+1)/2;;

(* Trouve tous les k-uplets de l de somme s *)
let rec kuplets l s k =
  if (s=0 && k=0) then [[]] else
    match l with
    | [] -> []
    | h::t -> if h>s then kuplets t s k else
                let p1 = kuplets t (s-h) (k-1)  in
                if p1 <> [] then 
                (List.map (fun x -> h::x) p1) @ kuplets t s k else kuplets t s k;;

let get_kuplets n = kuplets (entiers (n*n)) (somme_magique n) n;;


  