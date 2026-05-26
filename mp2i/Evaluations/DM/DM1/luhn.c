#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

// --8<-- [start:Q1]
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
// --8<-- [end:Q1]

// --8<-- [start:Q3]
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
// --8<-- [end:Q3]

// --8<-- [start:Q5]
// Compte le nombre de numéros valides dans le tableau donné argument
int compte_valide(int nums[], int size)
{
    int cpt = 0;
    for (int i = 0; i < size; i++)
    {
        if (valide(nums[i]))
        {
            cpt += 1;
        }
    }
    return cpt;
}
// --8<-- [end:Q5]

// --8<-- [start:Q7]
int cree_valide(int num)
{
    num = num * 10;
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
    if ((simpair + spair) % 10 != 0)
    {
        return 10 - (simpair + spair)%10;
    }
    else
    {
        return 0;
    }
}
// --8<-- [end:Q7]

int main()
{
    // --8<-- [start:Q2]
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
    // --8<-- [end:Q2]
    int numeros[100] = {
        42893834,
        469308860,
        816927776,
        146369152,
        577477938,
        242383354,
        198853863,
        497604926,
        965166499,
        896414216,
        252023627,
        504900275,
        833686900,
        25200593,
        448977637,
        675139265,
        651805400,
        403834260,
        40891723,
        34557363,
        350052114,
        215953688,
        947025672,
        269564290,
        364657825,
        610215303,
        787228626,
        336651237,
        451740674,
        687031351,
        15139298,
        19798024,
        156340226,
        357230580,
        691330690,
        258981679,
        599613932,
        890184567,
        281750117,
        564780427,
        311762298,
        533773735,
        594844219,
        145449195,
        84137843,
        568985378,
        345751986,
        735943243,
        497983155,
        386643704,
        295664130,
        848035267,
        127760916,
        242689800,
        117599563,
        492418736,
        378068621,
        429991706,
        829069962,
        354972812,
        117023051,
        844209254,
        374770840,
        273363275,
        726603368,
        591265053,
        57508467,
        326217296,
        6613137,
        339258576,
        416161248,
        843538950,
        398195826,
        11005451,
        988988143,
        482333671,
        105154348,
        859903643,
        743440430,
        603137506,
        771710878,
        564268084,
        451172761,
        899471783,
        806957882,
        93935849,
        917054033,
        185026515,
        523927549,
        746123991,
        539999326,
        640950606,
        115496762,
        439933680,
        439477399,
        842100126,
        556362267,
        496985862,
        693480949,
        562975391,
    };
    // --8<-- [start:Q4]
    for (int i = 0; i < 100; i++)
    {
        if (!valide(numeros[i]))
        {
            printf("Le nombre %d est invalide \n", numeros[i]);
        }
    }
    // --8<-- [end:Q4]
    // --8<-- [start:Q6]
    srand(42);
    int size = 10000;
    int tab[size];
    for (int i = 0; i < size; i++)
    {
        tab[i] = rand() % 100000000;
    }
    printf("Nombre de numéros valides : %d\n", compte_valide(tab, size));
    // --8<-- [end:Q6]
    for (int i = 0; i < 100; i++)
    {
        if (valide(numeros[i]))
        {assert(cree_valide(numeros[i] / 10) == numeros[i]%10);}
    }
}