
{% set num = 7 %}
{% set niveau = "mp2i_s1"%}

{{ titre_chapitre(num,niveau)}}

{{ citation("Beware of bugs in the above code; I have only proved it correct, not tried it.","Donald Knuth","[Correspondance avec van Emde Boas](https://cs.stanford.edu/~knuth/faq.html)")}}

## Cours
{{ cours(num) }}

## Travaux dirigés
{{ td(num) }}

## Travaux pratiques

!!! danger
    En cas de difficultés sur les exercices de programmation proposés dans ce chapitre, revenir sur ceux du chapitre précédent d'introduction à OCaml.

{{ exo("Fonctions anonymes",[],0)}}

On peut définir en OCaml des fonction anonymes, à l'aide de la syntaxe `#!ocaml fun arg1 .. argn -> expr` par exemple l'expression `#!ocaml let c = (fun n -> n*n) 10;;` s'évalue à `100` car on applique la fonction (anonyme) $n \mapsto n^2$ à 10.

1. Ecrire une fonction `entiers` qui prend en argument un entier `n` et renvoie la liste des entiers de `n` à `1`. 

2. En utilisant une fonction anonyme et `List.map` transformer cette liste en celle des inverses des entiers

3. Calculer la somme des éléments de cette liste à l'aide d'un `List.fold`

{{ exo("Creation et affichage",[])}} 

1. Ecrire en OCaml une fonction `aleatoire` qui prend en argument un entier `n` et un entier  `vmin` et `vmax` et renvoie une liste de `n` valeurs entières comprises entres 0 et `vmax`

    !!! aide
        En OCaml la fonction `Random.int` renvoie un entier au hasard entre 0 (inclus) et la valeur entière donnée en argument (exclus).

2. Ecrire en OCaml une fonction `affiche` qui prend en argument une liste d'entiers et l'affiche à la façon de `utop`. Par exemple `affiche [2; 6; 7 ]` doit afficher dans le terminal `[2; 6; 7 ]`

{{ exo("Tri par insertion en OCaml",[])}}

1. Ecrire en OCaml une fonction `insertion` qui prend en argument un entier `n` et une liste *triée* d'entiers `entiers` et renvoie la liste dans laquelle `n` a été inséré à la bonne position dans `entiers`. Par exemple `insertion 3 [2; 7; 8 ]` doit renvoyer `|2; 3; 7; 8]`

2. En déduire une fonction `tri_insertion` qui prend en argument une liste d'entiers et renvoie cette liste triée en utilisant l'algorithme du tri par insertion.

3. Tester en utilisant les fonctions de l'exercice **1**.


{{ exo("Tri par sélection en OCaml",[])}}

1. Ecrire en OCaml une fonction `min_reste` qui prend en argument une liste `entiers` et renvoie un couple composé du minimum de la liste `entiers` et de la liste `entiers` privé d'*une* seule occurrence du minimum. Par exemple : 
    * `min_reste [6; 7; 3; 8; 10]` doit renvoyer `3, [6; 7; 8; 10]`
    * `min_reste [2; 6; 1; 3; 1; 5]` doit renvoyer `1, [2; 6; 3; 1; 5]`

2. En déduire une fonction `tri_selection` qui prend en argument une liste `entiers` et renvoie cette liste triée dans l'ordre croissant en utilisant l'algorithme du tri par sélection.

3. Tester en utilisant les fonctions de l'exercice **1**.


{{ exo("Code de César en OCaml",[]) }}

1. Ecrire en OCaml, une fonction `chiffre_caractere` qui prend en argument un caractère `car` et une clé `cle` et renvoie `car` chiffré en utilisant le code de cesar de de clé `c` lorsque `car` est une lettre (majuscule ou minuscule), sinon on ne fait rien et on renvoie `car`.
    
    !!! aide
        Pour faire un *pattern matching* sur les lettres minusucles on peut écrire `#!ocaml | 'a'..'z' -> `

2. Ecrire une fonction `reste` qui prend en argument une chaine et renvoie cette chaine privée de son premier caractère

3. Ecrire une fonction recursive `cesar` qui prend en argument une chaine et une clé et permet de chiffrer (ou de déchiffre) cette chaine avec le code de César

4. La fonction `String.map` permet d'appliquer une fonction à chaque caractère d'une chaine à la façon de `List.map`. Proposer une version du chiffrement de César utilisant `String.map`


{{ exo("Tri fusion en OCaml",[]) }}

1. Ecrire une fonction `separe` en OCaml qui prend en argument une liste `l` et renvoie deux listes contenant chacune la moitié (à une unité près) des éléments de `l`

    !!! aide
        On pourra utiliser un *pattern matching* sur le motif `h1::h2::t` et mettre `h1` dans la première liste et `h2` dans la seconde

2. Ecrire une fonction `fusion` qui prend en argument deux listes *déjà triées* et renvoie la fusion de ces deux listes.

3. Ecrire le `tri_fusion` en OCaml à l'aide de ces deux listes

4. Le *tri rapide* est similaire au tri fusion mais pour séparer les deux listes, on utilise un *pivot* choisit au hasard dans la liste et on sépare ensuite la liste entre les éléments inférieurs au pivot et les éléments supérieur au pivot. Implémenter en OCaml ce nouvel algorithme de tri

5. Quel est la complexité de ce nouvel algorithme dans le pire des cas ?

6. Effectuer des mesures de temps de calcul pour ce nouvel algorithme. Commenter


## Humour d'informaticien
![BinarySearch](./Images/C7/search.png){.imgcentre width=500px}
