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

void display_heap(heap mh)
{
    int newline = 1;
    for (int i=0;i<mh.size;i++)
    {
        printf("%d ",mh.tab[i]);
        if (i==newline-1)
        {
            printf("\n");
            newline= newline*2+1;
        }

    }
    printf("\n");
}

void shuffle(int tab[], int size)
{
    for (int i=1;i<size;i++)
    {
        swap(tab,rand()%i,i);
    }
}

int main()
{
    int s = 100000000;
    int *v = malloc(sizeof(int)*s);
    int *sorted = malloc(sizeof(int)*s);
    float st, et;
    srand(time(NULL));
    for (int i=0;i<s;i++)
    {
        v[i] = i;
    }
    shuffle(v,s);
    st = (float)clock()/CLOCKS_PER_SEC;
    heap mh = make_heap(s);
    for (int i=0;i<s;i++)
    {
        insert_heap(v[i],&mh);
    }
    for (int i=0;i<s;i++)
    {
        sorted[i] = getmin(&mh);
    }
    et = (float)clock()/CLOCKS_PER_SEC;
    printf("Terminé en %f !\n",et-st);
}