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
    return (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0;
}

// Renvoie true si la date est une date valide
bool est_valide(date d)
{
    int max_jours[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (est_bissextile(d.annee))
    {
        max_jours[2] = 29;
    }
    return (d.mois > 0 && d.mois < 13 && d.jour > 0 && d.jour <= max_jours[d.mois]);
}

// Cree la date de jour j, mois m et année a
date cree_date(int j, int m, int a)
{
    date d;
    d.jour = j;
    d.mois = m;
    d.annee = a;
    return d;
}

bool compare(date d1, date d2)
{
    if (d1.annee != d2.annee)
    {
        return d1.annee < d2.annee;
    }
    if (d1.mois != d2.mois)
    {
        return d1.mois < d2.mois;
    }
    return d1.jour < d2.jour;
}

void echange(date tab[], int i, int j)
{
    date temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

void tri_dates(date tab[], int size)
{
    int cpos;
    for (int i = 2; i < size; i++)
    {
        cpos = i;
        while (cpos >= 1 && compare(tab[cpos], tab[cpos - 1]))
        {
            echange(tab, cpos, cpos - 1);
            cpos = cpos - 1;
        }
    }
}

date *recuperer_dates(int nb_dates)
{
    date *les_dates = malloc(sizeof(date) * nb_dates);
    FILE *reader = fopen("dates.txt", "r");
    int j, m, a;
    date d;
    int idx = 0;
    while (fscanf(reader, "%d/%d/%d\n", &j, &m, &a) != EOF)
    {
        d = cree_date(j, m, a);
        if (est_valide(d))
        {
            les_dates[idx] = d;
            idx = idx + 1;
        }
    }
    return les_dates;
}

void lendemain(date *d)
{
    assert(est_valide(*d));
    int max_jours[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (est_bissextile(d->annee))
    {
        max_jours[2] = 29;
    }
    if (d->jour < max_jours[d->mois])
    {
        d->jour = d->jour + 1;
    }
    else if (d->mois < 12)
    {
        d->jour = 1;
        d->mois = d->mois + 1;
    }
    else
    {
        d->jour = 1;
        d->mois = 1;
        d->annee = d->annee + 1;
    }
}

// calcule l'écart entre d1 et d2 (même année) et d1<d2
int nb_jours(date d1, date d2)
{
    int max_jours[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int nb = 0;
    if (est_bissextile(d1.annee))
    {
        max_jours[2] = 29;
    }
    if (d1.mois == d2.mois)
        return (d2.jour - d1.jour);
    nb = nb + (max_jours[d1.mois] - d1.jour);
    for (int i = d1.mois + 1; i < d2.mois; i++)
    {
        nb += max_jours[i];
    }
    nb += d2.jour;
    return nb;
}

int somme_jours(int annee1, int annee2)
{
    int nb = 0;
    for (int i = annee1; i < annee2; i++)
    {
        if (est_bissextile(i))
        {
            nb += 366;
        }
        else
        {
            nb += 365;
        }
    }
    return nb;
}

int ecart2(date d1, date d2)
{
    date fin_annee = {.jour = 31, .mois = 12, .annee = d1.annee};
    date debut_annee = {.jour = 1, .mois = 1, .annee = d2.annee};
    int n1 = nb_jours(d1, fin_annee);
    int n2 = somme_jours(d1.annee + 1, d2.annee);
    int n3 = nb_jours(debut_annee, d2);
    return n1 + n2 + n3 + 1;
}

bool egales(date d1, date d2)
{
    return (d1.jour == d2.jour && d1.mois == d2.mois && d1.annee == d2.annee);
}

int ecart(date *d1, date d2)
{
    int nb = 0;
    while (!egales(*d1, d2))
    {
        lendemain(d1);
        nb += 1;
    }
    return nb;
}

void affiche(date d)
{
    if (d.jour < 10)
    {
        printf("0");
    }
    printf("%d/", d.jour);
    if (d.mois < 10)
    {
        printf("0");
    }
    printf("%d/", d.mois);
    printf("%d", d.annee);
}

void decale(date *d, int nb_jours)
{
    for (int i = 0; i < nb_jours; i++)
    {
        lendemain(d);
    }
}

int randint(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void write_int(FILE *writer, int number, int size)
{
    int n = 0, nb = number;
    while (nb != 0)
    {
        nb = nb / 10;
        n = n + 1;
    }
    while (n < size)
    {
        fprintf(writer, "0");
        n = n + 1;
    }
    fprintf(writer, "%d", number);
}

void make_random(int nb)
{
    FILE *writer = fopen("dates.txt", "w");
    srand(time(NULL));
    const int bad = 15;
    int max_jours[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int annee, mois, jour, temp, err;
    for (int i = 0; i < nb; i++)
    {
        annee = randint(1942, 2022);
        if (est_bissextile(annee))
        {
            max_jours[2] = 29;
        }
        mois = randint(1, 12);
        jour = randint(1, max_jours[mois]);
        if (rand() % 100 < bad)
        {
            err = randint(1, 3);
            if (err == 1)
            {
                printf("Erreur 1\n");
                mois = randint(13, 14);
            }
            if (err == 2)
            {
                printf("Erreur 2\n");
                jour = max_jours[mois] + randint(1, 2);
            }
            if (err == 3)
            {
                printf("Erreur 3\n");
                temp = mois;
                mois = randint(13, max_jours[mois]);
                jour = temp;
            }
            printf("*** : %d/%d/%d\n", jour, mois, annee);
        }
        write_int(writer, jour, 2);
        fprintf(writer, "/");
        write_int(writer, mois, 2);
        fprintf(writer, "/%d\n", annee);
    }
}

int compte_valide()
{
    FILE *reader = fopen("dates.txt", "r");
    int j, m, a;
    date d;
    int ok = 0;
    while (fscanf(reader, "%d/%d/%d\n", &j, &m, &a) != EOF)
    {
        d = cree_date(j, m, a);
        if (est_valide(d))
        {
            ok = ok + 1;
        }
    }
    return ok;
}

int main()
{
    // make_random(5000);
    date *les_dates;
    int n_dates = compte_valide();
    les_dates = recuperer_dates(n_dates);
    date my_bd = {.jour = 14, .mois = 5, .annee = 1970};
    date to_day = {.jour = 8, .mois = 10, .annee = 2023};
    printf("Nombre de dates non valides = %d\n", n_dates);
    tri_dates(les_dates, n_dates);
    printf("Date la plus anciennce : ");
    affiche(les_dates[0]);
    printf("\n");
    printf("Date la plus récente : ");
    affiche(les_dates[n_dates - 1]);
    printf("\n");
    printf("Ecart entre la plus ancienne et la plus récente =%d\n", ecart2(les_dates[0], les_dates[n_dates - 1]));
    printf("Ecart entre la plus ancienne et la plus récente =%d\n", ecart(&les_dates[0], les_dates[n_dates - 1]));
    printf("Mon age en jour = %d\n", ecart2(my_bd, to_day));
    free(les_dates);
}