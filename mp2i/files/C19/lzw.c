#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define CODESIZE 16
#define HTSIZE 262144
#define MAGIC 31

struct node_s
{
    char *str;
    int code;
    struct node_s *next;
};
typedef struct node_s node;
typedef node *lst;
typedef lst* hashtable;

uint64_t hash(char *s)
{
    uint64_t hv = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        hv = hv * 31 + (uint8_t)(s[i]);
    }
    return hv;
}

bool add_str(lst *l, char *s, int c)
{
    // Ajoute une chaine et son code à une liste chainée.
    int n = strlen(s);
    node *new = malloc(sizeof(node));
    char *v = malloc(sizeof(char) * (n + 1));
    if (new == NULL || v == NULL)
    {
        return false;
    }
    strcpy(v, s);
    new->str = v;
    new->code = c;
    new->next = *l;
    (*l) = new;
    return true;
}

bool remove_str(lst *l, char *s)
{
    lst previous = NULL;
    lst current = *l;
    while (current != NULL && strcmp(current->str, s) != 0)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        return false;
    }
    if (previous == NULL)
    {
        *l = (*l)->next;
    }
    else
    {
        previous->next = current->next;
    }
    free(current->str);
    free(current);
    return true;
}

void view_lst(lst l)
{
    while (l != NULL)
    {
        printf("(%s : %d) -> ", l->str, l->code);
        l = l->next;
    }
    printf(" NULL \n");
}

hashtable make_hashtable(int htsize)
{
    hashtable ht = malloc(sizeof(lst*)*htsize);
    if (ht==NULL)
    {
        exit(1);
    }
    return ht;
}

bool insert_hashtable(hashtable ht, char* s, int c)
{
    int idx = hash(s) % HTSIZE;
}

int main()
{
    lst l = NULL;
    add_str(&l, "toto", 42);
    add_str(&l, "x", 2);
    add_str(&l, "ttt", 10);
    add_str(&l, "z", 28);
    view_lst(l);
    remove_str(&l, "z");
    remove_str(&l, "toto");
    view_lst(l);
}