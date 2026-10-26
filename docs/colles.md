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

---

## Semaines du 26/10 et du 02/11

??? note "Chapitres concernés"
    * Les chapitres [C0](https://fabricenativel.github.io/cpge-info/mp2i/systemes/), [C1](https://fabricenativel.github.io/cpge-info/mp2i/introC/) et [C2](https://fabricenativel.github.io/cpge-info/mp2i/discipline/) des semaines précédentes
    * Le chapitre [**C3 - Pointeurs et types structurés**](https://fabricenativel.github.io/cpge-info/mp2i/pointeurs/) :
        * [Cours](https://fabricenativel.github.io/cpge-info/mp2i/Cours/C3/C3-cours.pdf)
        * [TD](https://fabricenativel.github.io/cpge-info/mp2i/TD/TD3.pdf)
        * [TP](https://fabricenativel.github.io/cpge-info/mp2i/pointeurs/#travaux-pratiques)
    * Le chapitre [**C4 - Arithmétique des ordinateurs**](https://fabricenativel.github.io/cpge-info/mp2i/arithmetique/) :
        * [Cours](https://fabricenativel.github.io/cpge-info/mp2i/Cours/C4/C4-cours.pdf)
        * [TD](https://fabricenativel.github.io/cpge-info/mp2i/TD/TD4.pdf)
        * [TP](https://fabricenativel.github.io/cpge-info/mp2i/arithmetique/#travaux-pratiques)

??? rappel "Notions du [programme officiel](https://fabricenativel.github.io/cpge-info/officiel/programme.pdf) abordées"
    * *Section 3.1* et *Section 5.1* - Gestion de la mémoire et types de données : organisation de la mémoire (pile et tas), portée syntaxique et durée de vie des variables. Pointeurs, allocation dynamique (`malloc`, `free`, `sizeof`, pointeur `NULL`, fuites mémoire). Types structurés (`struct`, `typedef`, accès `.` et `->`). Tableaux dynamiques unidimensionnels et multidimensionnels (linéarisation ou tableau de pointeurs).
    * *Annexe A* - Éléments du langage C : passage des paramètres par valeur (simulation du passage par adresse à l'aide de pointeurs), arguments de la ligne de commande (`int argc, char* argv[]`), compilation séparée et fichiers d'en-tête (rôle du `.h`, gardes d'inclusion `#ifndef`, `#define`, `#endif`, production d'exécutables), manipulation élémentaire de fichiers texte (`fopen`, `fclose`, `fprintf`, `fscanf`).
    * *Section 1.1* et *Annexe A* - Arithmétique des ordinateurs et représentation des données :
        * Représentation des entiers naturels en base 2 et 16, conversions, algorithme des divisions successives.
        * Représentation des entiers relatifs en complément à deux sur $n$ bits, calcul de l'opposé, plage de valeurs représentables $[-2^{n-1}, 2^{n-1}-1]$, dépassement de capacité (*overflow*), types entiers signés et non signés (`int8_t`, `uint8_t`, `int32_t`, etc.).
        * Représentation des caractères : codage ASCII, type `char`.
        * Nombres en virgule flottante : norme IEEE-754 (formats simple et double précision, bit de signe, exposant décalé, mantisse normalisée), nombres dyadiques.
        * Conséquences de l'arithmétique flottante : erreurs d'arrondi, absorption et annulation catastrophique, non-associativité de l'addition, test d'égalité avec tolérance $\varepsilon$.


* **Pointeurs et gestion de la mémoire (C3) :**
    * Expliquer l'organisation de la mémoire d'un programme (pile d'exécution, tas, zone statique/globale) ainsi que la portée et la durée de vie des variables.
    * Suivre et tracer l'état de la mémoire (adresses et valeurs des variables et des pointeurs) lors de l'exécution d'un code C manipulant des pointeurs (`&`, `*`, réaffectation).
    * Écrire une fonction modifiant une ou plusieurs variables de la fonction appelante via des pointeurs (simulation du passage par adresse : échange de deux valeurs, renvoi simultané du quotient et du reste de la division euclidienne, calcul simultané du minimum et du maximum d'un tableau).
    * Identifier les erreurs courantes et les comportements indéfinis : déréférencement d'un pointeur non initialisé ou valant `NULL`, retour de l'adresse d'une variable locale allouée sur la pile, déréférencement après libération (*dangling pointer*), fuite mémoire (*memory leak*).
    * Allouer et libérer dynamiquement un tableau 1D sur le tas (`malloc`, `sizeof`, `free`) avec vérification systématique de l'allocation (`assert` ou test de `NULL`).
    * Expliquer la représentation d'une matrice par un tableau linéarisé de taille $n \times p$ (accès à l'élément $(i,j)$ par `tab[i * p + j]`).
* **Types structurés, fichiers et modularité (C3) :**
    * Définir un type structuré avec `struct` et `typedef`, déclarer et initialiser une variable de ce type, accéder aux champs avec l'opérateur `.` ou `->` selon qu'il s'agit d'une variable de type structure ou d'un pointeur vers une structure.
    * Récupérer et convertir des arguments passés sur la ligne de commande (`int argc, char* argv[]`, utilisation de `atoi`).
    * Ouvrir, lire, écrire et fermer un fichier texte en langage C (`fopen` en mode `"r"` ou `"w"`, `fclose`, `fprintf`, `fscanf`).
* **Arithmétique des ordinateurs et représentation des données (C4) :**
    * Convertir un entier naturel entre les représentations décimale, binaire et hexadécimale (à la main ou en programmant l'algorithme des divisions successives).
    * Déterminer la représentation en complément à deux sur $p$ bits d'un entier relatif et retrouver la valeur d'un mot binaire signé. Connaître la plage des entiers représentables sur $p$ bits : $[-2^{p-1}, 2^{p-1}-1]$.
    * Effectuer des additions en binaire signé et identifier les cas de dépassement de capacité (*overflow* / *underflow*) sur des entiers signés ou non signés (`uint8_t`, `int8_t`).
    * Expliquer le principe du codage des caractères en ASCII et la manipulation du type `char`.
    * Décrire la norme IEEE-754 pour les flottants (en simple et double précision) : répartition des bits (signe, exposant décalé avec biais, mantisse avec bit implicite $1$).
    * Coder et décoder un nombre flottant au format IEEE-754 simple précision (sur des nombres dyadiques simples).
    * Expliquer les limites de l'arithmétique flottante : finitude de la précision, erreurs d'arrondi, non-associativité de l'addition, phénomène d'absorption et d'annulation, nécessité de comparer deux flottants à une tolérance $\varepsilon$ près (`fabs(a - b) < eps`).


