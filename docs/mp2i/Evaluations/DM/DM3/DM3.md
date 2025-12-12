hide: - navigation  in index.md

{{dm(3,"Ensemble d'entiers - Terminaison - Pile")}} 

## Exercice 1 : Ensemble d'entiers

Première partie du sujet zéro de {{sc("ccmp")}} à télécharger ci-dessous :

{{telecharger("Exercice 1","./ExtraitS0_MPI.pdf")}}

## Exercice 2 : Terminaison d'une fonction 

Montrer la terminaison de la fonction ci-dessous pour tout $n \in \mathbb{N}^*$ :

```ocaml
--8<-- "DM3/term.ml"
```

## Exercice 3 : Pile

1. Résoudre [l'exercice du mot mystère du chapitre 8](https://fabricenativel.github.io/cpge-info/mp2i/sl/#exercice-12-mot-mystere) en utilisant OCaml

2. Même question en langage C

??? Aide "Indication"
    On pourra utiliser une pile qu'on implémentera par la méthode des son choix.

## Exercice 4 : Comptine enfantine

Certaines comptines enfantines ont pour objectif de désigner une personne "au hasard", un exemple bien connu est  *Am, stram, gram, pic et pic et colégram*. On suppose que $N$ enfants numérotés de 0 à $N-1$ sont assis en cercle et que l'un d'entre eux (le numéro $k$) récite une comptine contenant $S$ syllabes. A la première syllable il désigne son suivant immédiat dans le cercle puis il avance d'un enfant à chaque syllable jusqu'à la fin de la comptine. L'enfant désigné à la fin de la comptine doit quitter le cercle et le processus recommence à partir de son suivant immédiat jusqu'à ce qu'un seul enfant reste.

1. Donner une illustration de ce processus avec $N=5$ et $S=7$, en supposant que l'enfant $0$ commence.
    
2. Implémenter en OCaml, un programme exécutant ce processus et donnant le numéro de l'enfant restant. On pourra utiliser 
    le module `Queue` de OCaml. Dont on rappelle ci-dessous les fonctions principales :
		
    * `#!ocaml Queue.create`  qui crée une file vide d'éléments de type `'a`.
    * `#!ocaml Queue.add`  qui enfile un élément.
    * `#!ocaml Queue.take` qui défile
		
3. Dans un cercle de 1000 enfants avec une comptine de 4200 syllabes, quel sera le dernier enfant restant (on rappelle que le premier enfant porte le numéro 0 et qu'il récite en premier la comptine). {{check_reponse("94")}}

4. Reprendre cet exercice en C en implémentant la file  par la méthode de votre choix.