{% set num = 1 %}
{% set niveau = "itc_s1"%}
{{ titre_chapitre(num,niveau)}}



## Installation

### Python

=== "Linux"

    Python fait normalement partie intégrante de toutes les distributions Linux, aucune installation n'est nécessaire. Pour le vérifier taper simplement la commande `#!bash python3 --version` dans un terminal (sous ubuntu le raccourci clavier pour ouvrir un terminal est ++ctrl+alt+t++).

=== "Windows"

    1. Télécharger les fichiers d'installation sur [python.org](https://www.python.org/downloads/windows/){target=_blank}. Il faut sélectionner dans les *stable releases*, le fichier d'installation correspondant à votre ordinateur (sur un ordinateur récent cela devrait être la version `64-bit`)
    2. Lancer l'installation en prenant soin de bien cocher l'option `Add Python to PATH` (en bas de la fenêtre du programme d'installation)
    3. Ouvrir un terminal et y taper simplement `python` pour vérifier que tout s'est déroulé correctement

=== "MacOS"
    Sur les ordinateurs Apple récents, Python devrait être déjà installé. Pour le vérifier, lancer un terminal et taper la commande `#!bash python3 --version`.

### IDE

De nombreux environnement intégré de développement (*IDE* pour *I*ntegratred *D*evelopement *E*nvironment en anglais) existent pour programmer en Python. Parmi les plus connus (que vous avez peut-être rencontré au lycée), on peut citer [spyder](https://www.spyder-ide.org/){target=_blank}, [Visual Studio Code](https://code.visualstudio.com/download) ou encore [thonny](https://thonny.org/){target=_blank}. Vous êtes libre d'utiliser celui qui vous convient. En cours, les exemples seront traités avec **thonny**, c'est aussi l'IDE déjà installé sur les ordinateurs de la salle de TP.

### En cas de problèmes ...

Le mini IDE déjà rencontré au chapitre précédent ne nécessite aucune installation et sera toujours disponible ci-dessous :

{{IDE(MIN_SIZE=7)}}

## Premiers pas dans la console

Pour accéder à une *console* Python, taper la commande `python` dans un terminal sur votre ordinateur ou utiliser le terminal ci-dessous intégré dans votre navigateur et qui fonctionnera sans aucune installation de logiciel tiers. 

{{ terminal() }}


### Expressions arithmétiques
Taper dans le terminal `6*7` puis la touche ++return++ pour voir apparaître la réponse à [*la grande question sur la vie, l'Univers et le reste*](https://fr.wikipedia.org/wiki/La_grande_question_sur_la_vie,_l%27Univers_et_le_reste){target=_blank}. En mode *console* Python évalue donc les expressions arithmétiques entrées au clavier et affiche leur valeur dans la console. Les opérateurs utilisés dans ces expressions sont rappelés ci-dessous

!!! retenir "A retenir !"
    En Python, les expressions arithmétiques utilisent les opérateurs suivants :

    * `+` : addition
    * `-` : soustraction
    * `*` : multiplication
    * `/` : division décimale
    * `//`: quotient dans la division euclidienne
    * `%` : reste dans la division euclidienne (particulièrement utile pour les tests de divisibilité)

{{exo("Evaluations d'expressions arithmétiques",[],0)}}
 
Calculer les expressions suivantes (vous pouvez vérifier vos résultats en les entrant dans le formulaire idoine)

* Calculer $(547 \times 915) + (1789 \times 1815)$  {{check_reponse("3747540")}}
* Calculer $212^{7} - 313^{3}$  {{check_reponse("19246467284425111")}}
* Déterminer le reste dans la division euclidienne de 123456789 par 2024  {{check_reponse("885")}}
* Donner les 5 derniers chiffres de $2024^{30}$  {{check_reponse("17376")}}


{{ terminal() }}

### Entiers et flottants

Le dernier exemple de l'exercice précédent semble montrer qu'*il n'y a pas de limitations au nombre de chiffres des entiers en Python*. En tapant `2024.0**30` dans la console, on obtient un résultat bien différent. En effet, `2024` est un entier de Python, il est du type `int` alors que `2024.0` est un nombre à virgule flottante de Python, il est du type `float`. Les représentations internes et les algorithmes de calculs utilisés sur ces deux types de nombres sont **différents** (ces points seront abordés dans le courant de l'année). En tapant `2024.0**100`, on peut aussi constater que les nombres trop grands ne semblent pas avoir de représentation flottante (on parle de dépassement de capacité ou *overflow* en anglais), alors que `2024**100` ne posera aucun problème à Python.

!!! Retenir "A retenir"
    Python utilise deux types de nombres :

    * les entiers (type `int`) dont la taille n'est pas limitée. 
    * les flottants (type `float`) qui s'écrivent toujours avec le séparateur décimal `.` et sur lesquels des dépassements de capacité sont possibles.
    * ces deux types numériques partagent les mêmes opérateurs `+,-,*,/,**`
    * On utilisera la division euclidienne (`//` pour le quotient, et `%` pour le reste) uniquement sur les entiers positifs.
    
### Comparaisons

En tapant `20 > 7` dans une console Python, on obtient `True`, `8 < 1` donne `False`. Ces deux expressions sont dites *booléennes*, elles ne peuvent prendre que deux valeurs qui en Python sont donc `True` ou `False`. Les autres opérateurs de comparaisons sont donnés ci-dessous, on prendra bien garde au fait que le test d'égalité est `==` (et pas `=`).

Les opérateurs `not` (unaires), `or` et `and` (binaires) sont définies sur les expressions booléennes, tester par exemple (en essayant de prévoir le résultat en amont):

* `#!python not 6!=7`
* `#!python 6<5 or 12>10`
* `#!python 11!=7 and 6!=7`

!!! Retenir "A retenir"
    Les opérateurs de comparaison sont :

    * `<` ou `>` : strictement inférieur et strictement supérieur
    * `<=` ou `>=` : inférieur ou égal  et supérieur ou égal
    * `==` ou `!=` : égal et différent
    * L'opérateur unaire `not` renvoie la négation d'un expression booléenne (`not a` vaut `True` ssi `a` vaut `False`)
    * L'opérateur binaire `and` renvoie la conjonction de deux expression booléenne (`a and b` vaut True ssi `a` et `b` valent `True`)
    * L'opérateur binaire `or` renvoie la disjonction de deux expression booléenne (`a or b` vaut True ssi `a` ou `b` valent `True`)

{{ exo("Expression booléene",[])}}
Ecrire une expression booléenne qui correspond au *ou exclusif*, entre deux valeurs booléennes `a` et `b`, c'est-à-dire qui vaut vraie si `a` ou `b` est vraie mais pas les deux à la fois.

### Variables

En tapant `annee = 2024` dans la console, on crée une *variable* de nom (ou d'identifiant) `annee` et de valeur `2024`. Pour attribuer cette valeur, on a utilisé le symbole `=`, on dit que c'est le symbole d'**affectation**.

!!! note
    * Le caractère espace ` ` n'est pas autorisé dans un nom de variable, l'usage est de le remplacer par l'*underscore* `_`. A l'exception de ce dernier, il est recommandé de ne pas utiliser de caractères spéciaux dans les noms de variables.
    * Les chiffres sont autorisés mais un nom de variable ne peut pas commencer par un chiffre
    * Python distingue les majuscules et les minuscules dans les noms de variables, donc `test` et `Test` sont deux noms de variables différents

Cette variable peut être utilisé dans d'autre calculs, par exemple `age = annee - 2006` calculera l'age d'une personne née en 2006. Et l'année prochaine est évidemment donnée par `annee_prochaine = annee + 1`, on peut se passer de `annee_prochaine` pour écrire `annee = annee + 1`, cette dernière expression devant être comprise comme remplacer la valeur de `annee` par sa valeur plus un.

{{exo("Manipulations de variables",[])}}

{{terminal()}}

1. Créer une variable `pi` de valeur  `3.14`, calculer l'aire d'un disque de rayon $7,5$ en utilisant cette valeur de `pi`.

2. On considère le programme de calcul suivant :
    1. choisir un nombre entier positif
    2. ajouter 3 à ce nombre
    3. multiplier par le nombre choisi au départ
    4. soustraire 9

    On note `a` le nombre de départ, et `b`, `c` et `d` les nombres obtenus aux étapes suivantes, écrire les affectations permettant de calculer `b`, `c` et `d`. 
    
    Ecrire une unique instruction d'affectation permettant de remplacer le nombre `a` choisi au départ par le résultat du programme de calcul *en utilisant uniquement `a` comme variable*.

3. On suppose déjà crées deux variables `x` et `y`, écrire une suite d'affectations permettant d'échanger les valeurs de ces deux variables.

### Chaines de caractères

Python manipule aussi des variables non numériques : les *chaines de caractères* (type `str`) toujours données entre guillemets simple (`'`) ou double (`"`). Par exemple, `#!python mot = "Hello"`, ou `#!python phrase = "L'informatique, c'est fantastique"`. Attention, remplacer les guillemets double `"`, par des simples dans l'instruction précédente, serait problématique ... voyez-vous pourquoi ?

Les opérateurs suivants sont définis sur les chaines de caractères :

* `+` qui ajoute bout à bout deux chaines de caractères, on parle d'opérateur de *concaténation*. Par exemple `"Hello"`+`"world"` donne `Helloworld`.
* `*` dont le second opérande est un entier `n` et qui concatène `n` fois la chaine donnée en argument avec elle même. Par exemple `"bla"*3` done `"blablabla"`.
* Les crochets `[]` permettent d'accéder aux caractères d'une chaine en donnant leur position *numérotée à partir de 0*, par exemple, si `langage = "Python"`, alors `langage[0]` donne `P`.
* La fonction `len` renvoie la longueur d'une chaine de caractères, par exemple `len("Python")` donne 6.

## Premiers programmes

Vous pouvez tester les programmes ci-dessous en les recopiant dans la partie supérieure du mini IDE :

{{ IDE() }}

### Instruction `print`
Le mode *programme* consiste à écrire une séquence d'instructions puis à la faire executer par Python. Dans ce mode, les valeurs calculées ne sont **pas** affichées directement, une instruction spécifique permet de demander un affichage, c'est l'instruction `#!python print`. Par exemple, dans le programme suivant, seule la valeur de `d` sera affichée (grâce à l'instruction `print` de la ligne 5.)

```python linenums="1" title=""
a = 1
b = -12
c = 35
d = b**2 - 4* a* c
print(d)
```

!!! retenir "A retenir"
    * En mode programme, Python exécute une séquence d'instructions
    * Seuls les affichages explicitement demandés à l'aide d'instructions `print` sont réalisés
    * Un même instruction `print` peut produire plusieurs affichages, on sépare alors les éléments à afficher par des virgules. Par exemple si `a` vaut 10, `#!python print("La variable a vaut ",a)` affichera `La variable a vaut 10`.

### Instructions conditionnelles

En Python, on peut écrire :
```python title=""
if <condition>:
    <instructions>
```
où `<condition>` est une expression booléenne de façon à exécuter le bloc `<instruction>` seulement lorsque `<condition>` s'évalue à `True`. On fera bien attention à la syntaxe notamment au caractère `:` qui suit la condition et à l'*indentation* (décalage vers la droite) du bloc d'instructions.
Dans l'exemple ci-dessous, si la variable `x` est différente de zéro, alors on définit une variable `y` valant `1/x`.
```python title=""
if x!=0:
    y = 1/x
```
Une instruction conditionnelle peut comporter une clause `else` qui indique les instructions à effectuer lorsque la condition n'est pas vérifiée :
```python title=""
if <condition>:
    <instructions1>
else:
    <instructions2>
```
c'est-à-dire que si `<condition>` s'évalue à `True` alors c'est `<instructions1>` qui est exécuté sinon c'est `<instructions2>`.
Par exemple :
```python linenums="1"
if jour=="Samedi" or jour=="Dimanche":
    print("Bon week-end !")
else:
    print("Au boulot !")
```
Affichera `Bon week-end !` si la variable `jour` vaut `"Samedi"` ou `"Dimanche"` et `"Au boulot !"` sinon.

!!! danger
    La condition de la ligne 1 ci-dessous, pourrait s'écrire en français, "Si le jour est samedi ou dimanche". Ce qu'on pourrait vouloir traduire en Python par `#!python if jour=="Samedi" or "Dimanche"`. Cette construction bien qu'acceptée par Python n'est **PAS** le test désiré (et s'évalue en fait toujours à `True`). On fera donc attention à **toujours** avoir une comparaison dans les deux opérandes d'un `and` (ou d'un `or`).

{{ exo("Instructions conditionnelles",[])}}
{{IDE(MIN_SIZE=7)}}

1. On suppose déjà définie une variable `reponse` et une variable `points`, écrire une instruction conditionnelle qui affiche `Bonne réponse` lorsque `reponse` vaut 2 et incrémente la variable `points`. Dans le cas contraire `points` est décrémenté et on affiche `Erreur`
2. On suppose déjà définies deux variables `a` et `b`, écrire une instruction conditionnelle qui permet de définir la variable `c` égale au maximum entre `a` et `b`


### Boucles

Pour afficher un carré de 5 sur 5 constitué de caractères `#`, on pourrait écrire :
```python title=""
print("#"*5)
print("#"*5)
print("#"*5)
print("#"*5)
print("#"*5)
```
c'est-à-dire qu'on doit répéter un nombre donné de fois une même instruction, ce qui peut-être réalisé de façon beaucoup plus concise *et qui se généralise aisément à un nombre quelconque de ligne* à l'aide d'une *boucle* :
```python title=""
for i in range(5):
    print("#"*5)
```

!!! retenir "A retenir"
    * L'instruction `for <variable> in range(<entier>)`  permet de créer une variable parcourant les entiers de 0 (inclus) à `<entier>` (exclu)
    * Les instructions indentées suivantes seront exécutées pour chaque valeur prise par la variable
    * La boucle `for` permet donc notamment de répéter un nombre *prédéfini* de fois des instructions, on dit que c'est une boucle *bornée*.
    * L'instruction `range`, peut être utilisée :
        * avec un seul paramètre `n`, la variable prend alors les valeurs entières de l'intervalle $[0;n-1]$
        * avec deux paramètres `m` et `n`, la variable prend alors les valeurs entières de l'intervalle $[m;n-1]$
        * avec trois paramètres `m`, `n` et `s` la variable prend alors les valeurs de $[m;n-1] \cap \{ m + ks; k \in \mathbb{N}\}$.

Lorsqu'il n'est pas possible de connaître à l'avance le nombre de répétitions nécessaires, on utilise une boucle `while` qui s'exécute tant qu'une condition est vraie. Par exemple, si on suppose qu'on a placé un capital à un taux d'intérêt $t=3 \%$, et qu'on veut savoir au bout de combien d'années ce capital aura doublé, on peut utiliser le programme suivant :
```python title=""
annee = 1
taux = 1.03
taux_global = taux
while taux_global<2:
    annee = annee + 1
    taux_global = taux*taux_global
print("Après, ",annee," années, le capital aura doublé")
```

{{ exo("Quelques boucles à écrire",[])}}

{{IDE()}}

1. Ecrire un programme utilisant une boucle et affichant :
```title=""
**********
*        *
*        *
*        *
*        *
*        *
*        *
*        *
*        *
**********
```
2. Ecrire un programme utilisant une boucle et qui affiche les 10 premiers multiples de 42.
3. Ecrire un programme utilisant une boucle et qui affiche un compte à rebours de 10 à 1.
4. La coupe du monde de football se déroule tout les quatre ans et sa première édition date de 1930. D'autre part, à cause de la seconde guerre mondiale, la compétition n'a pas eu lieu en 1942 et en 1946. Ecrire un programme Python qui liste toutes les années où la coupe du monde s'est déroulée de 1930 à nos jours. Compléter ce programme de façon à afficher le numéro de l'édition pour chaque année.
5. Ecrire un programme Python qui utilise une boucle et qui calcule la somme des entiers impairs entre 1 et 999 (compris).


### Fonctions

La formule permettant de convertir les degrés Celsius ($c$) en degré Fahrenheit est ($f$) : $f = \dfrac{9}{5} c +32$. Cette conversion peut-être représentée par une **fonction** de Python qui prend en entrée un paramètre $c$ (les degrés Celsius) et renvoie un résultat $f$ (les degrés Fahrenheit) :

```python linenums="1" title="Un premier exemple de fonction"
def celsius_en_fahrenheit(c):
    f = (9/5)*c + 32
    return f
```

Maintenant en tapant, par exemple `celsius_en_fahrenheit(10)`, on effectue un **appel** à cette fonction, qui renvoie un résultat, ce résultat peut être mémorisé dans une variable, utilisé comme paramètre d'une autre fonction, affiché, ...
Par exemple, si on souhaite simplement afficher le nombre de degrés Fahrenheit correspondant à 100 degré Celsius, on pourrait ajouter la ligne suivante au programme précédent :

 `#!python print("100 degrés celsius =",celsius_en_farenheit(100)," degrés Fahrenheit")`

!!! retenir "A retenir"
    * La definition d'une fonction en Python commence par le mot clé `#!python def` suivi du nom de la fonction puis de ses arguments entre parenthèses et séparés par des virgules
    * Une fonction peut prendre 0, un, ou plusieurs arguments
    * Les instructions qui forment le corps de la fonction sont *indentés*, la fin de cette indentation marque la fin du bloc d'instructions de la fonction
    * Une fonction *peut* renvoyer un résultat à l'aide d'une instruction `#!python return`
    * Exemple : la fonction suivante, prend deux paramètres (`largeur` et `longueur`) et renvoie le périmètre d'un rectangle de dimension `largeur x longueur` : 
        ```python title=""
        def perimetre(longueur,largeur):
            p = 2 * (longueur+largeur)
            return p
        ```
    * Une fonction peut ne rien renvoyer et par exemple produire simplement un affichage :
        ```python title=""
        def repete(caractere,n):
            print(caractere*n)
        ```
    * Les deux exemples précédents, montrent qu'il ne faut pas confondre `print` et `return`. Dans un cas on renvoie un résultat (qui est récupéré et peut être réutilisé à l'endroit de l'appel de la fonction), dans le second on effectue simplement un affichage *rien* n'est renvoyé vers l'appel à la fonction. Ainsi on pourrait logiquement écrire `p = perimetre(2,7)` (et `p` aurait la valeur `18`, mais ne sera pas affiché) alors que `x = repete('*',10)` n'affectera rien à `x` (mais produira un affichage).

{{ exo("Quelques fonctions élémentaires",[])}}

{{IDE()}}

1. Ecrire une fonction qui prend en argument une valeur numérique `x` et renvoie son carré.
2. Ecrire une fonction qui prend trois arguments `a,b` et `c` et calcule $b^2 - 4ac$.
3. Ecrire une fonction qui prend en argument un entier et renvoie `True` si cet entier est divisible par 7 et qu'il se termine par 9.
4. Ecrire une fonction qui renvoie la valeur absolue du nombre `x` donné en argument.

    !!! note
        Cette fonction existe déjà et s'appelle `abs`.

5. Ecrire une fonction qui renvoie `True` si l'entier donné en argument est une année [bissextile](https://fr.wikipedia.org/wiki/Ann%C3%A9e_bissextile){target=_blank}. Une année est bissextile si elle est divisible par 4 mais pas par 100 ou s'il est divisible par 400.
6. Ecrire une fonction qui prend en argument une chaine de caractères et renvoie son dernier caractère.
7. Ecrire une fonction `est_triangle` qui prend en argument trois nombres `a`, `b` et `c` et qui renvoie `True` si ces trois entiers peuvent être les longueurs des trois côtés d'un triangle.

    !!! aide
        * Cela revient à vérifier que les trois entiers vérifient l'inégalité triangulaire ou encore que le plus grand des trois est inférieur à la somme des deux autres
        * La fonction permettant de déterminer le maximum d'une liste de nombres existe déjà et s'appelle `max`.


### Instruction `input`

Lorsqu'un programme Python rencontre une instruction comme `variable = input()`, il attend la saisie d'un texte au clavier (suivie de l'appui de la touche entrée ++return++) et la **chaine de caractères** saisie est alors affectée à la variable `variable`. On peut préciser le message à afficher avant la saisie en argument de `input`. Par exemple :
```python title=""
prenom = input("Entrer votre prénom")
print("Bonjour,",prenom)
```

!!! danger
    Ce qui est saisi au clavier est toujours interprété par Python comme du **texte** (type `str`), pour l'utiliser comme nombre il faudra effectuer une conversion vers le type souhaite (`int` ou `float`).

## Cours

{{fiche_cours(num)}}


## Exercices de synthèse

{{ exo("Factorielle",[])}}

On appelle *factorielle* d'un entier $n$ et on note $n!$ le produit de cet entier par tous ceux qui le précèdent à l'exception de zéro. Et on convient d'autre part que $0!=1$. Par exemple $5! = 5 \times 4 \times \times 3 \times 2 \times 1 = 120$. Ecrire une fonction `factorielle` qui prend en argument un entier `n` et renvoie sa factorielle.

Vérifier en entrant ici la valeur de $42!$ : {{check_reponse("1405006117752879898543142606244511569936384000000000") }}



{{ exo("Puissance",[])}}

Le but de l'exercice est d'écrire la fonction puissance (sans utiliser l'opérateur `**` de Python).

1. En supposant `n` entier et positif, écrire *sans utiliser l'opérateur* `**` de Python, une fonction `puissance_positif` qui prend en entrée un nombre `x` et `n`  et renvoie $x^n$.
2. Ecrire une nouvelle fonction `puissance` qui prend en argument un nombre `x` et un entier `n` et renvoie $x^n$.

    !!! aide
        Attention à bien traiter tous les cas possibles.


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

{{ exo("Nombres premiers",[])}}

1. Ecrire une fonction `racine` qui prend en entrée un entier `n` positif et renvoie le plus grand entier `k` tel que `k * k <= n`.
    Par exemple, `racine(9)` renvoie 3 et `racine(18)` renvoie 4.

2. Ecrire une fonction qui prend en argument un nombre et renvoie `True` lorsque ce nombre est premier et `False` sinon.

    !!! aide
        On peut se contenter de tester si les entiers $k$ compris entre 2 et la partie entière de $\sqrt{n}$ inclus divisent $n$ et utiliser la question 1.

3. Ecrire une fonction `somme_premiers` qui prend en entrée un entier `n` et calcule la somme des nombres premiers inférieurs ou égaux à `n`. Par exemple `somme_premiers(10)` vaut `2 + 3 + 5 + 7 = 17`

4. Tester votre fonction en calculant `somme_premiers(10000)` :  {{check_reponse("5736396")}}

{{ exo("Palindrome",[])}}

Ecrire une fonction qui vérifie si la chaine passée en argument est un [palindrome](https://fr.wikipedia.org/wiki/Palindrome){target=_blank} (c'est-à-dire qu'elle s'écrit à l'identique de droite à gauche ou de gauche à droite, comme le mot *radar*).


{{ exo("Parcours de chaine de caractères",[])}}

1. Ecrire une fonction `contient` qui prend en argument une chaine de caractères `chaine` et un caractere `c` et qui renvoie `True` si `c` est dans `chaine` et  `False` sinon.

2. Ecrire une fonction `occurrence` qui prend en argument une chaine de caractères `chaine` et un caractere `c` et qui renvoie le nombre d'apparitions de `c` dans `chaine`.

3. On considère la chaine `mystere` ci-dessous composée de caractères très semblables difficiles à distinguer à l'oeil nu :
```
mystere = "O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8O0oQ0OoQD0OQ0o0OQD80oQ0OoQD0OQ0o0OQD8"
```
Combien de `O` contient cette chaine ?  
Vérifier votre réponse : {{check_reponse("220")}}

{{ exo("Conjecture de syracuse",[])}}

La [conjecture de syracuse](https://fr.wikipedia.org/wiki/Conjecture_de_Syracuse){target=_blank} est l'hypothèse selon laquelle la suite  $(u_n)_{n \in \mathbb{N}}$ définie par son premier terme $u_0$ et la relation de récurrence :  
$u_{n+1} = \left\{ \begin{array}{ll} \dfrac{u_n}{2} & \mathrm{\ si\ } u_n \mathrm{\ est \ paire} \\ 3u_n+1 & \mathrm{\ sinon} \\ \end{array} \right.$  
atteint 1. Dans la suite de cette exercice on supposera cette conjecture vérifiée (bien qu'elle n'ait pas été mathématiquement prouvée, la conjecture a été vérifiée numériquement pour tous les entiers jusqu'à $2^{58}$).

1. Ecrire la fonction `terme_suivant` qui prend en argument un entier $n$ et renvoie $\dfrac{n}{2}$ si $n$ est paire et $3n+1$ sinon.
2. Ecrire une fonction `duree_vol` qui prend en argument un entier $u_0$ et renvoie le plus petit entier $n$ appelé *durée de vol* tel que $u_n=1$. Par exemple `duree_vol(7)` doit renvoyer 16, en effet les termes successif de la suite sont `7, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4 ,2, 1`.  
Tester votre fonction en calculant la durée de vol de 123456789 :   
Vérifier votre réponse : {{check_reponse("177")}}

3. Quelle est la plus grande durée de vol lorsque $1 \leq u_0 \leq 10000$ ?  
Vérifier votre réponse : {{check_reponse("261")}}

4. Vérifier que cette durée de vol maximale est atteinte pour une seule valeur de $u_0$, quelle est cette valeur ?  
Vérifier votre réponse : {{check_reponse("6171")}}

5. L'altitude maximale est la valeur maximale atteinte par la suite de Syracuse. Ecrire une fonction prenant $u_0$ et renvoyant l'altitude maximale atteinte. Par exemple l'altitude maximal de $u_0 = 7$ est $52$ (voir les termes de cette suite à la question 2.).

6. Quelle est l'altitude maximale de $9331$ ?  
Vérifier votre réponse : {{check_reponse("345544")}}

