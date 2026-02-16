// Nearest smaller value
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct pile_s
{
    int taille_max;
    int indice_sommet;
    int *contenu;
};
typedef struct pile_s pile;

pile cree_pile(int tmax)
{
    pile p;
    p.taille_max = tmax;
    p.indice_sommet = -1;
    p.contenu = malloc(sizeof(int) * tmax);
    return p;
}

bool est_vide(pile p)
{
    return p.indice_sommet == -1;
}

void empiler(pile *p, int v)
{
    assert(p->indice_sommet + 1 < p->taille_max);
    p->indice_sommet += 1;
    p->contenu[p->indice_sommet] = v;
}

int depiler(pile *p)
{
    assert(!est_vide(*p));
    p->indice_sommet--;
    return p->contenu[p->indice_sommet + 1];
}

int sommet(pile *p)
{
    if (est_vide(*p))
    {
        return -1;
    }
    int temp = depiler(p);
    empiler(p, temp);
    return temp;
}

void libere(pile *p)
{
    free(p->contenu);
}

int *vpp_naif(int tab[], int size)
// Renvoie pour chaque indice i, l'emplacement de plus proche valeur inférieure -1 si inexistant
{
    int *nsv = malloc(sizeof(int) * size);
    int idx;
    nsv[0] = -1;
    for (int i = 1; i < size; i++)
    {
        idx = i - 1;
        while (idx >= 0 && tab[idx] >= tab[i])
        {
            idx--;
        }
        if (idx < 0)
        {
            nsv[i] = -1;
        }
        else
        {
            nsv[i] = tab[idx];
        }
    }
    return nsv;
}

int *vpp_pile(int tab[], int size)
{
    pile p = cree_pile(size);
    int *nsv = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        while (!est_vide(p) && sommet(&p) >= tab[i])
        {
            depiler(&p);
        }
        nsv[i] = sommet(&p);
        empiler(&p, tab[i]);
    }
    return nsv;
}

void view(int *tab, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d, ", tab[i]);
    }
    printf("%d \n", tab[size - 1]);
}

int main()
{
    int test[] = {5, 7, 11, 6, 9, 2};
    int size = 6;
    int *res1 = vpp_naif(test, size);
    int *res2 = vpp_pile(test, size);
    view(res1, size);
    view(res2, size);
    free(res1);
    free(res2);
}