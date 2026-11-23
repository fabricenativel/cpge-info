#include <stdio.h>

int somme(int n)
{
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0 || i % 7 == 0)
        {
            s += i;
        }
    }
    return s;
}

int main()
{
    printf("Somme 10 = %d\n", somme(10));
    printf("Somme 50000 = %d\n", somme(50000));
}