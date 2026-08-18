#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
int mystere(int n)
{
    assert(n > 1);
    int d = 2;
    while (n % d != 0)
    {
        d = d + 1;
    }
    return d;
}
// Renvoie true ssi n est premier
bool est_premier(int n)
{
    assert(n >= 0);
    if (n == 0 || n== 1)
    {
        return false;
    }
    return (mystere(n) == n);
}
int main()
{
    assert(mystere(42) == 2);
    assert(mystere(35) == 5);
    assert(est_premier(2));
    assert(!est_premier(1));
    assert(est_premier(17));
    assert(!est_premier(77));
}