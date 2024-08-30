{% set num = 3 %}
{% set niveau = "itc_s1"%}
{{ titre_chapitre(num,niveau)}}

Dans de très nombreuses situations, un programme doit pouvoir récupérer ou écrire des informations dans un fichier. Ce chapitre propose de découvrir les fonctions de Python permettant de le faire. Nous utiliserons deux exemples de fichiers disponibles en téléchargement ci-dessous :

* le fichier [informaticiens.txt](./files/C3/informaticiens.txt) qui contient une liste d'informaticiens célèbres
* le fichier [films.txt](./files/C3/films.txt) qui contient une liste de films.
* le fichier [dates.txt](./files/C3/films.txt) qui contient une liste de dates au format `JJ/MM/AAAA`.

!!! danger
    Avant de continuer télécharger ces fichiers (clic droit sur leurs noms puis `Enregistrer la cible du lien sous ...`) dans un dossier de votre choix, par la suite vous sauvegarderez vos scripts Python de ce chapitre *dans ce même répertoire*.

## Ouverture d'un fichier en lecture seule

Pour ouvrir un fichier, on utilise la fonction `#!python open`, cette fonction prend comme paramètre le nom du fichier et elle renvoie une variable appelée **descripteur de fichier**. Par exemple, dans l'instruction suivante :
```python
desc_fic = open("informaticiens.txt")
```
la variable `desc_fic` est notre descripteur de fichier, et nous avons ouvert le fichier ayant pour nom sur le disque dur : `informaticiens.txt`. Il faut interpréter un descripteur de fichier comme un *canal de lecture* pour accéder à ce fichier.

Si après avoir exécuté le programme ci-dessous vous obtenez un `FileNotFoundError: [Errno 2] No such file or directory:` c'est que Python ne trouve pas sur votre disque le fichier que vous essayer d'ouvrir, on rappelle que le programme Python et le fichier doivent se trouver dans le même répertoire !

!!! retenir "A retenir"

    * La fonction #!python `#!python open` permet d'ouvrir un fichier présent dans le dossier courant.
    * Cette fonction prend en paramètre un nom de fichier et renvoie un descripteur de fichier.
    * L'erreur `FileNotFoundError` indique que le fichier n'a pas été trouvé.

## Lecture d'un fichier

Si l'instruction `#!python desc_fic = open("informaticiens.txt")` s'est produite correctement, on dispose maintenant d'un canal de lecture vers le fichier. Pour lire les données on utilise la fonction `#!python read` sur ce descripteur :

```python
desc_fic = open("informaticiens.txt")
# Une fois le fichier ouvert, on effectue les opérations de lecture sur le descripteur
contenu = desc_fic.read()
print(contenu)
```

Comme vous pouvez le constater, la fonction `#!python read` lit la **totalité** du fichier en une seule fois ! 
D'autre part, une fois le fichier lu tout se passe comme si le descripteur de fichier `desc_fic` était arrivé à la fin du fichier, ainsi une deuxième lecture du fichier ne retournera plus aucune donnée (la fin de fichier est déjà atteinte).

```python
desc_fic = open("informaticiens.txt")
# Une fois le fichier ouvert, on effectue les opérations de lecture sur le descripteur
contenu = desc_fic.read()
print(contenu)
deuxieme_lecture = desc_fic.read()
print("Deuxieme lecture :", deuxieme_lecture)
```

La variable `deuxieme_lecture` est vide le descripteur de fichier étant positionné "à la fin" il n'y a plus d'informations à lire.

!! retenir "A retenir"

    * La fonction `!#python read` permet de lire la *totalité* d'un fichier ouvert avec `#!python open`.
    * Après lecture, le descripteur de fichier est positionné en fin de fichier et il n'y a plus d'information à lire.


Une bonne pratique de programmation consiste à fermer un fichier après l'avoir utilisé. C'est le rôle de l'instruction `#!python close`, le programme précédent devrait donc se terminer par `#!python desc_fic.close()`.

