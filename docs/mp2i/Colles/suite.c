#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void u(int n)
{
    double v = M_E - 1;
    printf("v0=%.16f\n",v);
    for (int i=1;i<=n;i++)
    {
        v = (double)i*v - 1.0;
        printf("v%d=%.16f\n",i,v);
    }
}

int main(int argc, char* argv[])
{
    u(atoi(argv[1]));
}