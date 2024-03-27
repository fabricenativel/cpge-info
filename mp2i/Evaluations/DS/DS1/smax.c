#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* make_rand(int size, int vmin, int vmax)
{
    srand(time(NULL));
    int *tab = malloc(sizeof(int)*size);
    for (int i=0;i<size;i++)
    {
        tab[i] = rand()%(vmax-vmin) + vmin;
    }
    return tab;
}

int max2(int a, int b)
{
    if (a>b )
        {return a;}
    {return b;}
}

int smax(int tab[],int size)
{   int best = -__INT_MAX__;
    int sm = 0;
    for (int i=0;i<size;i++)
    {   
        sm = max2(tab[i],sm+tab[i]);
        best = max2(best,sm);
    }
    return best;
}

int somme_partielle(int tab[], int i, int j)
{
    int s = 0;
    for (int k=i;k<=j;k++)
    {
        s =  s + tab[k];
    }
    return s;
}

int smax2(int tab[], int size)
{
    int best = tab[0];
    int sc = 0;
    for (int i=0;i<size;i++)
    {
        for (int j=i;j<size;j++)
        {
            sc = somme_partielle(tab,i,j);
            if (sc>best)
            { best = sc;}
        }
        
    }
    return best;
}

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

int main()
{
    int size = 10;
    int min = -50;
    int max = 50;
    //int ttab[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int  *ttab = make_rand(size,min,max);
    printf("Somme max version O(n2) = %d\n",smax2(ttab,size));
    printf("Somme max version O(n) = %d\n",smax(ttab,size));
    affiche(ttab,size);
    printf("\n");
    free(ttab);
}