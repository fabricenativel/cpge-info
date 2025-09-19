#include <stdio.h>

int var1; //Dans le segment de données (non initialisé)
int var2 = 42; //Dans le segment de données (initialisé)

int carre(int a)
{
    int r = a*a; // Dans la pile lors d'un appel à carre
    return r;
}

int main()
{
    int var3; //Dans la pile (variable locale)
    var3 = carre(var2); //Récupère la valeur renvoyée
    return 0;
}