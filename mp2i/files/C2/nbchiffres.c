#include <stdio.h>
#include <assert.h>

int nb_chiffres(int n)
{
    assert(n >= 0);
    int p = 0;
    if (n == 0)
    {
        return 1;
    }
    while (n > 0)
    {
        n = n / 10;
        p = p + 1;
    }
    return p;
}

int main()
{
    assert (nb_chiffres(0)==1);
    assert (nb_chiffres(7)==1);
    assert (nb_chiffres(10)==2);
    assert (nb_chiffres(11)==2);
    assert (nb_chiffres(2567)==4);
}