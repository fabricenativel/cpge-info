{% set num = 13 %}
{% set niveau = "mp2i_s2"%}

{{ titre_chapitre(num,niveau)}}

{{ citation("When in doubt, use brute force.","K. Thomson")}}

## Cours

{{ cours(num) }}


## Travaux pratiques

!!! note
    Dans ce chapitre, on peut résoudre les problèmes proposés dans le langage de son choix.

{{exo("Problème du sac à dos par force brute",[],0)}}

On dispose d’un sac à dos et d’une liste objet ayant chacun un poids et une valeur. Le problème du sac à dos consiste à remplir ce sac en maximisant la valeur des objets qu’il contient tout en respectant une contrainte sur le poids du sac.
Dans l'exemple représenté ci-dessus ([credit : wikipedia](https://en.wikipedia.org/wiki/Knapsack_problem){target=_blank})

![sac](./Images/C13/Knapsack_Problem_Illustration.svg){.imgcentre width=500px}

Le poids maximal du sac est de 15kg, la combinaison d'objet ne dépassant pas ce poids et de valeur maximale est celle constituée de tous les livres sauf le vert. Le but de l'exercice est de résoudre un problème du sac à dos par *force brute* (un algorithme bien plus efficace sera vu plus tard dans l'année.)

1. Créer un type adapté permettant de représenter un objet. Dans la suite, on suppose que les $n$ objets sont rangés dans un tableau de taille $n$.
2. On décide de représenter un choix d'objets par un tableau  $c$ de $n$ booléens, tel que $c_i$ vaut `true` si l'objet $i$ fait partie du choix et `false` dans le cas contraire. Par exemple si $n=5$ la combinaison `{false, false, true, false, true}` signifie qu'on a pris les objets 2 et 4. Ecrire une fonction `poids_valeur` qui prend en entrée un tableau d'objets et un tableau de booléens représentant un choix d'objets et qui renvoie le poids et la valeur de ce choix.
3. Avec $n$ objets, combien de combinaisons faudra-t-il tester ? Justifier
4. Ecrire une fonction qui résoud le problème par force brute.

    !!! aide
        Pour énumérer les choix possibles on peut  utiliser un compteur binaire

5. Résoudre le problème avec un sac de poids maximal **67** et la liste de 24 objets suivantes :
```
7.8,3897
3.8,1953
7.9,3871
9.1,4598
1.4,602
5.6,2730
8.7,4283
5.5,2668
7.7,3895
6.9,3512
8.7,4318
8.9,4355
7.3,3660
2.9,1574
5.3,2548
0.5,142
0.8,430
0.6,398
3.8,1776
8.2,4073
8.8,4507
5.7,2932
1.0,599
7.8,3802
```

    Tester votre réponse : {{check_reponse("34098")}}

    !!! note
        Vous pouvez créer un fichier texte représentant la liste des objets et le faire lire par votre programme, c'est une excellente occasion de revoir la lecture de fichier !

6. Mesurer le temps d'exécution de votre programme avec la commande `time` des sytèmes Linux (ou directement avec le module `time.h` du C ou `Sys.time` en OCaml)

7. Prédire le temps d'exécution pour un problème avec 50 objets.

## Humour d'informaticien

![tree](./Images/C13/geekandpoke_bruteforce.png){.imgcentre width=500px}
