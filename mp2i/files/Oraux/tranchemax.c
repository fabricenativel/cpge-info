#include <stdio.h>
#include <stdlib.h>

int max3(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    if (b > c)
        return b;
    return c;
}


int tranchemax_naif(int tab[], int n)
{
    // A compléter
}

// Maximum des tranches qui contiennent l'élément d'indice k
int max_tranchek(int tab[], int start, int k, int end)
{
    // A compléter
}


int main()
{
    int test[9] = {2, -7, -5, 4, -1, 10, -4, 9, -2};
    int n = 9;
    printf("Somme maximale d'une tranche = %d\n", ...... );
}