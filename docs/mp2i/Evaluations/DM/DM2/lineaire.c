#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TAILLE 100
#define VIVANT '#'
#define MORT '.'


bool* rule(int num)
{
    bool *r = malloc(sizeof(bool)*8);
    for (int i=0;i<8;i++)
    {
        if (((num>>i)&1) == 1)
        {r[i] = true;}
        else
        {r[i] = false;}
    }
    return r;
}

int value(bool b1, bool b2, bool b3)
{
    int v = 0;
    if (b1) {v+=4;}
    if (b2) {v+=2;}
    if (b3) {v+=1;}
    return v;
}

bool* evolution_rule(bool etat[], int rnum)
{
    bool * nouvel_etat = malloc(sizeof(bool)*TAILLE);
    nouvel_etat[0] = false;
    nouvel_etat[TAILLE-1] = false;
    bool * r = rule(rnum);
    for (int i=1;i<TAILLE-1;i++)
    {
        nouvel_etat[i] = r[value(etat[i-1],etat[i],etat[i+1])];
    }
    return nouvel_etat;
}

bool* evolution(bool etat[])
{
    bool * nouvel_etat = malloc(sizeof(bool)*TAILLE);
    nouvel_etat[0] = false;
    nouvel_etat[TAILLE-1] = false;
    for (int i=1;i<TAILLE-1;i++)
    {
        if ((etat[i-1] || etat[i+1]) && !(etat[i-1]&&etat[i+1])) 
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

void affiche(bool etat[])
{
    for (int i=0;i<TAILLE;i++)
    {
        if (etat[i])
        {
            printf("%c",VIVANT);
        }
        else
        {
            printf("%c",MORT);
        }
    }
    printf("\n");
}

int compte(bool etat[])
{
    int total = 0;
    for (int i=0;i<TAILLE;i++)
    {
        if (etat[i])
        {total += 1;}
    }
    return total;
}

int main()
{
    bool start[TAILLE] = {false};
    srand(time(NULL));
    start[TAILLE/2] = true;
    bool* new = evolution(start);
    affiche(start);
    for (int i=0;i<50;i++)
    {   
        affiche(new);
        new = evolution(new);
    }
    printf("Nombre de cellules vivantes : %d\n",compte(new));
}