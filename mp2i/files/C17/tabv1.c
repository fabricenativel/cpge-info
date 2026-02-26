#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct sizedarray
{
    int size;
    int* array;
};
typedef struct sizedarray sizedarray;

sizedarray make(int s, int defaultvalue)
{
    sizedarray sa;
    sa.size = s;
    sa.array = malloc(sizeof(int)*s);
    for (int i=0;i<sa.size;i++)
    {
        sa.array[i] = defaultvalue;
    }
    return sa;
}

void view(sizedarray sa)
{
    for (int i=0;i<sa.size;i++)
    {
        printf("%d ",sa.array[i]);
    }
    printf("\n");
}

bool set(sizedarray sa, int idx, int value)
{
    if (idx>=sa.size) {return false;}
    sa.array[idx] = value;
    return true;
}

void freemem(sizedarray sa)
{
    free(sa.array);
    sa.size = 0;
}

int main()
{
    sizedarray test =  make(10, 0);
    view(test);
    set(test,1,42);
    view(test);
    freemem(test);
}