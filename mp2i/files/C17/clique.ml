type graphe = {
  taille : int;
  ladj : int list array};;


let rec etend_clique gr clique candidats =
  match candidats with
  | [] -> []
  | c::t ->
      if List.for_all (fun x -> List.mem c gr.ladj.(x)) clique then
        (c::clique)::(etend_clique gr clique t) else (etend_clique gr clique t);;

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
    