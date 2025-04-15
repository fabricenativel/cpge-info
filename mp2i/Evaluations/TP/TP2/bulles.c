#include <stdio.h>
#include <assert.h>

void echange(int tab[], int i, int j, int taille)
{
    assert (i>=0 && i<taille && j>=0 && j<taille);
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

// Parcours le tableau tab jusqu'à l'indice limite
// en échangeant un élément avec son voisin s'il lui est supérieur
void parcours(int tab[], int limite, int taille)
{
    assert (limite<taille);
    for (int i=0;i<limite;i++)
    {
        if (tab[i]>tab[i+1])
        {
            echange(tab,i,i+1,taille);
        }
    }
}

// Tri à bulles du tableau tab
void tri_bulles(int tab[], int taille)
{
    for (int lim=taille-1;lim>=1;lim--)
    {
        parcours(tab,lim,taille);
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

int main()
{
    int test[5000];
    for (int i=0;i<5000;i++)
    {
        test[i] = i*i - 564*i + 77760;
    }
    tri_bulles(test,5000);
    printf("Réponse = %d\n", test[2024]);
}