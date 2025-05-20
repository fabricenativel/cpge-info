type pbsac =
  {
    pmax : int;
    objets : (int*int) list
  }

  let ex = 
    {
      pmax = 10;
      objets = [(4, 20); (5, 28); (6, 36); (7, 50)]
    }

let pb =
  {
    pmax = 40;
    objets = [(2, 90); (24, 1100); (3, 140); (17, 810); (11, 485); (14, 620); (28, 1320); (10, 440)];
  }

let ll =
  {
    pmax = 670;
    objets = [
    (78,3897);
    (38,1953);
    (79,3871);
    (91,4598);
    (14,602);
    (56,2730);
    (87,4283);
    (55,2668);
    (77,3895);
    (69,3512);
    (87,4318);
    (89,4355);
    (73,3660);
    (29,1574);
    (53,2548);
    (5,142);
    (8,430);
    (6,398);
    (38,1776);
    (82,4073);
    (88,4507);
    (57,2932);
    (10,599);
    (78,3802);
    ]
  }

let rec poids_valeur objets choix =
  match objets, choix with
  | [], [] -> (0, 0)
  | [], _ -> failwith "Erreur : choix trop long"
  | _, [] -> failwith "Erreur : choix trop court"
  | (v,p)::reste, pris::rchoix -> let vr, pr = poids_valeur reste rchoix in
    if pris then v+vr, p+pr else vr, pr;;

let rec tri objets =
  List.sort (fun (p1, v1) (p2, v2) -> if (float_of_int v1 /. float_of_int p1) > (float_of_int v2 /. float_of_int p2) then -1 else 1) objets;;

let glouton pbsac =
  let objets_tries = tri pbsac.objets in
  let rec aux objets pmax =
    match objets with
    | [] -> 0
    | (p,v)::reste -> if p<=pmax then
        let vr = aux reste (pmax - p) in
        v + vr
      else aux reste pmax
  in
  aux objets_tries pbsac.pmax;;

let dynamique pbsac =
  let rec aux objets pmax =
    match objets with
    | [] -> 0
    | (p,v)::reste ->
      if p<=pmax then
        let avec = v + aux reste (pmax-p) in
        let sans = aux reste pmax in
        max avec sans
      else aux reste pmax
  in
  aux pbsac.objets pbsac.pmax;;




