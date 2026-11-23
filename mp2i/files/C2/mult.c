#include <stdio.h>
#include <assert.h>

int mult(int n, int m)
{
    assert (n>=0 && m>=0);
    int r = 0;
    int m0 =m;
    while (m>0)
    {
        m = m - 1;
        r =r + n;
        assert (r == (m0-m)*n);
    }
    return r;
}

int main()
{
    assert (mult(4,3)==12);
    assert (mult(4,0)==0);
    assert (mult(4,1)==4);
    assert (mult(4,15)==60);
}