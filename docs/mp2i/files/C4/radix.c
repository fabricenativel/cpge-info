#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define BIT_NUMBER 8
#define BUCKET_NUMBER (1<<BIT_NUMBER)
#define PASS_NUMBER (64/BIT_NUMBER)


void view(uint64_t tab[], int size)
{
    for (int i=0;i<size-1; i++)
    {
        printf("%ld, ",tab[i]);
    }
    printf("%ld \n",tab[size-1]);
}


uint64_t digit(uint64_t n, uint8_t d)
{
    if (d==0 || n==0)
    {
        return n & ((1 << BIT_NUMBER) - 1);
    }
    return digit(n>>BIT_NUMBER, d-1);
}

void copy_values(uint64_t in[], uint64_t out[], int size)
{
    for (int i=0; i<size; i++)
    {
        out[i] = in[i];
    }
}

void digit_sort(uint64_t in[], uint64_t out[], int size, uint8_t d)
{
    // Calcul de la taille de chaque seau
    uint64_t bucket_size[BUCKET_NUMBER] = {0};
    uint64_t c;
    for (int i=0;i<size;i++)
    {
        bucket_size[digit(in[i],d)]++;
    }
    // Tableau des positions courantes dans chaque seau
    int bucket_position[BUCKET_NUMBER];
    bucket_position[0]=0;
    for (int i=1;i<BUCKET_NUMBER;i++)
    {
        bucket_position[i] = bucket_position[i-1] + bucket_size[i-1];
    }
    // Parcours et rangement sans le tableau de sortie
    for (int i=0;i<size;i++)
    {
        c = digit(in[i],d);
        out[bucket_position[c]++] = in[i];
    }
}


void radix_sort(uint64_t in[], uint64_t out[], int size)
{
    uint64_t * temp;
    for (int digit=0;digit<PASS_NUMBER;digit++)
    {
        digit_sort(in,out,size,digit);
        temp = in;
        in = out;
        out = temp;
    }
}

int main()
{
    int tsize = 1000000000;
    printf("Génération d'un tableau de %d entiers positifs sur 64 bits : ",tsize);
    fflush(stdout);
    clock_t start,end;
    uint64_t *test = malloc(sizeof(uint64_t)*tsize);
    uint64_t p1,p2;
    for (int i=0;i<tsize;i++)
    {
        p1 = rand();
        p2 = rand();
        test[i] = (p1<<32) + p2;
    }
    printf(" ok !\n");
    uint64_t *tri = malloc(sizeof(uint64_t)*tsize);
    printf("Tri par radix sort par chiffres sur %d bits : ",BIT_NUMBER);
    fflush(stdout);
    start = clock();
    radix_sort(test,tri,tsize);
    end = clock();
    printf(" ok !\n");
    printf("Temps écoulé = %ld secondes \n", (end-start)/CLOCKS_PER_SEC);
    for (int i=1;i<tsize;i++)
    {
        assert(test[i-1]<test[i]);
    }
    printf("Tout est ok ! \n");
}