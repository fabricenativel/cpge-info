#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>
// --8<-- [start:struct_tas]
struct heap_s
{
    int size;
    int capacity;
    int *array;
};
typedef struct heap_s heap;
// --8<-- [end:struct_tas]

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

void swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

heap make_heap(int cap)
{
    int *t = malloc(sizeof(int) * cap);
    heap mh;
    mh.size = 0;
    mh.capacity = cap;
    mh.array = t;
    return mh;
}

// --8<-- [start:sift_up]
bool insert_heap(int nv, heap *mh)
{
    int cp = mh->size;
    if (mh->size == mh->capacity)
    {
        return false;
    }
    else
    {
        mh->array[cp] = nv;
        while (father(cp) != -1 && mh->array[cp] < mh->array[father(cp)])
        {
            swap(mh->array, cp, father(cp));
            cp = father(cp);
        }
        mh->size = mh->size + 1;
        return true;
    }
}
// --8<-- [end:sift_up]

int getmin(heap *mh)
{
    if (mh->size > 0)
    {
        int mv = mh->array[0];
        int cp = 0;
        int leftson = 1;
        mh->array[0] = mh->array[mh->size - 1];
        mh->size = mh->size - 1;
        while ((leftson < mh->size && mh->array[leftson]<mh->array[cp]) || (leftson+1<mh->size && mh->array[leftson+1]<mh->array[cp]))
        {
            if (leftson + 1 == mh->size || mh->array[leftson] < mh->array[leftson + 1])
            {
                swap(mh->array, cp, leftson);
                cp = leftson;
            }
            else
            {
                swap(mh->array, cp, leftson + 1);
                cp = leftson + 1;
            }
            leftson = son(cp);
        }
        return mv;
    }
    return -1;
}

void display_heap(heap mh)
{
    int newline = 1;
    for (int i = 0; i < mh.size; i++)
    {
        printf("%d ", mh.array[i]);
        if (i == newline - 1)
        {
            printf("\n");
            newline = newline * 2 + 1;
        }
    }
    printf("\n");
}

void shuffle(int array[], int size)
{
    for (int i = size-1; i > 0; i--)
    {
        swap(array, rand() % (i+1), i);
    }
}

bool check(heap mh)
{
    for (int i = 0; i < mh.size; i++)
    {
        if (son(i) < mh.size)
        {
            if (mh.array[i] > mh.array[son(i)])
            {
                return false;
            }
            if (son(i) + 1 < mh.size)
            {
                if (mh.array[i] > mh.array[son(i) + 1])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int s = 20000;
    int *v = malloc(sizeof(int) * s);
    int *sorted = malloc(sizeof(int) * s);
    float st, et;
    srand(time(NULL));
    for (int i = 0; i < s; i++)
    {
        v[i] = i;
    }
    shuffle(v, s);
    st = (float)clock() / CLOCKS_PER_SEC;
    heap mh = make_heap(s);
    for (int i = 0; i < s; i++)
    {
        insert_heap(v[i], &mh);
    }
    for (int i = 0; i < s; i++)
    {
        sorted[i] = getmin(&mh);
    }
    for (int i=0; i<s-1; i++)
    {
        assert (sorted[i]<=sorted[i+1]);
    }
    et = (float)clock() / CLOCKS_PER_SEC;
    printf("Terminé en %f !\n", et - st);
}