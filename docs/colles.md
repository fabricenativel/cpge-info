hide: - navigation in liens.md

# Programme de colles

## Semaines du 07/09 et du 14/09



??? note "Chapitres concernés"
    * [**C0 - Systèmes d'exploitation et environnement Linux**](https://fabricenativel.github.io/cpge-info/mp2i/systemes/) : 
        * [Cours](https://fabricenativel.github.io/cpge-info/mp2i/Cours/C0/C0-cours.pdf) 
        * [TD](https://fabricenativel.github.io/cpge-info/mp2i/TD/TD0.pdf)
        * [TP](https://fabricenativel.github.io/cpge-info/mp2i/systemes/#travaux-pratiques)
    * [**C1 - Premiers pas en langage C**](https://fabricenativel.github.io/cpge-info/mp2i/introC/) :
        * [Cours](https://fabricenativel.github.io/cpge-info/mp2i/Cours/C1/C1-cours.pdf)
        * [TD](https://fabricenativel.github.io/cpge-info/mp2i/TD/TD1.pdf)
        * [TP](https://fabricenativel.github.io/cpge-info/mp2i/introC/#travaux-pratiques)

??? rappel "Notions du [programme officiel](https://fabricenativel.github.io/cpge-info/officiel/programme.pdf) abordées"
    * *Section 5.2* - Gestion des fichiers : organisation hiérarchique, liens physiques et symboliques, accès, droits et attributs. Flux standard (`stdin`, `stdout`, `stderr`). Redirection et tubes (*pipe*).
    * *Annexe A* et *Section 5.1* - Langage C : Traits généraux, définitions et types de base, tableaux statiques, chaînes de caractères, structures de contrôle.


* **En environnement Linux :**
    * Déterminer des chemins absolus ou relatifs dans une arborescence donnée.
    * Calculer ou modifier les permissions d'un fichier en octal et en symbolique (`chmod`).
    * Expliquer la différence entre un lien physique et un lien symbolique (partage d'inode vs pointeur de chemin, effet de la suppression de la cible).
    * Écrire une ligne de commande combinant plusieurs filtres (`ls`, `grep`, `head`, `tail`, `wc`) à l'aide de tubes (*pipe*) et de redirections.
* **En langage C :**
    * Prévoir le résultat et le type d'une expression arithmétique ou logique (division entière, conversion de type, évaluation paresseuse).
    * Écrire une fonction C réalisant un traitement élémentaire sur des nombres (somme, factorielle, test de divisibilité, suite récurrente).
    * Parcourir un tableau statique 1D pour calculer une somme, trouver le maximum ou tester la présence d'une valeur.
    * Manipuler une chaîne de caractères en s'appuyant sur le caractère sentinelle `'\0'` (calculer sa longueur, la renverser, tester si elle est un palindrome).
    * Identifier les risques de comportement indéfini (dépassement d'indice de tableau, variable non initialisée).

    

---

## Semaines du 21/09 et du 28/09

??? note "Chapitres concernés"
    * Les chapitres [C0](https://fabricenativel.github.io/cpge-info/mp2i/systemes/) et [C1](https://fabricenativel.github.io/cpge-info/mp2i/introC/) des semaines précédentes
    * Le chapitre [**C2 - Discipline de programmation**](https://fabricenativel.github.io/cpge-info/mp2i/discipline/) :
        * [Cours](https://fabricenativel.github.io/cpge-info/mp2i/Cours/C2/C2-cours.pdf)
        * [TD](https://fabricenativel.github.io/cpge-info/mp2i/TD/TD2.pdf)
        * [TP](https://fabricenativel.github.io/cpge-info/mp2i/discipline/#travaux-pratiques)

??? rappel "Notions du [programme officiel](https://fabricenativel.github.io/cpge-info/officiel/programme.pdf) abordées"
    * *Section 1.1* - Algorithmes et programmes : terminaison, correction partielle et totale, variant, invariant de boucle.
    * *Section 1.2* - Discipline de programmation : spécification (données attendues en entrée, fournies en sortie/retour), préconditions, postconditions, programmation défensive et assertions (`assert`).
    * *Section 1.3* - Validation, test : jeu de tests associé à un programme, graphe de flot de contrôle, chemins faisables, critères de couverture (sommets, arcs), test des conditions.


* Validation, jeu de tests, graphe de flot de contrôle. Préconditions, instructions `assert`.
* Terminaison et correction d'algorithmes simples. Les variants et invariants pourront être suggérés aux élèves. Exemples traités en cours/TD : multiplication par additions successives, quotient et reste dans la division euclidienne, recherche du premier diviseur supérieur ou égal à deux d'un entier.

