#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void u(int n)
{
    double v0 = 1.25;
    double v1 = 1.4;
    double v2;
    for (int i=2;i<=n;i++)
    {
        v2 = 10 - 23/v1 + 14/(v0*v1);
        v0 = v1;
        v1 = v2;
        printf("v%d=%.16f\n",i,v2);
    }
}

int main(int argc, char* argv[])
{
    u(atoi(argv[1]));
}

