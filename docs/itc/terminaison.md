{% set num = 10 %}
{% set niveau = "itc_s2"%}
{{ titre_chapitre(num,niveau)}}

## Cours

{{ affiche_cours(num) }}

## Travaux pratiques

{{exo("Recherche simple dans une liste",[],0)}}

On souhaite écrire une fonction `recherche` en Python qui prend en argument une liste `lst` et une élément `elt` renvoie `True` ou `False` suivant que `elt` se trouve ou non dans `lst`. On donne ci-dessous la réponse d'un élève :

```python linenums="1"
def recherche(elt,lst):
    ''' Renvoie True si element est dans liste, False sinon '''
    for x in liste:
        # Si x est bien égal à élément renvoyer True sinon renvoyer False
        if x=element: 
            return True
        else:
            return False
```

1. Recopier ce code puis corriger l'erreur commise sur le test d'égalité à la ligne 5.
2. Vérifier que les tests `recherche(3,[3,10,7])` et `recherche(4,[3,10,7])` renvoient les valeurs attendues.
3. En faisant un test adapté, montrer que cette fonction n'est pas correcte.
4. Doit-on renvoyer `False` si le *premier* élément testé est différent de celui recherché comme indiqué dans le commentaire ligne 4 ?
5. Corriger cette fonction.
6. En vous inspirant de la fonction `recherche` écrire une fonction `occurrences` qui prend en argument une liste `lst` et un élément `elt` et renvoie le nombre d'apparitions de `elt` dans `lst`. Par exemples `#!python occurrences([2,7,1,2,8,2,6],2)` renvoie `3` et `#!python occurrences([2,7,1,2,8,2,6],5)` renvoie 0. 

{{exo("Comptage des éléments d'une liste",[])}}

On suppose qu'on a procédé à une élection, on dispose :

* d'une liste `candidats` donnant les noms des candidats par exemple `#!python ['A', 'B', 'C', 'D']`, 
* d'une liste `votes` représentant les votes. par exemple `#!python ['C', 'B', 'C', 'C', 'D', 'B', 'D', 'B']`, on suppose que cette liste ne contient *que des noms de candidats*

On  veut écrire une fonction `resultats` qui renvoie une dictionnaire dont les clés seront les noms des candidats et les valeurs leurs nombre de vote. . Par exemple, avec les deux listes données en exemple ci-dessus, `resultats` doit renvoyer le dictionnaire `#!python {'A': 0, 'B':3, 'C':3, 'D':2}`

1. Ecrire une version de la fonction `resultats` qui  utilise une fonction `occurrences` qui prend en argument une liste `lst` et un élément `elt` et renvoie le nombre d'apparitions de `elt` dans `lst` (voir exercice précédent). Combien de comparaisons effectue chaque appel à occurrences ? En déduire le nombre de comparaisons effectué par cette version de `resultats`

2. Ecrire une version de la fonction `resultats` qui part d'un dictionnaire dont les clés sont les candidats et les valeurs 0, parcourt la liste `votes` et incrémente la valeur associée au candidat rencontré. Quelle est le nombre de comparaisons effectués par cette version de `resultats` ?

{{exo("Recherche dichotomique dans une liste triée",[])}}

Si une liste est **triée**, un algorithme de recherche plus efficace que la recherche simple (voir exercice 1), appelée *recherche dichotomique* existe. Il consiste pour recherche un élement `x` dans une liste `lst` de longueur `n` à

* comparer `x` à `lst[n//2]`
* en cas d'égalité on renvoie `true`
* sinon on recommence la recherche dans la liste `lst[n//2]` si `x < lst[n//2]` et `lst[n//2+1::]` sinon

Le but de l'exercice est d'écrire une fonction `dichotomie` qui implémente de façon *récursive* cet algorithme.

1. Quelle sont les cas de base de l'arrêt de la récursion ? 
2. Ecrire la fonction `dichotomie`
3. Donner une version itérative de cette fonction.
4. Modifier votre fonction afin qu'elle renvoie l'indice de `x` lorsque `x` est présent dans `lst` et `-1` sinon.

{{ exo("Recherche des deux éléments les plus proches dans une liste",[])}}

Ecrire une fonction `plus_proche` qui prend en argument une liste et renvoie les deux éléments les plus proches de cette liste.

!!! aide
    On pourra procéder en utilisant tous les couples possibles de deux indices c'est à dire pour une liste de longueur `n`:

    * `(0,1), (0,2), ... (0,n-1)`
    * `(1,2), (1,3), ... (1,n-1)`
    * `(2,3), ... (2, n-1)`

    C'est à dire qu'on doit utiliser *deux* boucles imbriquées.

{{exo("Recherche d'un motif dans un texte",[])}}

Pour recherche si un motif `m` (par exemple `"math"`) se trouve dans une texte `t` (par exemple `"C'est super l'informatique"`)on peut utiliser l'algorithme suivant :

* on parcourt chaque caractère de `c`
* si le caractère rencontré correspond au premier caractère du motif `m`, alors on avance dans le motif tant que les caractères coïncident
* si on atteint la fin du motif alors `m` se trouve bien dans `c` sinon on passe au caractère suivant de `c`.

On peut visualiser le fonctionnement de cet [algorithme en ligne ](https://boyer-moore.codekodo.net/recherche_naive.php){target=_blank} (crédit : N. Reveret et L. Abdal).

1. Ecrire une implémentation de cet algorithme en Python
2. Modifier votre fonction afin qu'elle renvoie l'indice de la première apparition du motif `m` s'il est présent (ou `-1` sinon)
3. Modifier de nouveau cette fonction afin qu'elle renvoie la liste des indices des occurrences du motif dans la chaine. Par exemple `recherche("ici","ici, ou encore ici ou même là")` renvoie la liste [0,15].


