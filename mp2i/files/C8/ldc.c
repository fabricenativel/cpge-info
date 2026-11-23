#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node_s
{
    int value;
    struct node_s *previous;
    struct node_s *next;
};
typedef struct node_s node;
struct dll_s
{
    node *first;
    node *last;
};
typedef struct dll_s dll;

void appendleft(dll *lst, int value)
{
    node *new = malloc(sizeof(node));
    new->value = value;
    new->previous = NULL;
    if ((*lst).first != NULL)
    {
        (*lst).first->previous = new;
        new->next = (*lst).first;
    }
    else
    {
        new->next = NULL;
        (*lst).last = new;
    }
    (*lst).first = new;
}

void appendright(dll *lst, int value)
{
    node *new = malloc(sizeof(node));
    new->value = value;
    new->next = NULL;
    if ((*lst).last != NULL)
    {
        (*lst).last->next = new;
        new->previous = (*lst).last;
    }
    else
    {
        new->previous = NULL;
        (*lst).first = new;
    }
    (*lst).last = new;
}

void view(dll lst)
{
    printf("NULL <-> ");
    while (lst.first != NULL)
    {
        printf("%d <-> ", lst.first->value);
        lst.first = lst.first->next;
    }
    printf("NULL \n");
}

int main()
{
    dll l;
    l.first = NULL;
    l.last = NULL;
    appendleft(&l, 12);
    appendleft(&l, 21);
    appendleft(&l, 42);
    view(l);
    appendright(&l, 6);
    appendright(&l, 11);
    appendleft(&l, 53);
        view(l);

}