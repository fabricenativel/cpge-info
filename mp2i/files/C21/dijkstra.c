#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct elt_s
{
    int prio;
    int line;
    int col;
};
typedef struct elt_s elt;

struct heap_s
{
    int size;
    int capacity;
    elt *data;
};
typedef struct heap_s heap;


int son(int i)
{
    int s = 2 * i + 1;
    return s;
}

int father(int i)
{
    if (i == 0)
    {
        return -1;
    }
    else
    {
        return (i - 1) / 2;
    };
}

void swap(elt *data, int i, int j)
{
    elt temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

heap make_heap(int c)
{
    heap mh;
    mh.size = 0;
    mh.capacity = c;
    mh.data = malloc(sizeof(elt) * c);
    return mh;
}



bool insert_heap(elt nv, heap *mh)
{
    int cp = mh->size;
    if (mh->size == mh->capacity)
    {
        return false;
    }
    else
    {
        mh->data[cp] = nv;
        while (cp != 0 && mh->data[cp].prio < mh->data[father(cp)].prio)
        {
            swap(mh->data, cp, father(cp));
            cp = father(cp);
        }
        mh->size = mh->size + 1;
        return true;
    }
}



elt getmin(heap *mh)
{
    if (mh->size > 0)
    {
        elt mv = mh->data[0];
        int cp = 0;
        int leftson = 1;
        mh->data[0] = mh->data[mh->size - 1];
        mh->size = mh->size - 1;
        while (leftson + 1 < mh->size && (mh->data[leftson + 1].prio < mh->data[cp].prio || mh->data[leftson].prio < mh->data[cp].prio))
        {
            if (mh->data[leftson].prio < mh->data[leftson + 1].prio)
            {
                swap(mh->data, cp, leftson);
                cp = leftson;
            }
            else
            {
                swap(mh->data, cp, leftson + 1);
                cp = leftson + 1;
            }
            leftson = son(cp);
        }
        if ((leftson < mh->size) && (mh->data[leftson].prio < mh->data[cp].prio))
        {
            swap(mh->data, cp, leftson);
        }
        return mv;
    }
    elt elt_null = {0, 0, 0}; // Return an empty element if the heap is empty
    return elt_null;
}

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

void show(bool *seen, int size)
{
    // Affiche les cases visitées
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (seen[i * size + j])
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int dijkstra(int *matrix, int size)
{
    heap pqueue = make_heap(size * size);
    int *mindist = malloc(size * size * sizeof(int));
    bool *seen = malloc(size * size * sizeof(bool));
    for (int i = 0; i < size * size; i++)
    {
        seen[i] = false;
    }
    mindist[0] = 0;
    elt start = {0,0,0};
    elt current;
    int endline = size-1;
    int encol = size-1;
    bool reached = false;
    insert_heap(start, &pqueue);
    while (!reached)
    {
        current = getmin(&pqueue);
        if (!seen[current.line*size+current.col])
        {
            mindist[current.line*size+current.col] = current.prio;
            seen[current.line*size+current.col] = true;
            if (current.line == endline && current.col == encol)
            {
                reached = true;
            }
            if (current.col < size - 1)
            {
                elt right = {current.prio + matrix[current.line * size + current.col + 1], current.line, current.col + 1};
                insert_heap(right, &pqueue);
            }
            if (current.line < size - 1)
            {
                elt down = {current.prio + matrix[(current.line + 1) * size + current.col], current.line + 1, current.col};
                insert_heap(down, &pqueue);
            }
        }
    }
    return mindist[endline * size + encol];
}




int main()
{
    char ex[] = "big.txt";
    int size = get_size(ex);
    int *mat = read_matrix(ex, size);
    double start = (double)clock()/CLOCKS_PER_SEC;
    int dij = dijkstra(mat, size);
    double end = (double)clock()/CLOCKS_PER_SEC;
    printf("Chemin le plus court (Dijkstra) = %d en %lf secondes \n",dij,(end-start));
    free(mat);
    return 0;
}