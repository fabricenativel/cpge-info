#include <stdio.h>
#include <stdlib.h>

struct vector {
    int current_size; // nombre d'éléments
    int max_size; // taille du tableau
    int* array; // tableau utilisé pour stocker les éléments
    int default_value; //valeur par defaut d'un élément du tableau
};
typedef struct vector vector;

vector create(int size, int value)
{
    vector v;
    v.current_size = size;
    v.max_size = size;
    v.default_value = value;
    v.array = malloc(sizeof(int)*size);
    for (int i=0; i<size;i++)
    {v.array[i]=value;}
    return v;
}


void display(vector v)
{
    printf("Taille actuelle : %d\n",v.current_size);
    printf("Taille maxi : %d\n",v.max_size);
    printf("Contenu = [");
    for (int i=0;i<v.current_size-1;i++)
    {
        printf("%d, ",v.array[i]);
    }
    if (v.current_size>0) printf("%d ",v.array[v.current_size-1]);
    printf("]\n");
}


void destroy(vector v)
{
    free(v.array);
}

int main()
{
    vector test = create(5, 10);
    display(test);
    destroy(test);
}