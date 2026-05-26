#include <stdio.h>

int etendue(int tab[], int size)
{
    int mint = tab[0];
    int maxt = tab[0];
    for (int i = 0; i < size; i++)
    {
        if (tab[i] < mint)
        {
            mint = tab[i];
        }
        if (tab[i] > maxt)
        {
            maxt = tab[i];
        }
    }
    return maxt - mint;
}

int main()
{
    int u[100];
    for (int i = 0; i < 100; i++)
    {
        u[i] = i * i - 133 * i + 3822;
    }
    printf("Etendue de u = %d\n", etendue(u, 100));
}