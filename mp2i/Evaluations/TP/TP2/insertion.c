#include <stdio.h>
#include <assert.h>

void echange(int tab[], int i, int j, int taille)
{
    assert (i>=0 && i<taille && j>=0 && j<taille);
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

// Insère tab[i] dans le sous tableau tab[0]...tab[i-1]
// en supposant que ce sous tableau est déjà trié
void insere(int tab[],int i,int size)
{
    while (i-1>=0 && tab[i]<tab[i-1])
    {
        echange(tab,i,i-1,size);
    }
}

// Tri par insertion le tableau tab
void tri_insertion(int tab[], int size)
{
    for (int i=1;i<size;i++)
    {
        insere(tab,i,size);
    }
}

int main()
{
    int test[5000];
    for (int i=0;i<5000;i++)
    {
        test[i] = i*i - 564*i + 77760;
    }
    tri_insertion(test,5000);
    printf("Réponse = %d\n", test[2024]);
}