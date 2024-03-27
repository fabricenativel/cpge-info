#include <stdio.h>

int ecart_max(int tab[], int size)
{
    int tmin = tab[0];
    int tmax = tab[0];
    for (int i=1;i<size;i++)
    {   
        if (tab[i]>tmax) tmax=tab[i];
        if (tab[i]<tmin) tmin=tab[i];
    }
    return tmax-tmin;
}

int main()
{   int tab[100];
    for (int i=1;i<100;i++)
    {tab[i] = i*i - 133*i + 3822;}
    printf("Résultat = %d\n",ecart_max(tab,100));
    return 0;
}