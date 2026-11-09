#include <stdio.h>

// Renvoie dieme chiffre de n
int chiffre(int n, int d)
{
    if (n==0 || d==0)
    {
        return n%10;
    }
    return chiffre(n/10,d-1);
}

// Recopie les valeurs du tableau entrée dans sorties
void copie_valeurs(int entree[], int sortie[], int size)
{
    for (int i=0;i<size;i++)
    {
        sortie[i] = entree[i];
    }
}

void tri_chiffre(int entree[], int sortie[], int size, int digit)
{
    // Calcul de la taille de chaque seau
    int taille_seau[10] = {0};
    int c;
    for (int i=0;i<size;i++)
    {
        taille_seau[chiffre(entree[i],digit)]++;
    }
    // Tableau des positions courantes dans chaque seau
    int position_seau[10];
    position_seau[0]=0;
    for (int i=1;i<10;i++)
    {
        position_seau[i] = position_seau[i-1] + taille_seau[i-1];
    }
    // Parcours et rangement sans le tableau de sortie
    for (int i=0;i<size;i++)
    {
        c = chiffre(entree[i],digit);
        sortie[position_seau[c]++] = entree[i];
    }
}

void tri_radix(int entree[], int sortie[], int size)
{
    for (int digit=0;digit<3;digit++)
    {
        tri_chiffre(entree,sortie,size,digit);
        copie_valeurs(sortie,entree,size);
    }
}

void affiche(int tab[], int size)
{
    for (int i=0;i<size-1; i++)
    {
        printf("%d, ",tab[i]);
    }
    printf("%d \n",tab[size-1]);
}

int main()
{
    int test[] = {123, 211, 312, 321, 133, 121, 213, 30, 103, 200};
    int size = 10;
    int tri[size];
    tri_radix(test,tri,size);
    affiche(tri,size);
}