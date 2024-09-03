{% set num = 19 %}
{% set niveau = "mp2i_s2"%}

{{ titre_chapitre(num,niveau)}}

{{ citation("An algorithm must be seen to be believed, and the best way to learn what an algorithm is all about is to try it.
","D. Knuth","The Art of Computer Programming Vol. 1, 3rd edition") }}

## Cours

{{ affiche_cours(num) }}

## Travaux dirigés

{{ td(num) }}


## Travaux pratiques

!!! danger
    * Afin de tester les divers algorithmes sur les textes, on suppose dans tous les exercices qu'on dispose d'un fichier texte encodé au **format {{sc("ascii")}} standard** c'est-à-dire qu'on utilise **128 cractères tous encodés sur 8 bits**. De cette façon :
    
        * pour les algorithmes de recherche on pourra indexer chaque caractère par une table de 128 entiers (c'est-à-dire identifier un caractère à son code {{sc("ascii")}}.
        * pour mesurer les taux de compressions, on pourra considérer qu'un fichier contenant $n$ caractères a une taille de $8n$ bits (le cas de l'{{sc("utf-8")}} s'avère bien plus problématique puis qu'un caractère occupe de 1 à 4 octets.)

    * On donne ci dessous un tel fichier prêt à l'emploi à télécharger : il s'agit du livre *Notre-Dame de Paris* (V. {{sc("Hugo")}}, 1831) qui servira d'exemple pour les tests.   
    {{telecharger("Notre-Dame de Paris (ascii)","./files/C19/notredame_ascii.txt",false)}}
    * Pour produire de tels fichiers, on pourra partir de n'importe quel fichier texte au format {{sc("utf-8")}} (par exemple un livre téléchargeable sur le site du   [projet Gutenberg](https://www.gutenberg.org/){target=_blank}) puis convertir ce fichier au format {{sc("ascii")}} en effectuant une translittération, c'est-à-dire par exemple en remplaçant `à` par `a` ou encore `é` par `e` pour cela, on pourra utiliser l'utilitaire `iconv` en ligne de commande avec la syntaxe suivante :
    ```bash
    iconv -f utf-8 -t ascii//TRANSLIT <source> -o <destination>
    ```

!!! aide
    En Ocaml la fonction suivante `lire_fichier string -> string` permet de lire la totalité d'un fichier dont on donne le nom et renvoie le contenu sous la forme d'une chaine de caractère :

    ```ocaml
    let lire_fichier fname =
    let reader = open_in fname in
    In_channel.input_all reader;;
    ```

{{exo("Autour de la recherche naïve",[],0)}}


1. En OCaml

    1. Ecrire en OCaml l'algorithme de recherche naïf vu en cours et qui renvoie la liste de toutes les occurrences du motif dans la chaine 

    2. Tester la sortie anticipée d'une boucle à l'aide de la levée d'une exception de façon à renvoyer uniquement la première occurrence. On pourra utiliser l'exception prédéfinie `Exit` ou créer une exception  en déclarant par exemple `#!Ocaml exception Trouve;;`.


2. En C

    1. Ecrire l'algorithme de recherche naïf qui renvoie l'indice de la première occurence (ou `-1`) si le motif ne se trouve pas dans la chaine.

        !!!aide
            On pourra utiliser la fonction `strncmp` de `<string.h>` pour comparer directement le motif à n'importe quelle partie du texte.

    2. Ecrire une fonction qui renvoie les indices de toutes les occurrences sous la forme d'une liste chainée d'entiers (afin de revoir rapidement leur implémentation).

Dans les deux langages, pour tester les programmes, on pourra :

3. Ecrire une fonction qui prend en argument un nom de fichier et renvoie une chaine de caractères contenant les caractères du fichiers.


4. Tester les fonctions de recherche en écrivant un programme qui prend en argument sur la ligne de commande un motif et le nom du fichier contenant le texte.

    !!! aide
        On rappelle :  

        * qu'en C, la fonction `main` doit alors s'écrire `#!c main(int argc, char* argv[])` et que le tableau de chaines de caractères `argv` contient les arguments présents sur la ligne de commande à partir de l'indice 1 (`argv[0]` est le nom de l'exécutable).
        * qu'en OCaml, on peut récupérer directement l'argument numéro `i`  à l'aide de `#!ocaml Sys.argv.(i)` (comme en C, l'argument d'indice 0 est le nom de l'exécutable)

{{exo("Avec une table de décalage",[])}}

On rappelle qu'on peut accélérer la recherche en commençant par la fin du motif (de longueur $l_m$) et en utilisant une *table de décalage* $d$  qui indique de combien d'emplacement on peut avancer lorsqu'on rencontre deux caractères qui ne se correspondent pas :

* Si un caractère $c$ n'est pas dans le motif alors $d(c)=l_m$ 
* Si c est le dernier caractère du motif, alors $d(c)$ est la distance entre l'*avant-dernière* occurrence de $c$ et la fin du motif
* Sinon $d(c)$ est la distance entre la dernière occurrence de $c$ et la fin du motif

Dans une recherche naïve on teste les correspondances à chaque indice possible dans le texte, cette table de décalage permet d'avancer plus vite (au maximum on avance de la longueur du motif).

1. Ecrire la table de décalage du motif `petite`
2. Ecrire dans le langage de votre choix une fonction `decalage` qui prend en argument un motif et renvoie sa table de décalage. On rappelle qu'on utilise 128 caractères, on connait donc à l'avance la taille de la table de décalage. Tester votre fonction sur le motif `petite`
3. Implémenter l'algorithme de recherche de Boyer-Moore-Hoorspool
4. On propose de comparer le nombre de comparaisons effectués par la recherche naïve et par l'algorithme de Boyer-Moore-Hoorspool :

    * Modifier votre algorithme de recherche naïve afin qu'il renvoie aussi le nombre de comparaisons effectués (dans le cas du C, on pourra passer un pointeur vers un entier en argument et le modifier dès qu'une comparaison est faite)
    * Modifier de même votre implémentation de Boyer-Moore-Hoorspool afin d'obtenir le nombre de comparaisons effectués.
    * Conclure en testant par exemple sur la recherche de `Quasimodo` dans le fichier `notredame_ascii.txt` téléchargeable ci-dessus.

