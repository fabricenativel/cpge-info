{% set num = 2 %}
{% set niveau = "itc_s1"%}
{{ titre_chapitre(num,niveau)}}

## Retour sur les chaines de caractères

On a déjà rencontré les chaines de caractères en Python, elles s'écrivent entre guillemets (`"`) ou apostrophes (`'`) et sont constituées d'une séquence de caractères auxquels on peut accéder directement grâce à leur indice (ou index) c'est-à-dire leur numéro à partir de 0 en utilisant la notation `[]`. Par exemple,
```python
exemple = "L'informatique c'est fantastique !"
a = exemple[0] # a vaut 'L' (le premier caractère)
b = exemple[3] # a vaut 'n' (le quatrième caractère)
```
D'autre part, la longueur d'une chaine de caractères (c'est-à-dire le nombre de caractères qu'elle contient) s'obtient avec la fonction `#!python len`. Par exemple `#!python len("PCSI")` vaut 4. Les indices des caractères d'une chaine `c` vont de `0` à `#!python3 len(c)-1`. Un accès au-delà de l'indice `len(c)-1` provoquera une erreur (`IndexError`).

!!! note
    On retiendra notamment que le *dernier* caractère d'une chaine `c` est celui d'indice `#!python len(c)-1`

!!! danger
    Les valeurs négatives d'indice sont acceptées en Python et sont alors considérés comme une numérotation à partir de $-1$ et depuis la fin de la chaine. c'est-à-dire que `c[-1]` est le dernier caractère de la chaine c, `c[-2]` son avant dernier, etc ..  
    Cette notation n'est *pas* au programme et ne sera pas utilisée dans le cadre de ce cours.

L'accès aux caractères via la notation `[]` associé à une boucle {{mpy('for')}}, permet d'effectuer un **parcours** d'une chaine de caractères afin de "sélectionner" un à un les caractères et éventuellement d'effectuer un traitement sur ces caractères. Typiquement, sur une chaine `c`, cette boucle prend la forme suivante : {{mpy('for i in range(len(c))')}} puisqu'alors la variable `i` prend les valeurs allant de 0 à {{mpy("len(c)-1")}} (inclus) ce qui correspond bien aux domaine valide des indices d'une chaine  `c`.

Par exemple, supposons qu'on veuille écrire une fonction permettant de compter le nombre de voyelles dans une chaine de caractères (écrite en majuscules), on pourrait écrire :

{{ IDE("scripts/compte_voyelle.py")}}

{{ exo("Test de présence",[],0) }}
1. Ecrire une fonction `est_dans` qui prend en argument une chaine de caractères `chaine` et un caractère `c` et qui renvoie `True` si  `c` est dans chaine et `False` sinon.

    !!! aide
        On rappelle que l'instruction `return` permet de quitter immédiatement une boucle.

2. Mofifier la fonction précédente afin qu'elle renvoie l'indice de la *première* occurence de  `c` dans `chaine` ou $-1$ si `c` n'apparaît pas dans chaine.

{{ exo("Nombre d'occurences",[])}}

Ecrire une fonction `compte_occurence` qui prend en argument une chaine de caractères `chaine` et un caractère `c` et qui renvoie le nombre d'apparitions de `c` dans `chaine`. Par exemple `compte_occurence("magnifique","i")` renvoie 2.

{{ exo("Somme des codes",[])}}
En informatique, chaque caractère est associé à un entier : son code *unicode*, par exemple le code *unicode* du caractère `A` est 65. En Python, pour obtenir le code *unicode* d'un caractère on utilise la fonction `ord`, ainsi `ord('A')` vaut 65. Déterminer la somme de tous les codes *unicode* des caractères de la phrase "*L'informatique en PCSI, c'est vraiment le top !*" ?  
**Attention** : les guillemets ne font pas partie de la phrase. 

!!! note "Remarques"
    * En tapant `#!python3 ord("A")` dans le terminal ci-dessous vous pouvez vérifier qu'on obtient bien 65.
    * L'unicode étend le code {{sc("ascii")}} qui est parfois plus connu. En effet, lorsque le code {{sc("ascii")}} d'un caractère existe, il correspond à son code unicode. Ainsi le code {{sc("ascii")}} de `A` existe (et vaut donc aussi 65), mais `ù` n'est pas un caractère {{sc("ascii")}} et n'a donc pas de code {{sc("ascii")}} mais a bien un code unicode : 249.

{{ IDE(MIN_SIZE=7) }}

Vérifier votre réponse : {{check_reponse("4118")}}

{{ exo("Caractères identiques",[])}}

