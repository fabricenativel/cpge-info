#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int carre(int n)
{
    int p = n * n;
    return p;
}

int main(int argc, char* argv[])
{
    for (int i=0;i<argc;i++)
    {printf("Argument n° %d = %s\n",i,argv[i]);}
}