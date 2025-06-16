let entiers n =
  List.init n (fun  i->i);;

let rec combinaisons k n =
  (* génère les combinaisons de k valeurs choisies parmi les entiers de  0 à (n-1) *)
  if k = 0 || k>n then [[]] else
    if k=n then [entiers n] else
      let p1 = combinaisons (k-1) (n-1) in
      let p2 = combinaisons k (n-1) in
      List.map (fun x->(n-1)::x) p1 @ p2;;


let somme_chemin mat ch =
  let n = Array.length mat in
  let somme = ref mat.(0).(0) in
  let l = ref 0 in
  let c= ref 0 in
  for m=0 to (2*n-3) do
    if List.mem m ch then
      l:=!l+1
    else
      c:=!c+1;
    somme:=!somme+mat.(!l).(!c);
    done;
  !somme;;

let max_somme m = 
  let n = Array.length m in
  let max_somme = ref 0 in
  let chemins = combinaisons (n-1) (2*n-2) in
  List.iter (fun ch->max_somme:=max !max_somme (somme_chemin m ch)) chemins;
  !max_somme;;

let () =
let exemple = 
   [|
    [|11; 19; 12;  2; 18; 18;  2;  9; 12; 17|];
    [|17; 14; 12; 10;  7; 18; 12;  5; 11;  7|];
    [| 4;  8;  2; 12;  2; 17; 16; 13;  1;  6|];
    [|13;  8; 20; 10;  3; 12; 17; 12; 12;  9|];
    [| 8;  3; 14; 17; 16; 10; 13; 10;  5; 20|];
    [| 9; 13; 17;  9; 10;  1; 11; 19; 20; 19|];
    [| 1;  6; 18; 15; 10;  2;  7;  9;  4; 20|];
    [| 3;  8; 17; 18; 20; 19; 16;  8;  2; 14|];
    [|19; 17; 18;  9; 20; 15;  6;  5; 16;  3|];
    [|13; 14; 14;  9; 16;  8; 17; 15;  9; 11|];
        |]
in Printf.printf "%d\n" (max_somme exemple);;
;;


    