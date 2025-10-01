#include <stdio.h>
#include <assert.h>

int somme(int n, int d, int t)
{
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % d == 0 && i % 10 == t)
        {
            s += i;
        }
    }
    return s;
}

int main()
{
    assert(somme(40,3,9)==48);
    assert(somme(100,2,0)==550);
    assert(somme(10,4,5)==0);
    printf("Somme cherchée = %d\n", somme(50000,3,7));
}