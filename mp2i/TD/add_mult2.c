#include <stdio.h>
#include <assert.h>

// pour n  et p deux entiers naturels renvoie le produit de n par p 
int multiplie(int n, int p){
    int prod = 0;
    while (n>0){
        if (n%2==1) {
            prod = prod+p;}
        n= n / 2;
        p = p*2;}
    return prod;}

int main()
{
    printf("12 * 30 = %d\n",multiplie(12,30));
}