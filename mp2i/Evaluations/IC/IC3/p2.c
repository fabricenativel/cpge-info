#include <stdio.h>
int main()
{
    int n = 42;
    int *p = &n; 
    *p = 2025;
    printf("Valeur de n = %d\n", n); 
}