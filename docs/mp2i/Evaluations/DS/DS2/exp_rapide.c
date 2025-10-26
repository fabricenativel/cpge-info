#include <stdio.h>
#include <assert.h>

double exp_rapide(double a, int n)
{ // pour n positif, renvoie a puissance n
    assert(n >= 0);
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
    printf("exp (rapide itératif)a^n=%lf\n", exp_rapide(a, n));
}