# Exercices complémentaires - Chapitre 1 (Introduction au C)

Ce document rassemble des exercices d'approfondissement sur les tableaux à une dimension et les chaînes de caractères en langage C, conformes au programme de MP2I.

---

{{ exo("Inversion et rotation circulaire d'un tableau en place", []) }}

On considère des tableaux d'entiers représentés par leur adresse de début `tab` et leur taille `n`. On rappelle qu'en C, un tableau passé en argument est modifié **en place**.

1. Écrire une fonction `#!c void miroir(int tab[], int debut, int fin)` qui inverse l'ordre des éléments du tableau situés entre les indices `debut` et `fin` inclus.  
   Par exemple, si `tab = {1, 2, 3, 4, 5, 6}`, après l'appel `miroir(tab, 1, 4)`, le tableau devient `{1, 5, 4, 3, 2, 6}`.

2. Écrire une fonction `#!c void rotation_droite_un(int tab[], int n)` qui effectue une rotation circulaire des éléments du tableau d'un cran vers la droite : le dernier élément passe en première position (`tab[0]`), et tous les autres sont décalés d'une case vers la droite.  
   Par exemple, `{10, 20, 30, 40}` devient `{40, 10, 20, 30}`.

3. En déduire une fonction `#!c void rotation_droite_naive(int tab[], int n, int k)` qui effectue une rotation de $k$ crans vers la droite en répétant $k$ fois l'opération précédente.  
   Quelle est la complexité en temps de cette méthode en fonction de $n$ et $k$ ?

4. **Méthode optimale (en temps $\mathcal{O}(n)$ et mémoire $\mathcal{O}(1)$) :**  
   On remarque qu'une rotation de $k$ crans vers la droite (avec $0 \leq k < n$) peut s'obtenir en effectuant trois inversions partielles successives :
   * Inverser la totalité du tableau : indices de $0$ à $n-1$.
   * Inverser les $k$ premiers éléments : indices de $0$ à $k-1$.
   * Inverser les $n-k$ derniers éléments : indices de $k$ à $n-1$.

   Écrire la fonction `#!c void rotation_droite(int tab[], int n, int k)` utilisant cette approche (on prendra soin de ramener $k$ dans $[0, n-1]$ grâce à l'opération modulo si $k \geq n$).

---

{{ exo("Tassement d'un tableau trié (Suppression des doublons en place)", []) }}

On dispose d'un tableau d'entiers `tab` de taille `n` **trié dans l'ordre croissant**, contenant d'éventuels doublons. On souhaite éliminer ces doublons en tassant les éléments distincts au début du tableau, **sans allouer de tableau supplémentaire** (mémoire auxiliaire $\mathcal{O}(1)$).

1. Écrire une fonction `#!c int supprimer_doublons(int tab[], int n)` qui modifie `tab` en place de sorte que les $k$ premières cases contiennent les éléments uniques de `tab` dans l'ordre croissant, et qui renvoie cet entier $k$ (la nouvelle taille utile du tableau).  
   *Exemple :*
   * Soit `tab = {1, 1, 2, 3, 3, 3, 5, 8, 8}` (taille $n = 9$).
   * Après l'appel `int k = supprimer_doublons(tab, 9);`, la fonction renvoie `k = 5`, et les $5$ premiers éléments de `tab` sont `{1, 2, 3, 5, 8}`.
   * Le contenu des cases au-delà de l'indice $k-1$ n'a pas d'importance.

    !!! aide
        On pourra utiliser deux indices : un indice de lecture qui parcourt tout le tableau, et un indice d'écriture qui progresse uniquement lorsqu'un nouvel élément distinct du précédent est rencontré.

2. Écrire une fonction `#!c void afficher_tableau(int tab[], int n)` et tester `supprimer_doublons` dans un programme `main` sur plusieurs cas :
   * Un tableau contenant plusieurs répétitions d'éléments.
   * Un tableau ne contenant que des éléments tous identiques (ex : `{2, 2, 2, 2}`).
   * Un tableau ne contenant aucun doublon (ex : `{1, 3, 5, 7}`).
   * Un tableau vide ($n = 0$) ou à un seul élément ($n = 1$).

---

{{ exo("Chiffrement de César et ROT13", []) }}

Le chiffrement de César est une technique de cryptographie élémentaire consistant à décaler chaque lettre de l'alphabet d'un nombre fixé de positions.

1. On rappelle qu'en C, une variable de type `char` stocke le code ASCII du caractère.  
   Écrire une fonction `#!c char decale_caractere(char c, int decalage)` qui :
   * Décale les lettres minuscules (`'a'` à `'z'`) de `decalage` crans dans l'alphabet (de façon circulaire : après `'z'` vient `'a'`).
   * Décale les lettres majuscules (`'A'` à `'Z'`) de la même manière (après `'Z'` vient `'A'`).
   * Laisse **inchangés** tous les autres caractères (espaces, chiffres, signes de ponctuation, etc.).

    !!! aide
        * On pourra utiliser l'expression `(c - 'a' + decalage) % 26` pour les minuscules, en prenant garde au fait qu'en C, le reste d'un nombre négatif par modulo `%` peut être négatif. Pour gérer un décalage négatif ou supérieur à 26, on calculera `(decalage % 26 + 26) % 26`.

2. Écrire une fonction `#!c void cesar(char s[], int decalage)` qui modifie la chaîne de caractères `s` en place en lui appliquant le chiffrement de César avec le décalage donné.

3. Le chiffrement **ROT13** est un cas particulier du chiffre de César avec un décalage de 13.
   * Pourquoi le chiffrement et le déchiffrement sont-ils identiques dans le cas du ROT13 ?
   * Tester la fonction `cesar` avec `decalage = 13` sur la chaîne `"Bonjour le monde !"` puis réappliquer la fonction sur le résultat pour vérifier qu'on retrouve le texte initial.
