#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>

#define CODESIZE 128

// --8<-- [start:type]
struct node_s
{
    unsigned char car; 
    int prio;
    struct node_s *sag;
    struct node_s *sad;
};
typedef struct node_s node;
typedef node *abh;
// --8<-- [end:type]

// --8<-- [start:heap]
struct heap_s
{
    int size;
    abh *data;
};
typedef struct heap_s heap;
// --8<-- [end:heap]


int son(int i)
{
    int s = 2 * i + 1;
    return s;
}

int father(int i)
{
    if (i == 0)
    {
        return -1;
    }
    else
    {
        return (i - 1) / 2;
    };
}

void swap(abh *data, int i, int j)
{
    abh temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

// --8<-- [start:make_heap]
heap make_heap(void)
{
    heap mh;
    mh.size = 0;
    mh.data = malloc(sizeof(abh) * CODESIZE);
    return mh;
}
// --8<-- [end:make_heap]

// --8<-- [start:insert_heap]
bool insert_heap(abh nv, heap *mh)
{
    int cp = mh->size;
    if (mh->size == CODESIZE)
    {
        return false;
    }
    else
    {
        mh->data[cp] = nv;
        while (cp != 0 && mh->data[cp]->prio < mh->data[father(cp)]->prio)
        {
            swap(mh->data, cp, father(cp));
            cp = father(cp);
        }
        mh->size = mh->size + 1;
        return true;
    }
}
// --8<-- [end:insert_heap]

// --8<-- [start:getmin]
abh getmin(heap *mh)
{
    if (mh->size > 0)
    {
        abh mv = mh->data[0];
        int cp = 0;
        int leftson = 1;
        mh->data[0] = mh->data[mh->size - 1];
        mh->size = mh->size - 1;
        while (leftson + 1 < mh->size && (mh->data[leftson + 1]->prio < mh->data[cp]->prio || mh->data[leftson]->prio < mh->data[cp]->prio))
        {
            if (mh->data[leftson]->prio < mh->data[leftson + 1]->prio)
            {
                swap(mh->data, cp, leftson);
                cp = leftson;
            }
            else
            {
                swap(mh->data, cp, leftson + 1);
                cp = leftson + 1;
            }
            leftson = son(cp);
        }
        if ((leftson < mh->size) && (mh->data[leftson]->prio < mh->data[cp]->prio))
        {
            swap(mh->data, cp, leftson);
        }
        return mv;
    }
    return NULL;
}
// --8<-- [end:getmin]

int *frequence(char *texte)
{
    // renvoie la fréquence d'apparition de chaque caractère dans texte
    int *fq = malloc(sizeof(uint32_t) * CODESIZE);
    int idx = 0;
    for (int i = 0; i < CODESIZE; i++)
    {
        fq[i] = 0;
    }
    while (texte[idx] != '\0')
    {
        fq[(uint8_t)texte[idx]]++;
        idx++;
    }
    return fq;
}

// --8<-- [start:make_leaf]
abh make_leaf(char c, int p)
{
    node *h = malloc(sizeof(node));
    h->car = c;
    h->prio = p;
    h->sag = NULL;
    h->sad = NULL;
    return h;
}
// --8<-- [end:make_leaf]

// --8<-- [start:make_tree]
abh make_tree(abh g, abh d)
{
    node *h = malloc(sizeof(node));
    h->car = '\0';
    h->prio = g->prio + d->prio;
    h->sag = g;
    h->sad = d;
    return h;
}
// --8<-- [end:make_tree]

// --8<-- [start:view]
bool is_leaf(abh g)
{
    return (g->sag == NULL && g->sad == NULL);
}

void write_nodes(FILE *writer, abh g)
{
    const char *nstyle = "[shape=point, width=0.05, height=0.05 xlabel=\"%d\"]\n";
    const char *fstyle = "[shape=circle, style=filled, fillcolor=lightblue, label=\"%c\" xlabel=\"%d\"]\n";
    const char *gstyle = "[shape=circle, style=filled, fillcolor=lightblue, label=\"\\\"\" xlabel=\"%d\"]\n";
    if (is_leaf(g))
    {
        fprintf(writer, "F%u ", (uint8_t)g->car);
        if (g->car == '"')
        {
            fprintf(writer,gstyle, g->prio);
        }
        else
        {
            fprintf(writer, fstyle, g->car, g->prio);
        }
    }
    else
    {
        fprintf(writer, "N%u ", (uint8_t)g->car);
        fprintf(writer, nstyle, g->prio);
        write_nodes(writer, g->sag);
        write_nodes(writer, g->sad);
    }
}

void make_edge(FILE *writer, node n1, node n2)
{
    if ((uint8_t)n1.car < CODESIZE)
    {
        fprintf(writer, "F%u ->", (uint8_t)n1.car);
    }
    else
    {
        fprintf(writer, "N%d -> ", (uint8_t)n1.car);
    }
    if ((uint8_t)n2.car < CODESIZE)
    {
        fprintf(writer, "F%u\n", (uint8_t)n2.car);
    }
    else
    {
        fprintf(writer, "N%d\n", (uint8_t)n2.car);
    }
}

void write_edges(FILE *writer, abh g)
{
    if (!is_leaf(g))
    {
        make_edge(writer, *g, *(g->sag));
        make_edge(writer, *g, *(g->sad));
        write_edges(writer, g->sag);
        write_edges(writer, g->sad);
    }
}

void view(abh g)
{
    FILE *writer = fopen("temp.gv", "w");
    fprintf(writer, "digraph huffmann {\n");
    write_nodes(writer, g);
    write_edges(writer, g);
    fprintf(writer, "}\n");
    fclose(writer);
    system("xdot temp.gv &");
}
// --8<-- [end:view]

// --8<-- [start:init_heap]
heap init_heap(char *texte)
{
    int *freq = frequence(texte);
    heap mh = make_heap();
    for (int i = 32; i < CODESIZE; i++)
    {
        if (freq[i] != 0)
        {
            insert_heap(make_leaf((char)i, freq[i]), &mh);
        }
    }
    return mh;
}
// --8<-- [end:init_heap]

// --8<-- [start:make_huffman]
abh make_huffman(heap *mh)
{
    abh g, d, new;
    new = malloc(sizeof(abh));
    uint8_t node_indx = CODESIZE + 1;
    while (mh->size != 1)
    {
        g = getmin(mh);
        d = getmin(mh);
        new->car = node_indx;
        node_indx++;
        new = make_tree(g, d);
        insert_heap(new, mh);
    }
    g = getmin(mh);
    g->car = node_indx;
    return g;
}
// --8<-- [end:make_huffman]

char *read_file(char *fname)
{
    FILE *reader = fopen(fname, "r");
    if (reader == NULL)
    {
        printf("Fichier non trouvé !");
        return "";
    }
    else
    {
        fseek(reader, 0, SEEK_END);
        int l = ftell(reader);
        rewind(reader);
        char *content = malloc(sizeof(char) * l);
        for (int i = 0; i < l; i++)
        {
            content[i] = fgetc(reader);
        }
        return content;
    }
}

void rec_code(abh mh, char* current, char ** code)
{
    int n = strlen(current);
    if (is_leaf(mh))
    {
        code[(uint8_t)(mh->car)] = malloc(sizeof(char)*(n+1));
        strcpy(code[(uint8_t)(mh->car)], current);
        printf("Code pour %c = %s\n",mh->car,code[(uint8_t)(mh->car)]);
    }
    else
    {
        char *cg = malloc(sizeof(char)*(n+2));
        char *cd = malloc(sizeof(char)*(n+2));
        strcpy(cg, current);
        strcpy(cd, current);
        strcat(cg,"0");
        strcat(cd,"1");
        rec_code(mh->sag,cg, code);
        rec_code(mh->sad,cd, code);
    }
}

char ** make_code(abh mh)
{
    char** res = malloc(sizeof(char*)*CODESIZE);
    rec_code(mh,"",res);
    return res;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Utilisation : %s <filename>\n", argv[0]);
        exit(1);
    }
    char *text = read_file(argv[1]);
    heap th = init_heap(text);
    abh huffman = make_huffman(&th);
    view(huffman);
    char **code = make_code(huffman);
    exit(0);
}