#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define TMAX 1000

/* Implémentation d'une pile de capacite maximale TMAX*/

struct pile_s
{
    int pile[TMAX];
    int taille;
};
typedef struct  pile_s pile;

pile cree_pile()
{
    pile p;
    p.taille = 0;
    return p;
}

// teste si la pile est vide
bool est_vide(pile p)
{
    return (p.taille==0);
}

// Empiler n sur p
void empiler(pile *p, int n)
{
    p->pile[p->taille] = n;
    p->taille+=1;
}

// Depiler p
int depiler(pile *p)
{
    assert (!est_vide(*p));
    p->taille-=1;
    return p->pile[p->taille];
}

int main()
{
    pile p= cree_pile();
    int n;
    empiler(&p, 5);
    empiler(&p, 12);
    n = depiler(&p);
    printf("Valeur dépilée : %d\n",n);
}


