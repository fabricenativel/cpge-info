{% set num = 0 %}
{% set niveau = "itc_s3"%}

{{ titre_chapitre(num,niveau)}}

## Cours

{{ cours(num) }}

Les exemples vu en cours

* ??? python "Syracuse"
    ```python
    --8<-- "C0/syracuse.py"
    ```

* ??? python "Série harmonique"
    ```python
    --8<-- "C0/harmo.py"
    ```

* ??? python "Calcul du PGCD"
    ```python
    --8<-- "C0/pgcd.py"
    ```

* ??? python "Recherche simple dans une liste"
    ```python
    --8<-- "C0/est_dans.py"
    ```

* ??? python "maximum des éléments d'une liste"
    ```python
    --8<-- "C0/max_liste.py"
    ```

## TP

### Pour démarrer en douceur

{{ exo("Premières fonctions",[],0)}}

1. Ecrire une fonction `perimetre_rectangle` qui prend en argument en argument deux entiers `longueur` et `largeur` et renvoie le perimètre du rectangle de dimension `longueur`x`largeur`


3. Ecrire une fonction `est_triangle` qui prend en argument trois entiers `a`,`b` et `c` et qui renvoie `true` si ces trois entiers peuvent être les longueurs des trois côtés d'un triangle. 

    !!! aide
        Cela revient à vérifier que les trois entiers vérifient l'inégalité triangulaire ou encore que le plus grand des trois est inférieur à la somme des deux autres.

4. On appelle *factorielle* d'un entier $n$ et on note $n!$ le produit de cet entier par tous ceux qui le précèdent à l'exception de zéro. Et on convient d'autre part que $0!=1$. Par exemple $5! = 5 \times 4 \times \times 3 \times 2 \times 1 = 120$. Ecrire une fonction `factorielle` qui prend en argument un entier `n` et renvoie sa factorielle.

5. Ecrire une fonction `bissextile` qui prend en argument un entier `annee` et renvoie `true` si cette année est bissextile et `false` sinon.

    !!! aide
        Une année est bissextile si elle est divisible par 4 mais pas par 100 ou s'il est divisible par 400.

6. Ecrire une fonction prenant en entrée un entier $n$ et renvoyant le plus petit entier $k$ tel que $2^k \geq n$.

7. Ecrire une fonction prenant en entrée un entier $n$ et qui renvoie    $\displaystyle{\sum_{k=1}^{n} k^2}$.

{{ exo("Un peu de dessin",[]) }}

1. Ecrire une fonction `carre_plein` prenant comme paramètre un entier `cote` et un caractère `car` et permettant d'afficher un carré de côté `cote` rempli de caractères `car`. Par exemple, `carre(5,'C')` produit l'affichage suivant :
```
CCCCC
CCCCC
CCCCC
CCCCC
CCCCC
```

2. Ecrire une fonction `rectangle_creux`  prenant trois paramètres : deux entiers `largeur` et `longueur` et un caractère `car` permettant d'afficher un rectangle creux de dimensions `largeur` sur `longueur` dont la bordure est constitué de caractères `car`. Par exemple `rectangle_creux(3,7,'~')` devrait produire l'affichage suivant :
```
~~~~~~~
~     ~
~~~~~~~
```

3. De la même façon écrire une fonction `triangle` prenant comme paramètre un entier `hauteur` et un caractère `car` telle que `triangle(6,'*')` produise l'affichage suivant :
```
     *
    ***
   *****
  *******
 *********
***********
```

{{ exo("Simulation d'un lancer de dé",[])}}

