#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct maillon
{
    int valeur;
    struct maillon *suivant;
};
typedef struct maillon maillon;
typedef maillon *liste;

void insere(liste *l, int v)
{
    maillon *n = malloc(sizeof(maillon));
    n->valeur = v;
    n->suivant = *l;
    *l = n;
}

int maxliste(liste l)
{
    int cmax = l->valeur;
    while (l != NULL)
    {
        if (l->valeur > cmax)
        {
            cmax = l->valeur;
        }
        l = l->suivant;
    }
    return cmax;
}

void affiche(liste l)
{
    printf("->");
    while (l != NULL)
    {
        printf("%d ->", l->valeur);
        l = l->suivant;
    }
    printf("NULL\n");
}

int main()
{
    liste l = NULL;
    printf("Maximum des éléments = %d\n",maxliste(l));
}
