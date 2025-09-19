hide: - navigation  in index.md

{{dm(1,"Algorithme de Luhn")}} 


L'[algorithme de Luhn](https://fr.wikipedia.org/wiki/Formule_de_Luhn), du nom de son inventeur 
[Hans Peter Luhn](https://fr.wikipedia.org/wiki/Hans_Peter_Luhn){.target =_blank} est célèbre car il est notamment utilisée pour vérifier qu'un numéro de carte de crédit est valide. Pour valider un numéro donné on calcule à partir de ses chiffres une valeur appelée *somme de contrôle*, si cette valeur est divisible par 10 alors le numéro est valide.

Le but de l'exercice est de mettre en oeuvre cet algorithme puis de le tester. 

## Une fonction annexe 

1. On commence par écrire  une fonction annexe qui sera utile dans le calcul de la somme de contrôle. Ecrire une fonction de signature `#!c int mult2(int c)` qui prend en entrée un entier naturel $c$ tel que $0\leqslant c \leqslant 9$ et renvoie $2c$  lorsque $0\leqslant 2c \leqslant 9$ et la somme des deux chiffres de $2c$ sinon. On vérifiera les préconditions à l'aide d'instructions `#!c assert`.

    ??? Question "Correction"
        ```c
        --8<-- "DM1/luhn.c:Q1"
        ```

2. Pour vérifier que la fonction `mult2` est totalement correcte, dix tests suffisent, lesquels et pourquoi ? Ecrire ces dix tests sous forme d'instructions `#!c assert`.

    ??? Question "Correction"
        L'unique argument de la fonction `mult2` ne prend que dix valeurs possibles (les chiffres de 0 à 9), donc on doit tester pour chacune de ces valeurs que le résultat renvoyé est correct :
        ```c
        --8<-- "DM1/luhn.c:Q2"
        ```

## Validation d'un numéro

Le calcul de la somme de contrôle consiste à faire la somme des chiffres du numéro à tester en utilisant au préalable la fonction `mult2` sur les chiffres dont le rang est pair (c'est à dire en partant de la fin du nombre, le 2e chiffre, le 4e, ...). Par exemples :

* pour `267` on doit faire `2 + mult2(6) + 7` ce qui donne  `2+3+7 = 12`.
* pour  `15782`, on doit faire la somme `1 + mult2(5) + 7 + mult2(8) + 2`, ce qui donne : `1+1+7+7+2 = 18`.
* pour  `124586`, on doit faire la somme `mult2(1) + 2 + mult2(4) + 5 + mult2(8) + 6`, ce qui donne : `2+2+8+5+7+6 = 30`.

On rappelle que le numéro est valide lorsque cette somme de contrôle est divisible par 10, ainsi des trois exemples précédents, seul le dernier est un numéro valide.

3. Vérifier (à la main) que le numéro `4762` est valide mais pas le numéro `5438`.

    ??? Question "Correction"
        On effectue le calcul de la somme de contrôle pour chacun des deux nombres :

        * pour `4762` : $8 + 7 + 3 + 2 = 20$ donc ce numéro est valide,
        * pour `5438` : $1 + 4 + 6 + 8 = 19$ donc ce numéro est invalide.

4. Ecrire une fonction de signature `#!c bool valide(int n)` qui prend en entrée un numéro `n` et renvoie un booléen indiquant si ce numéro est valide.

    !!! aide
        On rappelle que `n%10` permet d'obtenir le dernier chiffre d'un nombre écrit en base 10.


    ??? Question "Correction"
        ```c
        --8<-- "DM1/luhn.c:Q3"
        ```

## Tests

On donne ci-dessous la définition en C d'un tableau de 100 numéros dont un seul n'est pas valide :

```c
int numeros[100] = {42893834, 469308860, 816927776, 146369152, 577477938, 242383354, 198853863, 497604926, 965166499, 896414216, 252023627, 504900275, 833686900, 25200593, 448977637, 675139265, 651805400, 403834260, 40891723, 34557363, 350052114, 215953688, 947025672, 269564290, 364657825, 610215303, 787228626, 336651237, 451740674, 687031351, 15139298, 19798024, 156340226, 357230580, 691330690, 258981679, 599613932, 890184567, 281750117, 564780427, 311762298, 533773735, 594844219, 145449195, 84137843, 568985378, 345751986, 735943243, 497983155, 386643704, 295664130, 848035267, 127760916, 242689800, 117599563, 492418736, 378068621, 429991706, 829069962, 354972812, 117023051, 844209254, 374770840, 273363275, 726603368, 591265053, 57508467, 326217296, 6613137, 339258576, 416161248, 843538950, 398195826, 11005451, 988988143, 482333671, 105154348, 859903643, 743440430, 603137506, 771710878, 564268084, 451172761, 899471783, 806957882, 93935849, 917054033, 185026515, 523927549, 746123991, 539999326, 640950606, 115496762, 439933680, 439477399, 842100126, 556362267, 496985862, 693480949, 562975391, };
```

1. Déterminer à l'aide d'un programme utilisant la fonction de validation lequel de ces numéros est invalide.
Tester votre réponse {{check_reponse("842100126")}}:

    ??? Question "Correction"
        Dans la correction ci-dessous, la variable `numeros` est le tableau donné dans l'énoncé.
        ```c
        --8<-- "DM1/luhn.c:Q4"
        ```


2. Ecrire une fonction qui prend en entrée un tableau d'entiers et renvoie le nombre de numéros valide dans ce tableau. Par exemple sur le tableau `numeros` de 100 entiers  donné en exemple, cette fonction doit renvoyer 99 puisque un seul numéro est invalide.

    ??? Question "Correction"
        ```c
        --8<-- "DM1/luhn.c:Q5"
        ```

3. Dans la fonction `main` de votre programme, initialiser le générateur de nombre aléatoire avec la valeur **42** (on rappelle qu'il faut écrire `#!c srand(42)`). Puis générer un tableau de 10000 nombres aléatoires inférieurs à `100000000` (avec `#!c rand() % 100000000`) et en utilisant la fonction écrite à la question précédente déterminer le nombre de numéros valide dans le tableau. Tester votre réponse {{check_reponse("949")}}.

    ??? Question "Correction"
        ```c
        --8<-- "DM1/luhn.c:Q6"
        ```

## Compléter un numéro valide

1. Ecrire une fonction qui prend en entrée un entier `n` et détermine quel chiffre ajouter à droite de ce nombre de façon à ce que le nombre ainsi formé soit un numéro valide. Par exemple pour 732, cette fonction renvoie 8 car le nombre 7328 est valide : `mult2(7) + 3 + mult2(2) + 8 = 5 + 3 + 4 + 8 = 20`

    ??? Question "Correction"
        ```c
        --8<-- "DM1/luhn.c:Q7"
        ```