#include <stdio.h>

void compte_rebours(int n)
{
    for (int i = n; i >= 0; i--)
    {
        printf("%d\n", i);
    }
    printf("Partez !\n");
}

void compte_rebours_rec(int n)
{
    if (n == 0)
    {
        printf("Partez !\n");
    }
    else
    {
        printf("%d\n", n);
        compte_rebours_rec(n - 1);
    }
}

int main()
{
    compte_rebours(10);
    compte_rebours_rec(10);
}