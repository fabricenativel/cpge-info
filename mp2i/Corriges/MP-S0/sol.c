#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define INT_MIN INT32_MIN
#define INT_MAX INT32_MAX

struct maillon
{
    int donnee;
    struct maillon *suivant;
};
typedef struct maillon maillon_t;


// Q0
void affiche(maillon_t *t)
{
    maillon_t *lt = t;
    printf("->");
    while (lt!=NULL)
    {
        printf("%d -> ",lt->donnee);
        lt=lt->suivant;
    }
    printf("NULL\n");
}

// Q1
maillon_t *init(void)
{
    maillon_t *first = malloc(sizeof(maillon_t));
    maillon_t *last = malloc(sizeof(maillon_t));
    first->donnee = INT_MIN;
    first->suivant = last;
    last->donnee = INT_MAX;
    last->suivant = NULL;
    return first;
}

//Q2
maillon_t *localise(maillon_t *t, int v)
{
    maillon_t *res = t;
    while (res->suivant->donnee<v)
    {
        res = res->suivant;
    }
    return res;
}

//Q3
bool insere(maillon_t *t, int v)
{
    maillon_t *p = localise(t,v);
    maillon_t *n = malloc(sizeof(maillon_t));
    if (p->suivant->donnee!=v)
    {
        n->suivant = p->suivant;
        n->donnee = v;
        p->suivant = n;
        return true;
    }
    else
    { return false;}
}

//Q6
bool supprime(maillon_t *t,int v)
{
    maillon_t *emp = localise(t,v);
    if (emp->suivant->donnee==v)
    {
        emp->suivant = emp->suivant->suivant;
        return true;
    }
    else
    { return false;}
}

int main()
{
    maillon_t *test =  init();
    insere(test,12);
    insere(test,42);
    insere(test,7);
    insere(test,313);
    insere(test,7);
    affiche(test);
    supprime(test,42);
    affiche(test);
    supprime(test,42);
    affiche(test);
}