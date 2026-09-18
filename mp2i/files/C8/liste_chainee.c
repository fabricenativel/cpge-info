#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

struct maillon_s
{
    int valeur;
    struct maillon_s * suivant;
};
typedef struct maillon_s maillon;
typedef maillon* liste;



void view_list(liste l)
{
    printf("-> ");
    while (l!=NULL)
    {
        printf("%i -> ",l->valeur);
        l = l->suivant;
    }
    printf("null \n");
}

liste cree_liste()
{
    liste l= NULL;
    return l;
}

void ajout(liste *l, int v)
{
    liste nl=malloc(sizeof(maillon));
    nl->suivant = *l;
    nl->valeur =v;
    *l = nl;
}

void supprime(liste *l)
{
    if (l!=NULL)
    {
        liste ls = (*l)->suivant;
        free(*l);
        *l = ls;
    }
}

void detruit(liste *l)
{
    liste oh;
    while (*l!=NULL)
    {   
        oh = *l;
        *l = (*l)->suivant;
        free(oh);
    }
}

int somme_liste(liste l)
{
    int s = 0;
    while (l!=NULL)
    {
        s += l->valeur;
        l=l->suivant;
    }
    return s;
}


int somme_tab(int tab[], int size)
{
    int s = 0;
    for (int i=0; i<size;i++)
    {
        s += tab[i];
    }
    return s;
}

int main()
{   double t;
    clock_t start, end;
    liste l = NULL;
    int *tab = malloc(sizeof(int)*SIZE);
    for (int i=0;i<SIZE;i++)
    {
        tab[i]=i;
    }
    for (int i=0;i<SIZE;i++)
    {
        ajout(&l,i);
    }
    start = clock();
    printf("Somme (liste) : %d \n",somme_liste(l));
    end = clock();
    t = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Temps : %lf\n",t);
    start = clock();
    printf("Somme (tableau) : %d \n",somme_tab(tab,SIZE));
    end = clock();
    t = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Temps : %lf\n",t);
    detruit(&l);
    free(tab);
}