{% set num = 9 %}
{% set niveau = "itc_s2"%}
{{ titre_chapitre(num,niveau)}}

## Cours

{{ affiche_cours(num) }}

## Travaux pratiques

{{exo("Du binaire au décimal",[],0)}}

Ecrire une fonction `bin_to_dec` qui convertit un nombre en écriture binaire (donnée sous la forme d'une chaine de caractères composées de '0' et de '1') en écriture décimale. Par exemples,

* `bin_to_dec("10011")` doit renvoyer 19 car {{binaire_dec("10011")}},
* `bin_to_dec("11000100")` doit renvoyer 196 car {{binaire_dec("11000100")}},
* `bin_to_dec("1001100")` doit renvoyer 76 car {{binaire_dec("1001100")}}.

!!! aide
    On pourra parcourir par indice la chaine de caractère représentant l'écriture binaire à partir de la fin (chiffre de "poids" $2^0$) et en revenant au début.


{{exo("De l'hexadécimal au binaire",[])}}

1. Ecrire une fonction `valeur_chiffre` qui prend en argument un caractère représentant un chiffre en base 16 et renvoie la valeur de ce chiffre en base 10. Par exemple `valeur_chiffre('8')` renvoie 8, et `valeur_chiffre('E')` renvoie 14.

    !!! aide
        On pourra utiliser le fait que les lettres `A`,...,`E` ont des codes {{sc("ascii")}} consécutifs et utiliser la fonction `ord` de Python qui renvoie ce code.

2. Ecrire une fonction `hex_to_dec` qui prend en argument un nombre écrit en base 16 et renvoie l'écriture décimale de ce nombre. Par exemple  `hex_to_dec("C7E")` renvoie `3198` car $(C7E)_{16} = (12\times 16^2 + 7\times16 + 14)_{10}$

{{ exo("Algorithme des divisions succesives",[])}}

Le but de l'exercice est d'écrire une implémentation en Python de l'algorithme des divisions successives qui permet de convertir un nombre écrit en base 10 dans une base $b$ quelconque ($b \geqslant 2$).

On rappelle que l'algorithme consiste  tant que $n$ n'est pas nul à :

* Ajouter le reste dans la division euclidienne de $n$ par $b$ à l'écriture en base $b$
* remplacer $n$ par le quotient de $n$ dans la division euclidienne par $b$

 Si $b>10$, on utilise comme chiffre les lettres de l'alphabet, on déclare donc en début de programme une chaine de caractères :

```python
CHIFFRES="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
```

1. Ecrire une fonction `dec_to` qui prend en argument un entier `n` (type `int`) écrit en base 10 et une base `b` (supérieur ou égale à 2) et renvoie l'écriture de `n` dans la base `b`

2. Tester votre fonction en affichant l'écriture en base `29` de `620647` (on rappelle qu'il y a 29 chiffres en base 29, les premiers sont `0,1, .. ,9` et après on utilise  les lettres `A, B, ...`).  
Vérfier votre réponse {{check_reponse("PCSI")}}

3. Ecrire une fonction `base_to_dec` qui prend en argument une chaine de caractère représentant un nombre écrit dans une base $b \geqslant 2$ ainsi que cet entier $b$ et renvoie l'écriture décimale de ce nombre. Par exemple `base_to_dec("210112",3)` renvoie 581, car le nombre est donné en base 3 et $2 \times 3^5 + 3^4 + 3^2 + 3^1 + 2\times3^0 = 581$


{{ exo("Complément à deux",[]) }}

1. Ecrire une fonction Python `binaire(entier)` qui prend en entrée un entier compris entre 0 et 127 et renvoie une chaîne de caractère contenant la représentation binaire de cet entier sur un octet. Par exemple `binaire(42)` renvoie `"00101010"`.

2. Ecrire une fonction Python `inverse_bit(chaine)` qui prend en entrée une chaîne de caractère et renvoie la chaîne dans laquelle tous les 0 ont été remplacés par des 1 et tous les 1 par des 0. Par exemple `inverse_bit("10110001")` renvoie `"01001110"`

3. Ecrire une fonction Python `ajoute_un(chaine)` qui prend en entrée une chaîne de caractères et effectuer l'addition binaire de 1 au nombre binaire représenté par cette chaine. Par exemple `ajoute_un("1001010")` renvoie `1001011`.

4. En utilisant les fonctions ci-dessus, écrire une fonction Python qui renvoie la représentation en complément à deux sur 8 bits d'un entier passé en paramètre.