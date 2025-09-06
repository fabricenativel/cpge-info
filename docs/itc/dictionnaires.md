{% set num = 5 %}
{% set niveau = "itc_s1"%}
{{ titre_chapitre(num,niveau)}}

## Introduction

On rappelle que pour une *liste* de Python, les valeurs sont accessibles par l'intermédiaire de leur *indice*. Par exemple les éléments de la liste `#!python prenoms = ['Marie', 'Paul', 'Julie', 'Tom', 'Alice']`  sont accessibles via les indices `0, 1, 2, 3, 4` comme illustré ci-dessous :

| Elements | 'Marie' | 'Paul' | 'Julie' | 'Tom' | 'Alice' |
|----------|:-------:|:------:|:-------:|:-----:|:-------:|
| Indice   | 0       | 1      | 2       | 3     | 4       |



Un dictionnaire de Python est similaire à une liste mais les éléments appelées **valeurs** sont reperés par des **clés**. Un dictionnaire est donc comparable à un **tableau associatif** de clés et de valeurs, chaque clé (unique) étant associé à une valeur. Prenons un premier exemple, un dictionnaire permettant d'**associer** des clés (des prenoms) à des **valeurs** à une adresse mail :


| Clés     | 'Marie'          | 'Paul'          | 'Tom'            |
|----------|:----------------:|:---------------:|:----------------:|
| Valeurs  | 'marie@toto.com' | 'paul@truc.net' | 'tom@bidule.org' |

Pour créer ce dictionnaire en Python, on utilise la syntaxe suivante :

`#!python adresses = {'Marie' : 'marie@toto.com', 'Paul' : 'paul@truc.net', 'Tom' : 'tom@bidule.org'}`

c'est-à-dire :

* On liste entre accolades `{` `}` et séparés par des virgules `,` les paires clés/valeurs
* Les deux éléments d'une même paire sont séparés par le caractère `:`

## Opération de bases sur un dictionnaires 


* Affichage :  
    Pour afficher la totalité des paires d'un dictionnaire, on utilise l'instruction `print`
* Accès à une valeur :  
    Pour accéder aux valeurs de ce dictionnaire, on utilise une syntaxe similaire à celle des listes, mais on donne la clé entre crochets (`[` et `]`) et pas l'indice. Par exemple l'adresse mail de `'Paul'` s'obtient avec `adresses['Paul']`.

    !!! note
        Tenter d'accéder à une valeur via une clé inexistante produit une erreur `KeyError`

* Modifier une valeur :   
    Pour modifier une valeur dans un dictionnaire, on utilise l'affectation `=`. Par exemple pour modifier l'adresse de Tom : `adresses['Tom'] = tom@mel.org` 
* Supprimer une valeur :
    Pour supprimer une paire d'un dictionnaire on utilise l'instruction `del`. Par exemple pour supprimer `#!python del adresses['Marie']` supprimera la paire `'Marie' : 'marie@toto.com'` du dictionnaires `adresses`

{{ IDE("scripts/ex_dico.py",ID=1)}}

!!! retenir "A retenir"
    * Un **dictionnaire** permet de stocker des données sous la forme d'associations clés/valeurs
    * Pour créer un dictionnaire, on utilise la syntaxe :  
        `#!python mon_dico = {cle1 : valeur1, cle2 : valeur2, cle3:valeur3, ...}`. Un dictionnaire vide s'obtient avec `{}`.
    * On accède à une valeur par sa clé avec la syntaxe `#!python mon_dico[cle]`, si la clé n'existe on obtient l'erreur `KeyError`
    * On modifie une valeur existante ou créer une nouvelle association clé/valeur avec une affectation de la forme `#!python mon_dico[cle] = nouvelle_valeur`
    * On peut supprimer un couple clé/valeur avec `#!python del mon_dico[cle]`

{{ exo("Créer et manipuler un dictionnaire",[],0)}}

1. Créer un dictionnaire `coefficient` permettant d'associer à chaque épreuve finale du bac son coefficient (voir tableau ci-dessous) :
 ![coefficientbac](./Images/C5/bac.png){width=300px .imgcentre}
2. Ecrire une instruction `print` permettant d'afficher le coefficient du `'Grand oral'`.
2. Quelle instruction permet de modifier le coefficient de la philosophie en 9 ?
3. Quelle instruction permet de rajouter l'épreuve `'Option'` avec un coefficient 2 ?
4. Quelle instruction permet de supprimer l'épreuve `'Option'` crée ci-dessus ?

