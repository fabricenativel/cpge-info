#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

bool est_harshad(int n)
{
    int sum = 0;
    int num = n;
    while (num != 0)
    {
        sum += (num % 10);
        num = num / 10;
    }
    return (n % sum == 0);
}

int *get_harshad(int limit, int *size)
{
    *size = 0;
    for (int i = 1; i <= limit; i++)
    {
        if (est_harshad(i))
        {
            *size = *size + 1;
        }
    }
    int *harshad = malloc(sizeof(int) * (*size));
    int cpt = 0;
    for (int i = 1; i < limit; i++)
    {
        if (est_harshad(i))
        {
            harshad[cpt] = i;
            cpt++;
        }
    }
    return harshad;
}

int consecutifs(int tab[], int size, int *start)
{
    int cpt = 1;
    int maxc = 1;
    int maxs = 1;
    for (int i = 11; i < size; i++)
    {
        if (tab[i] == tab[i - 1] + 1)
        {
            cpt += 1;
            if (cpt > maxc)
            {
                maxc = cpt;
                maxs = tab[i - cpt + 1];
            }
        }
        else
        {
            cpt = 1;
        }
    }
    *start = maxs;
    return maxc;
}

void affiche(int tab[], int size)
{
    printf("{");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d, ", tab[i]);
    }
    printf("%d}\n", tab[size - 1]);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Utilisation : %s <entier> \n", argv[0]);
        return EXIT_FAILURE;
    }
    int n = atoi(argv[1]);
    if (est_harshad(n))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return EXIT_SUCCESS;
}