Ecrire une fonction `identiques` qui prend en argument deux chaines de caractères `c1` et `c2` et renvoie le nombre de fois où `c1` et `c2` ont le même caractère au même indice. Par exemple `identiques("python","poterie")` renvoie 2 car ces deux chaines coïndicent à l'indice `0` (un `p`) et à l'indice `2` (un `t`).

!!! important
    A noter qu'on peut accéder aux caractères d'une chaine mais pas les modifier ! Par exemple l'instruction de la ligne 2 ci-dessous provoque une erreur : `TypeError: 'str' object does not support item assignment`
    ```python
    exemple = "python"
    # On essaye de mettre une majuscule donc de remplacer le "p" par "P"
    exemple[0] = "P"
    ```

## Tranches

Une *tranche* (en anglais *slice*) d'une chaine de caractères s'obtient en donnant les indices de départ (*compris*) et de fin (*exclu*) séparé par le caractère `:` entre crochets. Par exemple, si on considère la chaine {{mpy("exemple = 'Bonjour'")}} dont on donne les indices des caractères ci-dessous :
{{indices("Bonjour",True)}}

* {{mpy("exemple[0:3]")}} vaut `"Bon"`
* {{mpy("exemple[3:7]")}} vaut `"jour"`
* {{mpy("exemple[3:5]")}} vaut `"jo"`

A noter que :

* si le début de tranche n'est pas précisé alors la tranche démarre au début de la chaine, par exemple {{mpy("exemple[:5]")}} vaut `"Bonjo"`
* si la fin de la tranche n'est pas précisée alors elle se termine à la fin de la chaine, par exemple {{mpy("exemple[4:]")}} vaut `"our"`
* et donc en précisant ni le début ni la fin, la tranche est la chaine complète, par exemple {{mpy("exemple[:]")}} vaut `"Bonjour"`

De la même façon que l'instruction `range`, une tranche accepte un troisième paramètre optionnel qui indique un pas de progression dans la récupération des caractères de la chaine. Par exemple, {{mpy("exemple[::2]")}} vaut `"Bnor"` car on ne récupère que les caractères situés aux indices `0, 2, 4` et `6`.

!!! note
    Les pas négatifs sont possibles, par conséquent {{mpy("exemple[::-1]")}} signifie par exemple récupérer tous les caractères à partir de la fin jusqu'au début et donc inverse l'ordre des caractères pour créer une nouvelle chaine qui  vaut `"ruojnoB"`.

{{ exo("Extraire des tranches",[])}}

{{ IDE("scripts/tranches.py")}}

## Tuples

De la même façon, qu'une chaine de caractères est une séquence de caractères repérés par des indices, un **tuple** est une séquence de valeur (de type quelconque) repéré par des indices. Par exemple :

* {{mpy("coordonnees = (3.2, -5.8, 7.0)")}}
* {{mpy("notes = (12, 4, 7, 11, 13, 15)")}}
* {{mpy('anniversaire = (31, "Janvier", 1956)')}}
* {{mpy('voyelles = ("a","e","i","o","u","y")')}}
* {{mpy('reponses = (True, False, False, True, False)')}}

Les éléments d'un tuple peuvent donc être de n'importe quel type et comme dans le troisième exemple être de types différents.

Ce qui a été vu sur les chaines de caractères reste en grande partie valide sur les tuples, notamment :

* on accède aux éléments d'un tuple avec la notation `[]`, on peut donc *parcourir* les éléments d'un tuple à l'aide d'une boucle `for`. Par, exemple `#!python mois = anniversaire[1]`
* on ne peut pas modifier les éléments d'un tuple. Par exemple `anniversaire[1] = 1` provoque une erreur `TypeError`
* la fonction `len` renvoie le nombre de valeurs présentes dans le tuple. Par exemple `len(anniversaire)` renvoie 3.
* la syntaxe des tranches est identique mais une tranche de tuple est un tuple. Par exemple `notes[:3]` renvoie `(12,4,7)`.

La particularité des tuples est de pouvoir être *décompacté* afin que chaque élément soit affecté à une valeur, par exemple :

* `#!python x, y, z =  coordonnees` va affecter `3.2` à `x`, `-5.8` à `y` et `7.0` à `z`
* `#!python mois, jour, annee = anniversaire` va affecter `31` à jour, `"Janvier"` à `mois` et `1956` à `annee`.

!!! danger
    Décompacter un tuple sans prévoir autant de variables que d'éléments dans le tuple provoque une erreur `ValueError`.

{{exo("Moyenne d'un tuple",[])}}

