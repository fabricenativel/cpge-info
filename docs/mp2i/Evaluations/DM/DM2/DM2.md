hide: - navigation  in index.md

{{dm(2,"Nombres de Lychrel")}} 


On dit qu'un nombre est un *nombre palindrome* lorsqu'il peut se lire indifféremment de droite à gauche ou de gauche à droite. Par exemple *27172*, *505* ou encore *183381* sont des nombres palindromes alors que *1515* ou *766* n'en sont pas. En partant d'un nombre quelconque écrit en base 10 et qu'on note $(a_{n-1}\dots a_0)_{10}$, tant que ce nombre n'est pas un nombre palindrome on l'additionne avec le nombre obtenu en écrivant ses chiffres de droite à gauche c'est à dire qu'on effectue l'addition $(a_{n-1}\dots a_0)_{10} + (a_{0}\dots a_{n-1})_{10}$. 

Prenons quelques exemples,

* Avec le nombre de départ $74$ on obtient, $74 + 47 = 121$ et donc un palindrome après une itération du procédé.
* Avec le nombre $178$ on obtient $178 + 871 = 1049$ puis $1049 + 9401 = 10450$ et enfin $10450 + 5401 = 15851$ qui est un palindrome. Cette fois, trois itérations ont été nécessaires pour produire un palindrome.

Le fait de savoir si ce procédé conduit toujours à un palindrome est une question ouverte et on appelle *nombre de lychrel* un nombre pour lequel ce procédé n'aboutit jamais à un palindrome. On ne sait donc pas si de tels nombres existents mais le plus petit nombre candidat est **196** car après [*trois ans de calcul*](https://www.fourmilab.ch/documents/threeyears/threeyears.html){target=_blank} (menées à la fin des années 1980) et plusieurs millions d'itérations, John Walker a montré que le procédé ne fournissait toujours pas un palindrome. Le but de l'exercice est de reproduire ces résultats, mais les ordinateurs ayant maintenant de bien meilleures capacités de calcul, cela devrait nous prendre bien moins que trois ans de calcul ...

## Une approche naïve

On utilise ici le type `uint64_t` du C (disponible dans `<stdint.h>`) afin de représenter un entier positif et on écrit les fonctions permettant d'itérer le processus jusqu'à détecter un palindrome.

1. Ecrire une fonction de signature `#!c uint64_t envers(uint64_t n)` qui renvoie le nombre formé par  les chiffres de l'entier `n` lus de droite à gauche, par exemple `envers(1789)` renvoie `9871`.

2. Ecrire une fonction de signature `#!c bool palindrome(uint64_t n)` qui renvoie `true` lorsque `n` est un nombre palindrome.

3. Ecrire une fonction de signature `#!c uint64_t terme_suivant(uint64_t n)` qui prend en entrée un entier `n` et renvoie le nombre obtenu en additionnant `n` au norme formé en écrivant les chiffres de `n` à l'envers.

4. Ecrire une fonction de signature `#!c int lychrel(unint64_t n, int limit, uint64_t *pal)` qui renvoie le nombre d'itérations nécessaire en partant de l'entier `n` pour obtenir un palindrome en répétant le processus consistant à additionner `n` avec le nombre formé par les chiffres de `n` écrit à l'envers. Cette fonction modifie aussi `*pal` en lui donnant la valeur du palindrome trouvé. Si après `limit` itérations un palindrome n'a pas été obtenu on renvoie `-1` et le pointeur `*pal` n'est pas modifié.

5. Vérifier que pour tous les entiers positifs strictement inférieur à 196, le processus s'arrête en moins de 100 itérations en produisant un palindrome. Vérifier vos résultats ci-dessous :

    * Nombre maximal d'itérations avant d'atteindre un palindrome {{check_reponse("24")}}
    * Plus petit entier pour lequel le nombre d'itération est maximal {{check_reponse("89")}}
    * Plus grand nombre palindrome obtenu {{check_reponse("8813200023188")}}

