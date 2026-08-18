let rec ack n m =
  match n, m with
  | 0, m -> m + 1
  | n, 0 -> ack (n - 1) 1
  | n, m -> ack (n - 1) (ack n (m - 1));;

let ack_memo n m =
  let memo = Hashtbl.create 10000 in
  let rec aux n m =
    if Hashtbl.mem memo (n,m) then Hashtbl.find memo (n,m) else
  match n, m with
  | 0, m -> Hashtbl.add memo (0,m) (m+1); m + 1
  | n, 0 -> let r = aux (n - 1) 1 in Hashtbl.add memo (n,0) (r); r
  | n, m -> let r = aux (n - 1) (aux n (m - 1)) in Hashtbl.add memo (n,0) (r); r in
  aux n m;;

type 'a arbrebin =
  | Vide
  | Noeud of  'a arbrebin * 'a * 'a arbrebin
