let maxfl l = 
  if l=[] then None else
    Some (List.fold_left (fun a b -> if a>b then a else b) Int.min_int l) ;;
    
