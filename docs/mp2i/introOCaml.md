
{% set num = 6 %}
{% set niveau = "mp2i_s1"%}

{{ titre_chapitre(num,niveau)}}

{{ citation("An industrial-strength functional programming language with an emphasis on expressiveness and safety","ocaml.org","[Site officiel d'OCaml](https://ocaml.org/)")}}

## Cours

{{ affiche_cours(num) }}

## Travaux dirigés

{{ td(num) }}

## Travaux pratiques

{{ exo("Un notebook pour démarrer",[],0)}}


!!! Note "A propos des notebooks"
    Dans cette activité, on utilise pour la première fois les **jupyter notebook**, c'est-à-dire des documents contenant à la fois :

    * des zones de texte explicatives, 
    * des zones de code Ocaml, executables directement à la façon de ce qui se passe lorsqu'on utilise l'environnement `utop` de OCaml.

    A chaque fois, que nous utilisons cet outil, deux choix s'offrent à vous :

    1. l'utiliser localement sur votre ordinateur à condition d'y avoir installé jupyter notebook (c'est le cas sur les ordinateurs de la salle). Pour cela, créer un dossier nommé par exemple `Notebook` et depuis un terminal lancer jupyter dans ce dossier en écrivant simplement :
    ```bash
    jupyter notebook
    ```
    L'application se lance dans votre navigateur, télécharger le notebook et utiliser le bouton <span class="encadre">Téléverser</span> en haut à droit pour le télécharger dans votre dossier et l'ouvrir.

    2. Utiliser l'application **Capytale** de votre environnement numérique de travail metice. Dans ce cas, utiliser le lien de partage fourni dans l'activité. Cette option vous permet notamment de travailler depuis la maison car aucune installation (ni de OCaml, ni de Jupyter) n'est nécessaire.

    Les activités utilisant un notebook proposerons donc toujours les deux options décrites ci-dessus.

{{notebook("c985-1905797","Notebook : Premiers pas en OCaml","./Notebook/TP - Premiers pas en OCaml.ipynb")}}



{{ exo("Quelques évaluations",[]) }}

1. Prédire le type et la valeur des expressions suivantes, vérifier en les évaluant `utop` :

    * `(7.-5.)  *. 3.`
    * `14 mod 3`
    * `(6+6)/2`
    * `5/2`
    * `'a'`
    * `"Ocaml"`
    * `"Hello" ^ " World"`
    * `3.0 ** 2`
    * `9 < 8`
    * `7 <> 5`
    * `"Incroyable".[5]`

2. Effectuer les calcul suivants à l'aide d'Ocaml :

    * Reste dans la division euclidienne de 2023 par 312
    * Quotient dans la division euclidienne de 7777 par 42
    * $7^4$
    * $\dfrac{14 + 9}{25-3\times7}$

{{ exo("Quelques erreurs ...",[])}}

1. Prédire l'évaluation de chacune des expressions ci-dessous

    * `let a = 5. + 2`
    * `if true then 1 else 2.0`
    * `let b = -3.14`
    * `'z' = "z"`
    * `let s = "Python" in s.[0] = 'C'`
    * `abs(-2.718)`
    * `let z = 2.0**5`
    * `let s = "OCaml" in if s.[1]="C" then true else false`

2. Vérifier en testant dans `utop` (et expliquer)


!!! note
    Pour les exercices suivants, on pourra au choix continuer à travailler dans `utop` soit faire les premières compilations.


{{ exo("Ou exclusif",[] )}}

1. Ecrire une fonction `xor` en OCaml qui prend en argument deux booléens `a` et `b` et renvoie `true` lorsque l'un des deux est vrai et `false` sinon

2. Donner une écriture de cette fonction en utilisant un filtrage par motif

{{ exo("Termes d'une suite",[])}}

Ecrire une fonctions `suite` qui prend en argument un entier `n` et renvoie le  `n`-ième terme de la suite $u$ définie par $u_0=1$ et $u_{n+1} = 2 u_n + 3$

{{ exo("Dessiner (sans boucles)",[] )}}

1. Ecrire une fonction `repete` qui prend en argument un caractère `car` et un entier `n` et affiche `n` fois ce caractère à l'écran puis passe à la ligne

2. En utilisant la fonction précédente écrire la fonction `triangle` qui prend en argument un caractère `car` et un entier `n` et dessine un triangle de ce caractère. Par exemple :
```ocaml
utop # triangle '*' 5;;
*****
****
***
**
*
```

3. Même question mais en affichant le triangle "pointe vers le haut" :
```ocaml
utop # triangle2 '*' 5;;
*
**
***
****
*****
```


{{ exo("Type nombre",[]) }}

1. Créer le type union `nombre` pouvant être un entier ou un flottant
2. A l'aide d'un filtrage par motif, écrire une fonction `addition` qui prend en argument deux variables de type `nombre` et renvoie leur somme.

{{ exo("Type couleur",[]) }}

1. Créer le type produit `couleur` sous la forme d'un triplet de trois entiers.
2. Le négatif d'une couleur $(x,y,z)$ est la couleur $(255-x, 255-y, 255-z)$. Ecrire une fonction prenant une couleur comme paramètre et renvoyant son négatif.
3. A l'aide d'un filtrage par motif écrire une fonction qui affiche :

    * `Rouge pur` si la composante rouge est strictement positive et les  deux autres composantes sont nulles,
    * `Vert pur` si la composante verte est strictement positive et les  deux autres composantes sont nulles,
    * `Bleu pur` si la composante bleue est strictement positive et les  deux autres composantes sont nulles,
    * `Mélange` dans les autres cas.
    
{{ exo("Cercle et carré",[])}}

1. Créer un type `Forme` permettant de représenter les carrés (en donnant leur côté) et les cercles (en donnant leur rayon)
2. Ecrire à l'aide d'un filtrage par motif la fonction qui calcule le périmètre d'un objet de type `Forme`.
3. Même question pour la surface

{{ exo("Chaines de caractères",[])}}

!!! aide
    * On rappelle que le caractère d'indice `i` de la chaine `chaine` s'obtient avec la notation `chaine.[i]`
    * La fonction `String.sub` prend en argument une chaine et deux indices et renvoie la sous chaine entre ces deux indices. Par exemple `String.sub "OCaml" 1 3` renvoir  `"Cam"`.

1. Ecrire une fonction  `est_dans` qui prend en argument une chaine de caractères `chaine` et un caractère `car` et renvoie `true` si `car` se trouve dans `chaine` et `false` sinon
2. Ecrire une fonction `compte_occurence` qui prend en argument une chaine de caractères `chaine` et un caractère `car` et renvoie le nombre d'apparition de `car` dans `chaine`


{{ exo("Création de liste",[])}}

1. Ecrire une fonction `cree_liste` qui prend en argument un élément `elt` et un entier `rep` et qui crée la liste constituée de `rep` fois l'élément `elt`. Par exemple `cree_liste  42 3` renvoie la liste `[42; 42; 42]`
2. Ecrire la fonction `entiers` qui prend en argument un entier `n` et renvoie la liste des entiers `[1,2,..,n]`. Par exemple `entiers 5` renvoie `[1; 2; 3; 4; 5]`.
3. Ecrire une fonction `double` qui prend en argument une liste et renvoie la liste dans laquelle chaque élément de `l` a été dupliqué. Par exemple `double [3; 6; 7]` renvoie la liste `[3; 3; 6; 6; 7; 7;]`.
4. Ecrire la fonction `mult_liste` qui prend en argument une liste et un entier `rep` et qui crée la liste constituée de `rep` répétitions de la liste. Par exemple `mult_liste [1; 4; 2] 3` renvoie la liste `[1; 4; 2; 1; 4; 2; 1; 4; 2]`

{{ exo("Somme, moyenne, maximum, minimum",[])}}

1. Ecrire une fonction `somme_int` qui prend en argument une liste d'entiers et renvoie la somme de ces entiers.

2. Ecrire une fonction `moyenne_float` qui prend en argument une liste non vide de flottants et renvoie leur moyenne.

3. Ecrire une fonction `minimum` qui renvoie le minimum de la liste non vide de nombres donnée en argument.

4. Ecrire une fonction `indice_max` qui renvoie la liste des indices des occurrences du maximum des éléments de la liste (non vide) donnée en argument.


{{ exo("Indice d'un element",[])}}

Ecrire une fonction `indice` qui prend en argument un entier `n` et une liste d'entiers `l` et qui renvoie l'indice de la première occurrence de `n` dans `l`. On renvoie `-1` si `n` n'appartient pas à `l`. Par exemples :

* `indice 3 [1; 6; 7; 2; 3; 0]` renvoie `4`
* `indice 1 [1; 6; 7; 2; 3; 0]` renvoie `0`
* `indice 5 [1; 6; 7; 2; 3; 0]` renvoie `-1`


{{ exo("Suppression d'un élément",[])}}

1. Ecrire une fonction `supprime` qui prend en argument une liste `l` et une valeur `v` et supprime toutes les occurrences de `v` dans `l`.
2. Même question en supprimant seulement la première occurrence
3. Même question en supprimant seulement la dernière occurrence

{{ exo("Retourner une liste",[])}}

Ecrire une fonction `retourne` qui prend en argument une liste et renvoie la liste retournée (c'est-à-dire avec les éléments dans l'ordre inverse). Par exemple `retourne [2; 4; 5; 1]` renvoie la liste `[1; 5; 4; 2]` 

!!! note "Remarque"
    Cette fonction existe déjà, c'est `List.rev`

{{ exo("Doublons dans une liste",[])}}

1. Ecrire une fonction `sans_doublons_triee` qui prend en argument une liste d'entiers **triée** et renvoie `true` si cette liste ne contient pas de doublons. Par exemple `sans_doublons_triee [2; 5; 5; 8; 10]` doit renvoyer  `false`.

2. Ecrire une fonction `elimine_doublons_triee` qui prend en argument une liste d'entiers **triée** et renvoie cette liste en supprimant tous les doublons éventuels qui s'y trouvent. Par exemple `elimine_doublons_triee [2; 5; 5; 8; 10]` doit renvoyer `[2; 5; 8; 10]`

3. Ecrire une fonction `compare` qui prend en argument deux entiers `a` et `b` et renvoie `-1` si `a<b`, `0` si `a=b` et `1` si `a>b`

4. Une fonction de tri de liste existe déjà en OCaml, c'est `List.sort` qui prend en argument une fonction de comparaison (telle que celle définie à la question précédente) et une liste et renvoie la liste triée en utilisant la fonction de comparaison. Tester cette fonction.

5. Ecrire les fonctions des questions **1** et **2** pour des listes quelconques (non forcément triées) en utilisant `List.sort`

6. Même question sans utiliser `List.sort`

{{ exo("Liste monotone",[])}}

Ecrire une fonction `monotone` qui prend en argument une liste et renvoie un booléen indiquant si la liste donnée en argument est monotone ou non.

!!! aide
    On pourra dans un premier temps écrire deux fonctions `croissante` et `décroissante` avant de trouver une solution plus concise.

{{ exo("Partition suivant un prédicat",[])}}

1. Ecrire une fonction `separe` qui prend en argument une liste et renvoie deux listes : celles des éléments positifs ou nuls et celle des éléments négatifs.
Par exemple `separe [2; -3; -2; -1; 7; -4]` renvoie les liste `[2; 7]` et `[-3; -2; -4]`.

2. En s'inspirant de l'exemple précédent écrire une fonction `separe_bis` qui prend de plus en argument une fonction qui renvoie un booléen (et s'applique aux éléments de la liste) et renvoie deux listes : celles pour laquelle l'application de la fonction renvoie `true` et celle pour laquelle l'application de la fonction renvoie `false`. 


{{ exo("Exercices en ligne",[]) }}

Le site officiel de [la fondation Ocaml](https://ocaml.org/){target=_blank}, propose des [exercices progressifs](https://ocaml-sf.org/learn-ocaml-public/#){target=_blank} à faire en ligne directement dans le navigateur.


## Humour d'informaticien
![Webcomic](./Images/C6/OCamlHumour.png){.imgcentre width=500px}
<span class="source">
Credit : [Hmm-la-bd](https://hmm-la-bd.eu/40/){target=_blank} {{sc ("cc by-nc")}}</span>