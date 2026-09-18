#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 26
#define SIZE 200000

struct node
{
    char word[26];
    int occ;
    struct node *next;
};
typedef struct node node;
typedef node* list;

unsigned hahsword(char  word[26])
{
    unsigned hash = 0;
    char c;
    int i=0;
    while ((c=word[i])!='\0')
    {
        hash += c;
        i++;
    }
    return hash;
}

bool is_in_list(list l, char w[26])
{
    while (l != NULL)
    {
        if (strcmp(l->word,w)==0)
            return true;
        l = l->next;
    }
    return false;
}

int get_occ_list(list l, char w[26])
{
     while (l != NULL)
    {
        if (strcmp(l->word,w)==0)
            {return l->occ;}
        l = l->next;
    }
    return 0;
}



void insert_in_list(list *l, char w[26])
{
    node *new_node = malloc(sizeof(node));
    strcpy(new_node->word,w);
    new_node->occ = 1;
    new_node->next = *l;
    *l = new_node;
}

void update_list(list *l, char*w, int v)
{
    list current = *l;
    while (current!=NULL && strcmp(current->word,w)!=0)
    {
        current = current->next;
    }
    current->occ = v;
}

int list_size(list l)
{
    int size = 0;
    while (l!=NULL)
    {
        size++;
        l = l ->next;
    }
    return size;
}

void view_list(node *l)
{
    printf("-> ");
    while (l != NULL)
    {
        printf("%s,%u -> ", l->word,l->occ);
        l = l->next;
    }
    printf("\n");
}

void print_all_list(node *l,int seuil)
{
    while (l != NULL)
    {
        if (strlen(l->word)>3 && l->occ > seuil)
        {printf("%s,%u \n", l->word,l->occ);}
        l = l->next;
    }

}

void view_hashtable(list hastable[SIZE])
{
    int tm = 0;
    for (int i = 0; i < SIZE; i++)
    {
        tm += list_size(hastable[i]);
        printf("Bucket %d de taille %d\n",i,list_size(hastable[i]));
        //view_list(hastable[i]);
    }
}

void print_all(list hastable[SIZE],int seuil)
{
    for (int i = 0; i < SIZE; i++)
    {
        print_all_list(hastable[i],seuil);
        //view_list(hastable[i]);
    }
}

bool is_in_hashtable(list hashtable[SIZE], char w[26])
{
    int bucket_number = hahsword(w)%SIZE;
    return is_in_list(hashtable[bucket_number], w);
}

void insert_in_hashtable(list hashtable[SIZE], char w[26])
{
    int bucket_number = hahsword(w)%SIZE;
    insert_in_list(&hashtable[bucket_number], w);
}

void update_hashtable(list hashtable[SIZE], char w[26], int n)
{
    int bucket_number = hahsword(w)%SIZE;
    update_list(&hashtable[bucket_number],w,n);
}

int get_val_hashtable(list hastable[SIZE], char w[26])
{
    int bucket_number = hahsword(w)%SIZE;
    return get_occ_list(hastable[bucket_number],w);
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

void stats(list hashtable[SIZE])
{
    int empty = 0;
    int collision = 0;
    int ll[100];
    for (int i=0;i<100;i++)
    {
        ll[i] = 0;
    }
    for (int i=0;i<SIZE;i++)
    {
        ll[list_size(hashtable[i])]++;
        if (list_size(hashtable[i])==0)
        {
            empty++;
        }
        if (list_size(hashtable[i])>1)
        {
            collision+=list_size(hashtable[i])-1;
        }
    }
    printf("Nombre d'alvéoles vides : %d\n",empty);
    printf("Nombre de collisions : %d\n",collision);
    for (int i=0;i<10;i++)
    {
        printf("Nombre de seaux de longueur %d : %d\n",i,ll[i]);
    }
}
void destroy_hash_table(list hashtable[SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        destroy_linked_list(hashtable[i]);
    }
}

char* get_word(FILE * reader)
{
    char *word = malloc(sizeof(char)*MAX_SIZE);
    if (fscanf(reader,"%s",word)==1)
        {return word;}
    else
        {
        free(word);
        return NULL;}
}



int main()
{
    char *word;
    int old_occ;
    int wc = 0;
    FILE* reader = fopen("mots.txt","r");
    node **dict = malloc(sizeof(list)*SIZE);
    for (int i = 0; i < SIZE; i++)
        {
        dict[i] = NULL;
        }
    while ((word=get_word(reader))!=NULL)
    {
    if (is_in_hashtable(dict,word))
    {old_occ = get_val_hashtable(dict,word);
     update_hashtable(dict,word,old_occ+1);}
    else
    {insert_in_hashtable(dict,word);
    wc++;}
    free(word);
    }
    printf("Nombre total de mots : %d\n",wc);
    stats(dict);
    printf("Nautilus : %d\n",get_val_hashtable(dict,"nautilus"));
    destroy_hash_table(dict);
    free(dict);
    fclose(reader);
}