#include <stdio.h>

int pgcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return pgcd(b, a % b);
}

int main()
{
    printf("pgcd(48, 18) = %d\n", pgcd(48, 18));
    return 0;
}
