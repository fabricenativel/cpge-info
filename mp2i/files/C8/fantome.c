#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// --8<-- [start:struct]
struct list_s
{
    int value;
    struct list_s * next;
};
typedef struct list_s list;
// --8<-- [end:struct]

list make_list()
{
    list * first = malloc(sizeof(list));
    first->next = NULL;
    return *first;
}

void add(list *l, int v)
{
    list * new = malloc(sizeof(list));
    new->value = v;
    new->next = l->next;
    l->next = new;
}

int del(list *l)
{
    int r = l->next->value;
    list* temp = l->next;
    l->next = temp->next;
    free(temp);
    return r;
}

void view(list l)
{
    printf("(X) - >");
    list *m = l.next;
    while (m!=NULL)
    {   
        printf("%d -> ",m->value);
        m = m->next;
    }
    printf(" NULL \n");
}

int main()
{
    list l  = make_list();
    add(&l, 12);
    add(&l,15);
    view(l);
    del(&l);
    view(l);
    del(&l);
    view(l);
}