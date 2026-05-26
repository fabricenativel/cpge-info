let somme_glouton pyramide =
let rec aux pyramide ligne colonne =
  if ligne = Array.length pyramide -1 then
    pyramide.(ligne).(colonne)
  else
    if pyramide.(ligne+1).(colonne) > pyramide.(ligne+1).(colonne+1) then
      pyramide.(ligne).(colonne) + aux pyramide (ligne+1) colonne
    else
      pyramide.(ligne).(colonne) + aux pyramide (ligne+1) (colonne+1) in
    aux pyramide 0 0;;


let () =let pyramide = [|
  [| 3 |];
  [| 7; 4 |];
  [| 2; 4; 6 |];
  [| 8; 5; 9; 3 |] |] in
  Printf.printf "Somme maximale (glouton) = %d\n" (somme_glouton pyramide);;