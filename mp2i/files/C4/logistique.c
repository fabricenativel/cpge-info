#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{   
    assert (argc == 3);
    double x = 0.5;
    double a = atof(argv[1]);
    int n =  atoi(argv[2]);

    for (int i=0;i<n;i++) 
    {
        x = a*x*(1-x);
        printf("x%d = %f\n",i+1,x);
    }
}