hide: - navigation  in index.md

{{dm(2,"A la recherche de la star")}} 

!!! danger "Récupération du devoir"
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
On répondra à ces premières questions dans le fichier `dm2.c` en écrivant des commentaires (donc sans écrire de programm) :

1. Quels sont les numéros des personnes que la personne 1 connait ?
2. Par qui est connu la personne 2 ?
3. Quelle est la star de ce groupe de personne ?
4. Combien peut-il y avoir de stars dans un groupe d'individus ?

## Partie II : lire les données

Le fichier à télécharger ci-dessous  contient la matrice `connait` d'une population de 1000 personnes, comme dans l'exemple ci-dessus, un 1 signifie `true` et un 0 `false`.
Ecrire un programme permettant de lire ce fichier et de stocker les informations dans un tableau de booléens `connait[1000][1000]` *qui sera alloué dans le tas sous la forme d'un tableau de tableau*.

{{telecharger("star.txt","./star.txt")}}

!!! Aide
    On rappelle que pour lire les données à partir d'un fichier, on doit suivre les étapes suivantes :

    * créer un flux de lecture (un objet de type `FILE *`) vers le fichier grâce à `fopen`
    * lire les données, ici on peut se contenter d'un lecture caractère par caractère, on pourra donc utiliser la fonction `fgetc`
    * fermer le fichier grâce à `fclose`

    On fera attention de sauter le caractère de fin de ligne `\n` à chaque fois qu'on a déjà lu une ligne de la matrice (donc 1000 caractères)



## Partie III : traiter les données

1. Ecrire une fonction `est_star` qui prend en argument une matrice de booléens et un entier `i` et renvoie `true` s'il n'y a que des `false` sur la ligne i (sauf à la colonne `i` où se trouve un `true`) et des `true` sur la colonne `i` .
2. En utilisant la fonction précédente, trouver la star et tester votre réponse dans le formulaire suivant :  {{check_reponse("795")}}
3. Donner un exemple de matrice de taille $5\times 5$ sur lequel cet algorithme prendrait (strictement) plus de 5 comparaisons pour trouver la star.

## Partie IV : gagner en efficacité

Trouver un algorithme permettant de trouver la star d'une matrice de taille $n\times n$ en effectuant seulement $n$ comparaisons.

??? aide "Indice"
    Si `i` et `j` sont tous les deux des stars potentielles, alors on peut toujours éliminer `i` ou `j`, en consultant la valeur de `connait[i][j]`