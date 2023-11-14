
{% set num = 7 %}
{% set niveau = "mp2i_s1"%}

{{ titre_chapitre(num,niveau)}}

{{ citation("Beware of bugs in the above code; I have only proved it correct, not tried it.","Donald Knuth","[Correspondance avec van Emde Boas](https://cs.stanford.edu/~knuth/faq.html)")}}

## Cours
{{ cours(num) }}

## TD
{{ td(num) }}

## TP

!!! danger
    En cas de difficultés sur les exercices de programmation proposés dans ce chapitre, revenir sur ceux du chapitre précédent d'introduction à OCaml.

{{ exo("Creation et affichage",[],0)}} 

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



## Humour d'informaticien
![BinarySearch](./Images/C7/search.png){.imgcentre width=500px}
