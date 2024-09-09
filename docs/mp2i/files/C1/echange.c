#include <stdio.h>

void echange(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 12;
    int b = 50;
    echange(a, b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}