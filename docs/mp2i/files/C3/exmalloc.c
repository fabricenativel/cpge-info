#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr1; // Pointeur non initialisé
    int *ptr2 = NULL; // Pointeur initialisé à NULL
    int n = 42;
    int* ptr3 = &n; // Pointeur vers une variable locale
    // Pointeur vers un bloc mémoire alloué dynamiquement
    int* ptr4 = malloc(sizeof(int)); 
    // Affectation de la valeur 14 au bloc mémoire pointé par ptr4
    *ptr4 = 14; 
}