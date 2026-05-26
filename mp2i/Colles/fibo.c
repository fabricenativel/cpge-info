#include <stdio.h>

int fibo(int n)
{
    int a = 1;
    int b = 1;
    int t;
    for (int i = 1;i<n;i++)
    {
        t = b;
        b = a + b;
        a = t;
    }
    return b;
}

int main()
{
    for (int i=0;i<10;i++)
    {
        printf("f(%d)=%d\n",i,fibo(i));
    }
}