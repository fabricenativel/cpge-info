type chemin_caillou = int array;;

let mvts = ref [];;

let caillou_vide chemin_caillou =
  let n = Array.length chemin_caillou in
  let p = ref 0 in
  for i=0 to n-1 do
    if chemin_caillou.(i) = 0 then p := i;
  done;
  !p ;;
 
let echange chemin_caillou i j =
  let copie = Array.copy chemin_caillou in
  let temp = copie.(i) in
  copie.(i) <- copie.(j);
  copie.(j) <- temp;
  copie;;

let randonneurG_avance chemin_caillou =
  let n = Array.length chemin_caillou in
  let ok = ref false in
  for i=0 to n-2 do
    if (chemin_caillou.(i)=1 && chemin_caillou.(i+1)=0) then ok := true;
  done;
  !ok;;

  let randonneurD_avance chemin_caillou =
    let n = Array.length chemin_caillou in
    let ok = ref false in
    for i=n-1 downto 1 do
      if (chemin_caillou.(i)=2 && chemin_caillou.(i-1)=0) then ok := true;
    done;
    !ok;;
  
let randonneurG_saute chemin_caillou =
    let n = Array.length chemin_caillou in
    let ok = ref false in
    for i=0 to n-3 do
      if (chemin_caillou.(i)=1 && chemin_caillou.(i+2)=0) then ok := true;
    done;
    !ok;;

let randonneurD_saute chemin_caillou =
    let n = Array.length chemin_caillou in
    let ok = ref false in
    for i=n-1 downto 2 do
      if (chemin_caillou.(i)=2 && chemin_caillou.(i-2)=0) then ok := true;
    done;
    !ok;;

let mouvement_chemin chemin_caillou =
  let p = caillou_vide chemin_caillou in
  let mvts = ref [] in
  if (randonneurG_avance chemin_caillou) then (mvts := (echange chemin_caillou p (p-1))::!mvts);
  if (randonneurG_saute chemin_caillou) then (mvts := (echange chemin_caillou p (p-2))::!mvts);
  if (randonneurD_avance chemin_caillou) then (mvts := (echange chemin_caillou p (p+1))::!mvts);
  if (randonneurD_saute chemin_caillou) then (mvts := (echange chemin_caillou p (p+2))::!mvts);
  !mvts;;

  let view a =
    let n = Array.length a in
    Printf.printf "[| "; 
    for i=0 to (n-2) do
      Printf.printf "%d; " a.(i);
    done;
    Printf.printf "%d |]\n" a.(n-1);;
  
  let rec view_all lm =
    match lm with
    | [] -> ()
    | h::t -> view h; view_all t;;

let rec init_chemin ng v1 nd v2 =
  let chemin = Array.make (ng+nd+1) 0 in
  for i = 0 to ng-1 do
    chemin.(i) <-v1 ;
  done;
  for i= ng+1 to ng+nd do
    chemin.(i) <-v2;
  done;
  chemin;;

let rec backtrack etat cible =
  if etat = cible then true else
    (try 
      let poss = (Array.of_list (mouvement_chemin etat)) in
      for i=0 to Array.length poss -1  do
        if (backtrack poss.(i) cible)  then 
          (mvts := poss.(i)::(!mvts);
          raise Exit
          )
      done;
      false
    with Exit -> true
    );;

let () = let n1 = 15 in
          let n2 = 15 in
          let deb = init_chemin n1 1 n2 2 in
         let fin = init_chemin n2 2 n1 1 in
        let res = backtrack deb fin   in
        if res then (Printf.printf "Solution trouvée\n"; view_all !mvts)
        else
          (Printf.printf "Pas de solutions\n !");;

