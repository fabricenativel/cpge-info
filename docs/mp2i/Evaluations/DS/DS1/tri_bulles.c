#include <stdio.h>
#include <stdlib.h>

void affiche(int tab[], int size)
{
    printf("{");
    for (int i=0; i<size-1; i++)
    {
        printf("%d,",tab[i]);
    }
    if (size>0)
    {
        printf("%d",tab[size-1]);
    }
    printf("}");
}

void echange(int tab[],int i,int j)
{
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

int* copie_tab(int tab[],int size)
{
    int *ctab = malloc(sizeof(int)*size);
    for (int i=0; i<size; i++)
    {
        ctab[i] = tab[i];
    }
    return ctab;
}

int* trie_bulles(int tab[],int size)
{
    int *copie = copie_tab(tab,size);
    for (int i=size-1;i>0;i=i-1)
    {
        for (int j=0; j<i; j++)
        {
            if (copie[j]>copie[j+1])
            {
                echange(copie,j,j+1);
            }
        }
        affiche(copie,size);
        printf("\n");
    }
    return copie;
}

int main()
{
    int tab[6] = {5, 11, 8, 9, 4, 6};
    int *tab_trie = trie_bulles(tab,6);
    for (int i=0; i<6; i++)
    {printf("%d ", tab_trie[i]);}
    printf("\n");
}