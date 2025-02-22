#include <stdio.h>
#include <stdbool.h>


// Valide une ligne
bool valide_ligne(int carre[], int lig, int n, int somme)
{
    int s = 0;
    for (int i=0; i<n; i++)
    {
        if (carre[n*lig+i]==-1) {return true;}
        else
        {
            s+=carre[n*lig+i];
        }
    }
    return s==somme;
}

bool valide_colonne(int carre[], int col, int n, int somme)
{
    int s = 0;
    for (int i=0; i<n; i++)
    {
        if (carre[n*i+col]==-1) {return true;}
        else
        {
            s+=carre[n*i+col];
        }
    }
    return s==somme;
}

bool valide_diag1(int carre[], int n, int somme)
{
    int s = 0;
    for (int i=0; i<n; i++)
    {
        if (carre[n*i+i]==-1) {return true;}
        else
        {
            s+=carre[n*i+i];
        }
    }
    return s==somme;
}

bool valide_diag2(int carre[], int n, int somme)
{
    int s = 0;
    for (int i=0; i<n; i++)
    {
        if (carre[n*i+n-i-1]==-1) {return true;}
        else
        {
            s+=carre[n*i+n-i-1];
        }
    }
    return s==somme;
}

bool valide_carre(int carre[], int n, int somme)
{
    for (int i=0;i<n;i++)
    {
        if (!valide_ligne(carre,i,n,somme) || !valide_colonne(carre,i,n,somme)) {return false;}
    }
    return valide_diag1(carre, n,somme) && valide_diag2(carre, n,somme);
}

int calcule_somme(int n)
{
    return n*(n*n+1)/2;
}

bool resolution(int carre[], int index, int n, int values[], bool utilise[], int somme, int size)
{
    if (index==size) {return true;}
    else
    for (int i=0; i<size; i++)
    {
        if (!utilise[i]) 
        {
            carre[index/size+index%size] = values[i];
            utilise[i] = true;
            if (valide_carre(carre,n,somme) && resolution(carre,index+1,n,values,utilise, somme,size)) {return true;}
            else
            {
                carre[index/size+index%size] = -1;
                utilise[i] = false;
            }
        }
    }
    return false;
}

int main()
{
    int n = 5;
    int size = n*n;
    int valeurs[size];
    int carre[size];
    bool utilise[size];
    for (int i=0; i<size; i++)
    {   valeurs[i]= i+1;
        carre[i] = -1;
        utilise[i] = false;
    }
    int somme = calcule_somme(n);
    printf("Carré de côté %d, somme = %d\n",n,somme);
    resolution(carre,0,n,valeurs,utilise,somme, size);
    for (int i=0;i<size;i++)
    {
        printf("%d, ",carre[i]);
    }
    printf("\n");
}




// Recherche d'un carré magique par backtracking
