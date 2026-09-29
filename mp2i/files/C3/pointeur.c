#include <stdio.h>

int main()
{
    int n = 7;
    int *p;
    *p = n;
    printf("Valeur de n =%d \n", *p);
    printf("Valeur de p= %p \n", p);
}
