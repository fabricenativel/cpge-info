let somme t i =
  failwith "à compléter"

let est_auto t =
  failwith "à compléter"

(* Fonction qui vous est donnée permettant d'afficher un tableau *)
let affiche t =
  print_string "[|";
  Array.iteri (fun i x -> print_int x; if i < Array.length t - 1 then print_string "; ") t;
  print_string "|]\n"

exception Echec

let valide tab i = true;;

(* Recherche par backtracking les tableaux autoréférents de taille n*)
let recherche n =
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
          (* Ici on valide que le début de solution est correcte  *)
          if not (valide t i) then raise Echec;
          (* Fin de la validation partir *)
          remplir_a_partir_de (i + 1)
        with Echec -> ()
      done
  in
  remplir_a_partir_de 0
