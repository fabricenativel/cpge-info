#include <stdio.h>

int fonction(int a)
{
    int b = a + 1;
    printf("Valeur de b = %d\n", b);
}

int main()
{
    int c = fonction(2);
    printf("valeur de c = %d \n", c);
}