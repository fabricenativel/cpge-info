# Exercice 3
## Nouvel enoncé :
On dit qu’un tableau tab de taille n est autoréférent si pour tout entier i ∈ [[0 ... n-1]], tab.(i) est le nombre d’occurences de i dans tab. Par exemple, le tableau ex=[| 1; 2; 1; 0 |] est autoréférent, en effet :
— ex.(0) = 1 et 0 apparaît bien une fois dans le tableau
— ex.(1) = 2 et 1 apparaît bien deux fois dans le tableau
— ex.(2) = 1 et 3 apparaît bien une fois dans le tableau
— ex.(3) = 0 et 3 n’apparaît pas dans le tableau
1. Justifier rapidement que si tab est un tableau autoréférent de taille n alors les éléments de tab sont tous inférieurs ou égaux à n
2. Montrer que pour n ∈ [[1...3]], il n’existe aucun tableau auto référent de taille n.
3. Déterminer un autre tableau autoréférent de taille 4 que celui donné en exemple.
4. Soit n≥ 7, on définit le tableau tab de taille n par :
Soit n≥ 7, on définit le tableau tab de taille n par :
— tab.(0) = n-4
— tab.(1) = 2
— tab.(2) = 1
— tab.(n-4) = 1
— tab.(i) = 0 si i ∈/ {0, 1, 2, n − 4}
Prouver que tab est autoréférent
5. Montrer que si tab est un tableau autoréférent de taille n alors la somme des éléments de tab vaut n.
La réciproque est-elle vraie ?
6. Ecrire en ocmal une fonction occurences : int array -> int array prenant en paramètre tab un array de longueur n constitués d'entiers inférieurs ou égaux à n  et renvoyant un tableau constitué des occurences des indices i dans tab pour $\forall i; 0 \leq i \leq n$ . On attend une complexité en O(n) où n est la taille du tableau.
7. Ecrire en OCaml une fonction est_autoreferent int array -> bool qui prend en argument un tableau d’entiers et renvoie true si ce tableau est autoréférent et false sinon.
8. En force brute, trouver tous les tableaux autoréférents de taille k pour $k \leq 7$.
On affichera au fur et à mesure les solutions trouvés.

On cherche maintenant à construire les tableaux autoréférents de taille n en utilisant un algorithme de recherche par retour sur trace (backtracking ) qui valide une solution partielle construite jusqu’à un index idx donné,
9. Proposer une fonction valide_partiel : int array -> int -> bool testant si le nombre d'occurence des indices i ne dépasse pas déjà leur prédiction pour tout i $\leq k$. 
10. Proposer une implémentation avec retour sur trace avec éventuellents des améliorations de la fonction de validation partielle en utilisant les résultats établis sur les tableaux autoréférents aux questions précédentes pour aller le plus loin possible...








1. 
Soit tab un tableau d'entiers de taille n.
Par l'absurde, si tab admet un élèment h ; h > n alors h figurent h fois dans tab ce qui est impossible!
Donc si tab est un tableau autoréférent de taille n alors les éléments de tab sont
tous inférieurs ou égaux à n

2. Pour $1 \leq n  \leq 3$, 
Si n = 1, la propriété précedante impose tab = [0] ou tab = [1]. Donc aucun tab autoinférent.
Si n = 2, si le premier élément de tab vaut 0, c'est contradictoire, 
 il y forcément un 0 à la deuxième place. tab = [1,0] ou tab = [2,0] sont tous deux impossible. Donc aucun tab autoinférent.
Si n = 3, si le premier élément de tab vaut 0, c'est contradictoire,
Donc tab s'écrit :
-[1,x,y] : Tab[0]=1 impose tab[1]>0, ce qui impose tab[2]=0 alors tab = [1,x,0] si x =1,2,3 ne conviennent pas.
-[2,x,y] : tab = [2,0,0] imp 
-[3,x,y] : tab = [3,0,0] imp
 Donc aucun tab autoinférent.

3.
[1; 2; 1; 0] est autoinférent.
[2; 0; 2; 0] est aussi autoinférent.

4.
Soit n≥ 7, on définit le tableau tab de taille n par :
— tab.(0) = n-4
— tab.(1) = 2
— tab.(2) = 1
— tab.(n-4) = 1
— tab.(i) = 0 si i ∈/ {0, 1, 2, n − 4}

Montrons que tab est autoréférent :
Par construction, tab.(i) = 0 si i ∈/ {0, 1, 2, n − 4} donc tab.(0) = n-4.
Il reste donc 3 indices à vérifier : {1,2,n-4} qui sont par construction bien défini.

5. 
Montrons que si tab est un tableau autoréférent de taille n alors la somme des éléments de tab vaut n.

La somme vaut tab[0]+tab[1]+tab[2]+tab[n-4] = n-4  + 2 + 1+ 2 = n

La réciproque est fausse : [1,1,1]  taille 3 et somme 3 et pourtant non autoinférent.

6..10
```ocaml

let occurences tab =
  let n = Array.length tab in
  let cpt = Array.make n 0 in
  for i=0 to n -1 do
      cpt.(tab.(i)) <- cpt.(tab.(i)) + 1
    done;
  cpt;;
  
let est_autoreferent tab =
  let n = Array.length tab in
  let test = occurences tab in
  try
  for i=0 to n-1 do
    if test.(i) <> tab.(i) then raise Exit;
  done;
  true
  with exit -> false;
;;

let brute k =
  let tab = Array.make k 0 in
  let rec backtrac tab k =
    let n = Array.length tab in
    try
    for i = 0 to n-1 do
      tab.(k) <- i ;
      if k<n-1 then aux tab (k+1) else if est_autoreferent tab then raise Exit;
    done;
    with exit -> for i = 0 to n-1 do print_int (tab.(i))  done; Printf.printf " - " in
  backtrac tab 0;;

let partiel t k =
  let n = Array.length t in
  if somme_partiel t k > n then false else
    let cpt = Array.make n 0 in
    try
      for i=0 to k-1 do
        cpt.(t.(i)) <- cpt.(t.(i)) + 1
      done;
      for i=0 to k-1 do
        if cpt.(i) > t.(i) then raise Exit;
      done;
      true
    with exit -> false;
;;

let recherche k =
  let tab = Array.make k 0 in
  let rec backtrac tab k = 
    let n = Array.length tab in
    try
    for i = 0 to n-1 do
      tab.(k) <- i ;
      if partiel tab k && k<n-1 then aux tab (k+1); 
      if k == n-1 && est_autoreferent tab then raise Exit;
    done;
    with exit -> for i = 0 to n-1 do print_int (tab.(i))  done; Printf.printf " - " in
  backtrac tab 0;;
```

