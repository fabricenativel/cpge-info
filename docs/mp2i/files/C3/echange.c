#include <stdio.h>

void echange(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main()
{
    int a = 42;
    int b = 2024;
    echange(&a, &b);
}
