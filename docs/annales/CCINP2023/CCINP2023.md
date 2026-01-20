{{titre_concours("CCINP","2023")}}


## Enoncé

{{telecharger("Enoncé","CCINP2023.pdf")}}

## Partie I - Acquisition du document

### Question 1

!!! note
    Les calculatrices étant interdites, on effectue le calcul en ordre de grandeur.

* Comme $256 = 2^8$, il faut un mot de 8 bits c'est à dire un octet pour un représenter un entier compris entre 0 et 255. Par conséquent il faut 3 octets pour chaque pixel.
* La largeur du format A4 est de $21$ cm soit environ $8.4$ pouces avec une résolution de 300 ppp on a donc environ 2500 pixels sur la largeur.
* La longueur du format A4 est de $29,7$ cm soit environ $12$ pouces ce qui donne avec la résolution de 300 ppp environ 3600 pixels sur la longueur.
Au final la taille de l'image sera environ $2.5 \times 3.6 \times 10^6 \times 3  \simeq 30 \times 10^6$ octets c'est à dire **30 Mo**.

### Question 2

!!! warning "Attention"
    La fonction de conversion proposée dans l'énoncé semble contenir des erreurs, on propose les corrections suivantes :

    * à la ligne 3, `#!python initialise(n0,n1,0)` au lieu de `#!python initialise(p,q,0)`
    * à la ligne 8, `#!python img[i][j] = int(val)` au lieu de `#!python img[i,j] = int(val)`

L'énoncé ne précise pas la complexité de la foncion `initialise` appelée par `conversion_gris` on suppose dans la suite qu'elle est de complexité $\mathcal{O}(n_0\,n_1)$ (initialisation d'une liste de liste de taille $n_0 \times n_1$).
La complexité de la fonction `conversion_gris` est  alors aussi $\mathcal{O}(n_0\,n_1)$, en effet elle utilise deux boucles imbriquées effectuées respectivement $n_0$ et $n_1$ fois et la boucle intérieure n'effectue que des opérations élémentaires (affectation et calcul). 

### Question 3

```python
--8<-- "CCINP2023/CCINP2023.py:Q3"
```

## Partie II - Reconnaissance du document

### Question 4

La proposition décrite dans l'énoncé correspond à la deuxième fonction du document réponse :
```python
--8<-- "CCINP2023/CCINP2023.py:Q4"
```

### Question 5