## Test d'appartenance à un dictionnaire

On peut tester si une clé existe ou non dans un dictionnaire avec `<cle> in <dico>` qui renverra `true` si `<cle>` est une clé présente dans `<dico>` et `<false>` sinon.

!!! note
    On peut aussi utiliser `#!python in` sur les listes pour y tester la présence d'un élément par exemple `2 in [1, 9, 4]` renvoie `false`. Pour des raisons qui seront détaillées plus loin dans le cours, on limitera volontairement l'utilisation du `in` aux dictionnaires et on l'évitera sur les listes.

{{ exo("Dictionnaire des nombres d'occurrences",[])}}

Ecrire une fonction `dico_occurrence` qui prend en entrée une chaîne de caractères `s` et renvoie un dictionnaire dont les clés sont les caractères présents dans `s` et les valeurs leurs nombres d'occurrences. Par exemple, `dico_occurrence("Bonjour")` doit renvoyer le dictionnaire `{'B' : 1, 'o':2, 'n':1, 'j':1, 'u':1, 'r':1}` car tous les caractères apparaissent une fois sauf `o` qui apparaît deux fois.

??? aide "Indices"
    1. Créer un dictionnaire vide
    2. Parcourir la chaine `s` caractère par caractère
    3. Si le caractère est déjà présent dans le dictionnaire incrémenter son nombre d'occurrence, sinon l'ajouter au dictionnaire avec une occurrence de 1.


## Parcourir un dictionnaire

On peut parcourir un dicionnaire par clés ou par valeurs et la syntaxe est similaire à celle déjà rencontrée sur les autres *itérables* (chaines de caractères, tuples, listes) : on utilise une boucle `for <cle> in <dico>`. Par exemple, dans la boucle `#!python for c in {"A":6, "T":12, "C":9, "G":14}` la variable `c` prendra les valeurs `"A"`, `"T"`, `"C"` et `"G"`.


{{ exo("Valeur d'un mot au Scrable",[])}}
Au jeu du Scrabble, chaque lettre a une valeur comme indiqué sur l'image ci-dessous :

![valeurs des lettres](./Images/C5/lettres.jpeg){.imgcentre width=300px}

Le but de l'exercice est d'écrire une fonction `score` qui prend un argument un `mot` et renvoie la somme des valeurs des lettres de ce mot. Par exemple `valeur("GIRAFE")` doit renvoyer 10 en effet :
![valeurs des lettres](./Images/C5/girafe.png){.imgcentre width=250px}
et donc la valeur est $2+1+1+1+4+1 = 10$

1. Compléter  une première version de `score` qui parcours les lettres du mots et ajoute la valeur suivant la lettre rencontrée.
```python
def score(mot):
    total = 0
    for lettre in ....:
        if lettre == 'A' or lettre=='E' or lettre=='I' ..... :
            total += 1
        if lettre == 'D' or lettre == 'G' or .......:
            totel += 2
        ...
        ...
    return ...
```


2. Les dictionnaires à la rescousse

    1. Créer un dictionnaire `valeur` dont les clés sont les lettres de l'alphabet et qui associe à chaque lettre sa valeur.

    2. Utiliser ce dictionnaire afin d'écrire une version bien plus courte et lisible de la fonction `score`.

## Dictionnaires et mutabilité

Les dictionnaires sont des structures de données *mutables* de Python, on retrouve donc les deux conséquences déjà observées sur les listes, à savoir :

* lorsqu'on on crée un dictionnaire avec l'opérateur `=` à partir d'un dictionnaire existant, toute modification de l'un entraine une modification de l'autre :

    {{IDE("scripts/dict_mut1.py",ID=2)}}

    Pour crée une "vraie" copie d'un dictionnaire `dico`, on peut utiliser `dico.copy()`. Par exemple, ci-dessus, on écrira ligne 2 `#!python dico2 = dico1.copy()`. Les modifications apportées à la copie ne se répèteront pas sur l'original (et inversement)

* lorsqu'on passe un dictionnaire à une fonction, tout modification effectuée dans la fonction modifie effectivement le dictionnaire

    {{IDE("scripts/dict_mut2.py",ID=3)}}

D'autre part, les clés d'un dictionnaires doivent nécessairement être *non mutables*, donc les listes par exemple ne peuvent pas être clés d'un dictionnaire, une tentative en ce sens, déclenche un `TypeError`.

## Exercices de synthèse


