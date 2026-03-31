#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 100000
#define STRINGSIZE 26

#define FREE 0
#define OCCUPIED 1
#define DELETED 2

struct slot_s
{
    char key[STRINGSIZE];
    int value;
    int status;
};
typedef struct slot_s slot;

struct hashtable_s
{
    slot *data;
    int full;
};
typedef struct hashtable_s hashtable;

unsigned hahsword(char word[26])
{
    unsigned hash = 0;
    char c;
    int i = 0;
    while ((c = word[i]) != '\0')
    {
        hash += c;
        i++;
    }
    return hash%SIZE;
}

hashtable make_hashtable()
{
    hashtable ht;
    ht.data = malloc(sizeof(slot) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        ht.data[i].status = FREE;
    }
    return ht;
}

void view_ht(hashtable ht)
{
    for (int i=0;i<SIZE;i++)
    {
        if (ht.data[i].status == OCCUPIED)
        {
            printf("|%d | %s | %d | \n",i,ht.data[i].key, ht.data[i].value);
        }
        else
        {
            printf("|%d | x | x | \n",i);
        }
    }
    
}

bool add(hashtable *ht, char k[STRINGSIZE], int v)
{
    if (ht->full == SIZE)
    {
        return false;
    }
    int bnum = hahsword(k);
    while (ht->data[bnum].status == OCCUPIED)
    {
        bnum = (bnum+ 1) % SIZE;

    }
    for (int i = 0; i < STRINGSIZE; i++)
    {
        ht->data[bnum].key[i] = k[i];
    }
    ht->data[bnum].value = v;
    ht->data[bnum].status = OCCUPIED;
    ht->full++;
    return true;
}


bool is_in(hashtable ht, char k[STRINGSIZE])
{
    int bnum = hahsword(k);
    while (ht.data[bnum].status != FREE)
    {
        if (strcmp(k,ht.data[bnum].key)==0)
        {
            return true;
        }
        bnum = (bnum + 1) % SIZE;
    }
    return false;
}

int get_val(hashtable ht, char k[STRINGSIZE])
{
    int bnum = hahsword(k);
    while (ht.data[bnum].status != FREE)
    {
        if (strcmp(k,ht.data[bnum].key)==0)
        {
            return ht.data[bnum].value;
        }
        bnum = (bnum + 1) % SIZE;
    }
    return -1;
}

void update(hashtable ht, char k[STRINGSIZE], int nv)
{
    int bnum = hahsword(k);
    while (ht.data[bnum].status != FREE)
    {
        if (strcmp(k,ht.data[bnum].key)==0)
        {
            ht.data[bnum].value = nv;
        }
        bnum = (bnum + 1) % SIZE;
    }
}

char *get_word(FILE *reader)
{
    char *word = malloc(sizeof(char) * STRINGSIZE);
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

int main()
{
    char *word;
    int old_occ;
    int wc = 0;
    FILE *reader = fopen("mots.txt", "r");
    hashtable dict = make_hashtable();
    while ((word = get_word(reader)) != NULL)
    {
        if (is_in(dict, word))
        {
            old_occ = get_val(dict, word);
            update(dict, word, old_occ + 1);
        }
        else
        {
            add(&dict, word, 1);
            wc++;
        }
        free(word);
    }
    printf("Nombre total de mots : %d\n", wc);
    char tw[26]="nautilus";
    printf("Nautilus : %d\n", get_val(dict, tw));
    fclose(reader);
}