hide: - navigation  in index.md

{{dm(2,"A la recherche de la star")}} 

!!! note "Devoir optionnel"
    * Bien qu'optionnel, ce devoir permet de manipuler des tableaux à deux dimensions en C et est donc *tres fortement recommandé*. 
    * La totalité du devoir est à rendre sous la forme d'un seul et unique fichier `dm2.c` que vous compléterez au fil des questions. Ce fichier vous a déjà été distribué et se trouve dans *votre répertoire personnel* du lycée. Vous pouvez y  accéder depuis un ordinateur du lycée ou depuis l'{{sc("ent")}} grâce à  l'application Nextcloud.
    * Votre fichier `dm2.c` complété devra être enregistré dans votre répertoire personnel du lycée et sera automatiquement ramassé à la date convenue.

On considère un groupe de $n$ individus, numérotés de 0 à $n-1$ et on dispose d'un tableau de booléens `connait` de $n$ lignes et de $n$ colonnes tel que pour tout $i$ ($0 \leq i < n$) et pour tout  $j$ ($0 \leq j < n$):

* `connait[i][j]` vaut `true` si la personne de numéro $i$ connait la personne  de numéro $j$
* `connait[i][j]` vaut `false` sinon

On dit qu'une personne est une *star* lorsqu'elle ne connait personne (à part elle-même) mais que tout le monde la connait. Dans toute la suite, on suppose que la population considérée contient au moins une star. Le but de l'exercice est d'écrire un programme permettant de la retrouver **efficacement** (c'est à dire en effectuant le moins de comparaison possible). 

## Partie I : comprendre le problème
On prend l'exemple d'une population de 5 personnes et on donne ci-dessous la matrice `connait`, où par souci de concision on a remplacé les `true` par 1 et les `false` par 0 :
```
10010
01110
01110
00010
11011
```
On répondra à ces premières questions directement dans le fichier `dm2.c` sous formes de commentaires (donc entre `\*` et `*\`) sans écrire de programme :

1. Quels sont les numéros des personnes que la personne 1 connait ?

    ??? Question "Corrigé"
        La personne 1 connait les personnes 1, 2 et 3 (on rappelle que les personnes sont numérotés depuis 0)

2. Par qui est connu la personne 2 ?

    ??? Question "Corrigé"
        La personne 2 est connu par la personne 2 et la personne 1

3. Quelle est la star de ce groupe de personne ?

    ??? Question "Corrigé"
        La star est la personne 3 car elle ne connait personne (à part elle-même) et elle est connue de toutes les autres personnes. En effet sur la ligne 3 il n'y a que des 0 (sauf sur la colonne 3) et dans la colonne 3 il n'y a que des 1
        
4. Combien peut-il y avoir de stars dans un groupe d'individus ?

    ??? Question "Corrigé"
        Il ne peut y avoir au maximum qu'une seule star dans un groupe. En effet si on suppose qu'il y en au moins 2 stars notées $s_1$ et $s_2$ alors $s_1$ doit connaitre $s_2$ (puisque $s_2$ est une star) et cela n'est pas possible puisque $s_1$ ne connait qu'elle même (puisque $s_1$ est une star).

## Partie II : lire et représenter les données

Le fichier à télécharger ci-dessous  contient la matrice `connait` d'une population de 1000 personnes, comme dans l'exemple ci-dessus, un 1 signifie `true` et un 0 `false`.
Ecrire un programme permettant de lire ce fichier et de stocker les informations dans un tableau de booléens `connait[1000][1000]` *qui sera alloué dans le tas sous la forme d'un tableau linéarisé de dimension 1000 par 1000*. 

{{telecharger("star.txt","./star.txt")}}

!!! Aide
    On rappelle que pour lire les données à partir d'un fichier, on doit suivre les étapes suivantes :

    * créer un flux de lecture (un objet de type `FILE *`) vers le fichier grâce à `fopen`
    * lire les données, ici on peut se contenter d'un lecture caractère par caractère, on pourra donc utiliser la fonction `fgetc` qui récupère à chaque lecture un caractère à partir du flux de lecture (attention à bien sauter le caractère `\n` de fin de ligne)
    * fermer le fichier grâce à `fclose`

    La matrice  est assez "petite" pour être alloué sur la pile. On pourra donc dans un premier temps, si on veut se passer de `malloc`, de `free` et de la linéarisation allouer sur la pile.


??? langageC "Correction"
    
    **Remarque** : la taille de la matrice (1000) est déclaré en début de programme dans la variable `SIZE`.
    
    ```c
        --8<-- "DM2/star.c:20:40"
    ```


## Partie III : traiter les données

1. Ecrire une fonction `est_star` qui prend en argument une matrice de booléens et un entier `i` et renvoie `true` s'il n'y a que des `false` sur la ligne i (sauf à la colonne `i` où se trouve un `true`) et des `true` sur la colonne `i` .

    ??? langageC "Correction"
            
        ```c
            --8<-- "DM2/star.c:43:53"
        ```

2. En utilisant la fonction précédente, trouver la star et tester votre réponse dans le formulaire suivant :  {{check_reponse("795")}}

    ??? langageC "Correction"
        On écrit simplement une boucle afin de tester les valeurs possibles (de `1` à `SIZE=1000`). On trouve que la star est la personne 795.

        ```c
            --8<-- "DM2/star.c:55:65"
        ```

3. Donner un exemple de matrice de taille $5\times 5$ sur lequel cet algorithme prendrait (strictement) plus de 5 comparaisons pour trouver la star.

    ??? langageC "Correction"
        On peut prendre l'exemple de la matrice suivante :
        ```
        11111
        01111
        00111
        00011
        00001
        ```        


## Partie IV : gagner en efficacité

Trouver et implémenter un algorithme permettant de trouver la star d'une matrice de taille $n\times n$ en effectuant seulement $n$ comparaisons.

??? langageC "Correction"
    L'idée de départ est de considérer que si `i` et `j` sont encore candidats avec `i`$\neq$`j` pour être des stars alors il suffit de regarder la valeur de `know[i][j]` pour éliminer soit `i` soit `j`. En effet,

    * si `know[i][j]=true` alors `i` connait `j` (avec `i`$\neq$`j`) et donc `i` n'est pas la star (puisqu'il connait quelqu'un d'autre)
    * sinon `know[i][j]=false` et donc `j` n'est pas la star puisque non connu de `i`

    On démarre donc avec deux indices `i=0` et `j=SIZE-1` et on élimine soit `i` (et on l'incrémente), soit  `j` (et on le décrémente).

    ```c
        --8<-- "DM2/star.c:67:82"
    ```

## Partie V : autres représentations de la matrice

Les élèves intéressés peuvent tester d'autres solutions vues en cours, pour représenter la matrice : 

* tableaux de tableaux
* tableaux de pointeurs

