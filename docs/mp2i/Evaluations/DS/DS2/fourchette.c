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

bool est_fourchette(int n)
{
    int dc = n % 10;
    int pc = n;
    while (pc > 9)
    {
        pc = pc / 10;
    }
    return (n % (pc * 10 + dc) == 0);
}

tableau fourchette(int deb, int fin)
{
    int cpt = 0;
    for (int i = deb; i < fin; i++)
    {
        if (est_fourchette(i))
        {
            cpt += 1;
        }
    }
    tableau res = cree_tableau(0, cpt);
    cpt = 0;
    for (int i = deb; i < fin; i++)
    {
        if (est_fourchette(i))
        {
            res.valeurs[cpt] = i;
            cpt += 1;
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Prend deux entier en ligne de commande \n");
        exit(1);
    }
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    tableau s = fourchette(n, m);
    affiche(s);
    libere(&s);
}