{{ exo("A vous de jouer !",[],0)}}

1. En utilisant Python, ouvrir le fichier `films.txt`
2. Lire ce fichier et en afficher le contenu
3. Fermer ce fichier


Au lieu de lire la totalité d'un fichier en une seule fois, il peut être préférable d'en récupérer les lignes soit dans une liste, soit une à une :

* afin de récupérer les lignes d'un fichier dans une liste, on peut utiliser `readlines` :
    ```python
    desc_fic = open("informaticiens.txt")
    lignes = desc_fic.readlines()
    print(lignes)
    desc_fic.close()
    ```
    On remarquera bien la différence avec `read` : ici on obtient une liste, ce qui permet par exemple d'accéder directement à une ligne en particulier du fichier : `#!pyton print(lignes[5])`.

* une autre possibilié est d'utiliser `readline` qui a pour effet de lire une seule ligne du fichier puis de positionner le descripteur de fichier sur la ligne suivante :
    ```python
    # Ouverture du fichier
    desc_fic = open("informaticiens.txt")
    # Lecture de la première ligne 
    ligne1 = desc_fic.readline()
    # le pointeur de lecture est positionné à la ligne suivante, un autre appel à readline lira donc la 2e ligne
    ligne2 = desc_fic.readline()
    # Lecture terminée on ferme le fichier
    desc_fic.close()
    print(ligne1)
    print(ligne2)
    ```

{{ exo("Affichage d'une ligne",[])}}

1. En utilisant `readlines` lire dans une liste les films présents dans le fichiers `films.txt`. Quel film se trouve sur la ligne 4 (on numérote les lignes à partir de 0).
2. Même question en utilisant `readline`

## Ecriture dans un fichier

Pour écrire dans un fichier, il faut l'ouvrir en mode `'w'` (pour **w**rite), si le fichier n'existe pas sur votre disque dur, il sera automatiquement crée :
```python
fichier_prenoms = open("prenoms.txt","w")
fichier_prenoms.write("Alice")
fichier_prenoms.write("John")
fichier_prenoms.write("Billy")
fichier_prenoms.close()
```
Après exécution de ce programme, un fichier `prenoms.txt` est crée dans votre répertoire.

{{ exo("Ajouter les sauts de lignes",[])}}

1. Ouvrir le fichier `prenoms.txt`, le lire et en afficher le contenu à l'aide de Python. Que remarquez-vous ?
2. Comment ajouter les sauts de lignes ?

## Traitement sur les lignes

Souvent, chaque donnée d'un fichier se trouve sur une ligne, par exemple le fichier [dates.txt](./files/C3/films.txt) (que vous du déjà téléchargé dans votre répertoire travail) contient une date par ligne. En lisant ce fichier avec `readlines`, on récupère donc une listes de dates *mais le saut de ligne final est présent* :
```python
reader = open("dates.txt")
contenu = reader.readlines()
print(contenu)
## affiche ['15/01/2012\n', '9/09/2007\n', '24/08/1999\n', '11/04/2000\n']
```
Pour enlever ce saut de ligne final (et éventuellement aussi des caractères espaces qui se trouveraient en début ou fin de ligne), on peut utiliser `strip` qui s'applique sur une chaines de caractères et renvoie une copie de cette chaine sans les sauts de lignes ou espace de début et de fin, ce qui donne :
```python
reader = open("dates.txt")
contenu = reader.readlines()
dates = [ligne.strip() for ligne in contenu]
print(dates)
## affiche ['15/01/2012', '9/09/2007', '24/08/1999', '11/04/2000']
```
Une autre fonction particulèrement intéressant lors de la lecture des fichiers est `split` qui s'applique sur une chaine de caractères et prend en argument un séparateur. Cette fonction renvoie les sous chaines construites en découpant la chaine de départ suivant le caractère séparateur. Par exemple :
```python
mots = "Python est super".split(" ")
# mots contient ["Python", "est", "super"]
prenoms = "Amélie,Pierre,Jacques,Albert,Susie".split(",")
# prenoms contient ["Amélie","Pierre","Jacques","Albert","Susie"]
valeurs = "5-12-54-11-13-9".split("-")
# valeurs contient ["5", "12", "54", "11", "13", "9"]
```
Ici, on peut par exemple utiliser cette fonctionnalité pour découper les dates et récupérer directement le jour, le mois et l'année :
```python
reader = open("dates.txt")
contenu = reader.readlines()
dates = [ligne.strip().split("/") for ligne in contenu]
print(dates)
# affiche [['15', '01', '2012'], ['9', '09', '2007'], ['24', '08', '1999'], ['11', '04', '2000']]
```

