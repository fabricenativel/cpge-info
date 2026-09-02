#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void echange(int tab[],int  i, int  j)
{
    int temp;
    temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}


int partitionne(int tab[], int start, int end)
{
    int pivot = tab[end-1];
    int e = start;
    // Entre 0 et e : <pivot, entre e et i : >= pivot
    for (int i = start; i < end-1; i++)
    {
        if (tab[i]<=pivot)
        {
            echange(tab, e, i);
            e+=1;
        }
    }
    echange(tab,end-1,e);
    return e;
}

void affiche(int tab[], int s, int e)
{
    printf("[ ");
    for (int i=s;i <e-1; i++)
    {
        printf("%d ",tab[i]);
    }
    printf("%d] \n",tab[e-1]);
}

void mqsort(int tab[], int start, int end)
{
    int e;
    if ((end-start)>0)
    {
        e = partitionne(tab, start, end);
        mqsort(tab,start,e);
        mqsort(tab,e+1,end);
    };
}

int main()
{
    srand(time(NULL));
    int s = 100;
    int tab[s];
    for (int i=0;i<s;i++)
    {
        tab[i] = rand()%100;
    }
    mqsort(tab, 0, s);
    affiche(tab,0,s);
}