Ecrire une fonction prenant en argument un tuple d'entiers de longueur strictement positive et qui renvoie la moyenne des valeurs de ce tuple.

## Itérables

Les chaines de caractères et les tuples sont tous deux des **itérables** de Python c'est-à-dire qu'on peut les parcourir directement à l'aide d'une boucle `for` qui prend alors la syntaxe suivante : `#!python for <element> in <iterable>`, notez bien l'absence de `range`. Dans ce cas, la variable de parcours n'est pas un entier (contrairement à la version avec `range`) mais directement les valeurs de l'itérable. 

!!! retenir "A retenir"
    * Avec la syntaxe `#!python for <indice> in range(<entier>)`, on effectue le parcours d'un itérable par indice.
    * Avec la syntaxe `#!python for <element> in <iterable>`, on effectue le parcours d'un itérable par valeur.
    * Exemples :  
        * `#!python for i in range(len("Bonjour"))`, la variable de parcours est *l'indice* des caractères successif de la chaine et donc prend les valeurs `0,1,...,6`
        * `#!python for lettre in "Bonjour"`, la variable de parcours est directement un caractère de la chaine et donc prend les valeurs `'B', 'o', ..., 'r'`


{{ exo("Faire un parcours par élément",[])}}

Reprendre les deux exercices ci-dessous en effectuant obligatoirement un parcours par élément dans l'écriture de la fonction.

1. Ecrire une fonction `est_dans` qui prend en argument une chaine de caractères `chaine` et un caractère `c` et qui renvoie `True` si  `c` est dans chaîne et `False` sinon. 

2. Ecrire une fonction prenant en argument un tuple d'entiers de longueur strictement positive et qui renvoie la moyenne des valeurs de ce tuple.

## Non mutabilité

En Python, certains types de variables sont dits **non mutables**, cela signifie notamment que ces variables ne *seront pas modifiées* dans les fonctions qui les utilisent. Tout se passe comme si une copie de la variable était envoyée à la fonction, les modification sur la copie (dans la fonction) n'affecteront pas l'original (dans le bloc qui appelle la fonction).
 
 Par exemple :
 {{ IDE("scripts/mutables.py")}}

!!! retenir "A retenir"
    Les types suivants de Python sont *non mutables* : `int`, `float`, `bool`, `str`, `tuple`, on ne modifie pas une variable de ce type en la passant à une fonction.

A noter que si on souhaite modifier une valeur non mutable, on peut la passer à une fonction et lui affecter la valeur renvoyée par cette fonction. Par exemple, pour incrémenter une variable de type `int` on pourrait écrire :

 Par exemple :
 {{ IDE("scripts/mutables2.py")}}


## Les listes de Python

Les listes de Python sont des séquences de valeurs **modifiables** repérées (comme les tuples et les chaines de caractères) par leur indice. Elles se notent entre crochets et les valeurs sont séparées par des virgules. Par exemple,

* {{mpy("temperatures = [24, 26, 26, 28, 28, 30, 29, 27, 27]")}}
* {{mpy('anniversaire = [23, "Juin", 1912]')}}
* {{mpy('points = [("A",-2,3),("B",2,7),("C",1,0)]')}}

On retrouve sur les listes les mêmes fonctionnalités vu sur les tuples (et les chaines de caractères) :

* longueur avec `len`
* accès à l'élément d'indice `i` de la liste `l` grâce à la syntaxe `l[i]`
* syntaxe d'extraction des tranches
* parcours par élément avec `in` ou parcours par indice avec `range`

De plus au contraire des tuples, les valeurs présentes dans une liste sont *modifiables*, par exemple :
```python
courses = ["oignons", "chips", "oranges", "sel", "poivre"]
# finalement on prend des cacahuètes à la place des chips :
courses[1] = "cacahuètes"
```

D'autre part les deux opérations suivantes sont possibles sur les listes (on fera bien attention à la syntaxe et notamment à l'absence de `=`) :

* ajouter un élément à la fin de la liste grâce à `append`, pour ajouter `x` à la fin de la liste `l`, on écrit `#!python l.append(x)`
* supprimer le dernier élément d'un liste grâce à `pop`, pour supprimer le dernier élément de la liste `l`, on écrit `#!python l.pop()`
* l'instruction précédente (c'est-à-dire `#!python l.pop()`) renvoie l'élément supprimé, on peut donc le récupérer par exemple pour l'affecter à une variable et écrire par exemple : `#!python dernier = l.pop()`


{{exo("Manipulation de liste",[])}}
On considère la liste de courses ci-dessous :
{{ IDE("scripts/apop.py")}}

