let choix matrice i j =
  let n = Array.length matrice in
  if i==n-1 then 0 else
    if j==n-1 then 1 else
      if matrice.(i+1).(j) >= matrice.(i).(j+1) then 1 else 0
    
let naif matrice =
  let n = Array.length matrice in
  let rec aux i j =
    if i=n-1 && j=n-1 then [] else
    let c = choix matrice i j in
      if c=1 then 1::aux (i+1) j else 0::aux i (j+1) in
    aux 0 0;;

let somme matrice chemin =
  let rec aux chemin i j =
    match chemin with
      |[] -> 0
      |d::reste -> if d=0 then matrice.(i).(j+1)+(aux reste i (j+1)) 
                  else matrice.(i+1).(j)+(aux reste (i+1) j) in
    matrice.(0).(0) + aux chemin 0 0;;


let dynamique matrice =
  let n = Array.length matrice in
  let rec aux i j =
    if i=n-1  && j=n-1 then 0 else
      if i=n-1 then matrice.(i).(j) + aux i (j+1) else
        if j=n-1 then matrice.(i).(j) + aux (i+1) j else
          let bas =aux (i+1) j in
          let droite = aux i (j+1) in
          max (matrice.(i+1).(j) + bas) (matrice.(i).(j+1) + droite) in
    matrice.(0).(0) + aux 0 0;;

let ex = [| [|2; 5; 4; 6|]; [|8; 5; 9; 8|]; [|5; 7; 4; 6|]; [|9; 6; 4; 4;|] |];;