#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

int plus_petit(bool dispo[], int size)
{
    for (int i=0; i<size; i++)
    {
        if (dispo[i]) {return i+1;}
    }
    return INT32_MAX;
}

bool possible(bool dispo[], int size, int target, int res[], int idx)
{
    char c;
    printf("Faire %d  avec [",target);
    for (int i=0;i<size;i++)
    {
        if (dispo[i]) {printf("%d; ",i+1);}
    }
    printf("]\n");
    c = getchar();
    if (target==0)
    {
        for (int i=0;i<idx;i++)
        {
            printf("%d",res[i]);
        }
        printf("\n");
        dispo[res[idx-1]-1]=true;
        possible(dispo,size,res[idx-1],res,idx-1);
        return true;
    }
    else
    {
    int m = plus_petit(dispo,size);
    printf("--> Plus petit = %d \n",m);
    // Si la cible est inférieur au plus petit nombre disponible alors impossible
    if (target<m) {return false;}
    // Sinon soit on utilise le plus petit ou pas
    dispo[m-1] = false;
    res[idx] = m;
    possible(dispo,size,target-m,res,idx+1);
    possible(dispo,size,target,res,idx);
    }
}

void nuplets(int n)
{
    int n2 = n*n;
    int target = n*(n2+1)/2;
    bool dispo[n2];
    int res[n];
    for (int i=0;i<n2;i++) {dispo[i]=true;}
    possible(dispo,n2,target,res,0);
}

int main()
{
    nuplets(3);
}