6. Modifier le code de la fonction `terme_suivant` (écrite à la question 3) en ajoutant une instruction `assert` permettant de vérifier que l'addition de `n` et de `n` écrit à l'envers ne provoque pas de dépassement de capacité. On pourra utiliser la constante `UINT64_MAX`. Tester alors la fonction `lychrel`  pour l'entier 196. Conclure quant à l'approche utilisant les entiers `uint64_t`.

## Utilisation d'un type structuré

Afin d'éviter le problème du dépassement de capacité, on propose d'utiliser un type structuré afin de représenter un entier, l'un des champs est le nombre de chiffres de l'entier et l'autre un pointeur vers une zone mémoire qui contiendra le tableau des chiffres du nombres :

```c
--8<-- "DM2/lychrel.c:struct"
```

Le champ `digits` sera alloué dynamiquement sur le tas une fois connu le nombre de chiffres de l'entier, de cette façon on évite les problèmes de dépassement de capacité. La seule limite est celle de la quantité de mémoire disponible. 

1. Ecrire une fonction `#!c number create(int n)` qui prend en entrée un entier positif `n` et renvoie une variable de type `number` tel que le champ `size` contienne le nombre de chiffres de `n` et le champ `digits` pointe vers une zone mémoire qui contient les chiffres de `n`. Par exemple pour l'entier `1789`, le champ `size` contient `4` et le champ `digits` pointe vers une zone mémoire contenant (dans cet ordre) les entiers `9, 8, 7` et `1`.

2. Ecrire une fonction `#!c bool palindrome(number dn)` qui renvoie `true` lorsque le nombre représenté par `dn` est un nombre palindrome.

3. Ecrire une fonction `#!c void next(number *dn)` qui ne renvoie rien et modifie  `*dn` de façon à représenter le terme suivant dans le processus consistant à additionner un entier avec le nombre écrit en retournant ses chiffres. Par exemple si `dn` correspond à l'entier `1789` alors après l'appel `next(dn)`, `dn` correspondra à  l'entier `1789 + 9871 = 11660` c'est à dire que son champ `size` contiendra 5 et que son champ `digits` pointera vers une nouvelle zone mémoire contenant les entiers `0, 6, 6, 1, 1` (on pensera à libérer la zone mémoire précédente).

4. Ecrire une fonction `#!c int lychrel(number *dn, int limit)` qui itère le processus consistant à remplacer `dn` par le nombre obtenu en l'additionnant au nombre formé en écrivant ses chiffres à l'envers jusqu'à soit atteindre un palindrome, soit atteindre un maximum de `limit` itérations. 

5. Tester votre fonction en vérifiant qu'en partant du nombre `1005499526` on obtient un palindrome après **109** itérations. Quel est ce palindrome ? {{check_reponse("66330069478378985774345546664554347758987387496003366")}}

6. Vérifier qu'en partant de 196, on n'obtient pas de palindrome en fixant une limite de 10000 itérations.

## Reproduction du résultat de J. Walker

1. Comme indiqué en introduction, en démarrant de 196 et après trois ans de calcul J; Walker a atteint un nombre d'un million de chiffres sans trouver de palindrome. Il avait donc fixé une limite *en nombre de chiffres* et non pas en nombre d'itérations comme nous venons de le faire. Ecrire une fonction `#!c bool walker(number *dn, int limit, int *nb_iter)` qui répète le processus jusqu'à obtention d'un palindrome et dans ce cas renvoie `true` ou jusqu'à atteindre un chiffre ayant  `limit` chiffres dans son écriture décimale et dans ce cas renvoie `false`. D'autre part cette fonction modifie `*nb_iter` en lui affectant le nombre d'itérations effectués à la fin du processus.

2. Tester votre fonction en recherchant le nombre d'itérations en partant de 196 pour atteindre un nombre ayant $100\,000$ chiffres. Vérifier votre réponse {{check_reponse("241389")}}.

    !!! aide
        On conseille de compiler avec l'option  `-O2` qui permet d'obtenir un code compilé plus rapide.

3. Retrouver le résultat de J. Walker en déterminant le nombre d'itérations nécessaires avant de produire le premier nombre ayant un million de chiffres.

    !!! note
        Le temps de calcul risque d'être conséquent, mais devrait être bien inférieur à 3 ans !