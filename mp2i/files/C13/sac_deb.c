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

bool incremente(bool choix[], int size)
{
    int idx = 0;
    if (choix[0]==false)
    {
        choix[0] = true;
        return true;
    }
    else
    {
        while (idx<size && choix[idx])
        {
            choix[idx] = false;
            idx++;
        }
        if (idx<size) {choix[idx]=true;}
        return (idx<size);
    }
}

int brute_force(objet objets[], int size, int pmax)
{
    uint64_t cmax = 1 << size;
    bool choix[SIZE];
    for (int i=0;i<SIZE;i++)
    {
        choix[i]=false;
    }
    objet sac;
    int opti = 0;
    while (incremente(choix,size))
    {
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
    int res = brute_force(obj,SIZE,67);
    printf("Valeur maximale = %d\n", res);
}