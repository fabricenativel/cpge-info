#include <stdlib.h>
#include <stdio.h>

struct list
{
    int current_size;
    int max_size;
    int *array;
};
typedef struct list list;


list create(int size, int value)
{
    list v;
    v.current_size = size;
    v.max_size = size;
    v.array = malloc(sizeof(int)*size);
    for (int i=0;i<v.current_size;i++)
    {
        v.array[i] = value;
    }
    return v;
}

void destroy(list v)
{
    free(v.array);
}

void display(list v)
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

void append(list *v, int value)
{
    if (v->current_size < v->max_size)
    {
        v->array[v->current_size] = value;
    }
    else
    {
        int *new_array = malloc(sizeof(int)*(v->max_size)*2);
        for (int i=0; i<v->current_size;i++)
        {
            new_array[i] = (v->array)[i];
        }
        new_array[v->current_size] = value;
        free(v->array);
        v->array = new_array;
        v->max_size = v->max_size*2;
    }
    v->current_size = v->current_size + 1;

}

int pop(list *v)
{
    v->current_size--;
    return (v->array)[v->current_size];
}


int main()
{
    list test = create(5, 10);
    display(test);
    append(&test,11);
    display(test);
    append(&test,12);
    display(test);
    printf("Last elt = %d\n",pop(&test));
    display(test);
    destroy(test);
}