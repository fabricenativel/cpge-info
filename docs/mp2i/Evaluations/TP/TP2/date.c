#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
struct date
{
    int jour;
    int mois;
    int annee;
};
typedef struct date date;

// Renvoie true si annee est bissextile, false sinon
bool est_bissextile(int annee)
{
    return (annee%4==0 && annee%100!=0) || annee%1000==0;
}

// Renvoie true si la date est une date valide 
bool est_valide(date d)
{
    int max_jours[13] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (est_bissextile(d.annee)) {max_jours[2]=29;}
    return (d.mois>0 && d.mois<13 && d.jour>0 && d.jour<=max_jours[d.mois]);
}

// Cree la date de jour j, mois m et année a
void set_date(date *d, int j, int m, int a)
{   
    d->jour = j;
    d->mois = m;
    d->annee = a;
}

date make_lendemain(date d)
{   assert(est_valide(d));
    date lendemain;
    int max_jours[13] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (est_bissextile(d.annee)) {max_jours[2]=29;}
    if (d.jour<max_jours[d.mois]) {
        lendemain.jour = d.jour+1;
        lendemain.mois = d.mois;
        lendemain.annee = d.annee;}
    else if (d.mois<12) {
        lendemain.jour = 1;
        lendemain.mois = d.mois +1;
        lendemain.annee =d.annee;
    }
    else
    {
        lendemain.jour = 1;
        lendemain.mois = 1;
        lendemain.annee =d.annee+1;
    }
    return lendemain;
}

void affiche(date d)
{   if (d.jour<10) {printf("0");}
    printf("%d/",d.jour);
    if (d.mois<10) {printf("0");}
    printf("%d/",d.mois);
    printf("%d",d.annee);
}

date decale(date d, int nb_jours)
{
    date dec = d;
    for (int i=0;i<nb_jours;i++)
    {
        dec = make_lendemain(dec);
    }
    return dec;
}

int randint(int min, int max)
{
    return rand()%(max-min+1) + min;
}

void make_random(int nb)
{
    FILE * writer= fopen("dates.txt","w");
    srand(time(NULL));
    const int bad = 15;
    int max_jours[13] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int annee, mois, jour, temp, err;
    for (int i=0;i<nb;i++)
    {
        annee = randint(1950,2020);
        if (est_bissextile(annee)) {max_jours[2]=29;}
        mois = randint(1,12);
        jour = randint(1,max_jours[mois]);
        if (rand()%100<bad)
        {   
            err = randint(1,3);
            if (err==1)
            {   printf("Erreur 1\n");
                mois = randint(13,14);
            }
            if (err==2)
            {   printf("Erreur 2\n");
                jour = max_jours[mois]+randint(1,2);
            }
            if (err==3)
            {   printf("Erreur 3\n");
                temp = mois;
                mois = randint(13,max_jours[mois]);
                jour = temp;
            }
            printf("*** : %d/%d/%d\n",jour,mois,annee);
        }
        fprintf(writer,"%d/%d/%d\n",jour,mois,annee);
    }
}


int count_bad()
{
    FILE * reader= fopen("dates.txt","r");
    int j,m,a;
    date *d = malloc(sizeof(date));
    int ok = 0;
    while (fscanf(reader,"%d/%d/%d\n",&j,&m,&a)!=EOF)
    {
        set_date(d,j,m,a);
        if (!est_valide(*d) )
        {
            ok = ok + 1;
        }
    }
    free(d);
    return ok;
}

int main()
{
    date date;
    //make_random(2023);
    printf("Nombre de dates non valides = %d\n",count_bad());
} 