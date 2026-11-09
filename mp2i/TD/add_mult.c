#include <stdio.h>

int mult(int n, int p){
    int prod = 0;
    while (p>0){
        prod = prod + n;
        p = p -1;}
    return prod;}

int main()
{
    printf("12 * 30 = %d\n",mult(12,30));
}