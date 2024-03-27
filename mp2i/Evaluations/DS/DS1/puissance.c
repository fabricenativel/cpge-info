#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

int valeur_absolue(int n)
{
    if (n < 0)
        return -n;
    return n;
}

double puissance(double a, int n)
{
    double p = 1.0;
    if (a == 0)
    {
        assert(n >= 0);
    }
    if (a == 0)
    {
        if (n == 0)
        {
            return 1.0;
        }
        else
        {
            return 0.0;
        }
    }
    for (int i = 0; i < valeur_absolue(n); i++)
    {
        p = p * a;
    }
    if (n < 0)
    {
        return 1 / p;
    }
    else
    {
        return p;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Puissance prend deux arguments \n");
    }
    else
    {
        double a = atof(argv[1]);
        int n = atoi(argv[2]);
        printf("%f ** %d = %f\n", a, n, puissance(a, n));
    }
}