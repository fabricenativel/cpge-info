#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

char CHIFFRES[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

struct nombre_s
{
    uint8_t nb_chiffres;
    uint8_t *chiffres;
};
typedef struct nombre_s nombre;

nombre cree_nombre(int n)
{
    int num = n;
    int nbc = 1;
    while (num >= 10)
    {
        num = num / 10;
        nbc += 1;
    }
    nombre nb;
    nb.nb_chiffres = nbc;
    nb.chiffres = malloc(sizeof(uint8_t) * nbc);
    for (int i = 0; i < nbc; i++)
    {
        nb.chiffres[i] = n % 10;
        n = n / 10;
    }
    return nb;
}

int valeur(nombre n)
{
    int poids = 1;
    uint64_t v = 0;
    for (int i = 0; i < n.nb_chiffres; i++)
    {
        v += n.chiffres[i] * poids;
        poids = poids * 10;
    }
    return v;
}

nombre copie(nombre n)
{
    nombre m;
    m.nb_chiffres = n.nb_chiffres;
    m.chiffres = malloc(sizeof(uint8_t) * m.nb_chiffres);
    for (int i = 0; i < m.nb_chiffres; i++)
    {
        m.chiffres[i] = n.chiffres[i];
    }
    return m;
}

void libere(nombre n)
{
    n.nb_chiffres = 0;
    free(n.chiffres);
}

void echange(uint8_t tab[], int i, int j)
{
    uint8_t temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

void tri(uint8_t tab[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                echange(tab, j, j + 1);
            }
        }
    }
}

void affiche(nombre n)
{

    for (int i = n.nb_chiffres - 1; i >= 0; i--)
    {
        printf("%u", n.chiffres[i]);
    }
}

nombre decroissant(nombre n)
{
    nombre m = copie(n);
    tri(m.chiffres, m.nb_chiffres);
    return m;
}

nombre retourne(nombre n)
{
    nombre m = copie(n);
    for (int i = 0; i < m.nb_chiffres; i++)
    {
        m.chiffres[i] = n.chiffres[n.nb_chiffres - 1 - i];
    }
    return m;
}

nombre kaprekar(nombre n)
{
    nombre c = decroissant(n);
    nombre d = retourne(c);
    return cree_nombre(valeur(c) - valeur(d));
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Utilisation : %s <entier>\n", argv[0]);
        return EXIT_FAILURE;
    }
    nombre n = cree_nombre(atoi(argv[1]));
    affiche(n);
    printf("\n");
    while ((getchar() != ' '))
    {
        n = suivant(n);
        affiche(n);
        printf("\n");
    }

    return EXIT_SUCCESS;
}
