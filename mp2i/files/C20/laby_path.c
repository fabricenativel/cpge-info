#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define FILEPATH "./biglaby.txt"
#define WIDTH 512
#define HEIGHT 512
#define EMPTY 0
#define WALL 1
#define VISITED 2
#define ROOT -1

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

int get_nodenum(int l, int c)
{
    return l * WIDTH + c;
}

void node_lc(int num, int *l, int *c)
{
    *l = num / WIDTH;
    *c = num % WIDTH;
}

bool in_grid(int l, int c)
{
    return (l >= 0 && l < HEIGHT && c >= 0 && c < WIDTH);
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

void view_map(int *map)
{
    int n;
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            n = map[get_nodenum(i, j)];
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

int *read_map(char path[], int w, int h)
{
    FILE *inputstream = fopen(path, "r");
    if (!inputstream)
    {
        printf("Fichier non trouvé !\n");
        exit(-1);
    }
    int *map = malloc(sizeof(int) * w * h);
    if (!map)
    {
        printf("Impossible d'allouer un espace mémoire suffisant \n");
        exit(-2);
    }
    char cc;
    for (int l = 0; l < h; l++)
    {
        for (int c = 0; c < w; c++)
        {
            cc = fgetc(inputstream);
            if (cc == '@')
            {
                map[l * w + c] = WALL;
            }
            else if (cc == '.')
            {
                map[l * w + c] = EMPTY;
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

int *solve(int *map, int sl, int sc, int el, int ec)
{
    int *parent = malloc(sizeof(int) * WIDTH * HEIGHT);
    queue q = create();
    int sn = get_nodenum(sl, sc);
    if (map[sn] != EMPTY)
    {
        return NULL;
    }
    map[sn] = VISITED;
    parent[sn] = -1; //La case d'origine n'a pas de parent
    insert(&q, sn, 0);
    bool exitfound = false;
    node cn;
    int cl, cc;
    int tl, tc, tn;
    while (!is_empty(q) && !exitfound)
    {
        cn = extract(&q);
        node_lc(cn.num, &cl, &cc);
        for (int i = 0; i < 4; i++)
        {
            tl = cl + DL[i];
            tc = cc + DC[i];
            tn = get_nodenum(tl, tc);
            if (in_grid(tl, tc) && map[tn] == EMPTY)
            {
                map[tn] = VISITED;
                parent[tn] = cn.num;
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
        int *path = malloc(sizeof(int) * (cn.dist + 1));
        int cnum = get_nodenum(el, ec);
        for (int i = cn.dist; i >= 0; i--)
        {
            path[i] = parent[cnum];
            cnum = parent[cnum];
        }
        free(parent);
        return path;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    int *map = read_map(FILEPATH, HEIGHT, WIDTH);
    // int r = solve(map,107,485,33,32);
    int *r = solve(map, 1, 419, 373, 490);
    int l,c;
    for (int i=0;i<10;i++)
    {
        node_lc(r[i],&l,&c);
        printf("(%d,%d)->",l,c);
    }
    printf("\n");
    free(map);
    if (r)
    {free(r);}
}