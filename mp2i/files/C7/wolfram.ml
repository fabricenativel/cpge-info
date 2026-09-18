

let init n b =
  List.init n (fun i->b);;

let display c =
  List.iter  (fun b -> if b then print_char '#' else print_char '.') c;
  print_newline();;

let rec set_cell config idx b = 
  match config with
  | [] -> failwith "Index hors de la liste"
  | h::t -> if idx=0 then b::t else h::(set_cell t (idx-1) b);;

let rule90 prev current next =
  match prev, current, next with
  | false, false, false -> false
  | false, true, false -> false
  | true, false, true -> false
  | true, true, true -> false
  | _, _, _ -> true;;


let evolution config =
  let rec aux cf prev newc =
    match cf with
    | [] -> [];
    | h::[] -> (rule90 prev h false)::newc
    | h1::h2::t -> aux (h2::t) h1 ((rule90 prev h1 h2)::newc) 
  in
  List.rev (aux config false []);;



let () =
 let c = init 20 false in
 let c = set_cell c 10 true in
 display c;
 let c = evolution c in
 display c;
 let c = evolution c in
 display c;
 let c = evolution c in
 display c;
 let c = evolution c in
 display c;
 let c = evolution c in
 display c;
 let c = evolution c in
 display c;;
