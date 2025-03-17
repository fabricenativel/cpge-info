hide: - navigation  in index.md

{{dm(3,"Trix radix")}} 

## Tris stables

Etant donné un ensemble $X$ de valeurs à trier, une *clé* de tri est une application  $C : X^2 \mapsto \mathbb{N}$ telle que :
    
* $C(x,y) < 0$ lorsque $x$ doit être placé avant $y$ ($x$ est plus petit que $y$ pour l'ordre considéré)
* $C(x,y) > 0$ lorsque $x$ doit être placé après $y$ ($x$ est plus petit que $y$ pour l'ordre considéré)
* $C(x,y) = 0$ lorsque $x$ peut indifférent être placé avant ou après $y$ ($x$ et $y$ sont "égaux" pour l'odre considéré).

!!! Exemple
    Lorsqu'on trie une listes de points de du plan par abscisse croissante, on peut choisir comme clé de tri la fonction qui associe à deux points la différence de leurs abscisses.

On dit qu'un tri est *stable* lorsqu'il préserve l'ordre des éléments égaux.

!!! Exemple
    Supposons qu'on trie la liste de points du plan $[(3;6), (2;5), (1;4), (2;3)]$ par abscisse croisante, alors les points $(2;5)$ et $(2;3)$ ayant même abscisse peuvent être placés indifféremment l'un avant ou après l'autre dans le tri, c'est à dire que :

    * $[(1;4), (2;5), (2;3), (3;6)]$ et
    * $[(1;4), (2;3), (2;5), (3;6)]$

    sont des résultats de tri valides (les points sont bien rangés par abscisse croissante) mais seul le premier est un tri *stable* car l'ordre initial des éléments égaux a été préservé $(2;5)$ est avant $(2;3)$ comme dans la liste initiale.

1. Rappeler le principe du tri par insertion, ce tri est-il stable ? 
2. Montrer sur un exemple bien choisi que l'implémentation classique du tri par sélection (pour trier une liste de $n$ valeurs, à l'étape $i$, $0 \leq i < n$, on recherche le plus petit élément dans le sous tableau commençant à l'indice $i$ et on l'échange avec celui situé à l'indice $i$) n'est pas un tri stable.

## Test de la fonction de tri intégrée à OCaml

La fonction `#!ocaml Array.sort : ('a -> 'a -> int) -> 'a array -> unit` intégrée à OCaml permet de trier un tableau de valeurs en donnant la clé de tri (c'est le premier argument c'est à dire la fonction `'a -> 'a -> int`). Par exemple, 
si `test` est le tableau  
`#!ocaml [| (1,4); (2,5); (2,3); (3,6) |]`,  
alors en évaluant `#!ocaml Array.sort (fun (x1,y1) (x2,y2) -> x1-x2) test`  
le contenu de `test` devient  
`#!ocaml [|(1, 4); (2, 3); (2, 5); (3, 6)|]`.

On remarque donc que ce tri n'est *pas stable* comme indiqué dans la [documentation officielle de OCaml](https://ocaml.org/manual/5.3/api/Array.html#sorting_and_shuffling){target=_blank}. D'autre part l'implémentation actuelle de ce tri se base sur le [tri par tas](https://fr.wikipedia.org/wiki/Tri_par_tas){target=_blank} qui sera vu plus loin dans l'année.

1. Ecrire en OCaml une fonction `tab_aleatoire : int -> int Array` qui prend en argument un entier `n` et renvoie un tableau d'entiers *positifs* aléatoire tous compris entre 0 et $2^{30} - 1$.

    !!! aide
        Utiliser la [fonction `Random.int`](https://ocaml.org/manual/5.2/api/Random.html#1_Basicfunctions){target=_blank} et penser à initialiser le générateur de nombre aléatoire.

2. Afficher le temps de calcul nécessaire pour trier un tableau de $10^7$ entiers généré aléatoirement par le fonction précédente en utilisant le tri intégré à OCaml.

    !!! aide
        Utiliser la [fonction `Sys.time`](https://ocaml.org/manual/5.1/api/Sys.html){target=_blank}

## Test de la fonction de tri intégrée au langage C

En C, on utilisera les entiers positifs codés sur 32 bits de `stdint.h` c'est à dire le tytpe `uint32_t` . Le langage C possède aussi une fonction de tri dans le module `<stdlib.h>` basée sur l'algorithme du [tri rapide](https://fr.wikipedia.org/wiki/Tri_rapide){target=_blank}, la signature de la fonction est :
```c
void qsort(void *tab, size_t dim, size_t size, int (*compar)(const void *, const void*))
```

* `tab` est un pointeur vers le premier élément du tableau à trier
* `dim` est le nombre d'éléments de ce tableau
* `size` est la taille d'un élément du tableau
* le quatrième argument est une *fonction* qui renvoie un entier et en prend en argument deux pointeurs (constant) vers `void`, c'est la clé de comparaison du tri. Pour trier des entiers de types `uint32_t`, on pourra utiliser la fonction suivante :
```c linenums="1"
--8<-- "DM4/radix.c:cmp"
```

Afin de tester cette fonction, 

1. Ecrire en C une fonction `#!c uint32_t *tab_aleatoire(int n)` qui prend en argument un entier `n` et renvoie un "tableau"  d'entiers *positifs* aléatoire tous compris entre 0 et $2^{30} - 1$.

    !!! aide
        Utiliser la [fonction `rand()`](https://ocaml.org/manual/5.2/api/Random.html#1_Basicfunctions){target=_blank} et penser à initialiser le générateur de nombre aléatoire.

2. Afficher le temps de calcul nécessaire pour trier un tableau de $10^7$ entiers généré aléatoirement par le fonction précédente en utilisant la fonction `qsort` présentée plus haut.

## Principe du tri radix 

Les tris précédents sont des tris généraux qui fonctionnent sur tous les types de données dès qu'une clé de tri est donnée. L'algorithme du tri radix ne fonctionne que sur certains types de données, en particulier les entiers positifs. Prenons un exemple pour illustrer le principe de cet algorithme, on suppose qu'on doit trier des entiers positifs ayant *au plus 3 chiffres en base 10*, par exemple $[212, 303, 155, 600, 42, 702, 182, 305]$, l'idée de l'algorithme est de trier *de façon stable* suivant le chiffre des unités, puis celui des dizaines, plus celui des unités, ainsi l'ordre déjà construit sur les plus petits chiffres sera préservée lorsqu'on trie sur les chiffres suivants. Comme les nombres ont au plus 3 chiffres, 3 passes sont nécessaires :

| Etape | Etat de la liste |
|-------|------------------|
|Etat initial | $[212, 303, 155, 600, 42, 702, 182, 305]$ |
|Tri suivant le chiffre des unités | $[60\underline{\color{red}0},21\underline{2},4\underline{\color{red}2},70\underline{\color{red}2},18\underline{\color{red}2},30\underline{\color{red}5}]$|
|Tri stable suivant le chiffre des dizaines | $[6\underline{\color{red}0}0, 7\underline{\color{red}0}2, 3\underline{\color{red}0}5, 2\underline{\color{red}1}2, \underline{\color{red}4}2, 1\underline{\color{red}8}2]$|
|Tri stable suivant le chiffre des centaines | $[\underline{\color{red}0}42, \underline{\color{red}1}82, \underline{\color{red}2}12, \underline{\color{red}3}05, \underline{\color{red}6}00, \underline{\color{red}7}02    ]$|

1. Donner les étapes de l'algorithme pour la liste $[707, 332, 117, 259, 9, 152, 419]$, en donnant vos résultats dans un tableau tel que celui présenté ci-dessus.

## Implémentation en base 10 en OCaml

Dans cette partie, on implémente en OCaml, le tri radix pour des entiers en base 10 strictement inférieur à $10^{10}$. 

1. Ecrire une fonction `chiffre int -> int -> int` qui prend en entré un nombre `n` et un rang `d` et renvoie le chiffre de rang `d` dans le nombre `n` (on considère que le chiffre des unités est le chiffre de rang 0). Par exemples,
    
    * `chiffre 759 0` renvoie 9
    * `chiffre 42 3` renvoie 0 
    * `chiffre 1066 3` renvoie 1
    
2. Ecrire une fonction `radix_pass : int array -> int -> ()` qui prend en entrée un tableau de nombres `entiers` et un rang `d` et modifie ce tableau en le triant de façon stable avec comme clé de tri la valeur du chiffre de rang d des nombres. Par exemple, si `t` est le tableau `[| 212; 303; 155; 600; 42; 702; 182; 305 |]` alors après l'appel `radix_pass t 0`  ce tableau  contiendra `[| 600; 212; 42; 702; 182; 305 |]` (voir l'exemple de déroulement de l'algorithme dans la partie précédente).  

    On pourra procéder de la façon suivante :

    * On effectue un premier parcours du tableau  `entiers` pour construire un tableau `taille_alveole` tel que  `taille_aveole.(i)` contient le  nombre d'entiers ayant `i` pour chiffre de rang `d`. Par exemple si on trie `[| 600; 212; 42; 702; 182; 305 |]` par chiffre des unités, `taille_aveole` doit contenir `[|1; 0; 4; 0; 0; 1; 0; 0; 0; 0 |]` (`1` entier se termine par `0`, aucun par `1`, `4` se terminent par `2`, ...). 
    * Grâce au tableau précédent, on construit un seconde tableau `position_alveole` tel que `position_alveole.(i)` indique la position de la prochaine insertion d'un nombre dont le chiffre de rang `d` est `i`. Dans l'exemple précédent, `position_alveole` doit contenir `[|0; 1; 1; 5; 5; 5; 6; 6; 6; 6 |]`.
    * On crée un tableau temporaire dans lequel on recopie les éléments de `entiers` en les mettant à l'emplacement désigné par `position_alveole.(i)̀` qu'on incrémente à chaque insertion d'un nombre dont le chiffre de rang `d` est `i`. Dans l'exemple précédent, le premier nombre se terminant par `2` sera inséré à l'indice `1` (on laisse la place avant pour celui se terminant par `0`) et on incrémente cette position de façon à ce que le prochain nombre rencontré se terminant par `2` soit inséré à l'indice `2`.
    * On recopie les éléments de ce tableau temporaire dans le tableau `entiers` (on pourra utiliser). 

4. Ecrire maintenant la fonction `tri_radix : int array -> int -> ()` qui prend en argument un tableau d'entiers ainsi que le nombre maximum de chiffres en base 10 de ces entiers et tri ce tableau avec l'algorithme du tri radix.

4. A présent on veut tester cet algorithme sur des entiers positifs aléatoires compris entre $0$ et $2^{30}-1$, vérifier rapidement que $10^{9} \leqslant 2^{30} < 10^{10}$ et en déduire le nombre de chiffres maximal en base 10 d'un entiers compris entre $0$ et $2^{30}$. Tester alors la fonction `tri_radix` sur un tableau de $10^{7}$ entiers aléatoires et comparer avec le temps de calcul obtenu avec l'algorithme de tri intégré à OCaml.

## Implémentation en base 2 puissance l en C

L'implémentation précédente utilise la base 10, alors que les entiers sont représentés en base 2 en machine, comme nous testons sur des entiers compris entre $0$ et $2^{30}-1$, ils ont au plus 30 chiffres en base 2. Si on trie en base 2, l'algorithme fera donc 30 passes, l'idée est donc de *regrouper les chiffres en base 2 en bloc de longueur l* afin de trier en base $2^l$. Par exemple, si $l=4$ cela revient à trier en base 16 (donc avec 16 valeurs possibles pour chaque chiffre). Et on ne doit plus faire que $\left\lceil\frac{30}{4}\right\rceil=8$ passes. 


1. Ecrire les fonctions de prototype `#!c uint32_t nombre_chiffres(uint32_t l)` et `#!c uint32_t nombre_passes(uint32_t l)` qui renvoient pour une taille de bloc `l` le nombre de chiffres en bases $2^l$ et le nombre de passes nécessaires pour l'algorithme du tri radix (avec des entiers compris entre $0$ et $2^{30}-1$).

2. Ecrire la fonction de prototype `#!c uint32_t chiffre(uint32_t n, uint32_t d, uint32_t l)` qui renvoie le chiffre de rang `d` de l'entier `n` en base `2^l`.

    !!! aide 
        On pourra utiliser les opérations bit à bit du C.

3. Ecrire la fonction `radix_passe` permettant de trier de façon stable en prenant comme clé de tri le chiffre de rang `k`.

4. Ecrire la fonction implémentant l'algorithme du tri radix en founissant la taille `l` des blocs de chiffre.

5. Justifier rapidement que les valeurs $l$ telles que $\left\lceil\frac{30}{l}\right\rceil=\left\lceil\frac{30}{l-1}\right\rceil$ ne présentent aucun intérêt. Puis, tester votre implémentation pour diverses valeurs de `l`

6. Comparer les temps de calculs obtenus avec ceux de la fonction  `qsort` en faisant varier la taille du tableau trié.

7. Déterminer la complexité du tri radix en fonction de la taille en bits des entiers triés et du nombre $l$ de bits regroupés afin de former un chiffre.
