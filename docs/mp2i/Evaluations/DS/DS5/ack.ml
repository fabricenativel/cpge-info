let rec ack n m =
  match n, m with
  | 0, m -> m + 1
  | n, 0 -> ack (n - 1) 1
  | n, m -> ack (n - 1) (ack n (m - 1));;

type 'a arbrebin =
  | Vide
  | Noeud of  'a arbrebin * 'a * 'a arbrebin
