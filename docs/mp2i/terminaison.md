
{% set num = 7 %}
{% set niveau = "mp2i_s1"%}

{{ titre_chapitre(num,niveau)}}

{{ citation("Beware of bugs in the above code; I have only proved it correct, not tried it.","Donald Knuth","[Correspondance avec van Emde Boas](https://cs.stanford.edu/~knuth/faq.html)")}}

## Cours
{{ affiche_cours(num) }}

## Travaux dirigés
{{ td(num) }}

## Travaux pratiques

!!! danger
    En cas de difficultés sur les exercices de programmation proposés dans ce chapitre, revenir sur ceux du chapitre précédent d'introduction à OCaml.


{{ exo("Compilation en OCaml",[],0)}}

1. Ecrire dans  `utop` une fonction récursive `somme_carres : int -> int` qui prend en entrée un entier `n` positif et renvoie la somme des carrés des entiers de 0 à `n` (on calculera récursivement sans utiliser la formule donnant le résultat général). Utiliser cette fonction afin de calculer la somme des carrés entiers de 1 à 2024.

2. On veut maintenant, écrire une version *compilée* de ce programme, recopier dans `VS Code` le code de la fonction `somme_carres`.
Le compilateur OCaml, est `ocamlopt`, comme avec `gcc`, on peut préciser le nom de l'exécutable crée avec l'option `-o`. 


    !!! aide
        Par exemple, pour compiler le programme `hello.ml` et produire l'exécutable `hello.exe`, on écrira simplement `ocamlopt hello.ml -o hello.exe`. 

    Afin que le programme compilé affiche la somme des carrés entiers de 1 à 2024, on ajoute en fin de programme `#!ocaml let () = print_int (somme_carres 2024); print_newline () ;;`. En effet, la dernière expression ne doit être qu'un simple affichage, écrire `let () = ...` permet de vérifier que l'évaluation de l'expression (un affichage) renvoie bien `()`.


{{ exo("Fonctions anonymes",[])}}

On peut définir en OCaml des fonction anonymes, à l'aide de la syntaxe `#!ocaml fun arg1 .. argn -> expr` par exemple l'expression `#!ocaml let c = (fun n -> n*n) 10;;` s'évalue à `100` car on applique la fonction (anonyme) $n \mapsto n^2$ à 10.

1. Ecrire une fonction `entiers` qui prend en argument un entier `n` et renvoie la liste des entiers de `n` à `1`. 

2. En utilisant une fonction anonyme et `List.map` transformer cette liste en celle des inverses des entiers

3. Calculer la somme des éléments de cette liste à l'aide d'un `List.fold`

{{ exo("Creation et affichage",[])}} 

1. Ecrire en OCaml une fonction `aleatoire` qui prend en argument un entier `n` et un entier  `vmin` et `vmax` et renvoie une liste de `n` valeurs entières comprises entres 0 et `vmax`

    !!! aide
        En OCaml la fonction `Random.int` renvoie un entier au hasard entre 0 (inclus) et la valeur entière donnée en argument (exclus).

2. Ecrire en OCaml une fonction `affiche` qui prend en argument une liste d'entiers et l'affiche à la façon de `utop`. Par exemple `affiche [2; 6; 7 ]` doit afficher dans le terminal `[2; 6; 7 ]`


{{ exo("Manipulations de listes",[])}}

1. Ecrire une fonction `pair_impair : int list -> int list * int list` qui prend en argument une liste d'entiers et renvoie la liste des éléments pairs et celle des éléments impairs. Par exemple `pair_impair [2; 7; 5; 4; 11; 8];;` renvoie `([2; 4; 8], [7; 5; 11])`

2. Ecrire une fonction `entrelace : 'a list -> 'a list -> 'a list` qui "entrelace" les deux listes données en argument en piochant alternativement un élément dans chacune des deux listes (jusqu'à ce que l'une des deux soit vide), par exemple `entrelace [1; 2; 3] [2; 6; 5];;` renvoie `[1; 2; 2; 6; 3; 5]`

3. Ecrire une fonction `compression : int list -> int list` qui prend en argument une liste et renvoie cette liste dans laquelle les éléments consécutifs égaux ont été supprimés. Par exemple `compression [2; 2; 2; 1; 1; 2; 2; 2; 2]` renvoie `[2, 1, 2]`.

    

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


