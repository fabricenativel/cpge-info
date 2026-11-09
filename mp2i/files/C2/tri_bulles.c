#include <stdio.h>
#include <assert.h>

void echange(int tab[], int i, int j)
{
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

void parcours(int tab[], int limite, int taille)
{
    assert (limite<taille);
    for (int i=0;i<limite;i++)
    {
        if (tab[i]>tab[i+1])
        {
            echange(tab,i,i+1);
        }
    }
}

void affiche(int tab[], int size)
{
    for (int i=0;i<size;i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");
}

void tri_bulles(int tab[], int taille)
{
    for (int lim=taille-1;lim>=1;lim--)
    {
        parcours(tab,lim,taille);
    }
}


int main()
{
    int test[5] = {12, 9, 17, 11, 3};
    tri_bulles(test,5);
}