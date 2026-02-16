type 'a heap = {mutable size : int; data : 'a array};;

let plus_petit a b =
  let k1,v1 = a in
  let k2,v2 = b in
  k1 < k2;;

let make_sorted_list size vmax =
  let lst = List.init size (fun i -> Random.int vmax) in
  List.sort (fun x y -> if x<y then -1 else (if x=y then 0 else 1)) lst;;

let make_array_sorted_list size lsize vmax =
  Array.init size (fun i -> make_sorted_list lsize vmax);;


let leftchild i n = let s = 2*i+1 in if s<n then s else -1

let parent i = let p = (i-1)/2 in if i<>0 then p else -1

let swap tab i j =
  let temp = tab.(i) in
  tab.(i) <- tab.(j);
  tab.(j) <- temp;;

let est_vide heap =
  heap.size == 0;;

let insert v heap =
  let cp = ref heap.size in
  heap.data.(!cp) <- v;
  while (parent !cp) <> (-1)  && (plus_petit heap.data.(!cp) heap.data.(parent !cp)) do
      swap heap.data !cp (parent !cp);
      cp := parent !cp;
  done;
  heap.size <- heap.size + 1;;


  let extract_min theap =
    let minv = theap.data.(0) in
    theap.data.(0) <- theap.data.(theap.size-1);
    let cp = ref 0 in
    let lc = ref (leftchild !cp theap.size) in
    while ( !lc <> (-1) && (plus_petit theap.data.(!lc) theap.data.(!cp) || (!lc+1 < theap.size && plus_petit theap.data.(!lc+1)  theap.data.(!cp)))) do
      if (!lc+1 >= theap.size || plus_petit theap.data.(!lc) theap.data.(!lc+1)) then
       (swap theap.data !cp !lc;
        cp := !lc)
      else  
        (swap theap.data !cp (!lc+1);
        cp := !lc+1);
      lc := leftchild !cp theap.size;
    done;
    theap.size <- theap.size -1;
    minv;;

let affiche_liste lst=
  Printf.printf "[";
  List.iter (fun i -> Printf.printf "%d " i) lst;
  Printf.printf "]\n";;


let affiche heap =
  Printf.printf "[%d] -> " heap.size;
  for i =0 to heap.size-1 do
    Printf.printf "(%d,%d); " (fst heap.data.(i)) (snd heap.data.(i));
  done;
  print_newline();;

    let () =
    if Array.length (Sys.argv) != 4 then
      (Printf.printf "Utilisation = %s <nombre de liste> <taille de chaque liste> <valeur maximale dans les listes>\n" Sys.argv.(0); 
      failwith "Erreur !")
    else
      ( let nblist = int_of_string (Sys.argv.(1)) in
        let lsize = int_of_string (Sys.argv.(2)) in
        let vmax = int_of_string (Sys.argv.(3)) in
        let asl = make_array_sorted_list nblist lsize vmax in
        let mh = {size = 0; data = Array.make 1000 (0,0)} in
        for i=0 to nblist-1 do
          Printf.printf "%d -> " i;
          affiche_liste asl.(i);
          insert (List.hd asl.(i),i) mh;
          asl.(i) <- List.tl asl.(i);
        done;
        let res = ref [] in
        while not (est_vide mh) do
          let valeur,num = extract_min mh in
          res := valeur::!res;
          if (List.length asl.(num) != 0) then
            (insert (List.hd asl.(num),num) mh;
            asl.(num) <- List.tl asl.(num));
          done;
        List.iter (fun x -> Printf.printf "%d " x) !res;
        print_newline ()
      );;



          



