#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
/* Implementation d'une file avec accès au premier et au dernier*/
struct maillon
{
    int valeur;
    struct maillon *suivant;
};
typedef struct maillon maillon;
struct file
{
    maillon *tete;
    maillon *queue;
};
typedef struct file file;

file cree_file()
{
    file f = {.tete = NULL, .queue = NULL};
    return f;
}

// Ajout à la fin (on a accès au dernier)
void enfiler(file *f, int val)
{
    maillon *nm = malloc(sizeof(maillon));
    nm->valeur = val;
    nm->suivant = NULL;
    if (f->queue == NULL)
    {
        f->queue = nm;
    }
    else
    {
        f->queue->suivant = nm;
        f->queue = nm;
    }
    if (f->tete == NULL)
    {
        f->tete = nm;
    }
}

// Ajout au début
void appendleft(file *f, int val)
{
    maillon *nm = malloc(sizeof(maillon));
    nm->valeur = val;
    nm->suivant = f->tete;
    f->tete = nm;
    if (f->queue == NULL)
    {
        f->queue = nm;
    }
}

// Affichage
void display(file f)
{
    maillon *cm = f.tete;
    printf("(T) : ");
    while (cm != NULL)
    {
        if (cm->suivant != NULL)
        {
            printf("%i -> ", cm->valeur);
        }
        else
        {
            printf("%i : (Q)", cm->valeur);
        }
        cm = cm->suivant;
    }
    printf("\n");
}

int defiler(file *f)
{
    int v = f->tete->valeur;
    maillon *old = f->tete;
    f->tete = f->tete->suivant;
    return v;
}

int prochain(file f)
{
    assert (f.tete != NULL);
    return (f.tete)->valeur;
}

file depuis_tableau(int tab[], int taille)
{
    file f = cree_file();
    for (int i = 0; i < taille; i++)
    {
        enfiler(&f, tab[i]);
    }
    return f;
}

int min3(int a, int b, int c)
{
    if (a<b && a<c)
    { return a;}
    if (b<c)
    {return b;}
    return c;
}

int * hamming(int n)
{
    file f2 = cree_file();
    file f3 = cree_file();
    file f5 = cree_file();
    int x2, x3, x5, xm;
    enfiler(&f2, 1);
    enfiler(&f3, 1);
    enfiler(&f5, 1);
    int *ham = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        x2 = prochain(f2);
        x3 = prochain(f3);
        x5 = prochain(f5);
        if (x2 == min3(x2, x3, x5))
        {
            xm = defiler(&f2);
        }
        if (x3 == min3(x2, x3, x5))
            {
                xm = defiler(&f3);
            }
        if (x5 == min3(x2, x3, x5))
        {
            xm = defiler(&f5);
        }
        enfiler(&f2, 2 * xm);
        enfiler(&f3, 3 * xm);
        enfiler(&f5, 5 * xm);
        ham[i] = xm;
    }
    return ham;
}

bool est_hamming(int n)
{
    if (n==1) {return true;}
    while (n%2==0)
    { n=n/2;}
    while (n%3==0)
    { n=n/3;}
    while (n%5==0)
    { n=n/5;}
    return (n==1);
}

int main(int argc, char *argv[])
{
    file f;
    int *res;
    int size = 20;
    res = hamming(size);
    for (int i=0;i<size;i++)
    {
        printf("%d; ",res[i]);
    }
    printf("\n");
}