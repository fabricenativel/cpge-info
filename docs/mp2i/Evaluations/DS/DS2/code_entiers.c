#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

bool appartient_bb(uint64_t s, int e)
{
    return s >> e & 1 == 1;
}

bool appartient(uint64_t s, int e)
{
    while (e != 0)
    {
        s = s / 2;
        e = e - 1;
    }
    return (s % 2 == 1);
}

uint64_t encode(bool tab[])
{
    uint64_t res = 0;
    uint64_t poids = 1;
    for (int i = 0; i < 64; i++)
    {
        if (tab[i])
        {
            res += poids;
        }
        poids = poids * 2;
    }
    return res;
}

bool *decode(uint64_t n)
{
    bool *tab = malloc(sizeof(bool) * 64);
    for (int i = 0; i < 64; i++)
    {
        tab[i] = (n%2 ==1);
        n =n /2;
    }
    return tab;
}

void affiche(bool *res)
{
    for (int i = 63; i >= 0 ; i--)
    {
        if (res[i])
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    int num = atoi(argv[1]);
    bool *res = decode(num);
    printf("Décocage de %d = ",num);
    affiche(res);
    printf("Encodage  = %ld\n", encode(res, 64));
}