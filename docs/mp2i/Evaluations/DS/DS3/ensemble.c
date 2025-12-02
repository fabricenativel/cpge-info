#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ensemble_s
{
    int cardinal;
    int* elements;
};
typedef struct ensemble_s ensemble;


ensemble cree_vide()
{
    ensemble e;
    e.cardinal = 0;
    e.elements = NULL;
    return e;
}

ensemble ajoute_element(ensemble ens, int elt)
{
    ensemble new;
    new.cardinal = ens.cardinal + 1;
    new.elements = malloc(sizeof(int)*new.cardinal);
    int offset = 0;
    for (int i=0;i<ens.cardinal;i++)
    {
        if (ens.elements[i]>elt && offset==0)
        {
            new.elements[i] = elt;
            offset = 1;
        }
        new.elements[i+offset] = ens.elements[i];
    }
    if (offset==0)
    {
        new.elements[new.cardinal-1] = elt;
    }
    return new;
}

ensemble intersection(ensemble ens1, ensemble ens2)
{
    int i1 = 0;
    int i2 = 0;
    int nb = 0;
    while (i1<ens1.cardinal && i2<ens2.cardinal)
    {
        if (ens1.elements[i1]==ens2.elements[i2])
        {
            nb+=1;
            i1++;
            i2++;
        }
        else if (ens1.elements[i1]<ens2.elements[i2])
        {
            i1++;
        }
        else
        {
            i2++;
        }
    }
    ensemble new;
    new.cardinal = nb;
    new.elements = malloc(sizeof(int)*nb);
    i1 = 0;
    i2 = 0;
    int i = 0;
    while (i1<ens1.cardinal && i2<ens2.cardinal)
    {
        if (ens1.elements[i1]==ens2.elements[i2])
        {
            new.elements[i++]=ens1.elements[i1];
            i1++;
            i2++;
        }
        else if (ens1.elements[i1]<ens2.elements[i2])
        {
            i1++;
        }
        else
        {
            i2++;
        }
    }
    return new;
}

void view(ensemble ens)
{
    printf("[%d] ",ens.cardinal);
    for (int i=0;i<ens.cardinal;i++)
    {
        printf("%d ",ens.elements[i]);
    }
    printf("\n");
}

bool appartient(ensemble ens, int elt)
{
    for (int i=0;i<ens.cardinal;i++)
    {
        if (ens.elements[i]==elt)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ensemble ens1 = cree_vide();
    ensemble ens2 = cree_vide();
    ens1 = ajoute_element(ens1, 2);
    ens1 = ajoute_element(ens1, 5);
    ens1 = ajoute_element(ens1, 7);
    ens2 = ajoute_element(ens2, 5);
    ens2 = ajoute_element(ens2, 6);
    ens2 = ajoute_element(ens2, 7);
    ens2 = ajoute_element(ens2, 10);
    view(ens1);
    view(ens2);
    ensemble ens3 = intersection(ens1, ens2);
    view(ens3);
    printf("%d \n",appartient(ens3, 5));
    printf("%d \n",appartient(ens3, 11));
}
