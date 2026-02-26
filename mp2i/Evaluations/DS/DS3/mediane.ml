let rec partage lst sep =
  match lst with
  | [] -> 0, 0
  | h::t -> let n1,n2 = partage t sep in 
            if h<sep then 1+n1,n2 else
            if h=sep then n1, n2 else
            n1, n2+1;;
  
let mediane lst =
  let rec aux n lst=
    if n=0 then List.hd lst else aux (n-1) (List.tl lst) in
  aux 0 lst;;



  