{% set num = 9 %}
{% set niveau = "mp2i_s1"%}

{{ titre_chapitre(num,niveau)}}

{{ citation("OCaml offers a happy compromise here, making it easy and natural to program in a pure style, but also providing great support for imperative programming","realworldocaml.org","[Real World OCaml](https://dev.realworldocaml.org/index.html)")}}

## Cours

{{ cours(num) }}

## Travaux dirigés


## Travaux pratiques

{{ exo("Manipulation des références",[],0)}}

1. Ecrire une fonction `affiche int ref -> unit` qui permet d'afficher l'entier dont une référence est passée en argument.

2. Ecrire une fonction `echange` qui échange le contenu des deux références (sur des objets de même type) donnés en argument.

3. Créer une fonction `incrémente int ref -> unit` qui ajoute 1 à la valeur contenue dans la référence entière donnée en argument.

{{ exo("Manipulation d'enregistrement modifiable",[]) }}

Dans tout la suite, on manipule le type suivant 
```ocaml
type fraction = {mutable numerateur : int; mutable denominateur : int}

```

!!! aide
    On rappelle qu'on peut créer un objet de type fraction avec :
    ```ocaml
    let ma_fraction = {numerateur=45; denominateur=12}
    ```

1. Ecrire une fonction `afficher` permettant d'afficher un objet de type fraction

2. Rappeler rapidement le principe de l'algorithme d'Euclide permettant de calculer le {{sc("pgcd")}} de deux entiers. Et en écrire une implémentation récursive en OCaml

3. Ecrire une fonction `simplifie fraction -> unit` qui prend en argument une fraction et ne renvoie rien mais modifie la fraction fournie en argument de façon à la rendre irreductible.

4. Tester votre fonction sur la fonction `a` donnée en ci-dessus

{{ exo("Création de tableaux",[]) }}

Les fonctions ci-dessous pourront être utiles pour tester les fonctions des autres exercices :

1. Une fonction `cree_tableau` qui prend en argument trois entiers `taille vmin vmax`  et crée un tableau de taille `taille` contenant des entiers au hasard compris entre `vmin` et `vmax`

    !!! aide
        On rappelle que `Random.int` prend en argument un entier `n` et tire au hasard un entier compris entre 0 **inclus** et `n` **exclus**

2. Une fonction `affiche_tableau` qui prend en argument un tableau d'entiers et affiche les éléments de ce tableau. 

{{ exo("Rechercher un élément",[]) }}

On veut écrire la fonction `appartient` 'a -> 'a array -> bool qui renvoie `true` ou `false` suivant que l'élément se trouve ou non dans le tableau. Par exemple, `appartient 2 [|6; 7; 9; 12 |]` s'évalue à `false`.

1. Proposer une solution utilisant une boucle `for`, peut-on quitter la boucle dès que l'élément est rencontré (à la façon de ce qu'on a pu faire à C) pourquoi ?

2. Proposer une solution utilisant une boucle `while`, cette fois est-il possible de quitter la boucle dès qu'on rencontre l'élément ? 

3. Proposer une version récursive n'utilisant pas de boucle.



{{ exo("Algorithmes classiques (pour réviser)",[]) }}

1. Ecrire en OCaml une fonction permettant de trier un tableau d'éléments par la méthode de votre choix, on rappelle qu'il faut connaitre (et avoir déjà implémenté) au moins une fois :

    * le tri par insertion
    * le tri par sélection
    * le tri à bulles
    * le tri fusion

2. Implémenter l'algorithme de recherche dichotomique en OCaml

{{ exo("Crible d'Erastothène",[]) }}

On rappelle qu'un nombre premier est un entier naturel ayant exactement deux diviseurs 1 et lui-même, ainsi 13 est premier mais pas 15. Le [crible d'Erastothène](https://fr.wikipedia.org/wiki/Crible_d%27%C3%89ratosth%C3%A8ne) est un algorithme permettant de trouver tous les nombres premiers inférieurs ou égaux à un entier `n` donné. 

!!! abstract "Algorithme"
    * on crée un tableau de booléens `premiers` de taille `n+1`
    * on initialise le tableau à `true` sauf `premiers[0]` et `premiers[1]` qui sont à `false` puisque  $0$ et 1 ne sont pas premiers.
    * on parcourt ce tableau si `premiers[i]` est à `true` alors on met tous ses multiples (sauf lui-même) à `false`
    * le parcours s'arrête dès que l'entier `i` est supérieur à $\sqrt{n}$.  

1. Ecrire  une fonction `crible` qui prend en paramètre un entier `n` et implémente cet algorithme de façon à renvoyer le tableau de booléens issu du crible (c'est à dire tel que `tab.(i)` contient `true` si `i` est premier et  `false` sinon)

2. Ecrire une fonction `premiers` qui prend en argument un entier `n`, utilise la fonction précédente puis crée la liste des nombres premiers jusqu'à `n`.

3. Ecrire  fonction `somme_premiers` qui prend en argument un entier `seuil` et renvoie la somme de tous les nombres premiers inférieurs ou égaux à `seuil`. Par exemple `somme_premiers(100)` renvoie `1060`.

4. Utiliser votre fonction pour calculer la somme des nombres premiers jusqu'à 100000. Tester votre réponse dans le formulaire suivant : {{check_reponse("454396537")}}
