#include <stdbool.h>
#include <stdio.h>

// Ecrire ci-dessous la fonction divisible
bool divisible(int n, int p)
{
    return (n%p==0);
}

int main()
{
    const int seuil = 10000;
    int somme = 0;
    for (int i=1;i<seuil;i=i+1)
    {
        if (divisible(i,3) || divisible(i,7))
        {
            somme = somme +i;
        }
    }
    printf("Résultat = %d\n",somme);
    return 0;
}