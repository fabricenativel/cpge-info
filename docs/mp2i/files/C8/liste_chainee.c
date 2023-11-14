#include <stdio.h>
#include <stdlib.h>

struct maillon
{
    int valeur;
    struct maillon * suivant;
};
typedef struct maillon maillon;
typedef maillon* liste;

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

void view_list(liste l)
{
    printf("-> ");
    while (l!=NULL)
    {
        printf("%i -> ",l->valeur);
        l = l->suivant;
    }
    printf("\n");
}

int main()
{
    liste *l = cree_liste();
    ajout(l,4);
    ajout(l,5);
    view_list(*l);
    supprime(l);
    view_list(l);
}