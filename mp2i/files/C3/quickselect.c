#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>

int *make_array(int size, int vmax)
{
    srand(time(NULL));
    int *arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % vmax;
    }
    return arr;
}

void view_array(int arr[], int size)
{
    if (size==0)
    {
        printf("[]\n");
    }
    else
    {
        printf("[");
        for (int i=0;i <size-1; i++)
        {
            printf("%d, ", arr[i]);
        }
        printf("%d]\n", arr[size-1]);
    }
}

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int split(int array[], int start, int end, int value)
{
    /*Renvoie le nombre d'éléments du sous tableau (entre start et end) strictement inferieurs à value
     Réarrange les éléments du tableau de façon à avoir avant l'indice k les élements < value.
    */
    int k = 0;
    for (int i = start; i < end; i++)
    {
        if (array[i] < value)
        {
            swap(array, i, k);
            k = k + 1;
        }
    }
    return k;
}

int quikselect(int array[], int size, int num)
{
    //Renvoie la num plus petit valeur du tableau 
    int start = 0;
    int end = size;
    int k = split(array, start, end, array[start]);
    while (k!=num)
    {
        if (k<num)
        {
            k = k + split(array, k-1, end, array[k]);
        }
        else
        {
        k = k - split(array, start, k+1, array[start+1]);
        }
    }
    return array[start];
}

int main()
{
    int tsize = 10;
    int *test = make_array(tsize, 100);
    view_array(test, tsize);
    int num = 3;
    printf("La %de plus petite valeur est %d\n", num, quikselect(test,10,num));
    return EXIT_SUCCESS;
}