#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool est_vide(pile p)
{
    return (p==NULL);
}

TYPE  depile(pile *p)
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

TYPE sommet(pile p)
{
    return p->valeur;
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
    FILE * reader = fopen("mystere.txt","r");
    char c;
    while ((c=fgetc(reader))!=EOF)
    {
        if (est_vide(p) || (sommet(p)!=c))
        {empile(&p,c);}
        else
        {depile(&p);}
    }
    affiche(p);
}