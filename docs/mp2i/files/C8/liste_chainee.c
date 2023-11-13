#include <stdio.h>
#include <stdlib.h>

struct maillon
{
    int valeur;
    struct maillon * suivant;
};
typedef struct maillon maillon;

maillon * cree_liste()
{
    maillon *m= NULL;
    return m;
}

maillon* ajout(maillon* m, int v)
{
    maillon *n=malloc(sizeof(maillon));
    n->suivant = m;
    n->valeur =v;
    return n;
}

maillon* supprime(maillon* m)
{
    if (m!=NULL)
    {
        maillon *sav = m->suivant;
        free(m);
        return sav;
    }
}



void view_list(maillon *m)
{
    printf("-> ");
    while (m!=NULL)
    {
        printf("%i -> ",m->valeur);
        m = m->suivant;
    }
    printf("\n");
}

int main()
{
    maillon *liste = cree_liste();
    liste = ajout(liste,4);
    liste = ajout(liste,5);
    view_list(liste);
    liste = supprime(liste);
    view_list(liste);
    liste = supprime(liste);
    view_list(liste);
    liste = ajout(liste,7);
}