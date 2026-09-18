#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void affiche(int tab[], int size)
{
    for (int i=0;i<size;i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");
}

void partage(int tab[], int size1, int size2, int moitie1[], int moitie2[])
{
    for (int i=0;i<size1;i++)
    {
        moitie1[i]=tab[i];
    }
    for (int i=0;i<size2;i++)
    {
        moitie2[i]=tab[size1+i];
    }
}

int* fusion(int tab1[], int size1, int tab2[], int size2)
{
    int * tab = malloc(sizeof(int)*(size1+size2));
    int i = 0;
    int i1 = 0;
    int i2 = 0;
    while (i<size1+size2)
    {
        if ((i1<size1 && i2<size2 && tab1[i1]<tab2[i2]) || (i2>=size2))
        {
            tab[i]=tab1[i1];
            i1 += 1;
        }
        else
        {
            tab[i]=tab2[i2];
            i2 += 1;
        }
        i += 1;
    }
    return tab;
}

int * tri_fusion(int tab[], int size)
{
    if (size>=2)
    {int size1 = size/2;
    int size2 = size-size1;
    int * moitie1 = malloc(sizeof(int)*size1);
    int * moitie2 = malloc(sizeof(int)*size2);
    partage(tab, size1, size2, moitie1, moitie2);
    int *mt1 = tri_fusion(moitie1,size1);
    int *mt2 = tri_fusion(moitie2,size2);
    return fusion(mt1,size1,mt2,size2);
    }
    int * mt = malloc(sizeof(int)*size);
    mt[0] = tab[0];
    return mt;
}

int main()
{
    srand(time(NULL));
    int t[100] ;
    for (int i=0;i<100;i++)
    {
        t[i] = rand()%1000;
    }
    int *tf = tri_fusion(t,100);
    affiche(tf,100);
    free(tf);
}