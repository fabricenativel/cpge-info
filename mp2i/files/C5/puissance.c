#include <stdio.h>

double puissance_iteratif(double a, int n)
{
    double p = 1.0;
    for (int k = 1; k <= n; k = k + 1)
    {
        p = p * a;
    }
    return p;
}

double puissance_recursif(double a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return a * puissance_recursif(a, n - 1);
    }
}

double puissance_acc(double a, int n, double acc)
{
    if (n == 0)
    {
        return acc;
    }
    else
    {
        return puissance_acc(a, n - 1, acc * a);
    }
}

double puissance_rapide(double a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        double pr = puissance_rapide(a, n / 2);
        if (n % 2 == 0)
        {
            return pr * pr;
        }
        else
        {
            return pr * pr * a;
        }
    }
}

// exponentiation rapide iteratif
double pri(double a, int n)
{
    double p = 1.0;
    while (n != 0)
    {
        if (n % 2 == 1)
        {
            p = p * a;
        }
        a = a * a;
        n = n / 2;
    }

    return p;
}

int main()
{
    int n;
    double a;
    printf("a=");
    scanf("%lf", &a);
    printf("n=");
    scanf("%d", &n);
    printf("exp (rapide récursif) a^n=%lf\n", puissance_rapide(a, n));
    printf("exp (rapide itératif)a^n=%lf\n", pri(a, n));
}