{{exo("Algorithme de Rabin-Karp",[])}}

1. Ecrire dans le langage de votre choix, une implémentation de l'algorithme de Rabin-Karp en utilisant la fonction de décalage qui effectue la somme des codes des caractères.

2. Modifier votre fonction afin de pouvoir obtenir en plus le nombre de collisions 

3. Tester en recherchant `ab` dans le fichier `notredame_ascii.txt`, combien de collisions ne sont *pas* des correspondances ? {{check_reponse("1803")}}

4.  Tester avec la nouvelle fonction de hachage   
$\displaystyle{h(s) = \sum_{i=0}^{n-1} 31^i \times c_i}$ (où les $c_i$ sont les caractères de la chaine $s$)

{{ exo("Algorithme de Huffmann",[])}}

!!! Aide
    On rappelle  que lors de la phase de construction de l'arbre, on sélectionne à chaque étape les deux arbres ayant les nombres d'occurrences les plus faibles. La structure de données adaptée est donc celle *d'une file de priorité* puisqu'elle permet la mise à jour de la structure de données en complexité logarithmique. Cette structure de données  s'implémente usuellement à l'aide d'un tas min binaire. Une implémentation de cette structure de donnée en OCaml est donnée ci-dessous. Cependant, on pourra aussi utiliser une simple liste dans laquelle on recherchera à chaque étape les éléments de plus petites priorités (ou coder sa propre implémentation). L'interface fournie est la suivante :

    * `#!ocaml let cree_file t default` crée une file de priorité de taille maximale `t` d'éléments de type de celui de `default`. Par exemple `#!ocaml let test = cree_file 10 ""` crée une file de priorité de taille 10 contenant des chaines de caractères.
    * `#!ocaml let enfile elt fp` enfile l'élément `elt` (représenté par un couple `priorite,valeur`) dans la file de priorité  `fp`. Par exemple `enfile (2,"Albert") test` ajoute "Albert" avec la priorité 2 dans la file `test`.
    * `#!ocaml let defile fp` renvoie l'élement de plus petite priorité (sous la forme d'un couple `priorite,valeur`)
    * `#!ocmal let taille fp` renvoie le nombre d'élements de la file `fp`

    ??? ocaml "Implémentation d'une file de priorité"
        ```ocaml
        --8<-- "C19/file_prio.ml"
        ```


Dans tout la suite on suppose défini `#!ocaml let nbchar = 128`,

1. Ecrire  une fonction `occurences : string -> int array` qui prend en argument une chaine de caractères `texte` et renvoie un tableau d'entier `occ` tel que `occ.(i)` contienne le nombre d'occurrence du caractère de code `i` dans `texte` (on rappelle qu'on considère que les codes des caractères sont ceux de l'{{sc("ascii")}}) et donc vont de 0 à 127.


