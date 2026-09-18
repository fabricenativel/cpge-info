#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 26
#define HT_SIZE 200000

#define FREE 0
#define OCCUPIED 1
#define DELETED 2

struct node
{
    char word[SIZE];
    struct node *next;
};
typedef struct node node;
typedef node *list;

struct item
{
    char key[26];
    list anagrammes;
    int status;
};
typedef struct item item;
typedef item *hashtable;

char *make_key(char *word)
{
    int n = strlen(word);
    char *key = malloc(sizeof(char) * n);
    char temp;
    int j;
    strcpy(key, word);
    for (int i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && key[j] < key[j - 1])
        {
            temp = key[j];
            key[j] = key[j - 1];
            key[j - 1] = temp;
            j = j - 1;
        }
    }
    return key;
}

unsigned hahsword(char *word)
{
    unsigned hash = 0;
    char c;
    int i = 0;
    while ((c = word[i]) != '\0')
    {
        hash += c;
        i++;
    }
    return hash % HT_SIZE;
}

bool is_in_list(list l, char *w)
{
    while (l != NULL)
    {
        if (strcmp(l->word, w) == 0)
            return true;
        l = l->next;
    }
    return false;
}

void insert_in_list(list *l, char *w)
{
    node *new_node = malloc(sizeof(node));
    strcpy(new_node->word, w);
    new_node->next = *l;
    *l = new_node;
}

void view_list(node *l)
{
    while (l != NULL)
    {
        printf("%s -> ", l->word);
        l = l->next;
    }
    printf("\n");
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

int list_size(list l)
{
    int s = 0;
    while (l != NULL)
    {
        s++;
        l = l->next;
    }
    return s;
}

char *get_word(FILE *reader)
{
    char *word = malloc(sizeof(char) * SIZE);
    if (fscanf(reader, "%s", word) == 1)
    {
        return word;
    }
    else
    {
        free(word);
        return NULL;
    }
}

int is_in(hashtable ht, char *key)
{
    int bucket = hahsword(key);
    while (ht[bucket].status != FREE)
    {
        if (strcmp(key, ht[bucket].key) == 0)
        {
            return bucket;
        }
        else
        {
            bucket = (bucket + 1) % HT_SIZE;
        }
    }
    return -1;
}

void view_hashtable(hashtable ht)
{
    for (int i = 0; i < HT_SIZE; i++)
    {
        if (ht[i].status == OCCUPIED && list_size(ht[i].anagrammes)>1)
        {
            printf("[%u] (%s) :  ", i, ht[i].key);
            view_list(ht[i].anagrammes);
        }
    }
}

int main()
{
    char *word;
    char *key;
    int bn;
    char wk;
    FILE *reader = fopen("tmots.txt", "r");
    hashtable ht = malloc(sizeof(item) * HT_SIZE);
    for (int i = 0; i < HT_SIZE; i++)
    {
        ht[i].key[0] = '\0';
        ht[i].anagrammes = NULL;
        ht[i].status = FREE;
    }
    while ((word=get_word(reader))!=NULL)
    {
        key = make_key(word);
        bn = is_in(ht, key);
        if (bn == -1)
        {
            bn = hahsword(key);
            strcpy(ht[bn].key, key);
            ht[bn].status = OCCUPIED;
        }
        if (!is_in_list(ht[bn].anagrammes, word))
        {
            insert_in_list(&ht[bn].anagrammes, word);
        }
    }
    view_hashtable(ht);
    fclose(reader);
}