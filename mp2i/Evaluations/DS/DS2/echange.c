#include <stdio.h>

void echange(int *p, int *q)
{
    *p = *p + *q;
    *q = *p - *q;
    *p = *p - *q;
}

int main()
{
    int n = 55;
    int m = 12;
    echange(&n, &m);
    printf("n = %d et m = %d\n",n,m);
}