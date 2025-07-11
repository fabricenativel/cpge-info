#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int get_size(char *filename)
{
    // Renvoie la taille de la matrice de chiffres du fichier
    int size = 0;
    FILE *reader = fopen(filename, "r");
    if (reader ==NULL) {
        printf("Fichier %s non trouvé !\n", filename);
        return -1; // Indicate an error
    }
    char c = '0';
    while (c != '\n' && c != EOF) {
        c = fgetc(reader);
        size++;
        }
    fclose(reader);
    return size-1;
}


int* read_matrix(char *filename, int size)
{
    // Lit la matrice de chiffres du fichier   
    FILE *reader = fopen(filename, "r");
    if (reader == NULL) {
        printf("Fichier %s non trouvé !\n", filename);
        return NULL; // Indicate an error
    }
    int *matrix = malloc(size * size * sizeof(int)); 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i * size + j] = (int)fgetc(reader)-48;
        }
        fgetc(reader); // Skip the newline character
    }
    fclose(reader);
    return matrix;
}


void view_matrix(int *matrix, int size)
{
    // Affiche la matrice de chiffres
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i * size + j]);
        }
        printf("\n");
    }
}


int dynprog(int *matrix, int size)
{
    int * mindist = malloc(size * size * sizeof(int));
    mindist[0]=0;
    int up, left;
    for (int i=1;i<size;i++)
    {
        mindist[i] = mindist[i-1] + matrix[i];
        mindist[i*size] = mindist[(i-1)*size] + matrix[i*size];
    }
    for (int i=1;i<size;i++)
    {
        for (int j=1;j<size;j++)
        {
            up = mindist[(i-1)*size+j];
            left = mindist[i*size+(j-1)];
            if (up < left) {
                mindist[i*size+j] = matrix[i*size+j] + up;
            } else {
                mindist[i*size+j] = matrix[i*size+j] + left;
            }
        }
    }
    return mindist[(size-1)*size+(size-1)];
}


int main()
{
    char ex[] = "big.txt";
    int size = get_size(ex);
    int *mat = read_matrix(ex, size);
    double start = (double)clock()/CLOCKS_PER_SEC;
    int pdyn = dynprog(mat, size);
    double end = (double)clock()/CLOCKS_PER_SEC;
    printf("Chemin le plus court (prog dyn) = %d en %lf secondes \n",pdyn,(end-start));
    free(mat);
    return 0;
}