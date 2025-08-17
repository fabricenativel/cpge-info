#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

// Prends en entrée un chiffre c (0 à 9) et renvoie 2*c si 2*c<10
// sinon la somme des chiffres de 2*c
int mult2(int c)
{
    assert(c >= 0 && c <= 9);
    int d = 2 * c;
    if (d >= 10)
    {
        return (d % 10 + 1);
    }
    else
    {
        return d;
    }
}

// Valide un numéro de carte num avec l'algorithme de Luhn
bool valide(int num)
{
    int spair = 0;
    int simpair = 0;
    bool impair = true;
    int chiffre;
    while (num != 0)
    {
        chiffre = num % 10;
        num = num / 10;
        if (impair)
        {
            simpair += chiffre;
        }
        else
        {
            spair += mult2(chiffre);
        }
        impair = !impair;
    }
    return (simpair + spair) % 10 == 0;
}

int cree_valide(int n)
{
    for (int c = 0; c < 10; c++)
    {
        if (valide(10 * n + c))
        {
            return c;
        }
    }
}

int test_hasard(int seed)
{
    srand(seed);
    int num;
    int cpt = 0;
    for (int i = 0; i < 10000; i++)
    {
        num = rand() % 100000000;
        if (valide(num))
        {
            cpt++;
        }
    }
    return cpt;
}

int main()
{
    // int tab[100];
    // for (int i=0; i < 100; i++)
    // {
    //     tab[i] = rand() % 100000000;
    //     tab[i] = tab[i] * 10 + cree_valide(tab[i]);
    // }
    // int bad = rand()%100;
    // tab[bad] = tab[bad] + 1; // rendre invalide
    // FILE* outf = fopen("luhn.txt", "w");
    // fprintf(outf, "int numeros[100] = {");
    // for (int i = 0; i < 100; i++)
    // {
    //     fprintf(outf, "%d, ", tab[i]);
    // }
    // fprintf(outf, "};\n");
    // fclose(outf);
    printf("Nombre de numéros valides : %d\n", test_hasard(42));
    int n = 42;
    for (int i=0;i<9;i++)
    {
        n = n * 10 + cree_valide(n);
        printf("%d\n", n);
    }
}