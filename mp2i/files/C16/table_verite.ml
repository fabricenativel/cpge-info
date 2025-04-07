type fl =
  | Top | Bot 
  | Var of int (*les variables propositionnelles*)
  | Non of fl 
  | Ou of fl*fl
  | Et of fl*fl
  | Imp of fl*fl
  | Equ of fl*fl

let list_var fl =
  (*Renvoie la liste des variables logiques utilisées dans une formule*)
  let rec aux fl acc =
    match fl with
    | Top | Bot -> acc
    | Var(n) -> if List.mem n acc then acc else n::acc
    | Non(sf) -> aux sf acc
    | Ou(sf1, sf2) -> aux sf1 (aux sf2 acc)
    | Et(sf1, sf2) -> aux sf1 (aux sf2 acc)
    | Imp(sf1, sf2) -> aux sf1 (aux sf2 acc)
    | Equ(sf1, sf2) -> aux sf1 (aux sf2 acc)
  in 
  aux fl [];;


let fnon p = (not p);;

let fet p q = (p && q);;

let fou p q = (p || q);;

let fimp p q = ((not p) || q);;

let fequ p q = ((not p && not q) || (p && q));;


let rec eval valuation formule  =
  match formule with
  | Bot -> false
  | Top -> true
  | Var(p) -> valuation.(p-1) 
  | Non(p) -> fnon (eval valuation p)
  | Et(p,q) -> fet (eval valuation p) (eval valuation q)
  | Ou(p,q) -> fou (eval valuation p) (eval valuation q)
  | Imp(p,q) -> fimp (eval valuation p) (eval valuation q)
  | Equ(p,q) -> fequ (eval valuation p) (eval valuation q);;


let rec print_formule f = match f with
  | Bot -> print_string "⊥"
  | Top -> print_string "⊤"
  | Var(n) -> (print_string "p"; print_int n; print_string "")
  | Non(g) -> (print_string "¬"; print_formule g)
  | Et(g, h) -> print_string "("; print_formule g; print_string " ∧ "; print_formule h; print_string ")";
  | Ou(g, h) -> print_string "("; print_formule g; print_string " ∨ "; print_formule h; print_string ")";
  | Imp(g, h) -> print_string "("; print_formule g; print_string " → "; print_formule h; print_string ")"
  | Equ(g, h) -> print_string "("; print_formule g; print_string " ↔ "; print_formule h; print_string ")"
;;

let print_var x =
  print_char (char_of_int ((int_of_char 'o')+x));;

let entete vars =
  List.iter (fun x -> print_string "│";  print_var x) vars;
  print_endline "│F│";
  print_string "├";
  for i=0 to (List.length vars - 1) do
    print_string "─┼";
  done;
  print_endline "─┤";;

let incremente v =
  let n = Array.length v in
  let pos = ref (n-1) in
  while (!pos >=0) && v.(!pos) do
    v.(!pos) <- false;
    pos := !pos - 1;
  done;
  if !pos >= 0 then (v.(!pos) <- true; true) else false;;

let table_verite fl =
  let vars = list_var fl in
  let n=List.length vars in
  let valuation = Array.make n false in
  entete vars;
  for i=0 to (1 lsl  n) - 1 do
    for j=0 to n-1 do
      if valuation.(j) then
        print_string "│1"
      else
        print_string "│0"
    done;
    print_string "│";
    if eval valuation fl then
      print_string "1│"
    else
      print_string "0│";
    print_newline();
    ignore (incremente valuation);
  done;;

let clauses fl =
  let vars = list_var fl in
  let n=List.length vars in
  let valuation = Array.make n false in
  let cl = ref [] in
  for i=0 to (1 lsl  n) - 1 do
    if eval valuation fl then
      cl := (Array.copy valuation)::!cl;
    ignore (incremente valuation);
  done;
  !cl;
;;



let ex = Equ (Imp (Var 1, Var 2), (Non (Var 3)));;
