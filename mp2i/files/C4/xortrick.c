#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 10000

int sum(int array[], int size)
{
    int s = 0;
    for (int i=0;i<size;i++)
    {
        s += array[i];
    }
    return s;
}

int find_missing(int fullarray[], int size, int array[])
{
    int full_sum = sum(fullarray, size);
    int array_sum = sum(array, size-1);
    return full_sum - array_sum;
}

int xortrick(int fullarray[], int size, int array[])
{
    int vxor = 0;

    for (int i = 0; i < size; i++)
    {
        vxor ^= fullarray[i];
    }
    
    for (int i = 0; i < size - 1; i++)
    {
        vxor ^= array[i];
    }

    return vxor;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <size>\n", argv[0]);
        return 1;
    }
    int size = atoi(argv[1]);
    int *array = malloc((size-1)*sizeof(int));
    int *fullarray = malloc(size*sizeof(int));
    int missing_value = rand() % MAX_VALUE;
    int missing_index = rand() % size;
    fullarray[missing_index] = missing_value;
    double stime;
    srand(time(NULL));
    for (int i=0; i<size-1;i++)
    {
        array[i] = rand() % MAX_VALUE;
    }
    for (int i=0; i<size;i++)
    {
        
        if (i<missing_index)
        {
            fullarray[i] = array[i];
        }
        else
        {
            fullarray[i] = array[i-1];
        }
    }
    stime = clock();
    int missing_sum = find_missing(fullarray, size, array);
    stime = (clock() - stime) / (double)CLOCKS_PER_SEC;
    printf("Missing value (somme) = %d en %lf sec. \n", missing_sum, stime);
    stime = clock();
    int missing_xor = xortrick(fullarray, size, array);
    stime = (clock() - stime) / (double)CLOCKS_PER_SEC;
    printf("Missing value (xor) = %d en %lf sec. \n", missing_xor, stime);
    free(fullarray);
    free(array);
    return EXIT_SUCCESS;
}
   