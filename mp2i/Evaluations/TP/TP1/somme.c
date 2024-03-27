#include <stdbool.h>
#include <stdio.h>

// Ecrire ci-dessous la fonction divisible
bool divisible(int n,int d)
{
    return (n%d == 0);
}

int somme(int seuil)
{
    int s = 0;
    for (int i=1;i<seuil;i++)
    {   
        if (divisible(i,3) || divisible(i,7))
        s+=i;
    }
    return s;
}

int main()
{
    printf("Résultat = %d",somme(10000));
    return 0;
}