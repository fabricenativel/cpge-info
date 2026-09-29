type 'a ab =
  |Vide
  |Noeud of  'a ab * 'a * 'a ab;;

let rec prefixe_quadratique ab =
  match ab with
  | Vide -> []
  | Noeud(g,x,d) -> x::prefixe_quadratique g @ prefixe_quadratique d;;


let rec prefixe_lineaire ab =
  let rec aux_pl ab acc =
    match ab with
    | Vide -> acc
    | Noeud(g,x,d) -> x::aux_pl g (aux_pl d acc)
  in
  aux_pl ab [];;

let rec infixe_quadratique ab =
  match ab with
  | Vide -> []
  | Noeud(g,x,d) -> infixe_quadratique g @ (x::infixe_quadratique d);;

let rec infixe_lineaire ab =
  let rec infixe_aux ab acc =
    match ab with
    | Vide -> acc
    | Noeud(g,x,d) -> infixe_aux g (x::infixe_aux d acc)
  in
infixe_aux ab [];;
  
let rec suffixe_quadratique ab =
  match ab with
  | Vide -> []
  | Noeud(g,x,d) -> suffixe_quadratique g @ suffixe_quadratique d @ [x];;

let rec suffixe_lineaire ab =
  let rec suffixe_aux ab acc =
    match ab with
    | Vide -> acc
    | Noeud(g,x,d) -> suffixe_aux g (suffixe_aux d (x::acc)) in
  suffixe_aux ab [];;

let rec insere x ab =
  match ab with
  | Vide -> Noeud(Vide,x,Vide)
  | Noeud(g,y,d) -> if x < y then Noeud(insere x g,y,d) else Noeud(g,y,insere x d);;


let rec aleatoire n =
  let t = Array.init n (fun i->i)  in
  for i=n-1 downto 1 do
    let j = Random.int (i+1) in
    let tmp = t.(i) in
    t.(i) <- t.(j);
    t.(j) <- tmp
  done;
  let ab=ref Vide in
    for i=0 to n-1 do
    ab:=insere  t.(i) !ab;
    done;
  !ab;;

let () = let n=14 in
          Random.self_init ();
          let ab = aleatoire n in
          let l1=prefixe_quadratique ab in
          List.iter (fun x -> Printf.printf "%d " x) l1;
          print_newline ();
          let l2=prefixe_lineaire ab in
          List.iter (fun x -> Printf.printf "%d " x) l2;
          print_newline ();
          let l3=infixe_quadratique ab in
          List.iter (fun x -> Printf.printf "%d " x) l3;
          print_newline ();
          let l4=infixe_quadratique ab in
          List.iter (fun x -> Printf.printf "%d " x) l4;
          print_newline ();
          let l5=suffixe_lineaire ab in
          List.iter (fun x -> Printf.printf "%d " x) l5;
          print_newline ();
          let l6=suffixe_quadratique ab in
          List.iter (fun x -> Printf.printf "%d " x) l6;
          print_newline ()
        ;;


