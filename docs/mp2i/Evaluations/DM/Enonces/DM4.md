hide: - navigation  in index.md

{{dm(4,"Le jeu de la vie ")}} 

Le devoir porte sur le [jeu de la vie](https://fr.wikipedia.org/wiki/Jeu_de_la_vie){target=_blank} inventé par le mathématicien [John Conway](https://fr.wikipedia.org/wiki/John_Horton_Conway){target=blank}. Pour découvrir ce "jeu", vous pouvez regarder l'excellente vidéo de la chaine youtube science étonnante :
<div class="centre"><iframe width="560" height="315" src="https://www.youtube.com/embed/S-W0NX97DB0?si=2xGfJnml3529SJqR" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe></div>

!!! note "Devoir optionnel"
    * Bien qu'optionnel, ce devoir permet de manipuler des tableaux à deux dimensions en C et est donc *tres fortement recommandé*. 
    * Le devoir est à rendre **en TP** pour le 15/11/2023 

Le [jeu de la vie](https://fr.wikipedia.org/wiki/Jeu_de_la_vie){target=_blank} permet de faire évoluer un ensemble de cases (appelées cellule) d'une grille (théoriquement infinie mais qui sera limitée pour ce DM) en suivant les règles suivantes :

* une cellule (donc une case de la grille) n'a que deux états possibles : vivante (la case est remplie) ou morte (la case est vide)
* une cellule morte qui possède exactement trois voisines vivantes devient vivante
* une cellule vivante qui possède exactement 2 ou 3 voisines reste vivante sinon elle meurt.


Par exemple :
Dans la configuration suivante, où on a numéroté chacune des cellules vivantes de façon à décrire le processus :
{{ make_jeuvie(['...#','.##.','..#.','#...'],[1,2,3,4,5])}}

La cellule 1 possède 1 voisines donc elle meurt, de même que la cellule numérotée 5 qui n'a aucune voisine.
Les cellules 2, 3 et 4, restent vivantes car elles ont deux ou trois voisines.
Et deux nouvelles cellules apparaissent (on les a numérotés 6 et 7) dans les cases qui possédaient exactement trois voisines. La configuration suivante est donc :
{{ make_jeuvie(['..#.','.###','..#.','....'],[6,2,3,7,4])}}
Aux étapes suivantes, on obtient les configuration ci-dessous (on ne numérote plus les cellules pour simplifier):
{{ make_jeuvie(['.###','.#.#','.###','....'],[])}} {{ make_jeuvie(['.#.#','#...','.#.#','..#.'],[])}} {{ make_jeuvie(['....','##..','.##.','..#.'],[])}}


Le but de l'exercice est de simuler le jeu de la vie en C dans une grille de dimension données. On représentera dans la totalité du sujet une grille par un tableau a *une dimension* de booléens. C'est à dire qu'on utilise la technique de linéarisation du tableau vu en cours. Par exemple la grille {{ make_jeuvie(['....','##..','.##.','..#.'],[])}} 

sera représenté en mémoire par un tableau à une seule dimension : {{make_jeuvie(['....##...##...#.'],[])}}

où les cellules mortes sont `false` et les cellules vivantes `true`. 

!!! aide 
    On rappelle qu'en faisant cette linéarisation l'élément situé en ligne `i` et colonne `j` a pour indice `i*LARGEUR + j` dans le tableau linéarisé.

## Partie 1 : Grille de taille 4x4

!!! note "Taille de la grille"
    Dans chaque partie du sujet, les dimension de la grille seront deux constantes entières notées `HAUTEUR` et `LARGEUR`. Pour définir ces constantes, deux possibilités s'offrent à vous :

    * utiliser `const` et les définir en variable globale en début de programme avec par exemple `const int HAUTEUR = 4;` (c'est la version recommandée au programme de mp2i).
    * utiliser une directive de précompilation `#define HAUTEUR 4` qui aura pour effet avant la compilation de remplacer dans votre code toutes les occurences de `HAUTEUR` par `4`.

Dans cette partie la grille est de dimension `4x4` et on cherche à reproduire l'évolution donnée en introduction. 

1. Ecrire une fonction `affiche` qui prend en argument un tableau de booléens de taille `HAUTEUR*LARGEUR` et l'affiche sous la forme d'une grille de `HAUTEUR` lignes sur `LARGEUR` colonnes en affichant `.` pour une cellule morte et `*` pour une cellule vivante. Vous pouvez tester votre fonction avec le tableau suivant :

    ```
    bool etat[HAUTEUR*LARGEUR] = {false,false,false,true,false,true,true,false,false,false,true,false,true,false,false,false};
    ```
    dont l'affichage devrait produire :
    ```
    ...#
    .##.
    ..#.
    #...
    ```

    !!! aide
        On rappelle qu'il est inutile de passer en argument la dimension du tableau car ce sont des variables globales

2. Ecrire une fonction `compte_voisin` qui prend en argument un tableau de booléens de taille `HAUTEUR*LARGEUR`, un entier `l` (la ligne), un entier `c` (la colonne) et renvoie le nombres de voisins de l'élément situé en ligne `l`, colonne `c`.

    !!! aide
        * On pourra écrire une fonction annexe qui teste si deux entiers `i` et `j` sont bien les indices de ligne et de colonne d'un élément de la grille (c'est à dire si `0 <= i < HAUTEUR` et `0 <= j < LARGEUR`).
        * Faites des tests pour cette fonction, par exemple pour la grille `etat` donnée à la question précédente, vous devriez obtenir :
            * `compte_voisin(etat, 0, 0) = 1`
            * `compte_voisin(etat, 1, 3) = 3`
            * `compte_voisin(etat, 3, 1) = 2`


3. Ecrire une fonction `etat_suivant` qui prend en argument un tableau de booléens de dimension `HAUTEUR*LARGEUR` et renvoie un **nouveau tableau de booléens, sans modifier celui donné en argument** contenant l'évolution suivante dans le jeu de la vie. Par exemple pour le tableau `etat` donné dans la question `1`, l'affichage du tableau produit par l'appel `etat_suivant(etat)` donne :
```
..#.
.###
..#.
....
```

4. Ecrire une fonction `copie_etat` qui prend en argument deux tableaux de booléens `etat1` et `etat2` de dimension `HAUTEUR*LARGEUR` ne renvoie rien et copie les valeurs de `etat2` dans `etat1`

5. Ecrire une fonction `evolution` qui prend en argument un tableau de booléens de dimension `HAUTEUR*LARGEUR` ainsi qu'un entier `nb_etapes` et un booléen `voir`. Cette fonction renvoie un tableau de booléens représentant l'état de la grille après `nb_etapes` evolutions, de plus si le booléen `voir` vaut `true` alors toutes les étapes intermédiaires sont affichées dans le terminal.
Par exemple, avec le tableau `etat` donné à la question 1, l'appel `resultat = evolution(etat, 10, true);` produit le résultat suivant dans le terminal :
```
..#.
.###
..#.
....

.###
.#.#
.###
....

.#.#
#...
.#.#
..#.

....
##..
.##.
..#.
```
Ce qui correspond bien aux évolutions du motif vu en introduction.

## Partie 2 : Lecture depuis un fichier

Le but de cette partie est de modifier l'état d'un motif connu ; le [*glider gun*](https://conwaylife.com/wiki/Period-33_glider_gun){target=_blank}, téléchargeable ci-dessous sous la forme d'un fichier texte dans lequel les cellules vivantes sont représentées par le caractère `O` et les cellules mortes par `.`
{{telecharger("Glider gun","glidergun.cells")}}

!!! note
    Le jeu de la vie possède son propre [wiki](https://conwaylife.com/wiki/){target=_blank} sur lequel des passionés du jeu postent des motifs nouveaux regulièrement. Le motif du Glider gun donné ci-dessus est extrait de ce site.

Dans cette partie, on travaille sur une grille de dimensions `57x37`. On doit donc modifier les constantes `HAUTEUR` et `LARGEUR` en début de programme. 

1. Ecrire une fonction `lire_grille` qui prend en argument un nom de fichier. Ce fichier représente l'état d'une grille de jeu de la vie de dimension `57x37`, les cellules mortes sont représentés par le caractère `O` et les cellules vivantes par le caractère `.`, cette fonction renvoie un tableau de booléens qui représente un etat du jeu.

2. Ecrire une fonction `compte_vivant` qui détermine le nombre de cellules vivantes d'un état du jeu.

3. Donner le nombre de cellules vivantes après 100 évolutions du *Glider gun*. Vous pouvez tester votre réponse dans le formulaire ci-contre : {{check_reponse("237")}}

## Partie 3 : Visualisation sous forme d'image pbm

Le format d'image {{sc("pbm")}} pour *Portable Bitmap file forMat* est un format d'image élémentaire permettant de représenter des images en noir et blanc. Le fichier est au format texte, 

* sur la première ligne on doit écrire `P1`
* la seconde ligne contient les dimensions de l'image séparés par un espace (nombre de colonnes puis nombre de lignes)
* Les lignes suivantes sont des constituées de 1 et de 0. Un `1` indique un pixel noir et  un `0` un pixel blanc

Par exemple :
```
P1
4 4
0110
0010
0010
1000
```

est le fichier {{sc("pbm")}} d'une image 4x4 qui agrandi donne le résultat ci-dessous :   
&nbsp; &nbsp; ![ex_pbm](./ex_pbm.png)

!!! warning "Attention"
    Selon la configuration de votre ordinateur et votre système d'exploitation, il vous faudra peut-être installer une application permettant de visualiser les images au format {{sc("pbm")}}.

1. Ecrire une fonction `cree_image` qui prend en argument un etat du jeu de la vie (de dimension 57x37) et crée le fichier {{sc("pbm")}} correspondant.

2. Créer l'image au format {{sc("pbm")}} de l'état initial du *Glider gun*.  

3. Créer l'image du *Glider gun* après 100 itérations.

!!! lien "Pour aller plus loin"
    Divers outils existent pour transformer une suite d'image en une animation (gif animé ou vidéo). Sur un système d'exploitation Linux on pourra par exemple utiliser `convert` disponible après installé `ImageMagick`. 