{{ exo("Palindrome",[])}}

En OCaml, `String.sub : string -> int -> int -> sub` prend en argument une chaine de caractère `s`  et deux entiers `n` et `m` et renvoie la renvoie la portion de `s` commençant à l'indice `n` et de longueur `m`, par exemple `#!ocaml String.sub "abcdef" 2 3 ;;` renvoie la chaine `"cde"`.

Ecrire une fonction `est_palindrome : string -> bool` qui renvoie `true` ssi la chaine fournie en argument est un palindrome

{{ exo("Code de César en OCaml",[]) }}

1. Ecrire en OCaml, une fonction `chiffre_caractere` qui prend en argument un caractère `car` et une clé `cle` et renvoie `car` chiffré en utilisant le code de cesar de de clé `c` lorsque `car` est une lettre (majuscule ou minuscule), sinon on ne fait rien et on renvoie `car`.
    
    !!! aide
        Pour faire un *pattern matching* sur les lettres minusucles on peut écrire `#!ocaml | 'a'..'z' -> `

2. Ecrire une fonction `reste` qui prend en argument une chaine et renvoie cette chaine privée de son premier caractère

3. Ecrire une fonction recursive `cesar` qui prend en argument une chaine et une clé et permet de chiffrer (ou de déchiffrer) cette chaine avec le code de César

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

{{exo("Mediane",[])}}

Cet exercice est à traité en langage C.

1. Ecrire une fonction `mediane` qui prend en argument un tableau d'entiers *supposée déjà trié* et renvoie sa [médiane](https://fr.wikipedia.org/wiki/M%C3%A9diane_(statistiques)){target=_blank}.

    !!! aide
        On prendra la valeur centrale dans le cas d'un tableau contenant un nombre impair d'éléments et la moyenne arithmétique entre les deux valeurs centrales dans le cas contraires.

2. On s'intéresse dans la suite de l'exercice à la recherche de la médiane de la fusion de deux tableaux triées, on veut donc écrire une fonction `mediane_fusion` qui prend en entrée *deux tableaux d'entiers* `tab1` (de longueur `n1`) et `tab2` (de longueur `n2`) et renvoie la médiane de la fusion.

    a. **Concaténation et tri**  
        On propose ici d'utiliser la méthode consistant à concaténer les deux tableaux `lst1` et `lst2`, à trier le résultat  puis à calculer la médiane en utilisant la fonction écrite à la question 1.Donner la complexité de cette méthode puis en proposer une implémentation sous la forme d'une fonction `med_fusion_tri`.

    b. **Parcours des deux listes**  
        On propose maintenant d'utiliser deux indices `i1` et `i2` afin de parcourir en alternance chacune des deux tableaux jusqu'à obtenir au moins la moitié des éléments. Pour cela, on initialise ces deux indices `i1` et `i2` à 0, puis à chaque étape après comparaison entre les éléments `tab1[i1]` et `tab2[i2]` on incrémente `i1` ou `i2`. Lorsque la somme des deux indices vaut la moitié de `n1+n2` cela signifie qu'on a atteint la médiane. Donner la complexité de cette méthode et en proposer une implémentation sous la forme d'une fonction `med_fusion_parcours`

    c. **Recherche dichotomique**
    
    1. On suppose qu'on a partitionné les éléments des deux listes `lst1` et `lst2` en prenant les `k` premiers éléments de `lst1` et les `l` premiers éléments de `lst2`. Donner les conditions portants sur `k` et `l` pour que cette partition représente la moitié gauche de la liste triée issue de la fusion de `lst1` et `lst2` (on pourra s'aider d'un schéma).

    2. En déduire une stratégie de recherche par dichotomie afin de déterminer la valeur correcte de `k`, nombre d'éléments à prendre dans `lst1`, la mettre en place en écrivant une fonction `med_dicho`. Quelle est la complexité de cette nouvelle méthode ?

        !!! aide
            On fera attention aux cas limites dans les indices.


{{ exo("Règle de Wolfram",[])}}

