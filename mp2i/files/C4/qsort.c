#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int cmp(const void *i, const void *j)
{
    uint64_t n = *(uint64_t *)i;
    uint64_t m = *(uint64_t *)j;
    if (n>m)
    {
        return 1;
    }
    if (n==m)
    {
        return 0;
    }
    return -1;

}


void view(uint64_t tab[], int size)
{
    for (int i=0;i<size-1; i++)
    {
        printf("%ld, ",tab[i]);
    }
    printf("%ld \n",tab[size-1]);
}

int main()
{
    int tsize = 100000000;
    printf("Génération d'un tableau de %d entiers positifs sur 64 bits : ", tsize);
    fflush(stdout);
    clock_t start, end;
    uint64_t *test = malloc(sizeof(uint64_t) * tsize);
    uint64_t p1, p2;
    for (int i = 0; i < tsize; i++)
    {
        p1 = rand();
        p2 = rand();
        test[i] = (p1 << 32) + p2;
    }
    printf(" ok !\n");
    printf("Tri par qsort :");
    fflush(stdout);
    start = clock();
    qsort(test, tsize, sizeof(uint64_t), cmp);
    end = clock();
    printf(" ok !\n");
    printf("Temps écoulé = %ld secondes \n", (end - start) / CLOCKS_PER_SEC);
    for (int i = 1; i < tsize; i++)
    {
        assert(test[i - 1] <= test[i]);
    }
    printf("Tout est ok ! \n");
}