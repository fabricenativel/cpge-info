#include <stdio.h>
#include <math.h>

const double pi = 3.14159;

double aire_disque(double rayon)
{
    return pi*pow(rayon,2.0);
}

int main()
{
    printf("Aire du disque de rayon 5 : %f\n",aire_disque(5.0));
    return 0;
}