#include <stdio.h>
#include <stdlib.h>

//Compte les occurrences de dans un tableau
int occurences(int tab[], int size, int value)
{
    int occ = 0;
    for (int i=1;i<=size;i++)
    {
        if (tab[i]==value)
        {occ++;}
    }
    return occ;
}

//Construit la suite des gn jusqu'au rang n
int * golomb(int n)
{
    int *g = malloc(sizeof(int)*(n+1));
    int ct = 2;
    g[1]=1;
    g[2]=2;
    for (int i=3;i<n;i++)
    {
        if (occurences(g,i-1,ct)==g[ct])
        {g[i]=ct+1;
        ct=ct+1;}
        else
        {g[i]=ct;}
    }
    return g;
}

// affiche
void affiche(int g[], int size)
{
    printf("[");
    for (int i=1; i<size;i++)
    {
        printf("%d, ",g[i]);
    }
    printf("] \n");
}

int main()
{
    int *g = golomb(40);
    affiche(g,40);
    free(g);
}