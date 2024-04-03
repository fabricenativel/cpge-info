type chemin_caillou = int array;;

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

let rec add x llist =
  match llist with
  | [] -> []
  | h::t -> (x::h)::(add x t);;

let passage ng nd =
  let debut = init_chemin ng 1 nd 2 in
  let fin = init_chemin nd 2 ng 1 in
  let rec cherche position mvts =
    match mvts with
    | [] -> if position=fin then [[position]] else []
    | mvt::suite -> let cs = cherche mvt (mouvement_chemin mvt) in (add position cs) @ cherche position suite 
    in
    cherche debut (mouvement_chemin debut);;

let () = let ex = passage 3 3 in view_all (List.hd ex);;
