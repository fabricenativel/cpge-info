#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct position_s
{
    int *etat;
    int noirs;
    int blancs;
    int vide;
    int taille;
    int dep;
};
typedef struct position_s position;

position initialisation(int b, int n)
{
    // Renvoie la situation initiale du casse tête avec b moutons noirs et n blancs
    position p;
    p.etat = malloc(sizeof(int) * (n + b + 1));
    p.dep = 0;
    p.noirs = n;
    p.blancs = b;
    p.taille = n + b + 1;
    p.vide = b;
    for (int i = 0; i < b; i++)
    {
        p.etat[i] = 1;
    }
    p.etat[b] = 0;
    for (int i = b + 1; i < n + b + 1; i++)
    {
        p.etat[i] = 2;
    }
    return p;
}

bool deplacement_gauche(position p)
{
    return p.vide > 0 && p.etat[p.vide - 1] == 1;
}

bool deplacement_droit(position p)
{
    return p.vide < p.taille - 1 && p.etat[p.vide + 1] == 2;
}

bool saut_gauche(position p)
{
    return p.vide > 1 && p.etat[p.vide - 2] == 1 && p.etat[p.vide - 1] == 2;
}

bool saut_droit(position p)
{
    return p.vide < p.taille - 2 && p.etat[p.vide + 2] == 2 && p.etat[p.vide + 1] == 1;
}

void deplace(position *p, int m)
{
    p->etat[p->vide] = p->etat[m];
    p->etat[m] = 0;
    p->vide = m;
}

void affiche(position p)
{
    for (int i = 0; i < p.taille; i++)
    {
        if (p.etat[i] != 0)
        {
            printf("%d", p.etat[i]);
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n");
}

bool est_solution(position p)
{
    for (int i = 0; i < p.noirs; i++)
    {
        if (p.etat[i] != 2)
        {
            return false;
        }
    }
    if (p.etat[p.noirs] != 0)
    {
        return false;
    }
    for (int i = p.noirs + 1; i < p.taille; i++)
    {
        if (p.etat[i] != 1)
        {
            return false;
        }
    }
    return true;
}

bool solve(position *p)
{
    if (est_solution(*p))
    {
        return true;
    }
    if (deplacement_gauche(*p))
    {
        deplace(p, p->vide - 1);
        p->dep += 1;
        if (!solve(p))
        {
            deplace(p, p->vide + 1);
            p->dep -= 1;
        }
        else
        {
            return true;
        }
    }
    if (deplacement_droit(*p))
    {
        deplace(p, p->vide + 1);
        p->dep += 1;
        if (!solve(p))
        {
            deplace(p, p->vide - 1);
            p->dep -= 1;
        }
        else
        {
            return true;
        }
    }
    if (saut_gauche(*p))
    {
        deplace(p, p->vide - 2);
        p->dep += 1;
        if (!solve(p))
        {
            deplace(p, p->vide + 2);
            p->dep -= 1;
        }
        else
        {
            return true;
        }
    }
    if (saut_droit(*p))
    {
        deplace(p, p->vide + 2);
        p->dep += 1;
        if (!solve(p))
        {
            deplace(p, p->vide - 2);
            p->dep -= 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Donner les tailles en ligne de commande !\n");
    }
    else
    {
        int b = atoi(argv[1]);
        int n = atoi(argv[2]);
        position s = initialisation(b, n);
        affiche(s);
        if (solve(&s))
        {
            affiche(s);
            printf("Solution atteinte en %d coups\n", s.dep);
        }
        else
        {
            printf("Pas de solution !\n");
        }
    }
}