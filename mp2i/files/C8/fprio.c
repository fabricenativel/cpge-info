#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// --8<-- [start:struct]
struct maillon_s
{
    int prio;
    struct maillon_s *suivant;
};
typedef struct maillon_s maillon;
typedef maillon *fprio;
// --8<-- [end:struct]

void enfile(fprio *f, int p)
{
    maillon *nouveau = malloc(sizeof(maillon));
    nouveau->prio = p;
    if (*f == NULL || (*f)->prio > p)
    {
        nouveau->suivant = *f;
        *f = nouveau;
    }
    else
    {
        fprio pos = *f;
        while (pos->suivant != NULL && pos->suivant->prio < p)
        {
            pos = pos->suivant;
        }
        nouveau->suivant = pos->suivant;
        pos->suivant = nouveau;
    }
}

int defile(fprio *f)
{
    int r = (*f)->prio;
    fprio temp = *f;
    *f = (*f)->suivant;
    free(temp);
    return r;
}

void detruit(fprio *f)
{
    fprio temp;
    while (*f != NULL)
    {
        temp = *f;
        *f = (*f)->suivant;
        free(temp);
    }
}

void view(fprio f)
{
    printf(" -> ");
    while (f != NULL)
    {
        printf("%d -> ", f->prio);
        f = f->suivant;
    }
    printf("NULL \n");
}

void traite(char *fname, int nb_op)
{
    FILE *reader = fopen(fname, "r");
    if (reader == NULL)
    {
        printf("Fichier non trouvé ! \n");
        exit(EXIT_FAILURE);
    }
    fprio f = NULL;
    int p;
    for (int i = 0; i < nb_op; i++)
    {
        if (fgetc(reader) == '+')
        {
            fscanf(reader, "%d", &p);
            enfile(&f, p);
        }
        else
        {
            printf("%d,", defile(&f));
        }
        fgetc(reader);
    }
    printf("\n");
    detruit(&f);
}

int main()
{
    char *fname = "patients.txt";
    int nb = 1000;
    traite(fname, nb);
}