2. On définit à présent le type : `#!ocaml type ab = Feuille of int | Noeud of ab*ab;;` qui permet de représenter un arbre de codage de Huffman, car c'est soit une feuille (avec le code du caractère) soit un noeud constitué d'un sous arbre droit et d'un sous arbre gauche. Ecrire une fonction `construire_arbre int array -> ab` qui prend en argument un tableau d'occurrence et constuit l'arbre de codage de Huffmann correspondant.

    !!!aide
        * Commencer par créer une file de priorité `a_traiter` dont les éléments sont du type `ab` et de taille maximale `nbchar`
        * Enfiler toutes `Feuilles(i)` en leur donnant comme priorité le nombre d'occurrence du caractère de code `i` (si ce nombre d'occurence est non nul)
        * Tant que `a_traiter` n'est pas réduit à un seul élément, extraire les deux ayant la plus grande priorité, les assembler en un nouvel arbre enfiler ce nouvel arbre en lui donnant la somme des priorités des deux éléments extraits.


3. Ecrire une fonction `cree_code ab -> string array` qui prend en argument un arbre de codage de Huffmann et renvoie les codes des caractères qu'il contient (on ajoute un 0 lorsqu'on par à gauche et un 1 lorsqu'on part à droite).

4. Tester votre fonction sur l'exemple vu en cours du texte `les petits tests tres betes`

5. Ecrire une fonction qui calcule le taux de compression du texte. Sur l'exemple précédent vous devriez obtenir un taux de compression d'environ $0,366$

6. Ecrire une fonction `lire_fichier string -> string` qui renvoie dans une chaine de caractère le contenu du fichier dont le nom est donné en argument

7. Tester l'algorithme de compression de Huffmann sur le fichier `notre_dame_ascii.txt` disponible en téléchargement ci-dessus. Quel taux de compression obtient-on (arrondir à 3 chiffres après la virgule) ? {{check_reponse("0.558")}}


{{ exo("Algorithme LZW",[])}}

Le but de l'exercice est d'implémenter en OCaml l'algorithme {{sc("lzw")}}, on rappelle qu'on considère qu'on compresse des textes en {{sc("ascii")}} et qu'on identifie un caractère à son code (un entier compris entre 0 et 127). On se fixe un maximum pour la taille des codes (en bits) produits par l'algorithme. Lorsque ce maximum est atteint, on ne produit plus de codes pour les prefixes rencontrés.

1. Définir en début de programme une constante `taille_max`, qui contiendra la taille maximale en bits d'un code, on pourra prendre la valeur 16 (de cette façon, un code occupe au maximum 2 octets). Ecrire une fonction qui renvoie le numéro maximal d'un code en connaissant la taille maximale de code utilisée.

2. On stocke les codes de chacun préfixe dans une *table de hachage*, et on rappelle qu'initialement seuls les codes des lettres sont dans la table. Ecrire une fonction `code_ascii : () -> (string, int) Hashtbl` qui renvoie une table de hachage dont les clés sont les caractères {{sc("ascii")}} et les valeurs les codes associés.
        
    !!! aide
        * On pourra commencer par écrire une fonction `string_of_char : char -> string`  qui renvoie le caractère passé en argument sous la forme d'une chaine de caractère, par exemple `string_of_char 'A'` renvoie `"A"`.
        * On rappelle les fonctions suivantes du module `Hashtbl` :
            * `#!ocaml Hashtbl.mem` crée une table de hachage (on doit donner une taille initiale)
            * `#!ocaml Hashtbl.mem` permet de tester l'appartenance
            * `#!ocaml Hashtbl.add` permet d'ajouter un nouveau couple (clé, valeur)
            * `#!ocaml Hashtbl.find` permet de récupérer la valeur associée à une clé
            * `#!ocaml Hashtbl.replace` permet de modifier la valeur associée à une clé

3. Ecrire la fonction de compression de signature : `compression : string -> (string,int) Hashtbl -> int -> int list * int` qui prend en argument  la texte à compresser, la table de hachage, le nombre de caractères de l'alphabet initial et renvoie la liste des codes générés ainsi que le nombre total de codes.

    !!! aide
        On rappelle qu'à chaque étape :

        * on émet le code du plus long préfixe se trouvant dans la table
        * on crée un nouveau code pour ce préfixe augmenté du caractère suivant

4. Ecrire la fonction de décompression de signature `decompression : int list -> string` qui prend en argument la liste des codes et renvoie le texte décompressé. Cette fois, on a besoin d'un tableau de chaines de caractères dont indicé par le numéro des codes. Initialement ce tableau contient les caractères {{sc("ascii")}}.

5. Tester vos fonctions d'abord sur de petits exemples tels que ceux vu en cours puis des fichiers plus longs.

## Humour d'informaticien

![tree](./Images/C19/dependency.png){.imgcentre width=500px}
