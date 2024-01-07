#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Calcule la somme des inverses des entiers jusqu'à n
// Par exemple harmonique(3) renvoie 1 + 1/2 + 1/3
double harmonique(int n){
    double sh = 0;
    for (int i = 0; i < n; i = i + 1)
    {
        sh = sh + 1 / i;
    }
    return sh;}

// Renvoie true si tous les éléments de tab sont identiques
// Par exemple si test={2, 2, 2, 2} alors tab(test,4) renvoie true
bool tous_egaux(int tab[], int size){
    for (int i = 0; i < size; i = i + 1)
    {
        if (tab[i] != tab[i + 1])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

// Renvoie un pointeur vers un tableau contenant les entiers de 0 à n-1
int *cree_tab_entiers(int n){
    int tab_entiers[n];
    for (int i = 0; i < n; i++)
    {
        tab_entiers[i] = i;
    }
    return &tab_entiers;}

// Ne renvoie rien et remplace n par n/2 si n est pair et 3n+1 si n est impair
void syracuse(int n){
    if (n % 2 = 0)
    {
        n = n / 2;
    }
    else
    {
        n = 3 * n + 1;
    }}

// Programme qui affiche l'adresse de la variable p
int main(){
    int *p;
    *p = 42;
    printf("%p", p);}

// Programme qui demande deux entiers puis affiche leur somme
int main(){
    int a, b;
    printf("a=");
    scanf("%d", a);
    printf("b=");
    scanf("%d", b);
    printf("Somme = %d", a + b);}