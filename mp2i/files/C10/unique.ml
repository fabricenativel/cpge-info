
let rec est_dans elt lst =
  match lst with
  | [] -> false
  | h::t -> h=elt || est_dans elt t;;

let unique tab =
  let lst = ref [] in
  let n = Array.length tab in
  for i=0 to (n-1) do
    if (not (est_dans tab.(i) !lst)) then lst:=tab.(i)::!lst
  done;
  !lst;;

  

