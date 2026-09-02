#include <stdio.h>
#include <stdlib.h>


int tmaxi(int tab[], int size){
    int tmax = tab[0];
    int tij;
    for (int i=0;i<size;i++){
        tij=0;
        for (int j=i;j<size;j++){
            tij = tij + tab[j];
            if (tij>tmax) {tmax = tij;}}
    }
    return tmax;}


int* read_tab(char filename[], int *tab_size)
{
    // Taille du tableau
    int size = 0;
    int n;
    FILE* reader = fopen(filename,"r");
    while (fscanf(reader,"%d\n",&n)!=EOF)
    {
        size = size + 1;
    }
    // Allocation et lecture
    int *tab = malloc(sizeof(int)*size);
    rewind(reader);
    for (int i=0;i<size;i++)
    {
        fscanf(reader,"%d\n",&tab[i]);
    }
    *tab_size = size;
    return tab;
}

int main(int argc,char *argv[])
{
    //int test[9] = {2, -7, -5, 4, -1, 10, -4, 9, -2};
    int *test;
    int test_size;
    if (argc!=2) {
        printf("Utilisation : ./algo1.exe filename");
    }
    else
    {
        test = read_tab(argv[1],&test_size);
        printf("Lecture terminée, %d éléments lus\n",test_size);
    }
    printf("Somme maximale d'une tranche = %d\n",tmaxi(test,test_size));
    free(test);
}