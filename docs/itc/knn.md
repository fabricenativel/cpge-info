{% set num = 20 %}
{% set niveau = "itc_s3"%}

{{ titre_chapitre(num,niveau)}}

## Cours

{{ affiche_cours(num) }}

## Travaux pratiques


!!! lien "Jeu de données"
    Quelques sites proposant des jeu de données pour les algorithmes de classification :  

    * [Site de l'université Irvine de Californie](http://archive.ics.uci.edu/datasets){target=_blank}
    * [Kaggle](https://www.kaggle.com/datasets){target=_blank}

{{ exo("Un exemple corrigé pour knn",[],0)}}


!!! Note "A propos des notebooks"
    On utilise pour la première fois les **jupyter notebook**, c'est-à-dire des documents contenant à la fois :

    * des zones de texte explicatives, 
    * des zones de code Python, executables directement à la façon de ce qui se passe lorsqu'on utilise Python en mode console.

    A chaque fois, que nous utilisons cet outil, deux choix s'offrent à vous :

    1. l'utiliser localement sur votre ordinateur à condition d'y avoir installé jupyter notebook (c'est le cas sur les ordinateurs de la salle). Pour cela, créer un dossier nommé par exemple `Notebook` et depuis un terminal lancer jupyter dans ce dossier en écrivant simplement :
    ```bash
    jupyter notebook
    ```
    L'application se lance dans votre navigateur, télécharger le notebook et utiliser le bouton <span class="encadre">Téléverser</span> en haut à droit pour le télécharger dans votre dossier et l'ouvrir.

    2. Utiliser l'application **Capytale** de votre environnement numérique de travail metice. Dans ce cas, utiliser le lien de partage fourni dans l'activité. Cette option vous permet notamment de travailler depuis la maison car aucune installation (ni de Python, ni de Jupyter) n'est nécessaire.

    Les activités utilisant un notebook proposerons donc toujours les deux options décrites ci-dessus.
{{notebook("f2df-2110706","Notebook : Algorithme knn","./Notebook/PlusProchesVoisins.ipynb")}}

??? aide "Correction"
    {{notebook("6b54-2110802","Notebook : Correction Algorithme knn","./Notebook/PlusProchesVoisins-Correction.ipynb",True)}}

{{ exo("Un exemple pour k-moyenne",[])}}

{{notebook("3015-2167155","Notebook : Algorithme knn","./Notebook/k-moyennes.ipynb")}}


{{ exo("Reconnaissance de langues",[])}}

Le but de l'exercice est d'utiliser l'algorithme des $k$ plus proches voisins afin de reconnaître une langue. On donne ci-dessous 3 fichiers contenant chacun 1100 phrases, ces phrases sont extraites d'oeuvres littéraires célèbres qui sont dans le domaine public et gratuitement téléchargeable par exemple sur [Gutenberg](https://www.gutenberg.org/){target = _blank}.

* Un fichier contenant  des phrases extraites du roman *Les Misérables* (V. Hugo) {{telecharger("Phrases en français","./files/C20/phrases_FR.txt")}}
* Un fichier contenant  des phrases extraites du roman *Oliver Twist* (C. Dickens) {{telecharger("Phrases en anglais","./files/C20/phrases_EN.txt")}}
* Un fichier contenant  des phrases extraites du roman *Faust* (J. Goethe) {{telecharger("Phrases en allemand","./files/C20/phrases_DE.txt")}}

!!! Attention
    Le texte original a été pré traité :

    * Les majuscules ont été remplacées par les minusucules correspondantes
    * on a supprimé les accents et les lettres ont été transformées en leur équivalent non accentuées par exemple les "$é$" sont des "$e$".
    * les lettres ne figurant pas dans l'alphabet latin ont été remplacées par un "équivalent" ainsi le "$ç$" a été remplacé par "$c$" ou le "$\beta$ de l'allemand par un $s$.

Le but de l'exercice est de mettre en oeuvre puis de tester une méthode des $k$ plus proches voisins afin de déterminer la langue dans laquelle une phrase est écrite. 

1. Afin de mesurer la proximité entre deux phrases, on propose d'utiliser les *digrammes* c'est à dire les couples de deux lettres qui se suivent dans une phrase. Par exemple dans la phrase *"un petit test"*, on trouve les digrammes : *"un", "pe", "et", "ti", "it", "te", "es", "st"*. Et chacun de ces digrammes apparaît une seule fois. Dans la phrase *"C'est ma maman !"* la bigramme "ma" apparaît trois fois.  
Ecrire une fonction `cree_digramme` qui prend en argument une phrase et renvoie un dictionnaire dont les clés sont les digrammes que la phrase contient et les valeurs leur nombre d'apparition. Par exemple `cree_digramme("C'est ma maman !")` va renvoyer le dictionnaire `#!python {'es': 1, 'st': 1, 'ma': 3, 'am': 1, 'an': 1}`.

2. Afin de mesurer la distance entre deux phrases, on mesure la distance entre leurs dictionnaires de digrammes (en faisant simplement la somme des valeurs absolus des différences entre les nombres de digrammes). Par exemple, la distance entre `#!python {'es': 1, 'st': 1, 'ma': 2}` et `#!python {'et': 1, 'ti': 3, 'ma':2}` est 1 (`es`) + 1(`st`) + 1 (`et`) + 3 (`ti`) = 6.  
Ecrire la fonction `distance` qui prend en argument deux dictionnaires de digrammes et renvoie la distance entre ces deux dictionnaires.

3. Les fichiers donnés en introduction contiennent une phrase par ligne, écrire une fonction `lit_phrases` qui prend en argument un nom de fichier et une langue (`"FR","EN", "DE"`) et renvoie une liste de phrases étiquetées avec leur langue. C'est à dire une liste de tuples de la forme `("Un exemple de phrase", "FR")`.

4. Ecrire une fonction `knn` qui prend en argument une liste de phrases déjà étiquetées, une phrase `p` et un entier `k` et renvoie la langue majoritaire des `k` phrases les plus proches de `p`. Tester votre fonction sur quelques phrases de votre choix.

5. Séparer les données lues à la question 3 de façon à garder 100 phrases à des fin de test. Et construire la matrice de confusion sur ces 100 tests.

{{ exo("Les passagers du titanic",[])}}

Le but de l'exercice est d'utiliser un algorithme de classification pour prédire la survie des passagers du Titanic. Les données sont à récupérer sur le site [Kaggle](https://www.kaggle.com/c/titanic/data){target=_blank} et sont déjà séparées en deux parties :

* des données d’entraînements 
* des données de test

Les données sont au format `csv` et le détail des champs est donné sur [Kaggle](https://www.kaggle.com/c/titanic/data){target=_blank}.

!!! aide
    On pourra bien sûr commencer par écrire :

    * une fonction permettant de lire les données et de les récupérer dans un format exploitable
    * une fonction permettant de calculer une distance entre deux passager

{{ exo("Reconnaissance de chiffres manuscrits",[])}}

Une des plus [célèbres bases de données de chiffres manuscrits](https://en.wikipedia.org/wiki/MNIST_database){target=_blank} utilisée pour tester les algorithmes de classification est celle du {{sc("mnist")}}. Cette base de donnée est disponible sur le site de [Yann LeCun](http://yann.lecun.com/exdb/mnist/){target=_blank} et se compose d'un ensemble de 60000 images déjà classés et d'un ensemble de 10000 images pour les tests. 

Etant donnée sa taille importante, les images et leur classification sont dans un format binaire appelé `idx` non directement exploitable. Cependant vous trouverez ci-dessous un **extrait** de cette base constitué de 5000 images :
{{telecharger("Chiffres","./files/C4/minst/chiffres.zip")}}
Les images du fichier précédent sont au format [`PGM`](https://fr.wikipedia.org/wiki/Portable_pixmap){target=_blank} bien plus facilement lisible et exploitable à notre niveau. En effet, chaque image est un fichier texte contenant :

* sur la première ligne on trouve on code ("magic number") qui indique le format de l'image PGM ici c'est `P2`
* sur la seconde ligne on trouve les dimensions de l'image :`28 28` (les images  sont toutes carrés de 28 pixels de côté)
* sur la troisième ligne le `255` est le niveau de couleur maximal d'un pixel, ici 0 correspond donc au noir, 255 au blanc.
* sur la quatrième on trouve la valeur du chiffre manuscrit précédé de `# ` (c'est en commentaire)
* les 28 lignes suivantes sont les pixels de l'image et sont donc composées chacune de 28 nombres indiquant le niveau de gris de l'image.

A titre d'exemple le première image ci-dessous (celle de numéro 42 commence par les lignes suivantes :)
Le but de l'exercice est de tester les deux algorithmes de classification vus en cours sur cet exemple.

1. Télécharger le fichier, le décompresser et visualiser quelques images. Vérifier en comparant avec les exemples suivants :

    | Numéro | Image | Chiffre |
    |--------|-------|---------|
    | 42     | ![ex8](./files/C4/minst/img42.png)|  8 |
    | 1515   | ![ex7](./files/C4/minst/img1515.png)| 7  |
    | 2023   | ![ex1](./files/C4/minst/img2023.png)| 1 |

2. Ecrire une fonction `lire_image` qui prend en argument le numéro d'une image et renvoie un tuple composé du chiffre de l'image et d'une liste représentant les niveaux de gris des pixels de l'image (cette liste sera donc constitué de `28x28` nombres entiers compris entre 0 et 255). 

    !!! aide
        On rappelle que :

        * l'image est au fichier texte,
        * le chiffre se trouve sur la quatrième ligne et qu'il est précédé du caractère `#`
        * les niveaux de gris de chaque pixel sont sur les lignes suivantes.

3. Ecrire une fonction `distance` qui permet de calculer le carré de la distance euclidienne entre deux images de dimension `28x28`.

4. Mettre en oeuvre la méthode des k plus proches voisins sur cet exemple en utilisant les 4500 premières images comme image déjà classées et en utilisant les 500 suivantes pour les tests.

    !!! aide
        On pourra tester différentes valeurs de k et choisir une distance différente

5. Mettre en oeuvre la méthode des k-moyennes pour classer les 5000 données.

6. Comparer les résultats des deux méthodes.
