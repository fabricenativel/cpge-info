#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

/* Implémentation d'une file avec un tableau circulaire */
#define SIZE 10

struct file_s
{
    int t;     // Taille courante
    int d;     // Prochain à défiler
    int *elts; // pointeur (à allouer à la création)
};
typedef struct file_s file;

file cree_file()
{
    file new_queue;
    new_queue.d = 0;
    new_queue.t = 0;
    new_queue.elts = malloc(sizeof(int) * SIZE);
    return new_queue;
}

void affiche(file f)
{
    for (int i = 0; i < f.t; i++)
    {
        printf(" < %d  ", f.elts[(f.d + i) % SIZE]);
    }
    printf(" -- (%d/%d)= \n", f.t, SIZE);
}

void enfile(file *f, int v)
{
    assert(f->t < SIZE);
    // On enfiler à l'indice (d+t) modulo la capacité
    f->elts[(f->d + f->t) % SIZE] = v;
    f->t++;
}

int defile(file *f)
{
    assert (f->t!=0);
    int res = f->elts[f->d];
    f->t--;
    f->d++;
    return res;
}

int main()
{
    file f = cree_file();
    srand(time(NULL));
    enfile(&f, 7);
    for (int i = 0; i < 5; i++)
    {
        enfile(&f, rand() % 100);
    }
    affiche(f);
    defile(&f);
    affiche(f);
    defile(&f);
    affiche(f);
}