1. En utilisant la notation `[]`, remplacer les oranges par des pommes.
2. Ecrire une instruction permettant d'ajouter `"riz"` à cette liste.
3. Ecrire les instructions permettant de supprimer l'avant-dernier élément de cette liste.

## Mutables

Au contraire des autres types de variables rencontrées auparavant, les listes de Python (type `list`) sont *mutables*, une des conséquences importantes est qu'elles sont modifiées lorsqu'on les passe à une fonction. Par exemple 

{{ IDE("scripts/mutables3.py") }}

Autre conséquence, si `l` est une liste et qu'on écrit `m = l`, toute modification de `l`, modifie `m`. Par exemple :
```python
l = [1, 2, 3]
m = l
l.append(4)
# on a modifié l et cette modification affecte aussi m !!!
print(m)
```

## Générations de listes

On peut créer une liste :

* en donnant explicitement la liste de ses éléments, par exemple `amis = ["Pierre", "Paul", "Alice", "Bob"]`
* lorque la liste est composée de le répétition du même élément on peut utiliser `*` à la façon de ce qui a été vu sur les chaines de caractères, par exemple `zeros = [0] * 10` crée une liste contenant 10 zéros.
    !!! danger
        
* par ajouts successifs d'éléments à l'aide de `append`
* par *compréhension* c'est-à-dire en indiquant à l'aide d'une boucle `for` les éléments qui composent la liste (à la façon dont on définit parfois des ensembles en mathématiques). Par exemple `entiers = [i for i in range(10)]` crée la liste `[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]`.

{{exo("Création de listes",[])}}

1. Créer la liste des carrés des entiers de 1 à 10 par ajouts successifs (utiliser une boucle `for`).

2. Créer la liste des carrés des entiers de 1 à 10 par compréhension.

3. Créer la liste des entiers impairs de 1 à 99 par ajouts successifs

4. Créer la liste des entiers impairs de 1 à 99 par compréhension

5. Créer une liste contenant 20 fois `"Python"`

## Importation de fonctions en Python

On peut importer une fonction `f` se trouvant dans une librarie `lib` grâce à la syntaxe : `#!python from lib import f`. Par exemple la fonction racine carrée, `sqrt` n'existe pas nativement mais peut être importée depuis la librairie `math` à l'aide de `#!python from math import sqrt`.

On peut aussi importer la totalité de la librairie `lib` avec `#!python import lib`, par exemple, pour importer la totalité de la librairie `math` on écrit simplement `#!python import math`. Dans ce cas *toutes* les fonctions de la librairie sont accessibles mais on doit les nommer en les préfixant par le nom de la librairie, ici on pourrait donc calculer la racine carrée de 10 avec `racine10 = math.sqrt(10)`.

## Cours

{{fiche_cours(num)}}


## Exercices de synthèse

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
            On rappelle que la fonction `randint` peut être importée depuis le module `random`, elle permet de tirer un nombre en deux valeurs `a` et `b` données en paramètres.

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



{{ exo("Evolution d'une chaine de caractères",[]) }}
On considère une chaine de caractères initialement constituée de $k$ caractères `.` suivie d'un caractère `#` puis de $k$ caractères `#`. Par exemple pour $k=5$ la chaine est `.....#.....` (5 `.` suivi d'un `#` puis de 5 `.`). Cette chaine évolue de la façon suivante :

* si un `.` est entre un `#` et un `.`, il se transforme en `#` sinon il reste un `.`
* si un `#` est entre deux `#` ou s'il a un `#` à sa gauche et un `.` à sa droite, il se transforme en `.` sinon il reste un `#`
* le premier et le dernier caractère ayant un seul voisin, ils ne sont pas affectés par ces règles d'évolutions et restent toujours des `.`

Par exemple dans le cas $k=5$ : les étapes successives d'évolution sont :

* `.....#.....` (état initial :)
* `....###....` (étape 1)
* `...##..#...` (étape 2)
* `..##.####..` (étape 3)
* `.##..#...#.` (étape 4)
* `.#.####.##.` (étape 5)

Dans le cas $k=256$, et à l'étape 1000, combien de `#` contient la chaine ?

{{ IDE(MIN_SIZE=7) }}

Vérifier votre réponse : {{check_reponse("263")}}

{{ exo("Denivelé positif",[]) }}
On donne ci-dessous, une liste d'entiers `altitudes` (déjà présente dans votre mini IDE), qui correspond aux altitudes d'un coureur lors d'une course de montagne. On veut déterminer le *denivelé positif* de ce coureur c'est-à-dire la somme des longueurs des *ascensions*. Par exemple, si la liste `altitudes` est `[330, 490, 380, 610, 780, 550]` alors :

