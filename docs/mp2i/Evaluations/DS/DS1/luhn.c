#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

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

int main()
{
    assert(mult2(0) == 0);
    assert(mult2(1) == 2);
    assert(mult2(2) == 4);
    assert(mult2(3) == 6);
    assert(mult2(4) == 8);
    assert(mult2(5) == 1);
    assert(mult2(6) == 3);
    assert(mult2(7) == 5);
    assert(mult2(8) == 7);
    assert(mult2(9) == 9);
    assert(valide(4762));
    printf("Cree valide 543 = %d\n", cree_valide(543));
    printf("Cree valide 26 = %d\n", cree_valide(26));
    printf("Cree valide 476 = %d\n", cree_valide(476));
    printf("Cree valide 12458 = %d\n", cree_valide(12458));
}