## Exercices de synthèse

{{ exo("Manipulation de fichiers en Python",[])}}

1. Recopier et compléter le tableau suivant :

    | Nom du fichier | Descripteur | Mode     | Ouverture | Fermeture |
    |----------------|-------------|----------|-----------|-----------|
    |`eleves.txt`    | `fic`       |lecture   |           |           |
    |                |             |          | `d = open("dates.txt","a")`           |           |
    |`couleurs.txt`  |             |écriture  |           |`fic.close()`           |
    |`data.txt`      | `data`      |ajout     |           |           |
    |                |             |          | `exos = open("exos.txt","r")`           |           |

2. Quel instruction Python permet d'écrire dans un fichier un passage à la ligne ?
3. Que se passe-t-il si on ouvre un fichier déjà existant en mode écriture ?
4. Quelle instruction doit-on toujours trouver après une instruction `open` ?

{{ exo("Nombre de lignes d'un fichier",[])}}

Ecrire une fonction qui prend en paramètre un nom de fichier et retourne le nombre de lignes de ce fichier.

{{ exo("Recherche dans un dictionnaire",[])}}

Pour cette exercice on utilise le dictionnaire téléchargeable ci-dessous:
{{ telecharger("Dictionnaire","./files/C3/dictionnaire.txt")}}

1. Combien il y a-t-il de mots dans ce dictionnaire ?
2. Lister tous les mots de 17 lettres de ce dictionnaire.
3. Quel est le plus grand mot de ce dictionnaire ?
4. Lister tous les mots de 5 lettres qui ont un *d* en deuxième position et se terminent par un *e*.
5. Lister tous les mots palindromes de ce dictionnaire (un mot palindrome est un mot pouvant se lire indifféremment dans les deux sens par exemple *kayak* ou *été*)


{{ exo("Somme des entiers dans un fichier",[])}}

Le fichier `entiers.txt` téléchargeable ci-dessous contient sur chaque ligne un entier. Ecrire un programme Python qui lit ce fichier et fait la somme de ces entiers.
{{telecharger("entiers.txt","./files/C3/entiers.txt")}}

Vérifier la réponse fournie par votre programme ci-dessous :
{{ check_reponse('-1113')}}

!!! aide
    Les données lues dans un fichier sont toujours des chaines de caractères (type `str`), si on les additionne avec `+` cela correspond donc à la concaténation des chaines de caractères (comme dans `"20" + "24"` qui donne `"2024"`). Pour traiter les valeurs lues dans le fichier comme des entiers, il faudra donc au préalable les convertir en entier !


{{ exo("Boîte de plus grand volume",[])}}

Le fichier `boites.txt` est téléchargeable ci-dessous, chaque ligne de ce fichier contient la référence d'un modèle de boîte sous la forme d'un code à 4 lettres suivi de trois entiers représentant les dimensions de la boîte. A titre d'exemple, les trois premières lignes du fichier sont :
```
NWLR 283 75 46 
QBHC 117 70 79 
ZOWK 262 66 31
```
Donc, la boite de référence `NWLR` a comme dimension `283x75x46`.
{{telecharger("boites.txt","./files/C3/boites.txt")}}

Trouver la référence de la boîte de plus grand volume, et vérifier votre résultat dans le formulaire suivant :   {{ check_reponse("ZSDW") }}
