#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int somme_maxi(int tab[], int size)
{
    int sk = tab[0];
    int smax = tab[0];
    for (int k = 1; k < size; k++)
    {
        if (sk + tab[k] > tab[k])
        {
            sk = sk + tab[k];
        }
        else
        {
            sk = tab[k];
        }
        if (sk > smax)
        {
            smax = sk;
        }
    }
    return smax;
}

int *read_tab(char filename[], int *tab_size)
{
    // Taille du tableau
    int size = 0;
    int n;
    FILE *reader = fopen(filename, "r");
    while (fscanf(reader, "%d\n", &n) != EOF)
    {
        size = size + 1;
    }
    // Allocation et lecture
    int *tab = malloc(sizeof(int) * size);
    rewind(reader);
    for (int i = 0; i < size; i++)
    {
        fscanf(reader, "%d\n", &tab[i]);
    }
    *tab_size = size;
    return tab;
}

int tranche_max(int tab[], int size)
{
    int max = tab[0];
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        
        if ((max > 0 && tab[i] > max + tab[i]+ temp) || (max < 0 && tab[i] > max + temp ))
        {
            max = tab[i];
            temp = 0;
        }
        else if (tab[i] + temp >= 0)
        {
            max = tab[i] + temp + max;
            temp = 0;
        }
        else
        {
            temp += tab[i];
        }
    }
    return max;
}

int main()
{
    // int test[9] = {2, -7, -5, 4, -1, 10, -4, 9, -2};
    int *test;
    int test_size = 5;
    srand(time(NULL));
    test = malloc(sizeof(int)*test_size);
    for (int i=0;i<test_size;i++)
    {
        test[i] = rand()%10-6;
        printf("%d ",test[i]);
    }
    printf("\n");
    printf("Somme maximale d'une tranche = %d\n", somme_maxi(test, test_size));
    printf("Somme maximale d'une tranche = %d\n", tranche_max(test, test_size));
    free(test);
}