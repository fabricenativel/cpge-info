#include <stdio.h>

int signe(int n)
{
    if (n>0)
    {
        return 1;
    }
    if (n<0)
    {
        return -1;
    }
}

int main()
{
    int n=0;
    int sn = signe(n);
    printf("Le signe de %d est %d\n", n, sn);
    return 0;
}