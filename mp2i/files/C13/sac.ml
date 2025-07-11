type objet = {nom : string; poids : float; valeur : float}

let objets = [| 
  {nom="hamburger"; poids =0.3; valeur = 180.};
  {nom="marteau"; poids =4.1; valeur = 2050.};
  {nom="parapluie"; poids =0.6; valeur = 280.};
  {nom="ballon"; poids =1.7; valeur = 810.};
  {nom="clé"; poids =2.; valeur = 990.};
  {nom="sapin"; poids =2.9; valeur = 1275.};
  {nom="chapeau"; poids =5.7; valeur = 2570.};
  {nom="guitare"; poids =2.1; valeur = 920.};
|]

let calcule combinaison =
  let v = ref 0. in
  let p = ref 0. in
  for i = 0 to (Array.length combinaison)-1 do
    if combinaison.(i)==1 then 
      (v := !v +. objets.(i).valeur;
       p := !p +. objets.(i).poids;
      )
  done; 
  !v,!p;;

let aff_comb c =
  for i=0 to (Array.length c - 1) do
    Printf.printf "%d " c.(i);
  done;
  print_newline ();
;;

let brute_force pmax =
  let size = Array.length objets in
  let essai = Array.make size 0 in
  let cidx = ref (size-1) in 
  let opti = ref 0. in
  while essai.(0)!=2 do
    let ve,pe = calcule essai in
    if pe<pmax && ve > !opti then opti := ve;
    essai.(size-1) <- essai.(size-1) + 1;
    cidx := size-1;
    while (!cidx <> 0 && essai.(!cidx)==2) do
      (essai.(!cidx) <- 0;
      cidx := !cidx -1;
      essai.(!cidx) <- essai.(!cidx)+1;)
    done;
  done;
  !opti;;

let () = Printf.printf "Opti = %f\n" (brute_force 8.);;



