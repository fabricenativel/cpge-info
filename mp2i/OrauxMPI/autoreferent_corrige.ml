(* Question 1 *)
let somme t i =
  let s = ref 0 in
  for k=0 to i do
    s := !s + t.(k);
  done;
  !s;;

(* Question 2 *)
(* Il suffit de tester les valeurs possibles pour constater qu'on ne trouve pas de solution 
Pour n=4 on trouve le tableau  [| 2; 0; 2; 0|]
*)

(* Fonction qui vous est donnée permettant d'afficher un tableau *)
let affiche t =
  print_string "[|";
  Array.iteri (fun i x -> print_int x; if i < Array.length t - 1 then print_string "; ") t;
  print_string "|]\n"

(*Question 3*)
(* La complexité est en O(n) puisque les boucles sont répétées au plus n fois et ne contiennent que des opérations élémentaires*)
let est_auto t =
  let n = Array.length t in
  let cpt = Array.make  n  0 in
  try
  for i=0 to n-1 do
    if t.(i)<0 || t.(i)>=n then raise Exit else
    cpt.(t.(i)) <- cpt.(t.(i)) + 1
  done;
  for i=0 to n-1 do
    if cpt.(i) <> t.(i) then  raise Exit;
    done;
  true;
  with  Exit -> false;;
  
  let partiel t  k =
    let n = Array.length t in
    let cpt = Array.make  n  0 in
    try
    for i=0 to k-1 do
      cpt.(t.(i)) <- cpt.(t.(i)) + 1
    done;
    for i=0 to k-1 do
      if cpt.(i) > t.(i) then  raise Exit;
      done;
    true;
    with  Exit -> false;;

exception Echec

let compte tab elt idx =
  let res = ref 0 in
  for i = 0 to idx do 
    if tab.(i)=elt then res := !res + 1;
  done;
  !res;;

(* Question 5 : La somme des éléments d'un tableau autoréférent est la taille du tableau *)
let gen_auto n =
  let t = Array.make n (-1) in
  let rec remplir_a_partir_de i =
    if i = n then
      (* On est arrivé à la fin *)
      if est_auto t then
        affiche t
      else
        raise Echec
    else
      for k = 0 to n - 1 do
        try
          t.(i) <- k;
          (* Début élagage *)
          (* Il reste (n-1-i) cases à remplir parmi ces cases t.(0) moins le nombre de zeros déjà placés seront non nulles*)
          if somme t i + (n-1-i -(t.(0) - compte t 0 i)) > n then raise Echec;
          (* Stratégie améliorée de la question 5*)
          if not (partiel t i) then raise Echec;
          (* Fin élagage *)
          remplir_a_partir_de (i + 1)
        with Echec -> ()
      done
  in
  remplir_a_partir_de 0

  (*Q7 : on vérifie simplement que [| n-4; 2; 1; 0 .(que des 0 sauf à l'indice n-4 qui a un 1)..0|] est autoréférent*)
