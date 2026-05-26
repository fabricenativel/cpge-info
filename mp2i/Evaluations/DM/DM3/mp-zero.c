#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>

#define INT_MAX __INT32_MAX__
#define INT_MIN -__INT32_MAX__

struct maillon
{
    int donnee;
    struct maillon *suivant;
};
typedef struct maillon maillon_t;

// --8<-- [start:Q1]
maillon_t *init(void)
{
    // Création des 2 maillons encadrant la liste
    maillon_t *premier = malloc(sizeof(maillon_t));
    maillon_t *dernier = malloc(sizeof(maillon_t));
    premier->donnee = INT_MIN;
    premier->suivant = dernier;
    dernier->donnee = INT_MAX;
    dernier->suivant = NULL;
    return premier;
}
// --8<-- [end:Q1]

// --8<-- [start:Q2]
maillon_t *localise(maillon_t *t, int v)
{
    // On s'arrête lorsque la valeur du maillon suivant est > ou =
    while (t->suivant->donnee < v)
    {
        t = t->suivant;
    }
    return t;
}
// --8<-- [end:Q2]

// --8<-- [start:Q5]
bool insere(maillon_t *t, int v)
{
    maillon_t *p = localise(t, v);
    if (p->suivant->donnee == v)
    {
        return false;
    }
    maillon_t *n = malloc(sizeof(maillon_t));
    n->suivant = p->suivant;
    n->donnee = v;
    p->suivant = n;
    return true;
}
// --8<-- [end:Q5]

// --8<-- [start:Q6]
bool supprime(maillon_t *t, int v)
{
    maillon_t *p = localise(t, v);
    if (p->suivant->donnee != v)
    {
        return false;
    }
    maillon_t *temp = p->suivant;
    p->suivant = p->suivant->suivant;
    free(temp);
    return true;
}
// --8<-- [end:Q6]

void voir(maillon_t *t)
{
    printf("-∞ -> ");
    t = t->suivant;
    while (t->donnee != INT_MAX)
    {
        printf(" %d -> ", t->donnee);
        t = t->suivant;
    }
    printf("+∞ \n");
}

void detruit(maillon_t *t)
{
    maillon_t *temp;
    while (t != NULL)
    {
        temp = t;
        t = t-> suivant;
        free(temp);
    }
}

int main()
{
    maillon_t *e = init();
    insere(e, 1);
    insere(e, -4);
    insere(e, 7);
    insere(e, 2);
    insere(e, 2);
    insere(e, 3);
    voir(e);
    supprime(e,1);
    voir(e);
    detruit(e);
}

