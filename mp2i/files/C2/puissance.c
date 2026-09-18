#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

double puissance(double x, int n){
    assert (n>=0);
    double xn = 1.0;
    for (int i=1;i<=n;i++) {
        xn = xn * x;}
    return xn;}

int main(int argc, char* argv[])
{
    assert (argc==3);
    printf("Résultat = %f\n",puissance(atof(argv[1]),atoi(argv[2])));
}

