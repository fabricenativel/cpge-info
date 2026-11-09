type forme =  Carre of float | Cercle of float;;

let pi = 3.1415;;

let surface f =
  match f with
  | Carre  c -> c*.c 
  | Cercle r -> pi*.r*.r;;

let () = print_float (surface (Carre 5.));;