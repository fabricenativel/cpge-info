#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define EMPTY 0
#define WALL 1
#define VISITED 2


// --8<-- [start:sd]
struct node_s
{
    int num; //l'index de la case dans le tableau linéarisé
    int dist;//le nombre de déplacements pour l'atteindre
    struct node_s *next;//pointeur vers le noeud suivant
};
typedef struct node_s node;
typedef node *lnode;
struct queue_s
{
    lnode start;
    lnode end;
};
typedef struct queue_s queue;
// --8<-- [end:sd]

// --8<-- [start:Q3]
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
// --8<-- [end:Q3]

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

// --8<-- [start:Q2]
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
    // Puis on lit les coordonnées du point de départ et d'arrivée
    fscanf(inputstream, "%d", &l);
    fscanf(inputstream, "%d", &c);
    *start = get_index(l, c, *width);
    fscanf(inputstream, "%d", &l);
    fscanf(inputstream, "%d", &c);
    *arrival = get_index(l, c, *width);
    int *map = malloc(sizeof(int) * *height * *width);
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
// --8<-- [end:Q2]

// --8<-- [start:Q4]
int solve(char* fname)
{
    const int DL[4] = {0, -1, 0, 1}; //Les 4 mouvements possibles
    const int DC[4] = {1, 0, -1, 0};
    int* map;
    int height, width, start, arrival;
    map = read_map(fname,&height, &width, &start, &arrival);
    queue q = create();
    if (map[start] != EMPTY)
    {
        return -1;
    }
    map[start] = VISITED;
    insert(&q, start, 0);
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
                if (tn==arrival)
                {
                    exitfound = true;
                }
            }
        }
    }
    free(map);
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
// --8<-- [end:Q4]


// --8<-- [start:Q4]
int* solve_path(char* fname, int *size)
{
    const int DL[4] = {0, -1, 0, 1}; //Les 4 mouvements possibles
    const int DC[4] = {1, 0, -1, 0};
    int* map;
    int height, width, start, arrival;
    map = read_map(fname,&height, &width, &start, &arrival);
    int *parent = malloc(sizeof(int)*width*height);
    queue q = create();
    if (map[start] != EMPTY)
    {
        *size = 0;
        return NULL;
    }
    map[start] = VISITED;
    insert(&q, start, 0);
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
                parent[tn] = cn.num;
                insert(&q, tn, cn.dist + 1);
                if (tn==arrival)
                {
                    exitfound = true;
                }
            }
        }
    }
    free(map);
    destroy(&q);
    if (exitfound)
    {
        *size = cn.dist+1;
        int *path = malloc(sizeof(int) * *size);
        int cnum = arrival;
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
        *size = 0;
        return NULL;
    }
}
// --8<-- [end:Q4]

int main(int argc, char* argv[])
{
    if (argc!=2)
    {
        printf("Utilisation : %s <fichier> \n",argv[0]);
        exit(1);
    }
    int r = solve(argv[1]);
    printf("Réponse = %d\n",r);
}