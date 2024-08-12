
(******************************************************)
(* Concours commun INP                                *)
(* https://www.concours-commun-inp.fr                 *)
(* CC BY-NC-SA, Novembre 2023                         *)
(* https://creativecommons.org/licenses/by-nc-sa/4.0/ *)
(******************************************************)

type graphe = int list array

(*graphes donnés en exemple*)
let g1 = [|[1;3];[];[0;1;3];[1]|]

let g2 = [|[];[0];[0;3;1];[1]|]


(*Question 1*)

(*Pour faire les tests suivants, décommenter  les prochaines lignes*)

(*
est_sommet g1 0
est_sommet g2 4
*)


(*Question 2*)



(*Question 3*)

(*Question 4*)
 let est_chemin_simple_sans_issue g liste =
    let n = Array.length g in
    let visites = Array.make false (n - 1)
    (* tableau qui enregistre les sommets déjà vus*)
    in
    let rec test_aux liste =
        (* la fonction parcourt la liste en vérifiant au fur et à mesure que tous
         les critères sont vérifiés*)
        match liste with
        | [] -> (* à completer : cas du chemin vide*)
        | [a] -> (* à compléter : vrai dans le cas où le dernier sommet n'a jamais été visité
                   et que tout ses voisins l'on été*)
        | a::b::suite ->
            begin
               (* à compléter *)
           end
        in
        test_aux liste


(*Question 5*)

let genere_chemins_simples_sans_issue (g:graphe) =
    let taille = Array.length g in
    let liste_chemins = ref [] in (*garde en mémoire les chemins déjà trouvés ceci sont gardés en sens
                                    inverse *)
    let visites = Array.make taille false in (*garde en mémoire les sommets en cours de visite *)
    let chemin_courant_envers = ref [] in (*garde en mémoire le début d'un chemin*)
    let rec profondeur s = (*trouve tous les chemins simples sans issue commençant par s*)
        if not visites.(s) then
        begin
            visites.(s) <- true ;
            chemin_courant_envers := s::(!chemin_courant_envers) ;
            let voisins_libres = (* à compléter : calcule la liste des voisins de s encore non visités*)
            in
            if voisins_libres = [] then
                begin
                (* à compléter : cas où on a trouvé un chemin simple sans issue*)
                end
            else
                begin
                (*à compléter : cas où on continue les parcours pour trouver
                d'autres chemins*)
                end ; (*fin de l'instruction conditionnelle en fonction de voisins_libres *)
            visites.(s) <- false ; (*pour revenir en arrière *)
            chemin_courant_envers := List.tl !chemin_courant_envers ; (*pour revenir en arrière,
                                     List.tl permet de priver une liste de son premier element *)
        end
    in
    for i = 0 to (taille-1) do
        profondeur i
    done ; !liste_chemins


(*Question 6*)
