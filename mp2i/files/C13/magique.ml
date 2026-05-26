let ajoute m ll =
  List.map (fun l -> m::l) ll;;

let rec partitionne somme n entiers =
  Printf.printf "somme = %d - n = %d \n" somme n;
  (*Renvoie la liste des partitions possibles de somme en utilisant n entiers*)
    if (somme = 0) then (
      if n=0 then [[]] else []) else
    if n=0 then [] 
  else
      match entiers with
      | [] -> []
      | m::t -> if m<=somme then ajoute m (partitionne (somme-m) (n-1) t)   else partitionne somme n t
  ;;
