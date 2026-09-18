#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

uint64_t somme_premiers(int n)
{
    bool *premiers = malloc(sizeof(bool)*n);
    int k;
    uint64_t somme = 0;
    for (int i=2;i<n+1;i++) premiers[i]=true;
    premiers[0] = false;
    premiers[1] = false;
    for (int i=2;i<n+1;i++)
    {
        if (premiers[i])
        {   k = 2;
            while (k*i<n+1)
            {
                premiers[k*i] = false;
                k = k + 1;
            }
        }
    }
    for (int i=0;i<n+1;i++)
    {
        if (premiers[i]) somme+=(uint64_t)i;
    }
    return somme;
}

int main()
{
    printf("Somme = %ld\n",somme_premiers(10000000));
}