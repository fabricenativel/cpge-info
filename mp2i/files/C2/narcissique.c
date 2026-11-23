#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int puissance(int m, int n)
{
    assert (m>=0 && n>0);
    int r = m;
    for (int i=1;i<n;i++)
    {
        r = r *m;
    }
    return r;
}


int nb_chiffres(int n)
{
    assert (n>=0);
    int p = 0;
    if (n==0)
    { return 0;}
    while (n!=0)
    {
        n = n /10;
        p = p+1;
    }
    return p;
}

bool est_narcissique(int n)
{
    int p = nb_chiffres(n);
    int s = 0;
    int n0 =n;
    for (int i=0;i<p;i++)
    {
        s = s + puissance(n%10,p);
        n = n/10;
    }
    return (s==n0);
    
}

int narcissique_seuil(int n)
{
    int pg = 0;
    int m = 0;
    while (m<=n)
    {
        if (est_narcissique(m))
        {
            printf("%d\n",m);
            pg = m;
        }
        m++;
    }
    return pg;
}

int compte_narcissique(int n)
{
    int nb = 0;
    for (int i=0;i<=n;i++)
    {
        if (est_narcissique(i))
        {
            nb++;
        }
    }
    return nb;
}

int main()
{
    assert (est_narcissique(1634));
    int n = 10000000;
    printf("Plus grand narcissique inférieur à %d : %d\n",n,narcissique_seuil(n));
    printf("Nombre de narcissiques inférieur à %d : %d\n",n,compte_narcissique(n));
}