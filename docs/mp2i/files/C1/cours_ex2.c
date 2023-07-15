#include <stdio.h>

int main()  { 
    int somme = 0;
    const int nmax = 100;
    for (int i=1;i<=nmax;i=i+1)
        {somme = somme + i;}
    printf("1+2+...+100 = %d\n",somme);
    return 0;}
