
type direction = Droite | Bas;;

let somme_chemin matrice chemin =
  let n = Array.length matrice.(0) in
  let sc = ref matrice.(0).(0) in
  let lig = ref 0 in
  let col = ref 0 in
  for i=0 to 2*n-3 do
    if chemin.(i)==Droite then col:=!col+1 else lig:=!lig+1;
    sc := !sc + matrice.(!lig).(!col);
  done;
  !sc;;

  let rec entiers n =
    if n = 0 then [] else n::(entiers (n-1));;

  let rec union l1 l2 =
    match l1 with
    | [] -> l2
    | h::t -> union t (h::l2);;
  
  let combinaison k n =
    let memo = Hashtbl.create 10000 in
    let rec aux_combinaison k n memo =
    if Hashtbl.mem memo (k,n) then Hashtbl.find memo (k,n) else
    (
    if k=0 then [[]] else
     if k=n then [entiers n] else
      let p1 = aux_combinaison (k-1) (n-1) memo in
      let p2 = aux_combinaison k (n-1) memo in
      let res = union (List.map (fun x->n::x) (p1))  p2 in
      Hashtbl.add memo (k,n) res;
      res) in
    aux_combinaison k n memo
    ;;

  let chemins n =
    let rec aux_chemins k n =
      if k=0 then [[]] else
        if k=n then [entiers n] else
        let p1 = aux_chemins (k-1) (n-1) in
        let p2 = aux_chemins k (n-1) in
        union (List.map (fun x->n::x) (p1))  p2 
      in
    List.map  Array.of_list (aux_chemins n (2*n))
    ;;

  let cree_chemin tabint =
    let n = Array.length tabint in
    let res = Array.make (2*n) Droite in
    for i=0 to n-1 do
      res.(tabint.(i)-1)<-Bas;
    done;
    res;;

  let force_brute data =
    let n = Array.length data -  1 in
    let chs = Array.of_list (chemins n)  in
    let maxr = ref 0 in
    for i=0 to (Array.length chs - 1) do
      if somme_chemin data (cree_chemin (chs.(i)))  > !maxr then maxr:= somme_chemin data (cree_chemin (chs.(i)))
    done;
    !maxr;;

  let prog_dyn data =
    let n = Array.length data.(0) in
    let s = Array.make_matrix n n 0 in
    s.(0).(0) <- data.(0).(0);
    for k=1 to n-1 do
      s.(0).(k) <- s.(0).(k-1) + data.(0).(k);
      s.(k).(0) <- s.(k-1).(0) + data.(k).(0);
    done;
    for i=1 to n-1 do
      for j=1 to n-1 do
        s.(i).(j) <- data.(i).(j) + max s.(i-1).(j) s.(i).(j-1);
      done;
    done;
    s.(n-1).(n-1);;

  let rec resolution_rec data lig col =
    if (lig=0 && col=0) then data.(0).(0)
      else if (lig =0) then data.(0).(col)+ resolution_rec data  0 (col-1) 
      else if (col =0) then data.(lig).(0)+ resolution_rec data  (lig-1) 0 else
        data.(lig).(col) + max (resolution_rec data (lig-1) col) (resolution_rec data lig (col-1));;

  let read_data filename size =
    let reader = open_in filename in
    let data = Array.make_matrix size size  0 in
    for i=0 to size-1 do
      for j=0 to size-1 do
        data.(i).(j) <- Char.code (input_char reader) - 48
    done;
  ignore (input_char reader);
  done; 
    data;;

let choix matrice lig col =
  let n = Array.length matrice in
  if (col = n-1 || (lig!=n-1 && matrice.(lig+1).(col)>=matrice.(lig).(col+1))) 
  then Bas else Droite

let naif matrice =
  let n = Array.length matrice in
  let lig = ref 0 in 
  let col = ref 0 in
  let chemin = Array.make (2*n-2) Bas  in
  for i = 0 to 2*n-3 do
    chemin.(i) <- choix matrice !lig !col;
    if chemin.(i)=Bas then  lig := !lig + 1 else col := !col +1
  done;
  chemin;;




  let () = 
  let n = int_of_string(Sys.argv.(1)) in
  let data = Array.make_matrix n n 0 in
  Random.self_init();
  for i = 0 to n-1 do
    for j=0 to n-1 do
      data.(i).(j) <- Random.int 10;
    done;
  done;
    Printf.printf "Résolution (naif) = %d\n" (somme_chemin data (naif data));
    Printf.printf "Résolution (FB) = %d\n" (force_brute data);
    Printf.printf "Résolution (Récursif) = %d\n" (resolution_rec data (n-1) (n-1));
    Printf.printf "Résolution (PD) = %d\n" (prog_dyn data);
  ;;
