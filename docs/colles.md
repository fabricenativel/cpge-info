hide: - navigation  in liens.md

# Programme de colles

## Semaines du 01/09, du 08/09 et du 15/09

* Commandes de base d'un système Linux (`cd`, `mkdir`, `ls`, ...)
* Traits généraux du langage C (passage par valeur, portée, typage, comportement indéfini)
* Types de bases (`int`, `float`, `double`, `char`) et opérateurs associés
* Opérateurs de comparaison
* Tableaux statique, lecture et écriture d'un terme avec `tab[i]`
* Instructions conditionnelles, boucle `for` et `while`
* *A partir du 08/09* : validation, jeu de tests, graphe de flot de contrôle
* *A partir du 15/09* : terminaison d'un algorithme, variant


## Semaines du 22/09, du 29/06 et du 06/09

* Terminaison et correction d'algorithme simples. Les variants et invariants peuvent être suggérés aux élèves. Exemples traités en cours/TD : multiplication par addition successives, quotient et reste dans la division euclidienne, recherche de max/min dans un tableau, multiplication à la russe.
* Modèle mémoire du langage C, pile, allocation dynamique dans le tas. Utilisation des opérateurs `*` afin d'obtenir le contenu d'une adresse et de `&` pour l'adresse d'une variable. Instructions `malloc` et `free`.
* Ecriture en C de fonctions renvoyant un pointeur vers une zone mémoire allouée sur le tas qui sera traité comme un tableau, on pourra dire par abus de langage "*fonction renvoyant un tableau*"
* Types structurés en C, définition et utilisation. Pointeur vers un type structurée, la notation raccourcie `s->champ` pour `(*s).champ` doit être connue.
* Arguments en ligne de commande en C. Fonction `atoi` et `atof`.
* *A partir du 29/06* : représentation des entiers. Formats disponibles en OCaml et en C. Cas de dépassement de capacité.
* *A partir du 06/09* : représentation des flottants, exemples simples de conversion du type simple précision en décimal ou inversemment. Problème de fiabilité des calculs en arithmétique à virgule flottante.

## Semaines du 27/10, du 03/11 et du 10/11

* Types structurés en C, utilisation de pointeurs vers de tels types.
* Représentation des entiers et des flottants
* *A partir du 03/11* : Récursivité. Preuve de terminaison et correction d'algorithmes récursifs. Ecriture de fonctions simples en versions récursives (somme, minimum, puissance, dessins à l'aide d'instructions `print`). Récursivité croisée.
* *A partir du 10/11* : Aspects fonctionnels de OCaml. Ecriture et évaluation d'expressions en OCaml. Définition de fonctions, expressions conditionnelles. Type `list`, correspondance de motifs.

## Semaines du 24/11, du 01/12 et du 08/12

* Manipulations de listes en OCaml. Générations récursives de listes, utilisations de `List.init` (avec éventuellement une fonction anonyme). Correspondances de motifs sur les listes, écritures de fonctions récursives sur les listes (minimum, recherche, ...). Utilisation de `List.map`, `List.fold_left`, `List.fold_right`, `List.iter`. On n'utilise pas `List.nth`.

* Terminaison, correction et complexité. Complexités usuelles et exemple d'algorithmes ayant ces complexités. Définition et manipulation de la notation $\mathcal{O}$.

* *A partir du 01/12* : Complexité amortie (la *seule méthode* vue en cours est celle du potentiel). Tableaux et listes chainées comme structure de données abstraites. Implémentation de ces structures en C et en OCaml.

* *A partir du 08/12* : Piles et files, et implémentations de ces structures de données à l'aide de tableaux ou de listes.