{{ exo("Moyennes des élèves",[])}}

Voici un dictionnaire contenant  les notes obtenus par des élèves :
```python
notes = {
            "Albert"    : [7, 11, 15, 8, 9],
            "Alice"     : [14, 11, 6, 15],
            "Bob"       : [9, 9, 13, 14, 9],
            "Louise"    : [11, 13, 12, 14, 14],
            "Michelle"  : [2, 5, 4, 9],
            "Luc"       : [18, 14, 18, 11]
        }
```

1. Ecrire une fonction moyenne qui prend en argument une liste non vide d'entiers et renvoie la moyenne des éléments de cette liste.

2. Créer un dictionnaire possédant les mêmes clés (les prénoms) et contenant la moyenne de chaque élève.


{{ exo("Codage et décodage",[])}}

Le dictionnaire suivant représente un code, les clés sont les lettres de l'alphabet (en majuscule) et les valeurs sont les lettres par lesquelles les remplacer pour effectuer le codage :
```python
code = {'A': 'Y', 'B': 'S', 'C': 'B', 'D': 'I', 'E': 'T', 
        'F': 'Q', 'G': 'N', 'H': 'U', 'I': 'X', 'J': 'F',
        'K': 'C', 'L': 'W', 'M': 'K', 'N': 'H', 'O': 'E',
        'P': 'G', 'Q': 'O', 'R': 'P', 'S': 'L', 'T': 'M',
        'U': 'A', 'V': 'J', 'W': 'Z', 'X': 'V', 'Y': 'R',
        'Z': 'D'}
```
Par exemple le codage du mot `FACILE` est : `QYBXWT` (en effet la clé `F` est associée à la valeur `Q`, la clé `A` à la valeur `Y`, ...)

1. Ecrire une fonction qui prend en entrée une chaine de caractère et renvoie son codage. Si des caractères autres que des lettres majuscules sont présentes dans la chaine (ponctuation, espace, ...) ils sont laissées intactes. Tester votre fonction en déterminant le codage de la phrase `C'EST VRAIMENT SUPER DE FAIRE DU PYTHON !`. Tester votre réponse dans le formulaire suivant :   {{ check_reponse("B'TLM JPYXKTHM LAGTP IT QYXPT IA GRMUEH !")}}

2. Créer un dictionnaire `decode` qui "inverse" le dictionnaire `code` c'est-à-dire que la valeur associée à `Y` est `A`, celle associée à `B` est `S`, ...

3. Ecrire une fonction qui prend en entrée une chaine de caractère et renvoie son décodage. Tester votre fonction en décodant le message suivant : `LAGTP ! JEAL YJTD PTALLX W'TVTPBXBT`.


{{ exo("A la recherche du mot caché",[])}}

Vous pouvez télécharger ci-dessous un fichier `mot_cache.txt` :  
{{telecharger("mot_cache.txt","./files/C5/mot_cache.txt")}}    

ce fichier contient de nombreux caractères : tous ceux de code {{sc('ascii')}} compris entre 33 (`!`) et 126 (`~`). Tous ces caractères apparaissent au moins à 50 reprises (et jusqu'à 100 fois) *à l'exception de quelques uns* qui apparaissent rarement (moins d'une dizaine de fois).  
Retrouver les caractères qui apparaissent rarement, ranger les dans l'ordre de leur nombre d'apparition pour obtenir le mot caché. Vous pouvez vérifier votre résultat ci-dessous :
{{ check_reponse("Bravo") }}

!!! aide
    * Revoir si nécessaire comment ouvrir un fichier en Python et en lire le contenu.
    * On pourra construire un dictionnaire dont les clés sont les caractères et les valeurs leur nombre d'apparition.

{{ exo("S'entrainer sur CodEx",[])}}

Quelques exercices CodEx pour s'entrainer sur les dictionnaire :

* [Anniversaire](https://codex.forge.apps.education.fr/exercices/anniversaires/){target=_blank}
* [Concours de l'Eurovision](https://codex.forge.apps.education.fr/en_travaux/eurovision/){target=_blank}
* [Décomposition en facteurs premiers](https://codex.forge.apps.education.fr/exercices/decomposition_facteurs_premiers/){target=_blank}
* [Dictionnaire de J'aime](https://codex.forge.apps.education.fr/exercices/dictionnaire_aime/){target=_blank}
* [Pangramme](https://codex.forge.apps.education.fr/exercices/pangramme_1/){target=_blank}
