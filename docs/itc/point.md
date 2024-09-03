{% set num = 0 %}
{% set niveau = "itc_s1"%}

{{ titre_chapitre(num,niveau)}}

## Présentation

Cette première séance a pour objectif de faire le point sur vos acquis du secondaire en Python.  Chaque exercice proposé doit être résolu *en écrivant un petit programme en Python* (parfois une seule ligne suffit !). Pour écrire ces petits programmes :

* vous pouvez utiliser votre ordinateur personnel et votre environnement habituel de programmation Python
* vous pouvez utiliser le mini environnement intégré dans le navigateur et disponible à chaque exercice 

Vous pouvez vérifier votre réponse en la tapant dans le formulaire associé à chaque exercice

## Exercices 

{{ exo("",[],0) }}
Quel est le reste dans la division euclidienne de $2024^{42}$ par $1815$ ?
{{IDE(MIN_SIZE=7)}}


??? aide "Indice"
    En Python, les opérations sur les entiers sont obtenus à l'aide des opérateurs suivants :

    * `+` : addition
    * `-` : soustraction
    * `*` : multiplication
    * `/` : division décimale
    * `//`: quotient dans la division euclidienne
    * `%` : reste dans la division euclidienne

Vérifier votre réponse : {{ check_reponse("121")}}

{{ exo("",[]) }}
On note $a = 10001$, $b = 7777$ et $c = 145$, on calcule ensuite :

* $d = a^2 - 5bc$
* $e = 42d - ab$ si $d$ est divisible par 7 sinon $e = 7c^3$
* $f = e + d$ si $e$ et $d$ ont le même signe sinon $f = ed$

Quelle est la valeur de $f$ ?
{{IDE(MIN_SIZE=7)}}

??? aide "Indice"
    En Python, la structure suivante :
    ```python title=""
        if <condition>:
            <instructions1>
        else:
            <instructions2>
    ```
    permet d'exécuter le bloc d'instruction `<instructions1>` si `<condition>` est vraie et `<instructions2>` sinon. Par exemple, après exécution du programme suivant :
    ```python title=""
        a = 14
        if a > 10:
            b = 1
        else:
            b= 0
    ```
    `b` vaut 1 car comme `a>10`, c'est l'instruction `b=1` qui est exécutée.

Vérifier votre réponse : {{check_reponse("115722051")}}

{{ exo("",[]) }}
On considère la suite $(u_n)_{n \in \mathbb{N}}$ définie par $u_0 = 0.7$ et $u_{n+1} = 3.5 u_n(1-u_n)$. Calculer $u_{2024}$ (on donnera la valeur arrondie au centième).
{{ IDE(MIN_SIZE=7) }}

??? aide "Indice"
    En Python, une boucle `for` permet (notamment) de répéter le bloc d'instruction indenté qui suit. La syntaxe est : `#!python for variable in range(nombre_de_répétions):`

Vérifier votre réponse : {{check_reponse("0.38")}} (valeur arrondie au centièmre)

{{ exo("",[]) }}
En informatique, chaque caractère est associé à un entier : son code *unicode*, par exemple le code *unicode* du caractère `A` est 65. En Python, pour obtenir le code *unicode* d'un caractère on utilise la fonction `ord`, ainsi `ord('A')` vaut 65. Déterminer la somme de de tous les codes *unicode* des caractères de la phrase "*faire un peu de Python, c'est vraiment trop bien !*" ?  
**Attention** : les guillemets ne font pas partie de la phrase. 

!!! note "Remarques"
    * En tapant `#!python3 ord("A")` dans le terminal ci-dessous vous pouvez vérifier qu'on obtient bien 65.
    * L'unicode étend le code {{sc("ascii")}} qui est parfois plus connu. En effet, lorsque le code {{sc("ascii")}} d'un caractère existe, il correspond à son code unicode. Ainsi le code {{sc("ascii")}} de `A` existe (et vaut donc aussi 65), mais `ù` n'est pas un caractère {{sc("ascii")}} et n'a donc pas de code {{sc("ascii")}} mais a bien un code unicode : 249.

{{ IDE(MIN_SIZE=7) }}
??? aide "Indice"
    En Python, une boucle `for` permet (aussi) de *parcourir* un *itérable* (comme par exemple une chaine de caractère). La syntaxe est : `#!python for variable in iterable:` et permet de faire prendre à la variable chaque valeur présente dans l'*itérable*.

Vérifier votre réponse : {{ check_reponse("4491")}}

{{ exo("",[]) }}
Combien il y a-t-il de chiffres dans le nombre $42^{2024}$ ?
{{ IDE(MIN_SIZE=7) }}


Vérifier votre réponse : {{check_reponse("3286")}}

{{ exo("",[]) }}
On rappelle que la factorielle d'un entier naturelle $n$, notée $n!$, est le produit des entiers *strictement* positifs inférieurs ou égaux à $n$. Par exemple $5! = 5 \times 4 \times 3 \times 2 \times 1 = 120$. Quel est le nombre de 2 dans l'écriture décimale de $100!$ ?
{{ IDE(MIN_SIZE=7) }}

Vérifier votre réponse : {{check_reponse("19")}}


{{ exo("",[]) }}
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

{{ exo("",[]) }}
On donne ci-dessous, une liste d'entiers `altitudes` (déjà présente dans votre mini IDE), qui correspond aux altitudes d'un coureur lors d'une course de montagne. On veut déterminer le *denivelé positif* de ce coureur c'est-à-dire la somme des longueurs des *ascensions*. Par exemple, si la liste `altitudes` est `[330, 490, 380, 610, 780, 550]` alors :

* la course commence par une ascension de dénivelé positif $160$ ($490-330$)
* puis on a une descente (de $490$ à $380$)
* puis une ascension avec un dénivelé positif de $230$ ($610-380$)
* puis une nouvelle ascencion de dénivelé positif $170$ ($780-610$)
* puis une descente (de $780$ à $550$)

Le dénivelé cumulé positif total de cette course est donc $160+230+170=560$

Quel est le dénivelé cumulé positif total de la liste des altitudes donnée dans votre IDE ci-dessous ?


{{ check_reponse("1792") }}

{{IDE("scripts/denivele.py",MIN_SIZE=7)}}

??? aide "Indice"
    * Pour obtenir la valeur d'un élément dans une liste de Python, on peut utiliser la syntaxe `liste[indice]`. Par exemple si `noel = [25,12,2024]` alors `noel[1] = 12` (l'indice du premier élément est 0).
    * Pour parcourir une liste, on peut utiliser un boucle `for` dont la variable représente l'indice de la valeur à laquelle on souhaite accéder. Par exemple `for i in range(3)` crée une variable qui prendra successivement les valeurs `0,1` et `2` (dans un `range` la dernière valeur n'est *pas* prise), cette variable peut être utilisé dans la boucle pour accéder à `noel[0]` puis `noel[1]` et enfin `noel[2]`
    * La fonction `len` s'applique aussi aux listes et renvoie leur nombre d'éléments.

{{ exo("",[]) }}
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

{{ exo("",[])}}
Dans votre IDE ci-dessous, est déjà définie une liste de points du plan, chaque point est représenté par un *tuple* de python à deux éléments : son abscisse et son ordonnée. Par exemple `points = [ (2,-1), (3,5)]` contient les points de coordonnées $(2,-1)$ et $(3,5)$. Quelle est la plus courte distance entre deux points de la liste de points définie dans l'éditeur ci-dessous (valeur arrondie au centième) ?

{{IDE("scripts/points.py",MIN_SIZE=7)}}

Véfifier votre réponse : {{check_reponse("1.41")}}