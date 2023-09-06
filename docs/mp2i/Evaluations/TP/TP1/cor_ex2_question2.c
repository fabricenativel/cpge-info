#include <stdio.h>

int etendue(int tab[], int taille)
{
    int tmin = tab[0];
    int tmax = tab[0];
    for (int i=0;i<taille;i=i+1)
    {
        if (tab[i]<tmin)
        {
            tmin = tab[i];
        }
        if (tab[i]>tmax)
        {
            tmax = tab[i];
        } 
    }
    return tmax-tmin;
}

int main()
{
    int un[100];
    for (int i=0;i<100;i++)
    {
        un[i] = i*i - 133*i + 3822;
    }
    printf("Réponse = %d\n",etendue(un,100));
    return 0;
}