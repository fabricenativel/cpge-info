type entier_aucun =
| Aucun
| Entier of int

let rec premier_pair l =
match l with
| [] -> None
| h::t -> if h mod 2 = 0 then Some h else premier_pair t;;

