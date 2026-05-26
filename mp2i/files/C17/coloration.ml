type graphe = {
  taille : int;
  ladj : int list array};;

let valide gr col = 
 let n = gr.taille in
 let rec aux lst i =
  match lst with
  | [] -> true
  | h::t -> col.(h) <> col.(i) && aux t i
 in
 try  
 for i=0  to (n-1) do
    if not (aux gr.ladj.(i) i) then raise Exit
  done;
  true;
with Exit -> false;;

let complet n =
  {taille = n;
   ladj = Array.init n (fun i -> List.init (n-1) (fun j -> if j < i then j else j+1))};;
  

let plus_petit disponible =
  let r = ref (-1) in
  try
    for i=0 to Array.length disponible - 1 do
      if disponible.(i) then (r :=i; raise Exit)
    done;
    !r;
  with Exit -> !r;;

let glouton gr =
  let n = gr.taille in
  let col = Array.make n  0 in
  for i=0 to n-1 do
    let disponible = Array.init n (fun j -> true) in
    List.iter (fun j -> if col.(j)!=0 then disponible.(col.(j)-1) <- false) gr.ladj.(i);
    col.(i) <- (plus_petit disponible)+1;
  done;
  col;;

let lire_graph fname  n =
    let gr = {taille = n; ladj = Array.make n [] } in
    let reader = open_in fname in
    for i=0 to 999 do
      let arc=String.split_on_char ' ' (input_line reader) in
      let a = int_of_string (List.hd arc) in
      let b = int_of_string (List.hd (List.tl arc)) in
      gr.ladj.(a) <- b::gr.ladj.(a);
      gr.ladj.(b) <- a::gr.ladj.(b);
    done;
    for i=0 to 99 do 
      gr.ladj.(i) <- List.sort compare gr.ladj.(i);
    done;
    gr;;
    