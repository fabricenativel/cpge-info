#include <stdio.h>
#include <stdlib.h>

void calcule(int n)
{
    double u0 = 2.;
    double u1 = 3.;
    double u2;
    printf("u0 = %f\n",u0);
    printf("u1 = %f\n",u1);
    for (int i=2;i<=n;i++)
    {
        u2 = 15. - 54./u1 + 40./(u1*u0);
        u0 = u1;
        u1 = u2;
        printf("u%d = %lf\n",i,u1);
    }
}

int main(int argc,char* argv[])
{
    calcule(atoi(argv[1]));
}