#include <stdio.h>

int duree_vol(int n) {
    int dvol = 0;
    while (n!=1) {
        if (n%2==0) 
            {n = n/2;}
        else
            {n = 3*n+1;}
        dvol ++;}
    return dvol;}

int main()
{
    int n = 5;
    printf("Durée de vol de %d = %d\n",n,duree_vol(n));
}