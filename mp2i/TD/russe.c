#include <stdio.h>
#include <assert.h>

int russe(int a, int b)
{
    int m = 0;
    int a0 = a;
    int b0=b;
    printf("a = %d, b= %d, m=%d \n",a,b,m);
    while (a>0)
    {
        if (a%2 ==1)
        { 
            a = a - 1;
            m = m + b;
        }
        else
        {
            a =  a / 2;
            b = b*2;
        }
        printf("a = %d, b= %d, m=%d \n",a,b,m);
        assert (m + a*b == a0*b0);
    }
    return m;
}

int main()
{
    int a,b;
    printf("a =");
    scanf("%d",&a);
    printf("b =");
    scanf("%d",&b);
    int m=russe(a,b);
    printf("Résultat = %d\n",m);
}