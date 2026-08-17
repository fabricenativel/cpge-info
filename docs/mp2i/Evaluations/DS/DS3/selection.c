#include <stdio.h>
#include <assert.h>

void echange(int tab[], int i, int j, int taille)
{
    assert(i >= 0 && i < taille && j >= 0 && j < taille);
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

// Renvoie l'indice du minimum des éléments de tab depuis l'indice ind
int indice_min_depuis(int tab[], int taille, int ind)
{
    assert(ind < taille && ind >= 0);
    int vmin = tab[ind];
    int imin = ind;
    for (int i = ind; i < taille; i++)
    {
        if (tab[i] < vmin)
        {
            imin = i;
            vmin = tab[i];
        }
    }
    return imin;
}

// Tri en place un tableau par sélection
void tri_selection(int tab[], int size)
{
    int im;
    for (int i = 0; i < size; i++)
    {
        im = indice_min_depuis(tab, size, i);
        echange(tab, i, im, size);
    }
}

int main()
{
    int test[5] = {2, -5, -4, 4, 1};
    tri_selection(test, 5);
}