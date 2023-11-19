#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

bool appartient_bb(uint64_t s, int e)
{
    return s>>e & 1 == 1;
}

bool appartient(uint64_t s, int e){
    while (e!=0){
        s = s/2;
        e = e - 1;}
    return (s%2 == 1);}

uint64_t encode(int tab[], int size)
{
    uint64_t res = 0;
    for (int i=0; i<size; i++)
    {
        res += (uint64_t)pow(2.0,(double)(tab[i]));
    }
    return res;
}

int*  decode(uint64_t n)
{
    int * tab = malloc(sizeof(int)*64);
    int cid = 0;
    for (int i=0;i<64;i++)
    {
        if (n%2==1) {
            tab[cid] = i;
            cid++;
        }
        n = n/2;
    }
    return tab;
}

void affiche(int *res)
{
for (int i=0;i<64;i++)
    {
       printf("%d-",res[i]);
    }
    printf("\n");
}

int main()
{
    int num = 76;
    int *res = decode(num);
    printf("Décocage de 76 = ");
    affiche(res);
    printf("Encodage  = %ld",encode(res,64));
}