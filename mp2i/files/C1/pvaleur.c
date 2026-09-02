#include <stdio.h>

void incremente(int n)
{
    n = n + 1;
}

int main()
{
    int n = 42;
    incremente(n);
    printf("n = %d\n", n);
}