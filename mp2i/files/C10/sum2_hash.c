#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>

uint64_t

#define SIZE 100000
#define HASHTABLE_SIZE 200000

struct node
{
    int value;
    struct node *next;
};
typedef struct node node;
typedef node *list;


unsigned hash(int val)
{
    unsigned hash = (val + 10000000) % HASHTABLE_SIZE;
    return hash;
}

bool is_in_list(list l, int v)
{
    while (l != NULL)
    {
        if (l->value == v)
        {
            return true;
        }
        l = l->next;
    }
    return false;
}

void insert_in_list(list *l, int v)
{
    node *new_node = malloc(sizeof(node));
    new_node->value = v;
    new_node->next = *l;
    *l = new_node;
}

int list_size(list l)
{
    int size = 0;
    while (l != NULL)
    {
        size++;
        l = l->next;
    }
    return size;
}

void view_list(node *l)
{
    printf("-> ");
    while (l != NULL)
    {
        printf("%d -> ", l->value);
        l = l->next;
    }
    printf("\n");
}

void view_hashtable(list hastable[HASHTABLE_SIZE])
{
    int tm = 0;
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        tm += list_size(hastable[i]);
        printf("Bucket %d de taille %d\n", i, list_size(hastable[i]));
        // view_list(hastable[i]);
    }
}

bool is_in_hashtable(list hashtable[SIZE], int v)
{
    unsigned bucket_number = hash(v);
    return is_in_list(hashtable[bucket_number], v);
}

void insert_in_hashtable(list hashtable[SIZE], int v)
{
    unsigned bucket_number = hash(v);
    insert_in_list(&hashtable[bucket_number], v);
}

void destroy_linked_list(list l)
{
    while (l != NULL)
    {
        node *backup = l->next;
        free(l);
        l = backup;
    }
}

void make_ht(char filename[], list* hashtable)
{
    int num;
    FILE *reader = fopen(filename, "r");
    for (int i = 0; i < SIZE; i++)
    {
        fscanf(reader, "%d\n", &num);
        insert_in_hashtable(hashtable,num);
    }
}

void stats(list hashtable[HASHTABLE_SIZE])
{
    int empty = 0;
    int collision = 0;
    int ll[100];
    for (int i = 0; i < 100; i++)
    {
        ll[i] = 0;
    }
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        ll[list_size(hashtable[i])]++;
        if (list_size(hashtable[i]) == 0)
        {
            empty++;
        }
        if (list_size(hashtable[i]) > 1)
        {
            collision += list_size(hashtable[i]) - 1;
        }
    }
    printf("Nombre d'alvéoles vides : %d\n", empty);
    printf("Nombre de collisions : %d\n", collision);
    for (int i = 0; i < 10; i++)
    {
        printf("Nombre de seaux de longueur %d : %d\n", i, ll[i]);
    }
}
void destroy_hash_table(list hashtable[HASHTABLE_SIZE])
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        destroy_linked_list(hashtable[i]);
    }
}

int getsol(list *hashtable)
{
    list cl;
    for (int i = 0; i < HASHTABLE_SIZE - 1; i++)
    {
        cl = hashtable[i];
        while (cl != NULL)
        {
            if (is_in_hashtable(hashtable, 42 - (cl->value)))
            {
                return cl->value;
            }
            cl = cl->next;
        }
    }
    return 0;
}

int main()
{
    int sol;
    list *nums = malloc(sizeof(list) * HASHTABLE_SIZE);
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        nums[i] = NULL;
    }
    make_ht("numbers.txt",nums);
    sol = getsol(nums);
    printf("Solution : (%d,%d)\n", sol, 42 - sol);
    destroy_hash_table(nums);
    free(nums);
}