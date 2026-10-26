#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100000000

int main()
{
    srand(time(NULL));
    double s,e,t;
    double *op1 = malloc(sizeof(double)*N);
    double *op2 = malloc(sizeof(double)*N);
    double *r = malloc(sizeof(double)*N);
    for (int i=0;i<N;i++)
    {
        op1[i] = (double)rand()/(double)rand();
        op2[i] = (double)rand()/(double)rand();
    }
    s = clock();
    for (int i=0;i<N;i++)
    {
        r[i] = op1[i] / op2[i];
    }
    e = clock();
    t = (double)(e-s)/CLOCKS_PER_SEC;
    s = clock();
    for (int i=0;i<N;i++)
    {
        r[i] = op1[i] + op2[i];
    }
    e = clock();
    t = (double)(e-s)/CLOCKS_PER_SEC;
    printf("Temps pour les additions = %lf\n", t);
    printf("Temps pour les divisions = %lf\n", t);
}