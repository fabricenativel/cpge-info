#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void affiche(int n)
{
    assert(n > 1);
    double p = 1.25;
    double q = 1.4;
    double r;
    printf("v0=%lf\n", p);
    printf("v1=%lf\n", q);
    for (int i = 2; i <= n; i++)
    {
        r = 10 - 23 / q + 14 / (p * q);
        p = q;
        q = r;
        printf("v%d=%lf\n", i, r);
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        affiche(atoi(argv[1]));
    }
    else
    {
        printf("Utilisation : %s <entier>\n", argv[0]);
    }
    return 0;
}
