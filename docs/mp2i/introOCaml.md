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


!!! note "À propos des notebooks"
    Dans cette activité, on utilise pour la première fois les **notebooks Jupyter**, c'est-à-dire des documents contenant à la fois :

    * des zones de texte explicatives, 
    * des zones de code OCaml, exécutables directement à la façon de ce qui se passe lorsqu'on utilise l'environnement `utop` d'OCaml.

    À chaque fois que nous utilisons cet outil, deux choix s'offrent à vous :

    1. L'utiliser localement sur votre ordinateur à condition d'y avoir installé Jupyter Notebook (c'est le cas sur les ordinateurs de la salle). Pour cela, créer un dossier nommé par exemple `Notebook` et depuis un terminal lancer Jupyter dans ce dossier en écrivant simplement :
    ```bash
    jupyter notebook
    ```
    L'application se lance dans votre navigateur. Téléchargez le notebook puis utilisez le bouton <span class="encadre">Téléverser</span> en haut à droite pour l'importer dans votre dossier et l'ouvrir.

    2. Utiliser l'application **Capytale** de votre environnement numérique de travail Métice. Dans ce cas, utilisez le lien de partage fourni dans l'activité. Cette option vous permet notamment de travailler depuis la maison car aucune installation (ni d'OCaml, ni de Jupyter) n'est nécessaire.

    Les activités utilisant un notebook proposeront donc toujours les deux options décrites ci-dessus.

{{notebook("c985-1905797","Notebook : Premiers pas en OCaml","./Notebook/TP - Premiers pas en OCaml.ipynb")}}



{{ exo("Quelques évaluations",[]) }}

1. Prédire le type et la valeur des expressions suivantes, vérifier en les évaluant dans `utop` :

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

2. Effectuer les calculs suivants à l'aide d'OCaml :

    * Reste dans la division euclidienne de 2023 par 312
    * Quotient dans la division euclidienne de 7777 par 42
    * $7^4$
    * $\dfrac{14 + 9}{25-3\times7}$

{{ exo("Quelques erreurs ...",[])}}

1. Prédire l'évaluation de chacune des expressions ci-dessous :

    * `let a = 5. + 2`
    * `if true then 1 else 2.0`
    * `let b = -3.14`
    * `'z' = "z"`
    * `let s = "Python" in s.[0] = 'C'`
    * `abs(-2.718)`
    * `let z = 2.0**5`
    * `let s = "OCaml" in if s.[1]="C" then true else false`

2. Vérifier en testant dans `utop` (et expliquer l'erreur constatée).


!!! note
    Pour les exercices suivants, on pourra au choix continuer à travailler dans `utop` ou bien réaliser les premières compilations de fichiers `.ml`.


{{ exo("Ou exclusif",[] )}}

1. Écrire une fonction `xor` en OCaml qui prend en argument deux booléens `a` et `b` et renvoie `true` lorsque exactement l'un des deux est vrai et `false` sinon.

2. Donner une écriture de cette fonction en utilisant le filtrage par motif.

{{ exo("Quelques fonctions élémentaires",[])}}

1. Écrire une fonction `perimetre_cercle : float -> float` qui prend en argument un flottant `r` et renvoie le périmètre du cercle de rayon `r`. On utilisera une valeur de `pi` de `3.14159` définie *dans un environnement local*.

2. Écrire une fonction `discriminant : float -> float -> float -> float` qui prend en argument trois flottants $a, b$ et $c$ et renvoie $b^2 - 4ac$.

3. Écrire une fonction `est_pair : int -> bool` qui renvoie `true` lorsque l'entier donné en argument est pair.

4. Écrire une fonction `mention : float -> string` qui renvoie la mention au {{sc("bac")}} associée à la moyenne donnée en argument ; par exemple `mention 12.8` donne `"Assez bien"`.

5. Écrire une fonction `fact : int -> int` qui renvoie la factorielle de l'entier donné en argument.

{{ exo("Termes d'une suite",[])}}

Écrire une fonction `suite` qui prend en argument un entier `n` et renvoie le $n$-ième terme de la suite $u$ définie par $u_0=1$ et $u_{n+1} = 2 u_n + 3$.

{{ exo("Dessiner (sans boucles)",[] )}}

1. Écrire une fonction `repete` qui prend en argument un caractère `car` et un entier `n` et affiche `n` fois ce caractère à l'écran puis passe à la ligne.

2. En utilisant la fonction précédente, écrire la fonction `triangle` qui prend en argument un caractère `car` et un entier `n` et dessine un triangle de ce caractère. Par exemple :
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

{{ exo("Type figure",[])}}

On considère le type union suivant permettant de représenter des figures géométriques :

```ocaml
type figure = 
| Cercle of float 
| Carre of float 
| Rectangle of float*float;;
```

1. En utilisant un filtrage par motif, écrire une fonction `perimetre` qui renvoie le périmètre d'une `figure`.

2. Définir la variable `rect` représentant un rectangle de dimensions $3\times9$ et calculer son périmètre à l'aide de la fonction précédente.

3. Reprendre les questions précédentes pour l'aire d'une figure (fonction `aire`).

{{ exo("Type nombre",[]) }}

1. Créer le type union `nombre` pouvant être un entier (`Entier of int`) ou un flottant (`Flottant of float`).
2. À l'aide d'un filtrage par motif, écrire une fonction `addition` qui prend en argument deux variables de type `nombre` et renvoie leur somme.

{{ exo("Type couleur",[]) }}

1. Créer le type produit `couleur` sous la forme d'un triplet de trois entiers (`int * int * int`).
2. Le négatif d'une couleur $(x,y,z)$ est la couleur $(255-x, 255-y, 255-z)$. Écrire une fonction prenant une couleur en argument et renvoyant son négatif.
3. À l'aide d'un filtrage par motif, écrire une fonction qui affiche :

    * `Rouge pur` si la composante rouge est strictement positive et les deux autres composantes sont nulles,
    * `Vert pur` si la composante verte est strictement positive et les deux autres composantes sont nulles,
    * `Bleu pur` si la composante bleue est strictement positive et les deux autres composantes sont nulles,
    * `Mélange` dans les autres cas.
    

{{ exo("Types enregistrements",[]) }}

On rappelle qu'en OCaml, un type enregistrement (*record*) permet de regrouper plusieurs champs nommés sous la syntaxe suivante :
```ocaml
type point2d = { x : float; y : float };;
```

1. Définir le type `point2d` ci-dessus. Écrire une fonction `distance : point2d -> point2d -> float` calculant la distance euclidienne entre deux points du plan :
   $$\mathrm{dist}(A, B) = \sqrt{(x_B - x_A)^2 + (y_B - y_A)^2}$$
   *(On utilisera la fonction `sqrt : float -> float`).*

2. Définir le type `etudiant` sous forme d'un enregistrement possédant deux champs : `nom` de type `string` et `notes` de type `float list`.

3. Écrire une fonction `moyenne : etudiant -> float` calculant la moyenne des notes d'un étudiant. On supposera que la liste des notes n'est pas vide.

4. Écrire une fonction `admis : etudiant list -> string list` qui prend en argument une promotion d'étudiants (représentée par une liste d'étudiants) et renvoie la liste des noms de ceux dont la moyenne est supérieure ou égale à $10{,}0$.


{{ exo("Arithmétique des rationnels",[]) }}

On souhaite implémenter une arithmétique exacte sur les nombres rationnels $\mathbb{Q}$.

1. Définir un type enregistrement `rationnel` avec deux champs entiers `num` (numérateur) et `den` (dénominateur).

2. Écrire une fonction récursive `pgcd : int -> int -> int` calculant le plus grand commun diviseur de deux entiers naturels non nuls à l'aide de l'algorithme d'Euclide.

3. Écrire une fonction `cree_rationnel : int -> int -> rationnel` qui prend un numérateur $n$ et un dénominateur $d \neq 0$, et renvoie la fraction sous forme irréductible avec un dénominateur strictement positif.  
   Par exemple, `cree_rationnel 6 (-8)` doit renvoyer `{num = -3; den = 4}`.

4. Écrire les fonctions `somme_rat : rationnel -> rationnel -> rationnel` et `prod_rat : rationnel -> rationnel -> rationnel` effectuant respectivement la somme et le produit de deux nombres rationnels sous forme irréductible.


{{ exo("Chaînes de caractères",[])}}

!!! aide
    * On rappelle que le caractère d'indice `i` de la chaîne `chaine` s'obtient avec la notation `chaine.[i]`.
    * La fonction `String.sub` prend en argument une chaîne, l'indice de départ et la longueur souhaitée, et renvoie la sous-chaîne correspondante. Par exemple `String.sub "OCaml" 1 3` renvoie `"Cam"`.

1. Écrire une fonction `est_dans` qui prend en argument une chaîne de caractères `chaine` et un caractère `car` et renvoie `true` si `car` se trouve dans `chaine` et `false` sinon.
2. Écrire une fonction `compte_occurence` qui prend en argument une chaîne de caractères `chaine` et un caractère `car` et renvoie le nombre d'occurrences de `car` dans `chaine`.


{{ exo("Création de liste",[])}}

1. Écrire une fonction `cree_liste` qui prend en argument un élément `elt` et un entier `rep` et qui crée la liste constituée de `rep` fois l'élément `elt`. Par exemple `cree_liste 42 3` renvoie la liste `[42; 42; 42]`.
2. Écrire la fonction `entiers` qui prend en argument un entier `n` et renvoie la liste des entiers `[1; 2; ...; n]`. Par exemple `entiers 5` renvoie `[1; 2; 3; 4; 5]`.
3. Écrire une fonction `double` qui prend en argument une liste `l` et renvoie la liste dans laquelle chaque élément de `l` a été dupliqué. Par exemple `double [3; 6; 7]` renvoie la liste `[3; 3; 6; 6; 7; 7]`.
4. Écrire la fonction `mult_liste` qui prend en argument une liste `l` et un entier `rep` et qui crée la liste constituée de `rep` répétitions de la liste `l`. Par exemple `mult_liste [1; 4; 2] 3` renvoie la liste `[1; 4; 2; 1; 4; 2; 1; 4; 2]`.

{{ exo("Somme, moyenne, maximum, minimum",[])}}

1. Écrire une fonction `somme_int` qui prend en argument une liste d'entiers et renvoie la somme de ces entiers.

2. Écrire une fonction `moyenne_float` qui prend en argument une liste non vide de flottants et renvoie leur moyenne.

3. Écrire une fonction `minimum` qui renvoie le minimum de la liste non vide de nombres donnée en argument.

4. Écrire une fonction `indice_max` qui renvoie la liste des indices des occurrences du maximum des éléments de la liste (non vide) donnée en argument.


{{ exo("Indice d'un élément",[])}}

Écrire une fonction `indice` qui prend en argument un entier `n` et une liste d'entiers `l` et qui renvoie l'indice de la première occurrence de `n` dans `l`. On renvoie `-1` si `n` n'appartient pas à `l`. Par exemple :

* `indice 3 [1; 6; 7; 2; 3; 0]` renvoie `4`
* `indice 1 [1; 6; 7; 2; 3; 0]` renvoie `0`
* `indice 5 [1; 6; 7; 2; 3; 0]` renvoie `-1`


{{ exo("Sécurisation avec le type option",[]) }}

Dans l'exercice précédent, la fonction `indice` renvoyait la valeur sentinelle `-1` en cas d'échec, ce qui n'est pas idiomatique en programmation fonctionnelle. Le type prédéfini `'a option` permet de représenter explicitement la présence ou l'absence d'une valeur :
```ocaml
type 'a option = None | Some of 'a;;
```

1. Écrire une fonction `indice_opt : 'a -> 'a list -> int option` qui renvoie `Some i` si l'élément apparaît pour la première fois à l'indice `i`, et `None` s'il n'apparaît pas dans la liste. Par exemple :

    * `indice_opt 3 [1; 6; 7; 2; 3; 0]` renvoie `Some 4`
    * `indice_opt 5 [1; 6; 7; 2; 3; 0]` renvoie `None`

2. Écrire une fonction `min_opt : 'a list -> 'a option` qui renvoie le plus petit élément d'une liste emballé dans `Some`, et `None` si la liste est vide (ce qui évite de déclencher une exception sur la liste vide).

3. Écrire une fonction `trouve_premier : ('a -> bool) -> 'a list -> 'a option` qui prend en argument un prédicat `p` et une liste `l`, et renvoie `Some x` pour le premier élément `x` de `l` tel que `p x = true`, et `None` si aucun élément ne vérifie le prédicat.


{{ exo("Suppression d'un élément",[])}}

1. Écrire une fonction `supprime` qui prend en argument une liste `l` et une valeur `v` et supprime toutes les occurrences de `v` dans `l`.
2. Même question en supprimant seulement la première occurrence.
3. Même question en supprimant seulement la dernière occurrence.

{{ exo("Retourner une liste",[])}}

Écrire une fonction `retourne` qui prend en argument une liste et renvoie la liste retournée (c'est-à-dire avec les éléments dans l'ordre inverse). Par exemple `retourne [2; 4; 5; 1]` renvoie la liste `[1; 5; 4; 2]`.

!!! note "Remarque"
    Cette fonction existe déjà dans la bibliothèque standard, c'est `List.rev`.

{{ exo("Doublons dans une liste",[])}}

1. Écrire une fonction `sans_doublons_triee` qui prend en argument une liste d'entiers **triée** et renvoie `true` si cette liste ne contient pas de doublon. Par exemple `sans_doublons_triee [2; 5; 5; 8; 10]` doit renvoyer `false`.

2. Écrire une fonction `elimine_doublons_triee` qui prend en argument une liste d'entiers **triée** et renvoie cette liste en supprimant tous les doublons éventuels qui s'y trouvent. Par exemple `elimine_doublons_triee [2; 5; 5; 8; 10]` doit renvoyer `[2; 5; 8; 10]`.

3. Écrire une fonction `compare` qui prend en argument deux entiers `a` et `b` et renvoie `-1` si `a < b`, `0` si `a = b` et `1` si `a > b`.

4. Une fonction de tri de liste existe déjà en OCaml, c'est `List.sort` qui prend en argument une fonction de comparaison (telle que celle définie à la question précédente) et une liste et renvoie la liste triée en utilisant la fonction de comparaison. Tester cette fonction.

5. Écrire les fonctions des questions **1** et **2** pour des listes quelconques (pas forcément triées) en utilisant `List.sort`.

6. Même question sans utiliser `List.sort`.

{{ exo("Liste monotone",[])}}

Écrire une fonction `monotone` qui prend en argument une liste et renvoie un booléen indiquant si la liste donnée en argument est monotone ou non.

!!! aide
    On pourra dans un premier temps écrire deux fonctions `croissante` et `decroissante` avant de trouver une solution plus concise.

{{ exo("Partition suivant un prédicat",[])}}

1. Écrire une fonction `separe` qui prend en argument une liste et renvoie deux listes : celle des éléments positifs ou nuls et celle des éléments négatifs.
Par exemple `separe [2; -3; -2; -1; 7; -4]` renvoie les listes `[2; 7]` et `[-3; -2; -4]`.

2. En s'inspirant de l'exemple précédent, écrire une fonction `separe_bis` qui prend de plus en argument une fonction qui renvoie un booléen (et s'applique aux éléments de la liste) et renvoie deux listes : celle pour laquelle l'application de la fonction renvoie `true` et celle pour laquelle l'application de la fonction renvoie `false`.


{{ exo("Fonctions d'ordre supérieur et fonctions anonymes",[]) }}

En OCaml, les fonctions sont des valeurs de première classe : elles peuvent être passées en argument à d'autres fonctions (fonctions d'ordre supérieur) ou définies localement sans nom grâce à la syntaxe `fun x -> ...`.

Le module `List` de la bibliothèque standard fournit notamment :

* `List.map : ('a -> 'b) -> 'a list -> 'b list` applique une fonction à chaque élément d'une liste ;
* `List.filter : ('a -> bool) -> 'a list -> 'a list` conserve les éléments satisfaisant un prédicat ;
* `List.fold_left : ('a -> 'b -> 'a) -> 'a -> 'b list -> 'a` combine les éléments d'une liste de gauche à droite à partir d'un accumulateur initial.

1. **`List.map` et fonction anonyme :**  
   À l'aide de `List.map` et d'une fonction anonyme, écrire une expression qui convertit une liste de températures en degrés Celsius en degrés Fahrenheit ($T_F = 1{,}8 \times T_C + 32$).  
   Par exemple, appliquée à `[0.0; 20.0; 100.0]`, elle renvoie `[32.0; 68.0; 212.0]`.

2. **`List.filter` :**  
   En utilisant `List.filter` et une fonction anonyme, écrire une fonction `pairs : int list -> int list` qui extrait tous les entiers pairs d'une liste d'entiers.

3. **`List.fold_left` (réduction) :**  
   À l'aide de `List.fold_left`, définir en une seule ligne la fonction `somme : int list -> int` calculant la somme des éléments d'une liste d'entiers.

4. **Schéma de Horner :**  
   On représente un polynôme $P(X) = a_n X^n + a_{n-1} X^{n-1} + \dots + a_1 X + a_0$ par la liste de ses coefficients $[a_n; a_{n-1}; \dots; a_0]$ ordonnée par puissances décroissantes.  
   Rappeler le principe du schéma de Horner et écrire une fonction `horner : float list -> float -> float` qui prend la liste des coefficients et une valeur $x$, et calcule $P(x)$ à l'aide de `List.fold_left`.


{{ exo("Exercices en ligne",[]) }}


* Le site officiel de [la fondation OCaml](https://ocaml.org/){target=_blank} propose des [exercices progressifs](https://ocaml-sf.org/learn-ocaml-public/#){target=_blank} à faire en ligne directement dans le navigateur.

* Des [exercices OCaml interactifs et corrigés](https://fortierq.github.io/ocaml-exercices){target=_blank} par **Q. Fortier**.

## Humour d'informaticien
![Webcomic](./Images/C6/OCamlHumour.png){.imgcentre width=500px}
<span class="source">
Crédit : [Hmm-la-bd](https://hmm-la-bd.eu/40/){target=_blank} {{sc ("cc by-nc")}}</span>
