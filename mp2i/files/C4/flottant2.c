# include <stdio.h>
# include <math.h>

int main()
{
    double big = pow(2.0,53.0);
    double small = 1.0;
    double test;
    test = (big + small) - big;
    printf("Résultat = %f \n",test);
}