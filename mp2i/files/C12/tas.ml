type heap_int = {mutable size : int; data : int array};;

(* --8<-- [start:def_tas] *)
type 'a heap = {mutable size : int; data : 'a array};;
(* --8<-- [end:def_tas] *)

(* --8<-- [start:cree_tas] *)
let heap_of_int = {size = 0; data = Array.make 1000 0}
let heap_of_char = {size = 0; data = Array.make 1000 ' '}
(* --8<-- [end:cree_tas] *)

let leftchild i n = let s = 2*i+1 in if s<n then s else -1

let parent i = let p = (i-1)/2 in if i<>0 then p else -1

let swap tab i j =
  let temp = tab.(i) in
  tab.(i) <- tab.(j);
  tab.(j) <- temp;;

let insert v heap =
  let cp = ref heap.size in
  heap.data.(!cp) <- v;
  while (parent !cp) <> (-1)  && (heap.data.(parent !cp) > heap.data.(!cp)) do
      swap heap.data !cp (parent !cp);
      cp := parent !cp;
  done;
  heap.size <- heap.size + 1;;

let affiche heap =
  Printf.printf "[%d] -> " heap.size;
  for i =0 to heap.size-1 do
    Printf.printf "%d; " heap.data.(i);
  done;
  print_newline();;

(* --8<-- [start:sift_down] *)
  let extract_min theap =
    let minv = theap.data.(0) in
    theap.data.(0) <- theap.data.(theap.size-1);
    let cp = ref 0 in
    let lc = ref (leftchild !cp theap.size) in
    while ( !lc <> (-1) && (theap.data.(!lc) < theap.data.(!cp) || (!lc+1 < theap.size && theap.data.(!lc+1) < theap.data.(!cp)))) do
      if (!lc+1 >= theap.size || theap.data.(!lc)<theap.data.(!lc+1)) then
       (swap theap.data !cp !lc;
        cp := !lc)
      else  
        (swap theap.data !cp (!lc+1);
        cp := !lc+1);
      lc := leftchild !cp theap.size;
    done;
    theap.size <- theap.size -1;
    minv;;
(* --8<-- [end:sift_down] *)

  
let () = 
  let theap = {size = 0; data = Array.make 100 0 } in
  Random.self_init();
  for i = 1 to 20 do
    insert (Random.int 100) theap;
  done;
  affiche theap;
  let sorted = Array.make (theap.size) 0 in
  for i = 0 to 19 do
    sorted.(i) <- extract_min theap;
    Printf.printf "%d; " sorted.(i)
  done;
  print_newline ();;
  
  
