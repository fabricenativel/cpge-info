#include <stdio.h>
#include <stdlib.h>

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
    {file f = {.tete=NULL,.queue=NULL};
    return f;}


//Ajout à la fin (on a accès au dernier)
void appendright(file *f, int val)
{
    maillon *nm = malloc(sizeof(maillon));
    nm->valeur = val;
    nm->suivant = NULL;
    if (f->queue==NULL)
    {
        f->queue = nm;
    }
    else
    {f->queue->suivant = nm;
    f->queue=nm;}
    if (f->tete == NULL) {f->tete=nm;}
}

//Ajout au début
void appendleft(file *f, int val)
{
    maillon *nm = malloc(sizeof(maillon));
    nm->valeur = val;
    nm->suivant = f->tete;
    f->tete = nm;
    if (f->queue == NULL) {f->queue=nm;}
}

//Affichage
void display(file f)
{
    maillon *cm = f.tete;
    printf("(T) : ");
    while (cm!=NULL)
    {   
        if (cm->suivant!=NULL)
        {printf("%i -> ",cm->valeur);}
        else
        {printf("%i : (Q)",cm->valeur);}
        cm = cm->suivant;
    }
    printf("\n");
}

int popleft(file *f)
{
    int v = f->tete->valeur;
    maillon* old = f->tete;
    f->tete = f->tete->suivant;
    free(old);
    return v;
}

int main(int argc, char* argv[])
{
    file f = cree_file();
    int killer, n;
    if (argc!=2) {printf("Il faut donner le nombre de soldats\n");}
    else
    {n = atoi(argv[1]);
    // Cree la liste de n soldats
    for (int i=1;i<=n;i++)
    {
        appendright(&f,i);
    }
    while (f.queue->valeur != f.tete->valeur)
    {
        killer = popleft(&f);
        appendright(&f,killer);
        popleft(&f);
    }
    display(f);
    }
}