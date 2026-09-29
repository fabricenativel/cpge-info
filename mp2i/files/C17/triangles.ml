type graphe = {
  taille : int;
  ladj : int list array};;

let complet n =
  {taille = n;
   ladj = Array.init n (fun i -> List.init (n-1) (fun j -> if j < i then j else j+1))};;

let triangle1 gr = 
  let n = gr.taille in
  let tr = ref [] in
  for i=0 to n-1 do
    for j=i+1 to n-1 do
      for k=j+1 to n-1 do
        if List.mem k gr.ladj.(i) && List.mem j gr.ladj.(i) && List.mem k gr.ladj.(j) then
          tr := (i,j,k) :: !tr
      done;
    done;
  done;
  !tr;;

let rec sousliste lst n =
  match lst, n with
  | [], 0 -> [[]]
  | [], _ -> []
  | h::t, n ->
      let avec_h = List.map (fun l -> h::l) (sousliste t (n-1)) in
      let sans_h = sousliste t n in
      avec_h @ sans_h;;

      let triangle2 gr =
  let tr = List.map (function [i;j;k]->(i,j,k) |_ -> failwith "Erreur") (sousliste (List.init gr.taille (fun i -> i)) 3) in
  List.filter (function (i,j,k) ->
    List.mem k gr.ladj.(i) && List.mem j gr.ladj.(k) && List.mem i gr.ladj.(j)) tr;;
  
let lire_graph fname  n =
    let gr = {taille = n; ladj = Array.make n [] } in
    let reader = open_in fname in
    for i=0 to 999 do
      let arc=String.split_on_char ' ' (input_line reader) in
      let a = int_of_string (List.hd arc) in
      let b = int_of_string (List.hd (List.tl arc)) in
      if a<b then 
      gr.ladj.(a) <- b::gr.ladj.(a)
      else
      gr.ladj.(b) <- a::gr.ladj.(b);
    done;
    for i=0 to 99 do 
      gr.ladj.(i) <- List.sort compare gr.ladj.(i);
    done;
    gr;;


let rec intersection l1 l2 ex1 ex2 =
  match l1, l2 with
  | l1, [] -> []
  | [], l2 -> []
  | h1::t1, h2::t2 -> if h1=h2 && h1!=ex1 && h1!=ex2 then h1::intersection t1 t2 ex1 ex2 else
                      if h1<h2 then intersection t1 l2 ex1 ex2 else intersection l1 t2 ex1 ex2;;        

let  fait_triangle gr s =
  let rec aux lst =
  match lst with
  | [] -> []
  | h::t -> List.map (fun x-> (s,h,x)) (intersection gr.ladj.(s) gr.ladj.(h) s h) @ aux  t in
  aux gr.ladj.(s);;





let triangle3 gr =
  let n = gr.taille in
  let tr = ref [] in
  for i=0 to n-1 do
    tr := (fait_triangle gr i) @ (!tr);
  done;
  !tr;;


let cm elt lst =
  List.fold_left (fun acc x -> if x=elt then acc+1 else acc) 0 lst;;