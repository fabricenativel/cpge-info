type wdgraphe = {
  taille : int; 
  madj : float array array};;

let cree_graphe n =
  let gr = {taille = n; madj = Array.make_matrix (n+1) (n+1) infinity} in
  for  i=1 to n do
    gr.madj.(i).(i) <- 0.0;
  done;
  gr
;;

let rec ajoute_aretes graphe lar =
  match lar with
  | [] -> ()
  | (i,j,w)::t -> graphe.madj.(i).(j) <- w ; ajoute_aretes graphe t;;


  let affiche res =
    let n = Array.length res in
    for i=1 to n-1 do
      for j=1 to n-1 do
        if res.(i).(j)<>infinity then (Printf.printf " %f " res.(i).(j);) else (Printf.printf " *        ";)
      done;
      print_newline();
    done;
    print_endline "------------------";

  ;;

let fw wg =
  let n = wg.taille in
  let m = Array.make_matrix (n+1) (n+1) infinity in
  for i=1 to n do
    for j=1 to n do
      m.(i).(j) <- wg.madj.(i).(j);
    done;
  done;
   for k = 1 to n do
    for i=1 to n do
      for j=1 to n do
        let x = m.(i).(k) +. m.(k).(j) in
        if x <m.(i).(j)   then m.(i).(j) <- x;
      done;
    done;
  done; 
  m;;


let () =  let test = cree_graphe 4 in
          ajoute_aretes test [(1,3,-2.); (2,1,4.); (2,3,3.); (3, 4, 2.); (4,2,-1.)];
          affiche test.madj;
          let res = fw test in
          affiche res;
          
        ;;
