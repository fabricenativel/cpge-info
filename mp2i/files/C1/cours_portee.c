#include <stdio.h>

const int maxn = 10000;

double harmo(int n)
{
    double somme = 0;
    for (int i = 1; i <= n; i = i + 1)
    {
        somme = somme + 1.0 / i;
    }
    return somme;
}

int main()
{
    double s = harmo(maxn);
    printf("Somme = %f\n", s);
    return 0;
}