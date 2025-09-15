#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define EMPTY 0
#define WALL 1
#define VISITED 2

const int DL[4] = {0, -1, 0, 1};
const int DC[4] = {1, 0, -1, 0};

struct node_s
{
    int num;
    int dist;
    struct node_s *next;
};
typedef struct node_s node;
typedef node *lnode;
struct queue_s
{
    lnode start;
    lnode end;
};
typedef struct queue_s queue;

queue create()
{
    queue q = {.start = NULL, .end = NULL};
    return q;
}

bool is_empty(queue q)
{
    return q.start == NULL;
}

void insert(queue *q, int nodenum, int nodedist)
{
    // Ajout d'un noeud APRES le pointeur de fin
    node *new = malloc(sizeof(node));
    if (!new)
    {
        printf("Impossible d'allouer un espace mémoire suffisant \n");
        exit(-2);
    }
    new->num = nodenum;
    new->dist = nodedist;
    new->next = NULL;
    if (q->end)
    {
        q->end->next = new;
    }
    else
    {
        q->start = new;
    }
    q->end = new;
}

node extract(queue *q)
{
    // Retrait du noeud pointé par le pointeur de tête
    assert(q->start != NULL);
    node n;
    node *temp = q->start;
    n.num = q->start->num;
    n.dist = q->start->dist;
    q->start = q->start->next;
    if (!q->start)
    {
        q->end = NULL;
    }
    free(temp);
    return n;
}

void destroy(queue *q)
{
    node *temp;
    while (q->start)
    {
        temp = q->start;
        q->start = q->start->next;
        free(temp);
    }
}

// --8<-- [start:Q1]
int get_index(int l, int c, int width)
{
    return l * width + c;
}

void get_lc(int index, int *l, int *c, int width)
{
    *l = index / width;
    *c = index % width;
}
// --8<-- [end:Q1]

bool in_grid(int l, int c, int height, int width)
{
    return (l >= 0 && l < height && c >= 0 && c < width);
}

void view_node(node n)
{
    printf("(%d,%d)", n.num, n.dist);
}

void view_queue(queue q)
{
    node *p = q.start;
    while (p)
    {
        view_node(*p);
        printf("->");
        p = p->next;
    }
    printf("\n");
}

void view_map(int *map, int height, int width)
{
    int n;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            n = map[get_index(i, j, width)];
            if (n == EMPTY)
            {
                printf(".");
            }
            else if (n == WALL)
            {
                printf("@");
            }
            else
                printf("x");
        }
        printf("\n");
    }
}

int *read_map(char filename[], int *height, int *width, int *start, int *arrival)
{
    FILE *inputstream = fopen(filename, "r");
    int l, c;
    if (!inputstream)
    {
        printf("Fichier non trouvé !\n");
        exit(-1);
    }
    // Les dimensions sont sur les deux premieres lignes
    fscanf(inputstream, "%d", height);
    fscanf(inputstream, "%d", width);
    printf("(%d,%d)\n",*height,*width);
    // Puis on lit les coordonnées du point de départ et d'arrivée
    fscanf(inputstream, "%d", &l);
    fscanf(inputstream, "%d", &c);
    *start = get_index(l, c, *width);
    fscanf(inputstream, "%d", &l);
    fscanf(inputstream, "%d", &c);
    *arrival = get_index(l, c, *width);
    int *map = malloc(sizeof(int) * *height * *width);
    if (!map)
    {
        printf("Impossible d'allouer un espace mémoire suffisant \n");
        exit(-2);
    }
    char cc;
    fgetc(inputstream);
    for (int l = 0; l < *height; l++)
    {
        for (int c = 0; c < *width; c++)
        {
            cc = fgetc(inputstream);
            if (cc == '@')
            {
                map[get_index(l,c,*width)] = WALL;
            }
            else if (cc == '.')
            {
                map[get_index(l,c,*width)] = EMPTY;
            }
            else
            {
                printf("Caractère inconnu dans le fichier \n");
            }
        }
        fgetc(inputstream);
    }
    fclose(inputstream);
    return map;
}

int solve(int *map, int sl, int sc, int el, int ec, int height, int width)
{
    queue q = create();
    int sn = get_index(sl, sc, width);
    if (map[sn] != EMPTY)
    {
        return -1;
    }
    map[sn] = VISITED;
    insert(&q, sn, 0);
    bool exitfound = false;
    node cn;
    int cl, cc;
    int tl, tc, tn;
    while (!is_empty(q) && !exitfound)
    {
        cn = extract(&q);
        get_lc(cn.num, &cl, &cc,width);
        for (int i = 0; i < 4; i++)
        {
            tl = cl + DL[i];
            tc = cc + DC[i];
            tn = get_index(tl, tc, width);
            if (in_grid(tl, tc, height, width) && map[tn] == EMPTY)
            {
                map[tn] = VISITED;
                insert(&q, tn, cn.dist + 1);
                if (tl == el && tc == ec)
                {
                    exitfound = true;
                }
            }
        }
    }
    destroy(&q);
    if (exitfound)
    {
        return cn.dist + 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int h, w, d, a;
    int *map = read_map("minilaby.txt", &h, &w, &d, &a);
    // int r = solve(map,107,485,33,32);
    free(map);
}