type objet = {nom : string; poids : float; valeur : float}

let objets = [ {nom="hamburger"; poids =0.3; valeur = 180.};
  {nom="marteau"; poids =4.1; valeur = 2050.};
  {nom="parapluie"; poids =0.6; valeur = 280.};
  {nom="ballon"; poids =1.7; valeur = 810.};
  {nom="clé"; poids =2.; valeur = 990.};
  {nom="sapin"; poids =2.9; valeur = 1275.};
  {nom="chapeau"; poids =5.7; valeur = 2570.};
  {nom="guitare"; poids =2.1; valeur = 920.}
];;

let sac_glouton objets pmax =
  let objets_tries = List.sort (fun a b -> compare (a.valeur /. a.poids) (b.valeur /. b.poids)) objets in
  let rec remplir sac objets_restants pmax =
    match objets_restants with
    | [] -> sac
    | obj::reste -> if obj.poids <= pmax then
                      remplir (obj::sac) reste (pmax -. obj.poids)
                    else
                      remplir sac reste pmax in
    remplir [] objets_tries pmax;;

let () = 
      let res = sac_glouton objets 8. in
      List.iter (fun obj -> Printf.printf "%s\n" obj.nom) res;;

