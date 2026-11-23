#include <stdio.h>
#include <assert.h>

int quotient(int a, int b)
{
    int q = 0;
    int r = a;
    while (r >= 0)
    {
        q = q + 1;
        r = r - b;
    }
    return q - 1;
}

int main()
{
    assert (quotient(2,5)==0);
    assert (quotient(5,5)==1);
    assert (quotient(12,5)==2);
    assert (quotient(42,5)==8);
}