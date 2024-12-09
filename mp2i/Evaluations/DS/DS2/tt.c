#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
struct tableau_s
{
    int taille;
    int *valeurs;
};
typedef struct tableau_s tableau;

tableau cree_tableau(int valeur_initiale, int taille)
{
    tableau s;
    s.taille = taille;
    s.valeurs = malloc(sizeof(int) * taille);
    for (int i = 0; i < taille; i++)
    {
        s.valeurs[i] = valeur_initiale;
    }
    return s;
}

tableau cree_tableau_bug(int val, int taille)
{
    tableau t;
    t.taille = taille;
    int tab[taille];
    for (int i = 0; i < taille; i++)
    {
        tab[i] = val;
    }
    t.valeurs = tab;
    return t;
}

int donne_taille(tableau s)
{
    return s.taille;
}

void affiche(tableau s)
{
    printf("[");
    for (int i = 0; i < s.taille; i++)
    {
        printf("%d; ", s.valeurs[i]);
    }
    printf("]\n");
}

void libere(tableau *s)
{
    free(s->valeurs);
    s->taille = 0;
}

bool affecte(tableau s, int i, int v)
{
    if (i < s.taille)
    {
        s.valeurs[i] = v;
        return true;
    }
    return false;
}

int somme(tableau t)
{
    int s = 0;
    for (int i = 0; i < t.taille; i++)
    {
        s += t.valeurs[i];
    }
    return s;
}

tableau lire_entiers(char *filename)
{
    FILE *lecteur = fopen(filename, "r");
    tableau t;
    int temp;
    t.taille = 0;
    if (lecteur == NULL)
    {
        t.valeurs = NULL;
        return t;
    }
    while (fscanf(lecteur, "%d", &temp) != EOF)
    {
        t.taille += 1;
        printf("%d\n", temp);
    }
    fclose(lecteur);
    lecteur = fopen(filename, "r");
    t.valeurs = malloc(sizeof(int) * t.taille);
    for (int i = 0; i < t.taille; i++)
    {
        fscanf(lecteur, "%d", &t.valeurs[i]);
    }
    fclose(lecteur);
    return t;
}

int sqrt_int(int n)
{
    return (int)sqrt(n);
}

bool *crible(int n)
{
    bool *premiers = malloc(sizeof(bool) * (n + 1));
    premiers[0] = false;
    premiers[1] = false;
    int k;
    for (int i = 2; i <= n; i++)
    {
        premiers[i] = true;
    }
    for (int i = 2; i < isqrt(n) + 1; i++)
    {
        if (premiers[i])
        {
            k = 2;
            while (k * i <= n)
            {
                premiers[k * i] = false;
                k = k + 1;
            }
        }
    }
    return premiers;
}

tableau nombres_premiers(int n)
{
    bool *premiers = crible(n);
    int nb = 0;
    tableau t;
    for (int i = 0; i <= n; i++)
    {
        if (premiers[i])
        {
            nb += 1;
        }
    }
    t.taille = nb;
    t.valeurs = malloc(sizeof(int) * nb);
    for (int i = 0; i <= n; i++)
    {
        if (premiers[i])
        {
            t.valeurs[nb] = i;
        }
    }
    free(premiers);
    return t;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Prend un entier en ligne de commande \n");
        exit(1);
    }
    int n = atoi(argv[1]);
    tableau s = nombres_premiers(n);
    affiche(s);
    libere(&s);
}
