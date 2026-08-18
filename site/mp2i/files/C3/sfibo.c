#include <stdio.h>
#include <stdlib.h>

int* fibo(int n)
{
    int* termes = malloc(sizeof(int)*n);
    termes[0]=0;
    termes[1]=1;
    for (int i=2;i<n;i++)
    {
        termes[i] = termes[i-1] + termes[i-2];
    }
    return termes;
}

int somme_pair(int* tab, int size)
{
    int spair = 0;
    for (int i=0; i<size; i++)
    {
        if (tab[i]%2==0)
        {
            spair += tab[i];
        }
    }
    return spair;
}

int main()
{
    printf("Résultat = %d\n",somme_pair(fibo(42),42));
}
