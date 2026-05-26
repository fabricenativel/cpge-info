

let choix_variable fnc =
  (*Si la fnc contient une clause ayant un littéral alors renvoie ce littéral sinon renvoie un des littéraux présent dans une des plus petites clauses*)
  let rec aux fnc cmin littmin =
    match fnc with
    | [] -> littmin
    | []::t -> failwith "Erreur, la fnc contient une clause vide !"
    | h::t -> let nblitt = List.length h in
      let un_litt = List.hd h in
      if nblitt=1 then un_litt else
      if nblitt<cmin then aux t nblitt un_litt
      else aux t cmin littmin 
  in
  aux fnc Int.max_int 0;;

let maxvar fnc =
  let aux cl =
    List.fold_left (fun a b -> if a>abs(b) then a else abs(b))  0 cl in
  aux (List.map aux fnc);;

let substitue_clause clause v b =
  if (List.mem v clause && b) || (List.mem (-v) clause && (not b)) then [0] 
  else List.filter (fun x -> x<>v && x<>(-v)) clause;;

let substitue fnc v b =
  List.filter (fun x -> x<>[0]) (List.map (fun cl -> substitue_clause cl v b) fnc);; 

let quine fnc = 
  let nbvar = maxvar fnc in
  let valuation = Array.make nbvar false in
  let rec aux fnc valuation = 
    if List.mem [] fnc then false else
    if fnc = [] then true
    else (
      let cv = choix_variable fnc in
      valuation.(abs(cv)-1)<-(cv>0);
      let nouvelle_fnc1 = substitue fnc (abs(cv)) valuation.(abs(cv)-1) in
      if aux nouvelle_fnc1  valuation then true else
        (valuation.(abs(cv)-1)<-not valuation.(abs(cv)-1);
         let nouvelle_fnc2 = substitue fnc (abs(cv)) valuation.(abs(cv)-1) in
         if aux nouvelle_fnc2 valuation then true else false
        )
    ) in
  let res = aux fnc valuation in
  res, valuation
;;


let num i j k =
  (* Renvoie le numéro de la variable qui indique que la valeur k se situe ligne i et colonne j*)
  i*81 + 9*j + k;;

let lcv num =
  (*Renvoie lig, col et valeur à partir du numéro de variable *)
  let lig = (num-1)/81 in
  let col = (num-1-(lig*81))/9 in
  let valeur = num - lig*81 - col*9 in
  lig, col, valeur ;;


let toutes () =
  (*Renvoie les indices des toutes les cases du sudoku *)
  let tc = ref [] in
  for i = 0 to 8 do
    for j=0 to 8 do
      tc := (i,j)::!tc
    done;
  done;
  !tc;;

let lignes () = 
  (*Renvoie les indices des cases des 9 lignes d'un sudoku*)
  let temp = ref [] in
  let ll = ref [] in
  for lig=0 to 8 do
    temp := [];
    for col = 0 to 8 do
      temp := (lig,col)::!temp;
    done;
    ll := !temp::!ll;
  done;
  !ll;;

let colonnes () =
  let temp = ref [] in
  let cc = ref [] in
  for col=0 to 8 do
    temp := [];
    for lig = 0 to 8 do
      temp := (lig,col)::!temp;
    done;
    cc := !temp::!cc;
  done;
  !cc;;

let blocs () =
  (*Renvoie les indices des cases des neuf blocs d'un sudoku*)
  let temp = ref [] in
  let bb = ref [] in
  let sl = ref 0 in
  let sc = ref 0 in
  for bloc=0 to 8 do
    sl := (bloc/3)*3;
    sc := (bloc mod 3)*3;
    temp := [];
    for lig=0 to 2 do
      for col = 0 to 2 do
        temp := (!sl + lig, !sc + col)::!temp;
      done;
    done;
    bb := !temp::!bb;
  done;
  !bb;;

let au_moins cases =
  (*Prends une liste de cases et indique qu'une valeur k (1...9) doit apparaitre dans chacune de ces cases'*)
  let aux  case=
     let lig, col = case in
     List.init 9 (fun k -> num lig col (k+1)) in
  List.map (fun c -> aux c) cases 
;;

let au_plus cases =
  (*Prends une liste de cases et indique que deux valeurs distinctes ne peuvent pas apparaitre simultanément dans cette case *)
  let aux case =
    let lig, col = case in
    let cl = ref [] in
    for i = 1 to 9 do
      for j = i+1 to 9 do
        cl := [-num lig col i; -num lig col j]::!cl
      done;
    done;
    !cl;
  in
   List.flatten (List.map (fun c -> aux c) cases);;

let au_moins_liste lcases =
  List.flatten (List.map (fun c->au_moins c) lcases);;

let au_plus_liste lcases =
  List.flatten (List.map (fun c->au_plus c) lcases);;


let rec couples lst =
  (*Renvoie toutes les paires d'éléments de lst *)
  match lst with
  | [] -> []
  | h::t -> (List.map (fun x -> (h,x)) t)@couples t;;

let differents cases =
  (*prend une liste de case et indique qu'une même valeur  ne peut y apparaitre deux fois*)
  let couples_cases = couples cases in
  let aux cc k = 
    let c1,c2 = cc in
    let l1, c1 = c1 in
    let l2, c2 = c2 in
    [-num l1 c1 k; -num l2 c2 k] in
  let res = ref [] in
  for k = 1 to 9 do
    res := (List.map (fun cc -> aux cc k) couples_cases)@(!res);
  done;
  !res;;
;;

let differents lcases =
  List.flatten (List.map (fun c->differents c) lcases);;

let initialisation str =
  let lcl = ref [] in
  for i=0 to 80 do
    if str.[i] <> '0' then
      lcl := [(num (i/9) (i mod 9) ((int_of_char str.[i]) - int_of_char '0'))]::!lcl;
  done;
  !lcl;;

let test = "530070000600195000098000060800060003400803001700020006060000280000419005000080079";;
let dur = "000000013000200000000000080000760200008000400010000000200000750600340000000008000";;

let cree_solution valuation =
  let sudoku = Array.make_matrix 9 9 0 in
  for v = 1 to 729 do
    if valuation.(v-1) then
      let i,j,k = lcv v in
      sudoku.(i).(j) <- k
  done;
  sudoku;;

let affiche sudoku =
  for i = 0 to 8 do
    for j = 0 to 8 do
      Printf.printf "%d" sudoku.(i).(j);
    done;
    Printf.printf "\n";
  done;;



let solve sudoku =
  let contraintes =
    (initialisation sudoku)@(au_moins (toutes ()))@(au_plus (toutes ()))@(differents (lignes ()))@(differents (colonnes ()))@(differents (blocs ())) in
  print_endline "Initialisation terminée";
  let res, valuation = quine contraintes in
  if res then (print_endline "Succès"; let sol=cree_solution valuation in affiche sol) else print_endline "Echec";; 

let () =
    solve test;;