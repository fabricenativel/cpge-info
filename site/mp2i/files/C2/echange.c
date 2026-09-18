#include <stdio.h>

void echange(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main()
{
    int a = 15;
    int b = 42;
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a = %d\n",a);
    printf("b = %d\n",b);
}