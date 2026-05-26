#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

bool appartient_bb(uint64_t s, int e)
{
    return ((s >> e) & 1) == 1;
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
    printf("{");
    for (int i = 0; i <64 ; i++)
    {
        if (res[i])
        {
            printf("%d, ",i);
        }
    }
    printf("}\n");
}

uint64_t complementaire(uint64_t n)
{
    return ~n;
}

uint64_t reunion(uint64_t n, uint64_t m)
{
    return n | m;
}

int main(int argc, char* argv[])
{
    uint64_t num1 = (uint64_t)atoi(argv[1]);
    uint64_t num2 = (uint64_t)atoi(argv[2]);
    uint64_t rnum = reunion(num1, num2);
    bool *res1 = decode(num1);
    bool *res2 = decode(num2);
    printf("Décocage de %lu = ",num1);
    affiche(res1);
    printf("Décocade de %lu =",num2);
    affiche(res2);
    printf("Décocade de %lu =",rnum);
    affiche(decode(rnum));
}