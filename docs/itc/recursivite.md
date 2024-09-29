{% set num = 6%}
{% set niveau = "itc_s1"%}
{{ titre_chapitre(num,niveau)}}

## Exemple introductif

On veut écrire une fonction qui produit l'affichage de triangles de `n` lignes, la première ligne contenant un `*`, la seconde deux `*` et ainsi de suite. Par exemple pour `n=4`, la fonction doit afficher :
```
*
**
***
****
```

Une des possibilités est d'utiliser une boucle, on dit que la fonction est **itérative**  :
```python
def triangle(n):
    for i in range(1,n+1):
        print("*"*i)
```
{{IDE()}}

En observant la représentation ci-dessous, on constate aussi qu'il est possible de définir un triangle de `5` lignes par rappport à un triangle de `4` lignes, et plus généralement un triangle de `n` lignes par rapport à un triangle de `n-1` lignes : 

![triangle_recursif](./Images/C6/triangle_rec.png){widtht=500px .imgcentre}

En effet, construire un triangle de `n` lignes c'est :

* construire un triangle de `n-1` lignes
* ajouter une ligne de `n` étoiles

on vient de donner une méthode de construction **récursive**, qui doit se compléter en précisant qu'elle n'est valable que pour `n>0`. Cette définition trouve se traduit en python par :
```python
def triangle_recursif(n):
    if n>0:
        triangle_recursif(n-1)
        print('*'*n)
```

## Définition

!!! retenir "A retenir"
    Une fonction est dite **récursive** lorsqu'elle fait appel à elle-même. Par conséquent,

    * une fonction récursive permet, comme une boucle, de répéter des instructions puisque le bloc d'exécution de la fonction est rappelé (mais avec des paramètres différents).
    * une même fonction peut donc se programmer de façon *itérative* (avec des boucles) ou de façon récursive (en s'appelant elle-même).
    * une fonction récursive doit toujours contenir *au moins* une condition d'arrêt (sinon elle s'appellera elle-même à l'infini)


## Exemples corrigés

### Factorielle d'un entier

La [factorielle d'un entier](https://fr.wikipedia.org/wiki/Factorielle){target=_blank} est le produit de cet entier par tous ceux qui le précèdent (excepté 0). Cette fonction a [déjà été programmé de façon itérative](http://127.0.0.1:8000/cpge-info/itc/bases/#exercice-7-factorielle) mais elle s'exprime aussi par rapport à elle même et donc peut être programmé de façon récursive, en effet :  
$n! = n  \times \underline{(n-1)\times \dots \times 1}$ et puisque la partie soulignée vaut $(n-1)!$ :  
$n! = n \times (n-1)!$  
Cette écriture se traduit directement en Python par :
```python linenums="1"
def factorielle(n):
    if n==0:
        return 1
    else:
        return n*factorielle(n-1)
```

Il faut bien comprendre que par exemple pour calculer `factorielle(4)` python procédera de la façon suivante :

* calculer `factorielle(3)` et le multiplier par 4
* calculer `factorielle(2)` et le multiplier par 3
* calculer `factorielle(1)` et le multiplier par 2
* calculer `factorielle(0)` et le multiplier par 1
* comme la condition d'arrêt donc `factorielle(0)=1`, on peut remonter dans le calcul et obtenir 24

### Somme des éléments d'une liste

La somme des élements d'une liste $l = [l[0],\dots l[1]]$ peut s'exprimer ainsi :

* si la liste est vide c'est zéro (condition d'arrêt)
* sinon c'est le premier élément de la liste plus la somme de la liste à partir du second élément

c'est donc une définition récursive puisque nous avons exprimé la somme d'une liste à partir de la somme d'une (autre) liste. En python, il suffit de pouvoir exprimer la liste à partir du second élement à l'aide du tranche et on peut écrire :

```python
def somme(l):
    if l==[]:
        return 0
    else:
        return l[0] + somme(l[1:])
```

### Retourner une chaine de caractère

!!! note
    En cas de besoin, on conseille de revoir les [tranches](https://fabricenativel.github.io/cpge-info/itc/listes/#tranches){target=_blank} avant d'aborder cet exemple.

On veut écrire une fonctions récursive qui renvoie la chaine de caractère donnée en argument à l'envers. Par exemple `envers("Python")` doit renvoyer `"nohtyP"`. Comme précédemment, afin d'écrire une version récursive de cette fonction, il faut exprimer l'envers d'une chaine par rapport à l'envers d'une autre chaine (plus courte). On peut remarquer que pour écrire une chaine à l'envers, il suffit d'écrire son dernier caractère puis l'envers du reste de la chaine ce qui se traduit en Python par :

```python
def envers(chaine):
    if chaine=="":
        return ""
    else:
        return chaine[-1] + envers(chaine[0:-1])
```

{{exo("A vous de jouer !",[],0)}}

1. Ecrire une version récursive des fonctions suivantes :

    1. Fonction `puissance`, qui prend en argument un nombre $x$ et un entier $n$ (positif) et renvoie $x^n$.

    2. Fonction `palindrome`, qui prend en argument une chaine de caractère et qui renvoie `true` lorsque cette chaine est un palindrome

    3. Fonction `maximum`, qui prend en argument une liste d'entiers et renvoie le maximum des éléments de cette liste.

    4. Fonction `occurences`, qui prend en argument une liste d'entiers `l` et un entier `n` et renvoie le nombre d'apparitions de `n` dans `l`.

5. Modifier la fonction `triangle_recursif` de l'[exemple introductif](#exemple-introductif) afin d'afficher le même triangle mais "pointe vers le bas".