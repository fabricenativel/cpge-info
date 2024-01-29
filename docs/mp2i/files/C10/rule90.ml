open Hashtbl

let my_ht = Hashtbl.create 100000;;
let size = 30;;

let evolve pattern =
  match pattern with
  | "###" -> '.'
  | "##." -> '#'
  | "#.#" -> '.'
  | "#.." -> '#'
  | ".##" -> '#'
  | ".#." -> '.'
  | "..#" -> '#'
  | "..." -> '.'
  | _ -> failwith "Pattern non reconnu"

let next old =
  let ns = Array.make size '.' in
  ns.(0) <- evolve ("." ^ (String.make 1 old.[0]) ^ (String.make 1 old.[1]));
  ns.(size-1) <- evolve ((String.make 1 old.[size-2]) ^ (String.make 1 old.[size-1]) ^ ".");
  for i=2 to (size-2) do
    ns.(i) <- evolve ((String.make 1 old.[i-1]) ^ (String.make 1 old.[i])  ^ (String.make 1 old.[i+1]));
  done;
  String.of_seq (Array.to_seq ns);;

let () =
let st = ref "...............#.............." in
let cycle = ref false in
let step = ref 0 in
while (!cycle=false) do
  (
    if (Hashtbl.mem my_ht !st) then 
      (cycle := true;
        Printf.printf "Motif déjà rencontré : %s" !st; 
      )
   else (Hashtbl.add my_ht !st 0);
    st := next (!st);
    Printf.printf "%s\n" !st;
    step := !step +1;
  );
done;
Printf.printf "Cycle détecté après %d itérations" (!step-1);
;;
