{% set num = 3 %}
{% set niveau = "mp2i"%}

{{ titre_chapitre(num,niveau)}}


{{ citation("Pointers have been lumped with the `goto`  statement as a marvelous way to create impossible-to-understand programs. This is certainly true when they are used carelessly, and it is easy to create pointers that point somewhere unexpected. With discipline, however, pointers can also be used to achieve clarity and simplicity","B. Kernighan & D. Ritchie","[in the C programming language 1978](https://en.wikipedia.org/wiki/The_C_Programming_Language)")}}

## Cours

{{ cours(num) }}


## Travaux dirigés

## Travaux pratiques



{{ exo("Visualisation avec Python Tutor",[],0)}}
Le site [Python Tutor](https://pythontutor.com/c.html#mode=edit){target=_blank}, permet de visualiser l'execution de programmes C. 

1. Aller sur [Python Tutor](https://pythontutor.com/c.html#mode=edit){target=_blank}, recopier et visualiser l'exécution du programme suivant :

```C
#include <stdlib.h>

int main() {
  int n_local;
  int *p_local = &n_local;
  int *p_tas = malloc(sizeof(int));
  return 0;
}
```

2. En citant le cours, justifier brièvement que `p_local` pointe sur la pile alors que `p_tas` pointe sur le tas.

3. Compléter ce programme en définissant une variable globale `n_globale` de type `int` non initialisée. Que remarquez-vous ?

4. En utilisant le pointeur `p_local`, donner la valeur 42 à `n_local`

5. Quelle instruction, pourtant très importante, est manquante dans ce programme ? La rajouter et indiquer quelle option de compilation permettrait de faire apparaître le problème.

{{ exo("Pour démarrer en douceur",[])}}

1. Ecrire en C un programme qui définit (dans `main`) une variable locale `n_local` de type `int` et affiche son adresse mémoire.

    !!! aide
        * L'opérateur `&` permet de récupérer l'adresse d'une variable
        * Le spécificateur de format pour les pointeurs dans `printf` est `%p`

2. Ecrire en C un programme qui alloue dans le tas une variable de type `int` et affiche son adresse mémoire.

3. Les résultats sont-ils conformes au modèle mémoire du C vu en cours ? Justifier.

{{ exo("Warning",[])}}

On souhaite écrire en C, un programme qui affiche l'adresse et le contenu d'une variable locale à une fonction. 

1. Recopier, compiler (en ignorant le *warning*) et exécuter la proposition de solution suivante qui effectue un affichage depuis le `main` :

    ```C linenums="1"
    #include <stdio.h>
    #include <stdlib.h>

    int* get_adr_local()
    {
        int n_local = 15;
        return &n_local;
    }

    int main()
    {
        int *p = get_adr_local();
        printf("Adresse de la variable locale = %p",p);
        printf("Contenu = %d",*p);
    }
    ```

2. Expliquer le résultat obtenu 

    !!! aide
        Le *warning* obtenu à la compilation devrait vous mettre sur la voie

4. Est-il possible d'afficher l'adresse d'une variable locale à une fonction depuis le `main` ? Et depuis la fonction ?

3. Effectuer une allocation sur le tas à la ligne 6 (et changer le nom de la variable en `n_tas`). Expliquer pourquoi le programme fonctionne maintenant sans erreur

{{ exo("Renvoyer un tableau",[])}}

1. Recopier et compléter la fonction `get_tab` suivante qui prend en argument un entier `size` et une valeur  entière `val` et renvoie un tableau de taille `size` dont toutes les cases sont initialisées à `val` :
```C
int* get_tab(int size, int val)
{
    // Allouer sur le tas la place pour size entiers
    int* tab = .........;
    for (int i=0;.....;.....) 
    {
        tab[i] = ....;
    }
    return tab;
}
```

2. Ecrire un programme permettant de tester cette fonction

3. La mémoire allouée n'a pas dans la fonction, n'a pas été libéré, est-ce une erreur ?

3. En vous inspirant de cette fonction écrire :

    * une fonction renvoyant un tableau contenant les entiers de 1 à `size`

    * une fonction  renvoyant un tableau contenant `size` entiers aléatoires tous compris entre deux valeurs `vmin` et `vmax`

        !!! aide
            Pour générer un entier aléatoire entre `vmin` et `vmax` on utilisera la fonction `rand()` qui renvoie un entier entre 0 et une constante `RAND_MAX` puis on utilisera un modulo. 


{{ exo("Minimum et maximum",[])}}

On souhaite écrire une fonction `min_max` qui prend en argument un tableau contenant au moins un entier et permet d'obtenir le minimum et le maximum de ce tableau. 

1. Une première solution consiste à passer en paramètre deux pointeurs et à les faire pointer vers le minimum et le maximum du tableau. Dans ce cas la signature de la fonction sera donc :
    ```C
    void min_max(int tab[], int size, int *min, int *max)
    ```
Ecrire et tester cette fonction.

2. Une seconde solution consiste à définir un type structuré `couple` contenant deux champs de type `int` et de d'écrire une fonction renvoyant un `couple` dont le premier champ sera le minimum et le second le maximum. Dans ce cas, la signature de la fonction sera donc :
    ```C
    couple min_max(int tab[], int size)
    ```
Ecrire et tester cette fonction

    !!! aide
        La définition du type structuré couple s'écrit (en nommant les champs `first` et `second``):
        ```C
        struct couple {
            int first;
            int second;
        };
        typedef struct couple couple;
        ```

{{ exo("Sur les caractères",[]) }}

On souhaite écrire une fonction `inverse_casse` en C qui ne renvoie rien et change la casse de la lettre passée en argument (si c'est une majuscule alors elle devient minuscule et inversement). Si l'argument n'est pas une lettre, la fonction ne fait rien. 

!!! aide
    * Les caractères {{sc("ascii")}} des majuscules vont de 65 (pour le `A`) à 90 (pour le `Z`)
    * Les caractères {{sc("ascii")}} des minuscules vont de 92 (pour le `a`) à 122 (pour le `z`)

1. La proposition de solution ci-dessous ne compile pas, corriger les erreurs qui s'y trouvent puis exécuter le programme (les lignes problématiques sont surlignées).

    ```C hl_lines="5 7 11 13 15"
    #include <stdio.h>

    void inverse_casse(char lettre)
    {
        if (65<=lettre & lettre<=90)
        {lettre = lettre + 32;}
        if (92<=lettre & lettre<=122)
        {lettre = lettre - 32;}
    }

    int main 
    {
        lettre = 'c';
        inverse_casse(lettre);
        print("Résultat : %c",lettre)
        return 0;
    }
    ```

1. Expliquer pourquoi le programme affiche `c` (et que donc la fonction est inopérante)

2. Quelle devrait être la signature de cette fonction ?

3. Corriger la proposition ci-dessus

4. Compléter le programme en ajoutant une fonction `inverse_casse_chaine` qui ne renvoie rien et inverse la casse de toutes les lettres présentes dans la chaine donnée en paramètre    .


## Humour d'informaticien

{{ citation("1972 - Dennis Ritchie invents a powerful gun that shoots both forward and backward simultaneously. Not satisfied with the number of deaths and permanent maimings from that invention he invents C and Unix.","James Iry","[blog](http://james-iry.blogspot.com/2009/05/brief-incomplete-and-mostly-wrong.html?m=1)")}}

