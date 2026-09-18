#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct node_s
{
    int value;
    struct node_s *next;
};
typedef struct node_s node;

struct list_s
{
    int size;
    node* access;
};
typedef struct list_s list;

void add(list* l, int v)
{
    //Insère un élément dans la liste en la gardant rangée
    node *nn = malloc(sizeof(node));
    int temp;
    node * pl;
    assert (nn!=NULL);
    nn->value = v;
    nn->next = l->access;
    l->size += 1;
    l->access = nn;
    pl = l->access;
    while (pl->next!=NULL && pl->value > pl->next->value)
    {
        temp = pl->value;
        pl->value = pl->next->value;
        pl->next->value=temp;
        pl = pl->next;
    }
}

void view(list l)
{
    printf("(%d) : -> ", l.size);
    while (l.access!=NULL)
    {
        printf("%d -> ",l.access->value);
        l.access = l.access->next;
    }
    printf("NULL \n");
}

int main()
{
    list ml;
    ml.size = 0;
    ml.access = NULL;
    view(ml);
    add(&ml, 12);
    add(&ml, 25);
    add(&ml, 17);
    add(&ml, 3);
    add(&ml, 42);
    add(&ml, 14);
    view(ml);
}