* la course commence par une ascension de dénivelé positif $160$ ($490-330$)
* puis on a une descente (de $490$ à $380$)
* puis une ascension avec un dénivelé positif de $230$ ($610-380$)
* puis une nouvelle ascencion de dénivelé positif $170$ ($780-610$)
* puis une descente (de $780$ à $550$)

Le dénivelé cumulé positif total de cette course est donc $160+230+170=560$

Quel est le dénivelé cumulé positif total de la liste des altitudes donnée dans votre IDE ci-dessous ?


{{ check_reponse("1792") }}

{{IDE("scripts/denivele.py",MIN_SIZE=7, ID=1)}}

??? aide "Indice"
    * Pour obtenir la valeur d'un élément dans une liste de Python, on peut utiliser la syntaxe `liste[indice]`. Par exemple, si `noel = [25,12,2024]` alors `noel[1] = 12` (l'indice du premier élément est 0).
    * Pour parcourir une liste, on peut utiliser un boucle `for` dont la variable représente l'indice de la valeur à laquelle on souhaite accéder. Par exemple `for i in range(3)` crée une variable qui prendra successivement les valeurs `0,1` et `2` (dans un `range` la dernière valeur n'est *pas* prise), cette variable peut être utilisé dans la boucle pour accéder à `noel[0]` puis `noel[1]` et enfin `noel[2]`
    * La fonction `len` s'applique aussi aux listes et renvoie leur nombre d'éléments.

{{ exo("Evolution d'une liste",[]) }}
On considère la liste `carres` des $k$ premiers carrés des entiers *strictement* positifs, par exemple si $k=6$, `carres = [1, 4, 9, 16, 25, 36]`. Sur cette liste on effectue les opérations suivantes :

* on enlève les deux derniers éléments
* s'ils ont même parité on calcule leur somme, sinon leur différence (plus grand moins plus petit)
* on rajoute la valeur calculée à l'étape précédente (la somme ou la différence) la fin de la liste

Par exemple pour `carres = [1, 4, 9, 16, 25, 36]`

* les deux derniers éléments sont `25` et `36`, ils sont enlevés de la liste qui devient `[1, 4, 9, 16]`
* ces deux entiers n'ont pas la même parité, on fait la différence `36 - 25 = 11`
* on ajoute cette valeur à la fin de la liste qui devient `[1, 4, 9, 16, 11]`
On renouvelle ce processus sur la liste obtenue jusqu'à ce qu'elle contienne un unique élément (dans l'exemple ci-dessous on obtient successivement `[1, 4, 9, 5]` puis `[1, 4, 14]` puis `[1, 18]` et enfin `[17]`).

Quel est l'élément restant dans le cas $k=100$ ?

{{ check_reponse("18910")}}

{{IDE(MIN_SIZE=7)}}

??? aide "Indice"
    En python `append` et `pop` permettent d'effectuer les opérations suivantes sur une liste:

    * `append` ajoute l'élément donné en argument à la fin de la liste. Par exemple si `liste_de_courses = ["courgettes","poivrons","tomates","oignons"]`, l'instruction `liste_de_courses.append("aubergines")` va ajouter en fin de `liste_de_courses` l'élément `"aubergines"`. **Attention** à la syntaxe qui est `<liste>.append(<element>)`.
    * `pop` modifie une liste en lui enlevant son *dernier* élément et renvoie ce dernier élément. c'est-à-dire que le résultat d'un `pop` (l'élément supprimé) peut-être utilisé (pour donner une valeur à une variable par exemple). Par exemple si `matieres = ["Informatique","Anglais","Maths","Physique","SVT"]`, l'instruction `supprime = matieres.pop()` a **deux** effets :
        * le dernier élément de `matieres` est supprimé la liste devient `matieres = ["Informatique","Anglais","Maths","Physique"]`
        * ce dernier élément devient la valeur de `supprime` (et donc `supprime = "SVT"`)

{{ exo("Points du plan",[])}}
Dans votre IDE ci-dessous, est déjà définie une liste de points du plan, chaque point est représenté par un *tuple* de python à deux éléments : son abscisse et son ordonnée. Par exemple `points = [ (2,-1), (3,5)]` contient les points de coordonnées $(2,-1)$ et $(3,5)$. Quelle est la plus courte distance entre deux points de la liste de points définie dans l'éditeur ci-dessous (valeur arrondie au centième) ?

{{IDE("scripts/points.py",MIN_SIZE=7, ID=3)}}

Véfifier votre réponse : {{check_reponse("1.41")}}