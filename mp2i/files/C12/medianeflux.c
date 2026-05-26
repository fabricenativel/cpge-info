#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define N 1000000

struct heap_s
{
    int size;
    int capacity;
    int *array;
};
typedef struct heap_s heap;
struct heapmax_s
{
    int size;
    int capacity;
    int *array;
};
typedef struct heapmax_s heapmax;


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

heapmax make_heapmax(int cap)
{
    int *t = malloc(sizeof(int) * cap);
    heapmax mh;
    mh.size = 0;
    mh.capacity = cap;
    mh.array = t;
    return mh;
}

bool insert_heapmax(int nv, heapmax *mh)
{
    int cp = mh->size;
    if (mh->size == mh->capacity)
    {
        return false;
    }
    else
    {
        mh->array[cp] = nv;
        while (father(cp) != -1 && mh->array[cp] > mh->array[father(cp)])
        {
            swap(mh->array, cp, father(cp));
            cp = father(cp);
        }
        mh->size = mh->size + 1;
        return true;
    }
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


int getmax(heapmax *mh)
{
    if (mh->size > 0)
    {
        int mv = mh->array[0];
        int cp = 0;
        int leftson = 1;
        mh->array[0] = mh->array[mh->size - 1];
        mh->size = mh->size - 1;
        while ((leftson < mh->size && mh->array[leftson]>mh->array[cp]) || (leftson+1<mh->size && mh->array[leftson+1]>mh->array[cp]))
        {
            if (leftson + 1 == mh->size || mh->array[leftson] > mh->array[leftson + 1])
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

void insere(int tab[], int i,int v)
{
    tab[i]=v;
    while (i!=0 && tab[i-1]>tab[i])
    {
        swap(tab, i, i-1);
        i = i - 1;
    }
}

void init_flux(int graine)
{
    srand(graine);
}

int lire_flux(int vmin, int vmax)
{
    return vmin + rand() % (vmax-vmin);
}

float mediane(int tab[], int s)
{
    if ((s+1)%2==1)
    {
        return (float)tab[s/2];
    }
    return (tab[s/2]+tab[s/2+1])/2.;
}

void affiche(int tab[], int i)
{
    printf("[");
    for (int j=0;j<i;j++)
    {
        printf("%d, ", tab[j]);
    }
    printf("%d]",tab[i]);
}

int main()
{
    init_flux(42);
    int vmin = 0;
    int vmax = 1000000;
    int *flux_range = malloc(sizeof(int)*N);
    int nv;
    int maxn = 200000;
    heapmax petit = make_heapmax(maxn);
    heap grand = make_heap(maxn);
    for (int i=0;i<maxn;i++)
    {
        nv = lire_flux(vmin, vmax);
        insere(flux_range,i,nv);
        //printf("Valeur  = %d - Flux rangé", nv);
        //affiche(flux_range,i);
        //printf(" | sort : %f ", mediane(flux_range,i));
        if (petit.size==grand.size)
        {
            insert_heap(nv, &grand);
            insert_heapmax(getmin(&grand), &petit);
            //printf("| heap : %f\n", (float)petit.array[0]);
        }
        else
        {
            insert_heapmax(nv, &petit);
            insert_heap(getmax(&petit), &grand);
            //printf("| heap : %f\n", ((float)petit.array[0]+(float)(grand.array[0]))/2.0);
        }
        
    }
    printf(" Flux rangé -> %f\n", mediane(flux_range,maxn-1));
    if (petit.size!=grand.size)
    {
        printf(" Deux tas -> %f\n", (float)petit.array[0]);
    }
    else
    {
        printf(" Deux tas -> %f\n", ((float)petit.array[0]+(float)(grand.array[0]))/2.0);
    }
    free(flux_range);
    return 0;
}