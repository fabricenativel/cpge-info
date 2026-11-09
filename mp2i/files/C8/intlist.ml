type intlist =
| Vide
| TeteQueue of int * intlist;;

let ajoute n lst =
  TeteQueue (n,lst);;

let rec aleatoire n vmin vmax =
  match n with
  | 0 -> Vide
  | _ -> ajoute (vmin + Random.int (vmax-vmin+1)) (aleatoire (n-1) vmin vmax);;

let rec affiche lst =
  match lst with
  | Vide -> print_newline ()
  | TeteQueue (t,q) -> Printf.printf "%d; " t; affiche q;;

let rec partition lst predicat =
  match lst with
  | Vide -> Vide, Vide
  | TeteQueue (t,q) -> let q1,q2 = partition q predicat in
                       if (predicat t) then (ajoute t q1),q2 else q1,(ajoute t q2);;

          