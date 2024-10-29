#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TAILLE 100
#define VIVANT '#'
#define MORT '.'

// --8<-- [start:Q5]
bool *rule(int num)
{ // Renvoie le tableau de 8 booléens correspondant au numéro de la règle
    bool *r = malloc(sizeof(bool) * 8);
    for (int i = 0; i < 8; i++)
    {
        if (((num >> i) & 1) == 1)
        {
            r[i] = true;
        }
        else
        {
            r[i] = false;
        }
    }
    return r;
}

int value(bool b1, bool b2, bool b3)
{
    // Convertit en un entier (de 0 à 7) la configuration des 3 cellules
    int v = 0;
    if (b1)
    {
        v += 4;
    }
    if (b2)
    {
        v += 2;
    }
    if (b3)
    {
        v += 1;
    }
    return v;
}

bool *evolution_rule(bool etat[], int rnum)
{
    bool *nouvel_etat = malloc(sizeof(bool) * TAILLE);
    nouvel_etat[0] = false;
    nouvel_etat[TAILLE - 1] = false;
    bool *r = rule(rnum);
    for (int i = 1; i < TAILLE - 1; i++)
    {
        nouvel_etat[i] = r[value(etat[i - 1], etat[i], etat[i + 1])];
    }
    return nouvel_etat;
}
// --8<-- [end:Q5]

// --8<-- [start:Q2]
bool *evolution(bool etat[])
{
    bool *nouvel_etat = malloc(sizeof(bool) * TAILLE);
    nouvel_etat[0] = false;
    nouvel_etat[TAILLE - 1] = false;
    for (int i = 1; i < TAILLE - 1; i++)
    {
        if ((etat[i - 1] || etat[i + 1]) && !(etat[i - 1] && etat[i + 1]))
        {
            nouvel_etat[i] = true;
        }
        else
        {
            nouvel_etat[i] = false;
        }
    }
    return nouvel_etat;
}
// --8<-- [end:Q2]

// --8<-- [start:Q1]
void affiche(bool etat[])
{
    // Les constantes TAILLE, VIVANT (#) et MORT (.) sont définies en début de programme
    for (int i = 0; i < TAILLE; i++)
    {
        if (etat[i])
        {
            printf("%c", VIVANT);
        }
        else
        {
            printf("%c", MORT);
        }
    }
    printf("\n");
}
// --8<-- [end:Q1]

// --8<-- [start:Q4]
int compte(bool etat[])
{
    int total = 0;
    for (int i = 0; i < TAILLE; i++)
    {
        if (etat[i])
        {
            total += 1;
        }
    }
    return total;
}
// --8<-- [end:Q4]

// --8<-- [start:Q3]
void question3()
{
    bool start[TAILLE] = {false};
    start[TAILLE / 2] = true;
    affiche(start);
    bool *new = evolution(start);
    for (int i = 0; i < 50; i++)
    {
        affiche(new);
        new = evolution(new);
    }
}
// --8<-- [end:Q3]

int main()
{
    question3();
    bool start[TAILLE] = {false};
    srand(time(NULL));
    start[TAILLE / 2] = true;
    bool *new = evolution(start);
    affiche(start);
    for (int i = 0; i < 50; i++)
    {
        affiche(new);
        new = evolution(new);
    }
    printf("Nombre de cellules vivantes : %d\n", compte(new));
}