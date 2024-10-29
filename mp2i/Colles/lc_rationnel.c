#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


struct maillon
{
    int valeur;
    struct maillon * suivant;
};
typedef struct maillon maillon;
typedef maillon* liste;


bool est_dans(int tab[], int size, int elt)
{
    for (int i=0; i<size; i++)
    {
        if (tab[i]==elt) {return true;}
    }
    return false;
}

void chiffres(int a, int b)
{
    int q, r;
    int deja_vu[1000];
    int cpt = 0;
    deja_vu[cpt] = a; 
    bool ended = false;
    printf("%d.",a/b);
    a  = (a%b)*10;
    while (!ended)
    {
        q = a/b;
        r = a%b;
        a = r * 10;
        printf("%d",q);
        if (est_dans(deja_vu, cpt, a))
        {ended = true;}
        else
        {deja_vu[cpt++]=a;}
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    chiffres(a,b);
}