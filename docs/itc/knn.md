{% set num = 4 %}
{% set niveau = "itc_s3"%}

{{ titre_chapitre(num,niveau)}}

## Cours

{{ cours(num) }}

## TP

!!! lien "Jeu de données"
    Quelques sites proposant des jeu de données pour les algorithmes de classification :  

    * [Site de l'université Irvine de Californie](http://archive.ics.uci.edu/datasets){target=_blank}
    * [Kaggle](https://www.kaggle.com/datasets){target=_blank}

{{ exo("Un exemple corrigé pour knn",[],0)}}


!!! Note "A propos des notebooks"
    On utilise pour la première fois les **jupyter notebook**, c'est à dire des documents contenant à la fois :

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

