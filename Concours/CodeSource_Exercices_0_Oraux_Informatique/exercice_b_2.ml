type arbre =
  | V
  | N of arbre * int * arbre

let feuille = N (V, -1, V)
let droit = N (V, -1, feuille)
let gauche = N (feuille, -1, V)

let ex_a = N (
  N (droit, -1, V),
  -1,
  N (feuille, -1, gauche)
)

let ex_c = N (
  N (feuille, -1, gauche),
  -1,
  N (V, -1, gauche)
)
