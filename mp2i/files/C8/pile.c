#include <stdio.h>
#include <stdlib.h>

#define TYPE char

struct maillon
{
    TYPE valeur;
    struct maillon * suivant;
};
typedef struct maillon maillon;
typedef maillon* pile;

pile cree_pile()
{
    return NULL;
}

void empile(pile *p, TYPE v)
{
    pile np=malloc(sizeof(maillon));
    np->suivant = *p;
    np->valeur =v;
    *p = np;
}

int depile(pile *p)
{
    if (p!=NULL)
    {
        pile ls = (*p)->suivant;
        TYPE val = (*p)->valeur;
        free(*p);
        *p = ls;
        return val;
    }
}

void affiche(pile p)
{
    while (p!=NULL)
    {
        printf("%c<",p->valeur);
        p = p->suivant;
    }
    printf("\n");
}

int main()
{
    pile p = cree_pile();
    empile(&p,'M');
    empile(&p,'P');
    affiche(p);
    depile(&p);
    affiche(p);
}