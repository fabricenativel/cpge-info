type 'a file = {
  capacity : int; 
  data : 'a array;
  mutable size : int;
  mutable next : int 
  }

let enfiler file elt =
  if file.capacity=file.size then false else
    (
      file.data.((file.next + file.size) mod file.capacity) <- elt;
      file.size <- file.size +1;
      true
    )

let defiler file =
  if file.size = 0 then failwith "File vide" else
    file.size <- file.size - 1;
    file.next <- file.next+1;
    file.data.(file.next-1);;

let creer_file cap = {capacity = cap; data = Array.make cap 0; size = 0; next = 0};;


