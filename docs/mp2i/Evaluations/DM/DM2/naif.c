#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

uint64_t envers(uint64_t n)
{
    //Renvoie le nombre formé par les chiffres de n à l'envers
    uint64_t env = 0;
    while (n!=0)
    {
        env = env*10 + n%10;
        n = n/10;
    }
    return env;
}

bool palindrome(uint64_t n)
{
    //Renvoie true ssi n est un palindrome
    return (envers(n)==n);
}


uint64_t terme_suivant(uint64_t n)
{
    uint64_t env = envers(n);
    assert (UINT64_MAX - envers(n) > n);
    return n+env;
}

int lychrel(uint64_t n, int limit, uint64_t *pal)
{
    int nbiter = 0;
    while (!palindrome(n) && nbiter<limit)
    {
        n = terme_suivant(n);
        nbiter++;
    }
    if (palindrome(n))
    {
        *pal = n;
        return nbiter;
    }
    else
    {
        return -1;
    }
}


int main()
{
    int max_iter = 0;
    int max_int = 0;
    uint64_t max_pal = 0;
    uint64_t mpal;
    int res;
    for (int i=0;i<196;i++)
    {
        res =lychrel(i,100,&mpal);
        if (res==24)
        {
            printf("%d \n",i);
        }
        if (res>max_iter)
        {
            max_iter = res;
            max_int = i;
        }
        if (mpal>max_pal)
        {
            max_pal = mpal;
        }
    }
    printf("Nombre maximal d'itérations =%d\n",max_iter);
    printf("Atteint pour  =%d\n",max_int);
    printf("Plus grand palindrome obtenu =%lu\n",max_pal);
}