Au jeu des ["petits chevaux"](https://fr.wikipedia.org/wiki/Jeu\_des\_petits\_chevaux){target=_blank}, le joueur doit lancer un dé à six faces pour et obtenir 6 pour "sortir un de ses chevaux de l'écurie". On se demande, en moyenne combien de coups  il faut pour obtenir un 6 sur un lancer de dé.

1. En utilisant le module `random`,  écrire une fonction `lancer_de` qui ne prend aucun argument et renvoie un nombre choisir au hasard entre 1 et 6.
2. Ecrire une fonction, `obtenir6` qui ne prend aucun argument et qui renvoie le nombre lancer effectué pour obtenir une première fois 6.
3. Calculer la moyenne du nombre de coups nécessaire pour obtenir un six pour un grand nombre de parties (par exemple 10000).

{{exo("Pierre, feuille, ciseaux",[])}}

Ecrire un programme permettant de jouer à pierre-feuille-ciseaux contre l'ordinateur. On pourra procéder en 

1. Ecrivant une fonction `gagnant` qui prend en argument deux entiers représentant les choix de l'ordinateur et celui du joueur (par exemple : 0 = pierre, 1 = feuille, 2 =ciseaux) et renvoie le résultat de la partie sous la forme d'une chaine de caractères comme par exemple ("match nul" ou "joueur gagnant")
2. Ecrire une fonction `choix_ordi` qui renvoie un choix aléatoire parmi les trois possibilités

    !!! aide
        On rapelle que la fonction `randint` du module `random` permet de choisir un entier naturel compris entre les deux entiers donnés en argument.

3. Ecrire une fonction `choix_joueur` sans argument qui renvoie le choix du joueur

4. Utiliser les trois fonctions précédentes 

{{exo("Nombre premier",[])}}

Ecrire une fonction `est_premier` qui prend en argument un entier $n$ et renvoie `True` si ce nombre est premier et `False` sinon.

!!! aide
    On pourra se contenter de tester si les entiers  $k$ compris entre 2 et $\sqrt{n}$ divisent $n$.

### Sur les listes

{{ exo("Génération de listes en Python",[])}}

1. On considère le programme suivant :
```python
liste1 = [0]*100
liste2 = [0 for k in range(100)]
liste3 = []
for k in range(100):
    liste3.append(0)
```

    1. Quel est le contenu de chacune des listes ?
    2. Indiquer par quel procédé chacune de ces listes a été crée.

2. Ecrire un programme python permettant de créer les listes suivantes :
    1. Une liste contenant 12 fois le chiffre 7.
    2. La liste des nombres entiers de 1 à 100.
    3. Une liste contenant 1000 nombres tirés au sort entre 1 et 6.

        !!! Aide 
            On rappelle que la fonction `randint` peut être importer depuis le module `random`, elle permet de tirer un nombre en deux valeurs `a` et `b` données en paramètres.

    4. La liste des cubes des entiers de 1 à 10.


{{ exo("Parcours de listes en Python",[])}}

On suppose qu'on dispose d'une liste de notes, on veut écrire une fonction qui renvoie le nombres de notes qui sont en dessous de la moyenne. 

1. On considère une première version de cette fonction :
```python
def inferieur_moyenne(liste_notes):
	nb = 0
	for note in liste_notes:
	    if .....:
	    	nb = .......
	return ...
```
    1. Recopier et compléter cette fonction
    2. Tester cette fonction 

2. Voici une deuxième version de cette fonction :
```python
def inferieur_moyenne(liste_notes):
	nb = 0
	for indice in ........:
	    if ........... : 
	    	nb = .......
	return ...
```
    1. Recopier et compléter cette fonction
    2. Tester cette fonction

3. Quelle est la différence principale entre ces deux versions de la même fonction ?
4. Ecrire les fonctions suivantes :
    
    2. `somme_liste` qui prend comme argument une liste non vide de nombres et renvoie la somme de ces nombres.
    3. `moyenne_liste` qui prend comme argument une liste non vide de nombres et renvoie la moyenne de ces nombres.
    4. `max_liste` qui prend comme argument une liste non vide de nombres et renvoie le plus grand de ces nombres.
    5. `min_liste` qui prend comme argument une liste non vide de nombres et renvoie le plus petit de ces nombres.

{{ exo("Recherche d'occurences",[])}}

1. Ecrire une fonction `present` qui prend en argument un elément `elt` et une liste `liste`   et qui renvoie `True` si `elt` se trouve dans la liste `liste` et `False` sinon. Par exemple `present(3,[1,4,5])` renvoie `False`, par contre `present(4,[1,4,5])` renvoie `True`.
2. Tester cette fonction
3. Ecrire une fonction `occurence` qui renvoie le nombre de fois où `elt` apparaît dans `liste`.
4. Ecrire une fonction `indice` qui renvoie l'indice de la première apparition d'`elt`dans `liste`. On renvoie $-1$ si `elt` ne se trouve pas dans `liste`.


{{ exo("Chaines de caractères",[]) }}

1. Ecrire une fonction `compte_caractere(s,c)` qui prendre en argument une chaîne de caractère `s` et un caractère `c` et retourne le nombre de fois où `c` apparait dans `s`. Par exemple `compte_caractere("informatique","i"")` renvoie 2 puisqu'il y a deux `i` dans le mot `informatique`
2. Ecrire une fonction `inverse` qui prend en argument une chaîne de caractère et retourne cette chaîne écrite à l'envers. Par exemple, `inverse("Python")` donnera `"nohtyP"`.
3. Ecrire une fonction `compare` qui prend en argument deux chaînes de caractères et renvoie le nombre de fois où ces deux chaines on la même lettre au même emplacement. Par exemple, `compare("Python","Poterie")` retourne 2 car le "P" et le "t" sont situés aux mêmes emplacements dans les deux mots.

### Manipulations de fichiers

{{ exo("Nombre de lignes",[])}}
Ecrire une fonction qui prend en paramètre un nom de fichier et retourne le nombre de lignes de ce fichier.

{{ exo("Somme des entiers dans un fichier",[])}}

Le fichier `entiers.txt` téléchargeable ci-dessous contient sur chaque ligne un entier. Ecrire un programme Python qui lit ce fichier et fait la somme de ces entiers.
{{telecharger("entiers.txt","../itc/files/C0/entiers.txt")}}

{{ exo("Recherche dans un dictionnaire",[])}}

Pour cette exercice on utilise le dictionnaire téléchargeable ci-dessous:
{{ telecharger("Dictionnaire",".itc//files/C0/dictionnaire.txt")}}

1. Combien il y a-t-il de mots dans ce dictionnaire ?
2. Lister tous les mots de 17 lettres de ce dictionnaire.
3. Quel est le plus grand mot de ce dictionnaire ?
4. Lister tous les mots de 5 lettres qui ont un *d* en deuxième position et se terminent par un *e*.
5. Lister tous les mots palindromes de ce dictionnaire (un mot palindrome est un mot pouvant se lire indifféremment dans les deux sens par exemple *kayak* ou *été*)

### Exercices de synthèse

{{ exo("Conjecture de syracuse",[])}}

La [conjecture de syracuse](https://fr.wikipedia.org/wiki/Conjecture_de_Syracuse){target=_blank} est l'hypothèse selon laquelle la suite définie $(u_n)_{n \in \mathbb{N}}$ définie par son premier terme $u_0$ et la relation de récurrence :  
$u_{n+1} = \left\{ \begin{array}{ll} \dfrac{u_n}{2} & \mathrm{\ si\ } u_n \mathrm{\ est \ paire} \\ 3u_n+1 & \mathrm{\ sinon} \\ \end{array} \right.$  
atteint 1. Dans la suite de cette exercice on supposera cette conjecture vérifiée.

1. Ecrire la fonction `terme_suivant` qui prend en argument un entier $n$ et renvoie $\dfrac{n}{2}$ si $n$ est paire et $3n+1$ sinon.
2. Ecrire une fonction `duree_vol` qui prend en argument un entier $u_0$ et renvoie le plus petit entier $n$ appelé *durée de vol* tel que $u_n=1$. Par exemple `duree_vol(7)` doit renvoyer 16,en effet les termes successif de la suite sont `7, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4 ,2, 1`.
3. Quelle est la plus grande durée de vol lorsque $1 \leq u_0 \leq 1000$. Pour quelle(s) valeur(s) de $u_0$ est-elle atteinte ?


{{ exo("Problème de Joseph",[]) }}


<div class="centre"><iframe width="560" height="315" src="https://www.youtube.com/embed/uCsD3ZGzMgE" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></div>

Le but de l'activité est d'écrire un programme permettant de résoudre le [problème de Joseph](https://fr.wikipedia.org/wiki/Probl%C3%A8me_de_Jos%C3%A8phe){target=_blank} en révisant les listes de Python.


1. On représente un cercle de `n` soldats par la liste `[1,2,...,n]`. Ecrire une fonction `soldats(n)` qui renvoie la liste `[1,2,....,n]`

2. Afin de repérer l'épée, on décide que le soldat qui la tient se situe *toujours en première position de la liste*. Ainsi avec 5 soldats le cercle initial est `[1,2,3,4,5]` (`1` tient l'épée, il élimine 2 et passe l'épée à 3), donc après une étape la liste sera `[3,4,5,1]` (`3` tient l'épée) 

3. Programmer une fonction `josephus(n)` qui renvoie le soldat survivant pour un cercle de `n` soldats.

4. Quel sera le survivant dans une cercle de 1000 soldats ?

{{ exo("Triangle de Pascal",[]) }}

Ecrire un programme qui prend en argument un entier $1 \leq n \leq 10$ et affiche les $n$ premières lignes du [triangle de Pascal](https://fr.wikipedia.org/wiki/Triangle_de_Pascal){target=_blank}. Par exemple `pascal(4)` affiche :
```
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
```

!!! aide
    * On rappelle que le coefficient situé ligne $n$ et colonne $k$ noté $\displaystyle{\binom{n}{k}}$ se déduit de ceux de la ligne précédente grâce à la formule de Pascal : $\displaystyle{\binom{n}{k} = \binom{n-1}{k-1} + \binom{n-1}{k}}$
    * On pourra utiliser deux tableaux, l'un représentant la ligne précédente et un second la ligne en cours de construction.


{{ exo("Crible d'Erastothène",[]) }}

On rappelle qu'un nombre premier est un entier naturel ayant exactement deux diviseurs 1 et lui-même, ainsi 13 est premier mais pas 15. Le [crible d'Erastothène](https://fr.wikipedia.org/wiki/Crible_d%27%C3%89ratosth%C3%A8ne) est un algorithme permettant de trouver tous les nombres premiers inférieurs ou égaux à un entier `n` donné. 

!!! abstract "Algorithme"
    * on crée une liste de booléens `premiers` de taille `n+1`
    * on initialise le tableau à `true` sauf `premiers[0]` et `premiers[1]` qui sont à `false` puisque  $0$ et $1$ ne sont pas premiers.
    * on parcourt ce tableau si `premiers[i]` est à `true` alors on met tous ses multiples (sauf lui-même) à `false`
    * le parcours s'arrête dès que l'entier `i` est supérieur à $\sqrt{n}$.  

1. Ecrire une fonction `crible` qui prend en paramètre un entier `n` et implémente cet algorithme. L'utiliser pour afficher les nombres premiers inférieurs à 100.

    !!! aide
        Vous devriez obtenir : `2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97`

2. Ecrire une fonction `somme_premiers` qui prend en argument un entier `seuil` et renvoie la somme de tous les nombres premiers inférieurs ou égaux à `seuil`. Par exemple `somme_premiers(100)` renvoie `1060`

{{ exo("Tri par sélection",[] )}}

!!! abstract "Algorithme"
    L'algorithme du *tri par sélection* consiste à :  

    * rechercher le plus petit élement de la liste à partir de l'indice **0**
    * échanger cet élément avec celui situé à l'indice **0**
    * rechercher le plus petit élement de la liste à partir de l'indice **1**
    * échanger cet élément avec celui situé à l'indice **1**
    * et ainsi de suite jusqu'à atteindre la fin de la liste

  
1. Détailler les étapes de cet algorithme lorsqu'on le fait fonctionner sur la liste `[12,10,18,15,14]`
2. Ecrire une fonction `echange` qui prend en argument une liste et deux indices $i$ et $j$ et échange les éléments d'indice $i$ et $j$ de cette liste.
3. Ecrire une fonction `indice_min_depuis` qui prend en argument une liste et un indice $i$ et renvoie l'indice du minimum des éléments de cette liste depuis l'indice $i$.
4. Programmer et tester l'algorithme du tri par sélection


{{ exo("Tri par insertion",[] )}}
!!! abstract "Algorithme"
    * L'algorithme du *tri par insertion* consiste à considérer qu'une partie de la liste (initialement vide) située au début est déjà triée. On parcourt ensuite le reste de la liste et on insère chaque élément à la bonne position dans la partie déjà triée.  
    * Pour réaliser cette insertion, on pourra echanger l'élement avec son voisin de gauche tant qu'il lui est supérieur et que le début de la liste n'est pas atteint.

Programmer et tester cet algorithme.

{{ exo("Recherche dichotomique",[] )}}

!!! abstract "Algorithme"
    Pour rechercher un élement dans une liste **triée**, on peut :

    * partager la liste en deux parties de longueur égale (à une unité près).
    * comparer l'élément cherché avec celui situé au milieu et en déduire dans quel moitié poursuivre la recherche.
    * l'algorithme s'arrête lorsque la zone de recherche est vide.

Programmer et tester cet algorithme

