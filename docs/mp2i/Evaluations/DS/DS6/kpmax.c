#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct heap
{
    int size;
    int capacity;
    int *tab;
};
typedef struct heap heap;


int son(int i)
{
    int s = 2*i+1;
    return s;
}

int father(int i)
{
    if (i==0)  {return -1;}
     else
    {return (i-1)/2;};
}


void swap(int *tab, int i, int j)
{
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

heap make_heap(int cap)
{
    int * t = malloc(sizeof(int)*cap);
    heap mh;
    mh.size = 0;
    mh.capacity = cap;
    mh.tab = t;
    return mh;
}

bool insert_heap(int nv, heap* mh)
{
    int cp = mh->size;
    if (mh->size==mh->capacity)
    { return false;}
    else
    {
        mh->tab[cp] = nv;
        while (father(cp)!=-1 && mh->tab[cp]<mh->tab[father(cp)])
        {
            swap(mh->tab,cp,father(cp));
            cp = father(cp);
        }
        mh->size = mh->size+1;
    }
}

int getmin(heap * mh)
{
    if (mh->size>0){
    int mv = mh->tab[0];
    int cp = 0;
    int leftson =1;
    mh->tab[0] = mh->tab[mh->size-1];
    while (leftson<mh->size)
    {
        if (leftson+1==mh->size || mh->tab[leftson]<mh->tab[leftson+1])
        {
            swap(mh->tab,cp,leftson);
            cp = leftson;
        }
        else
        {
            swap(mh->tab,cp,leftson+1);
            cp = leftson+1;
        }
        leftson = son(cp);
    }
    mh->size = mh->size-1;
    return mv;
    }
}

int* kmax_heap(int t[], int n, int k)
{
    heap mh = make_heap(k);
    int *mk = malloc(sizeof(int)*k);
    int temp;
    for (int i=0;i<k;i++)
    {
        insert_heap(t[i],&mh);
    }
    for (int i=k;i<n;i++)
    {
        if (t[i]>mh.tab[0])
        {
            temp = getmin(&mh);
            insert_heap(t[i],&mh);
        }
    }
    for (int i=0;i<k;i++)
    {
        mk[i] = mh.tab[i];
    }
    return mk;
}

int main()
{
    int test[] = {12, 5, 4, 18, 22, 2, 3, 9, 19, 10};
    int *km = kmax_heap(test,10,4);
    for (int i=0;i<4;i++)
    {
        printf("%d ", km[i]);
    }
    printf("\n");
}