#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>

# define SIZE 24

struct objet
{
    float poids;
    int valeur;
};
typedef struct objet objet;


objet value_choix(objet objets[], bool choix[], int size)
{
    objet res = {.poids = 0.0, .valeur = 0};
    for (int i=0; i<size; i++)
    {
        if (choix[i])
        {
            res.poids += objets[i].poids;
            res.valeur += objets[i].valeur;
        }
    }
    return res;
}

void lire_objets(char * fname, objet objets[], int size)
{
    FILE * reader = fopen(fname,"r");
    double p;
    int v;
    for (int i=0; i<size; i++)
    {
        fscanf(reader,"%lf,%d\n",&p,&v);
        objets[i].valeur = v;
        objets[i].poids = p;
    }
    fclose(reader);
}

int brute_force(objet objets[], int size, int pmax)
{
    uint64_t cmax = 1 << size;
    bool choix[SIZE];
    objet sac;
    int opti = 0;
    for (uint64_t i=0; i<cmax; i++)
    {
        for (int j=0; j<size; j++)
        {
           // if ((i >> j) & 1==1) {choix[j]=false;} else {choix[j]=true;}
           choix[j] = (((i >> j) & 1)==1) ? false : true;
        }
        sac = value_choix(objets,choix,size);
        if (sac.valeur>opti && sac.poids<=pmax) {
            opti = sac.valeur;
        }
    }
    return opti;
}

int main()
{
    objet obj[SIZE];
    lire_objets("sac.txt",obj,SIZE);
    int res = brute_force(obj,SIZE,8);
    printf("Valeur maximale = %d\n", res);
}