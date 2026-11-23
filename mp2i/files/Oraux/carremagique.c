#include <stdio.h>
#include <stdbool.h>

void affiche_carre(int carre[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", carre[i * n + j]);
        }
        printf("\n");
    }
}

bool valide_ligne(int carre[], int i, int n, int somme)
{
    // A compléter !
}

bool valide_colonne(int carre[], int j, int n, int somme)
{
    // A compléter !
}

bool valide_diagonale1(int carre[], int n, int somme)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if (carre[i * n + i] == 0)
        {
            return true;
        }
        s += carre[i * n + i];
    }
    return s == somme;
}

bool valide_diagonale2(int carre[], int n, int somme)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if (carre[i * n + (n - i - 1)] == 0)
        {
            return true;
        }
        s += carre[i * n + (n - i - 1)];
    }
    return s == somme;
}

bool valide_carre(int carre[], int n, int somme)
{
    for (int i = 0; i < n; i++)
    {
        if (!valide_ligne(carre, i, n, somme) || !valide_colonne(carre, i, n, somme))
        {
            return false;
        }
    }
    return valide_diagonale1(carre, n, somme) && valide_diagonale2(carre, n, somme);
}

bool resolution(int carre[], int n, int somme, int k, bool utilise[])
{
    // Teste toutes les valeurs possibles pour l'élément d'indice k du carre
    // Renvoie false si aucune valeur ne convient, sinon poursuit la résolution à l'indice k+1
    if (k == n * n)
    {
        return true;
    }
    for (int v = 1; v <= n * n; v++)
    {
        if (!utilise[v - 1])
        {   // Placer v à l'indice k dans le tableau et rendre cette valeur indisponible
            

            // Si le carre est valide et que la résolution aboutie on renvoie vraie
            if ( .... )
            {
                return true;
            }
            // Sinon il faut faire un retour sur trace et tester les valeurs suivantes
            else
            {
                

            }
        }
    }
    // On a testé sans succès toutes les valeurs
    return ....;
}

int main()
{
    int n = 4;
    int carre[n * n];
    bool utilise[n * n];
    int somme = ........;
    for (int i = 0; i < n * n; i++)
    {
        carre[i] = 0;
        utilise[i] = false;
    }
    if (resolution(carre, n, somme, 0, utilise))
    {
        affiche_carre(carre, n);
    }
    else
    {
        printf("Aucune solution trouvée !\n");
    }
    return 0;
}