On considère une variante du [jeu de la vie](https://fr.wikipedia.org/wiki/Jeu_de_la_vie){target = _blank} se déroulant dans un tableau à une dimension. L'évolution de la case d'indice $i$ de ce tableau ne dépend que de l'état de la case d'indice $i$ et de ses voisins immédiats (donc les cases d'indices $i-1$ et $i+1$.). On donne ci-dessous l'évolution de la case centrale en fonction de l'état de ces 3 cases en notant "`#`" une case vivante et "`.`" une case morte 

* `...` $\rightarrow$ `.` (si les 3 cases sont vides, la case centrale reste vide)
* `..#` $\rightarrow$ `#`
* `.#.` $\rightarrow$ `.`
* `.##` $\rightarrow$ `#`
* `#..` $\rightarrow$ `#`
* `#.#` $\rightarrow$ `.`
* `##.` $\rightarrow$ `#`
* `###` $\rightarrow$ `.`


D'autre part on considère ici un tableau *fini* de $N$ cases et on considère que la voisine de gauche de la case d'indice 0 ainsi que la voisine de droite de la case d'indice $N-1$ sont toujours des cellules mortes.
On donne ci-dessous un exemple d'évolution avec $N=10$
{{make_jeuvie(["...##.####"],[])}} evolue en {{make_jeuvie(["..###.#..#"],[])}}

1. Implémentation en langage C

    Afin de représenter une configuration d'un jeu de la vie, on propose le type structuré suivant :

    ```c
        --8<-- "C7/wolfram.c:5:10"
    ```

    où le champ `size` correspond au nombre de cellules présentes dans la configuration et le champ `cells` est un pointeur qui sera initialisé vers une zone mémoire de `size` booléens.

1. Ecrire les fonctions `config init(int size, bool state)` et `void display(config c)` qui permettent respectivement de créer une configuration de `size` avec la valeur `state` pour toutes ces cellules et d'afficher une configuration (on utilisera `.` pour une cellule morte et `#` pour une cellule vivante)

2. Ecrire la fonction `void evolution(config *c)` qui modifie une configuration en la faisant évoluer une fois avec les règles données en introduction. On pourra s'aider d'une fonction annexe `bool rule90(bool prev, bool current, bool next)` qui renvoie l'état de la cellule centrale pour le triplet de cellule `prev,current,next`. 

3. Pour $N=30$ et pour le tableau initial représenté par "...............#.............." (toutes les cases sont mortes sauf la case d'indice 15) faire afficher les 100 premières évolutions successives.

    !!! aide
        Les premières lignes sont :
        ```
        ...............#..............
        ..............#.#.............
        .............#...#............
        ............#.#.#.#...........
        ...........#.......#..........
        ..........#.#.....#.#.........
        .........#...#...#...#........
        ........#.#.#.#.#.#.#.#.......
        .......#...............#......
        ......#.#.............#.#.....
        .....#...#...........#...#....
        ....#.#.#.#.........#.#.#.#...
        ```

3. La règle d'évolution donnée en introduction est un cas particulier des [règles de Wolfram](https://en.wikipedia.org/wiki/Elementary_cellular_automaton){target=_blank} et puisque l'évolution d'une case ne dépend que de l'état de ses voisines immédiates, il existe en réalité **256** règles possibles. Par exemple, puisque $177 = (10110001)_2$, la règle 177 correspond aux évolutions suivantes :
    * `...` $\rightarrow$ `#` 
    * `..#` $\rightarrow$ `.`
    * `.#.` $\rightarrow$ `.`
    * `.##` $\rightarrow$ `.`
    * `#..` $\rightarrow$ `#`
    * `#.#` $\rightarrow$ `#`
    * `##.` $\rightarrow$ `.`
    * `###` $\rightarrow$ `#`

    C'est à dire que le bit de rang k ($1 \leqslant k \leqslant 8$ ) de l'écriture binaire de 177 correspond à l'évolution de la configuration de l'écriture de $k$ en base 2.
    Ecrire une fonction `bool rule(bool prev, bool current, bool next, int rnumber)` qui pour un numéro de règle `rnumber` renvoie l'évolution de la case centrale du triplet de cellule `prev, current, next`.

4. Tester votre programme en faisant évoluer une configuration initiale de 500 cellules toutes mortes sauf celle d'indice 1 qui est vivante en utilisant la règle 60. Quel est le nombre de cellule vivantes après 500 évolutions  ? {{check_reponse("63")}} 

5. Reprendre entièrement l'exercice précédent en OCaml en représentant une configuration par le type `bool list`.

## Humour d'informaticien
![BinarySearch](./Images/C7/search.png){.imgcentre width=500px}
