#include <stdio.h>
int main()
{
    int n = 42;
    int *p;
    *p = n;
    printf("Valeur pointée par p : %d\n", *p); 
}