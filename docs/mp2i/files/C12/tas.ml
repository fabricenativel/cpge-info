type heap_int = {mutable size : int; data : int array};;

type 'a heap = {mutable size : int; data : 'a array};;

let heap_of_int = {size = 0; data = Array.make 1000 0}
let heap_of_char = {size = 0; data = Array.make 1000 ' '}

let leftchild i n = let s = 2*i+1 in if s<n then s else -1

let parent i = let p = (i-1)/2 in if p>0 then p else -1

let insert v heap =
  heap.data.(heap.size) <- v;
  let i = ref heap.size in
  let temp =ref 0 in
  while (parent !i) <> (-1)  && (heap.data.(parent !i) > heap.data.(!i)) do
      temp :=  heap.data.(!i);
      heap.data.(!i) <- heap.data.(parent !i);
      heap.data.(parent !i) <- !temp;
      i := parent !i;
  done;
  heap.size <- heap.size + 1;;

let affiche heap =
  for i =0 to heap.size-1 do
    Printf.printf "%d; " heap.data.(i);
  done;
  print_newline();;


  
let () = 
  let theap = {size = 0; data = Array.make 100 0 } in
  for i = 1 to 20 do
    insert i theap;
  done;
  affiche theap;;
