#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void view(uint32_t tab[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d, ", tab[i]);
    }
    printf("%d \n", tab[size - 1]);
}

uint32_t nombre_chiffres(uint32_t l)
{
    return (1 << l);
}

uint32_t nombre_passes(uint32_t l)
{
    if (30 % l == 0)
    {
        return 30 / l;
    }
    return (30 / l) + 1;
}

uint32_t chiffre(uint32_t n, uint32_t d, uint32_t l)
{
    if (n == 0)
    {
        return 0;
    }
    if (d == 0)
    {
        uint32_t r = n & ((uint32_t)(1 << l) - 1);
        return r;
    }
    return chiffre(n >> l, d - 1, l);
}

void radix_passe(uint32_t tab[], uint32_t temp[], int size, uint32_t d, uint32_t l)
{
    uint32_t nb_alveoles = nombre_chiffres(l);
    uint32_t *taille_alveoles = malloc(sizeof(uint32_t) * nb_alveoles);
    uint32_t *position_alveoles = malloc(sizeof(uint32_t) * nb_alveoles);
    uint32_t c;
    for (uint32_t i = 0; i < nb_alveoles; i++)
    {
        taille_alveoles[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        taille_alveoles[chiffre(tab[i], d, l)]++;
    }
    // Tableau des positions courantes dans chaque alvéole
    position_alveoles[0] = 0;
    for (uint32_t i = 1; i < nb_alveoles; i++)
    {
        position_alveoles[i] = position_alveoles[i - 1] + taille_alveoles[i - 1];
    }
    // Parcours et rangement sans le tableau temporaire
    for (int i = 0; i < size; i++)
    {
        c = chiffre(tab[i], d, l);
        temp[position_alveoles[c]++] = tab[i];
    }
    free(position_alveoles);
    free(taille_alveoles);
}

void tri_radix(uint32_t tab[], uint32_t temp[], int size, uint32_t l)
{
    uint32_t nb_passes = nombre_passes(l);
    for (uint32_t digit = 0; digit < nb_passes; digit++)
    {
        radix_passe(tab, temp, size, digit, l);
        for (int i = 0; i < size; i++)
        {
            tab[i] = temp[i];
        }
    }
}

uint32_t *tab_aleatoire(int n)
{
    uint32_t *tab = malloc(sizeof(uint32_t) * n);
    for (int i = 0; i < n; i++)
    {
        tab[i] = (uint32_t)(rand() % ((RAND_MAX / 2) - 1));
    }
    return tab;
}

// --8<-- [start:cmp]
int cmp(const void *a, const void *b)
{
    // On cast les pointeurs sur void en pointeurs sur uint32_t et on prend
    // leurs contenus pour trouver les entiers à comparer
    uint32_t x = *((uint32_t *)a);
    uint32_t y = *((uint32_t *)b);
    if (x > y)
    {
        return 1;
    }
    if (x == y)
    {
        return 0;
    }
    return -1;
}
// --8<-- [end:cmp]

int main(int argc, char *argv[])
{
    if (argc!=3){
        printf("Usage : %s <nb elts> <taille bloc> \n", argv[0]);
        exit(1);
    }
    int size = atoi(argv[1]);
    uint32_t l = (uint32_t)atoi(argv[2]);
    srand(time(NULL));
    printf("Génération du tableau aléatoire %ld \n", sizeof(uint32_t));
    uint32_t *test = tab_aleatoire(size);
    printf("Début du tri \n");
    clock_t deb = clock();
    qsort(test, size, sizeof(uint32_t), cmp);
    clock_t fin = clock();
    printf("Temps de calcul du qsort (%d entiers) = %f \n", size, (double)(fin - deb) / CLOCKS_PER_SEC);
    for (int i = 1; i < size; i++)
    {
        assert(test[i - 1] <= test[i]);
    }
    free(test);
    printf("Génération du tableau aléatoire \n");
    uint32_t *test2 = tab_aleatoire(size);
    printf("Début du tri : avec ds bloc de taille %d (%d chiffres) donc %d passes \n", l, nombre_chiffres(l), nombre_passes(l));
    clock_t deb2 = clock();
    uint32_t *temp = malloc(sizeof(uint32_t) * size);
    tri_radix(test2, temp, size, l);
    free(temp);
    clock_t fin2 = clock();
    printf("Temps de calcul du tri_radix (%d entiers) = %f \n", size, (double)(fin2 - deb2) / CLOCKS_PER_SEC);
    for (int i = 1; i < size; i++)
    {
        assert(test2[i - 1] <= test2[i]);
    }
    free(test2);

    printf("Tout est ok \n");
}