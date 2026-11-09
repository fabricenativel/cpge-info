type fl =
| Top | Bot 
| Var of int (*les variables propositionnelles*)
| Non of fl 
| Ou of fl*fl
| Et of fl*fl
| Imp of fl*fl
| Equ of fl*fl

type valuation = {
    t : bool array; (* le tableau de booléen *)
    mutable parite : bool (* la parité du nombre de 1*)
}


let ex = Imp (Et ((Var 1),(Non (Var 2))), (Var 3)) ;;

let rec taille fl =
  match fl with
  | Top | Bot | Var _ -> 1
  | Non sf -> 1 + taille sf
  | Ou (sf1, sf2) -> 1 + taille sf1 + taille sf2
  | Et (sf1, sf2) -> 1 + taille sf1 + taille sf2
  | Imp (sf1, sf2) -> 1 + taille sf1 + taille sf2
  | Equ (sf1, sf2) -> 1 + taille sf1 + taille sf2;;
 

let rec print_formule f = match f with
  | Bot -> print_string "⊥"
  | Top -> print_string "⊤"
  (*| Var(n) -> (print_string "p"; print_int n; print_string "")*)
  | Var(n) -> (print_char (char_of_int (int_of_char 'o'+n));)
  | Non(g) -> (print_string "¬"; print_formule g)
  | Et(g, h) -> print_string "("; print_formule g; print_string " ∧ "; print_formule h; print_string ")";
  | Ou(g, h) -> print_string "("; print_formule g; print_string " ∨ "; print_formule h; print_string ")";
  | Imp(g, h) -> print_string "("; print_formule g; print_string " → "; print_formule h; print_string ")"
  | Equ(g, h) -> print_string "("; print_formule g; print_string " ↔ "; print_formule h; print_string ")"
;;

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
  | Equ(p,q) -> fet (eval valuation p) (eval valuation q);;

let switch v n = v.t.(n) <- not v.t.(n); v.parite <- not v.parite;;

let first n = let res = Array.make n false in 
             {t = res; parite = true};;

let dernier v = let d = ref (Array.length v - 1) in
  while (!d >= 0 && not (v.(!d))) do
    d := !d - 1;
  done;
  !d;;


let next v = 
    let n = Array.length v.t in
    if v.parite then switch v (n-1) else
      let pos = dernier v.t in
      if pos = 0 then raise Exit  else switch v (dernier v.t - 1);;

let affiche v =
  let n = Array.length v.t in
  Printf.printf "[| ";
  for i=0 to n-1 do
    if v.t.(i) then Printf.printf "1; " else Printf.printf "0; "
  done;
  Printf.printf "|] \n";;
  

let () =  let v =  first 4 in 
          for i=0 to 14 do
            affiche v;
            next v;
          done;
          affiche v
        ;;