let valide_liste seq target =
  let rec valid_aux seq target vmin vmax =
    match seq with
    | [] -> false
    | [target] -> true
    | hseq::tseq -> vmin < hseq && hseq<vmax && if hseq<target then valid_aux tseq target hseq vmax else  valid_aux tseq target vmin hseq
  in
  valid_aux seq target 0 999;;

let valide_tableau tseq =
  let target = tseq.(Array.length tseq -1) in
  let vmin = ref 0 in 
  let vmax = ref 999 in
  let error = ref false in
  let index = ref 0 in
  while not !error && !index < (Array.length tseq -1) do
    if tseq.(!index) < !vmin || tseq.(!index) > !vmax then error := true else
      if tseq.(!index) > target then vmax := tseq.(!index) else vmin := tseq.(!index);
    index := !index +1;
    done;
  not !error;;


let tri tseq target =
  let rec tri_aux tseq inf sup target =
  match tseq with
  | [] -> (List.rev inf) @ sup
  | h::t -> if h<target then tri_aux t (h::inf) sup target else tri_aux t inf (h::sup) target in
  tri_aux tseq [] [] target;;

let tri2 tseq target =
  List.filter (fun x -> x<target) tseq @ List.rev (List.filter (fun x -> x>=target) tseq)


let () = let t =[| 
        [487; 503; 911; 954; 499; 651; 672; 668; 666];
			  [951; 812; 803; 798; 751; 670; 589; 652; 653; 666];
			  [985; 112; 251; 306; 444; 503; 574; 602; 605; 681; 666];
			  [844; 511; 845; 603; 702; 651; 699; 660; 670; 665; 666];
			  [303; 404; 541; 752; 749; 742; 592; 603; 666] |] in
        for i=0 to 4 do
          Printf.printf "Valide : %b\n" (valide_liste t.(i) 666);
          ignore (List.map (fun x -> print_int x; print_string "; ") (tri t.(i) 666));
          print_newline ();
        done
        ;;
