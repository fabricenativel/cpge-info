#include <stdio.h>
#include <stdlib.h>

/* Implémentation d'une file avec un tableau circulaire */
#define SIZE 10
#define TYPE char
struct file
{
    int size;
    int cid;
    TYPE tab[SIZE];
};
typedef struct file file;

void affiche(file f)
{   
    // printf("Tableau = ");
    // for (int i=0; i<SIZE;i++)
    // {
    //     printf("%c-",f.tab[i]);
    // }
    // printf("\n");
    //printf("Début = %d, Fin = %d\n",f.cid,f.size);
    //printf(" < ");
    for (int i=0; i<f.size; i ++)
    {
        printf("%c < ",f.tab[(f.cid+i)%SIZE]);
    }
    printf("\n");
}

void enfile(file *f,TYPE val)
{
    if (f->size<SIZE)
    {(f->tab)[(f->cid+f->size)%(SIZE)] = val;
    f->size = f->size +1;}
}

TYPE defile(file *f)
{
    if (f->size!=0)
    {
        TYPE val = f->tab[f->cid];
        f->size = f->size - 1;
        f->cid = (f->cid+1)%SIZE;
        return val;
    }
}

int main()
{
    file f;
    char c;
    f.size = 0;
    f.cid = 0;
    for (int i=0;i<SIZE;i++)
    {
        f.tab[i] =' ';
    }
    FILE * reader =fopen("touches.txt","r");
    while ((c=fgetc(reader))!=EOF)
    {
        if (c=='0')
        {
            defile(&f);
        }
        else
        {
            enfile(&f,c);
        }
        affiche(f);
    }
}