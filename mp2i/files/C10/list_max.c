#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int value;
    struct node *next;
};
typedef struct node node;
typedef node *list;

void insert(list *l, int v)
{
    node *n = malloc(sizeof(node));
    n->value = v;
    n->next = *l;
    *l = n;
}

void view(list l)
{
    printf("-> ");
    while (l != NULL)
    {
        printf("%d ->", l->value);
        l = l->next;
    }
    printf("\n");
}

void destroy(list *l)
{
    node *current = *l;
    node *save;
    while (current != NULL)
    {
        save = current->next;
        free(current);
        current = save;
    }
    *l = NULL;
}

void delete(list *l, int v)
{
    node *current = *l;
    node *prec = NULL;
    while (current != NULL && current->value != v)
    {
        prec = current;
        current = current->next;
        
    }
    if (current != NULL)
    {
        if (prec != NULL)
        {
            prec->next = current->next;
        }
        else
        {
            *l = current->next;
        }
        free(current);
    }
}

int main()
{
    list l = NULL;
    view(l);
    for (int i = 0; i < 10; i++)
    {
        insert(&l, i);
    }
    view(l);
    delete(&l, 5);
    delete(&l,9);
    view(l);
    destroy(&l);
}