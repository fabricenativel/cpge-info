#include <stdio.h>


void echange(int tab[],int  i, int  j)
{
    int temp;
    temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}


int partitionne(int tab[], int size)
{
    int pivot = tab[size-1];
    echange(tab,0,size-1); 
    int e = 0;
    // Entre 0 et e : <pivot, entre e et i : >= pivot
    for (int i = 0; i < size-1; i++)
    {
        if (tab[i]<=pivot)
        {
            echange(tab, e, i);
            e+=1;
        }
    }
    echange(tab,size-1,e);
    return e;
}

int main()
{
    int tab[]={3, 7, 8, 5, 2, 1, 9, 5, 4};
    printf("Sépartation en %d",partitionne(tab,9));
    for (int i=0;i<9;i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}