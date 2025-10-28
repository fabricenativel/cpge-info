#include <stdio.h>

int fonction(int a)
{
    a = a + 1;
    printf("Valeur de a = %d\n", a);
}

int main()
{
    int c = 2;
    int d = fonction(c);
    printf("valeur de c = %d \n", c);
    printf("valeur de d = %d \n", d);
}