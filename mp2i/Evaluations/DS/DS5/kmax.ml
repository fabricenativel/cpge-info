type tas = {mutable size : int; data : int array};;

let rec max_reste lst =
  match lst with
  | [] -> failwith "Extraction du maximum d'une liste vide"
  | h::[] -> h, []
  | h::t -> let m,r = max_reste t in if h>m then h, m::r else m, h::r;;

let rec kmax1 lst k =
  (*Renvoie les k premiers maximums de la liste lst ainsi que la liste lst privée de ces k premiers maximums*)
  if k=0 then [],lst else
    (
      let pm, reste = max_reste lst in
      let rmax, rl = kmax1 reste (k-1) in
      pm::rmax, rl);;

let rec kpremiers lst k =
  match lst,k with 
  | _,0 -> []
  | [],_ -> failwith "Pas assez d'éléments"
  | h::t, k -> h::(kpremiers t (k-1));;


let rec kmax2 lst k=
  let lst_trie = List.sort (fun n m -> m-n) lst in
  kpremiers lst_trie k;;



let heap_of_int = {size = 0; data = Array.make 1000 0}


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

let get_min theap =
  theap.data.(0);;

let get_size theap =
  theap.size;;

let cree_tas s =  {size = 0; data = Array.make s 0 };;

let kmax3 lst k=
let th = cree_tas k in
let rec aux lst =
  match lst with
  | [] -> List.init k (fun n-> extract_min th)
  | h::t -> if get_size th <k then (insert h th; aux t) else 
            (let mt = get_min th in 
            if h>mt then (ignore (extract_min th); insert h th; aux t) else (aux t))
  in
  aux lst;;
