#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define SIZE 37
#define PBPATH "./solitaire/"
#define HASHTABLE_SIZE 50000000

const int COL_START[7] = {2, 1, 0, 0, 0, 1, 2};
const int COL_END[7] = {4, 5, 6, 6, 6, 5, 4};
const int ML[4] = {0, -1, 0, 1};
const int MC[4] = {1, 0, -1, 0};

struct move
{
    int sl;
    int sc;
    int dir;
};
typedef struct move move;
struct moves
{
    move m[100];
    int s;
};
typedef struct moves moves;

struct node
{
    uint64_t value;
    struct node *next;
};
typedef struct node node;
typedef node *llist;

struct game
{
    bool state[7][7];
    uint64_t end;
    move history[100];
    int step;
    int stone;
    int ends;
    int exp;
};
typedef struct game game;

bool is_in_list(node *linked_list, uint64_t val)
{
    while (linked_list != NULL)
    {
        if (linked_list->value == val)
            return true;
        linked_list = linked_list->next;
    }
    return false;
}

void insert_in_list(node **linked_list, uint64_t val)
{
    node *new_node = malloc(sizeof(node));
    new_node->value = val;
    new_node->next = *linked_list;
    *linked_list = new_node;
}

void view_list(node *linked_list)
{
    printf("-> ");
    while (linked_list != NULL)
    {
        printf("%ld -> ", linked_list->value);
        linked_list = linked_list->next;
    }
    printf("\n");
}

int get_hash(uint64_t value)
{
    return (int)(value % HASHTABLE_SIZE);
}

void view_hashtable(node **hastable)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        printf("Bucket %i : ", i);
        view_list(hastable[i]);
    }
}

bool is_in_hashtable(node **hashtable, uint64_t val)
{
    int bucket_number = get_hash(val);
    return is_in_list(hashtable[bucket_number], val);
}

void insert_in_hashtable(node **hashtable, uint64_t val)
{
    int bucket_number = get_hash(val);
    insert_in_list(&hashtable[bucket_number], val);
}

void destroy_linked_list(node *list)
{
    while (list != NULL)
    {
        node *backup = list->next;
        free(list);
        list = backup;
    }
}

void destroy_hash_table(node **hashtable)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        destroy_linked_list(hashtable[i]);
    }
}

bool ingrid(int l, int c)
{
    return (l >= 0 && l < 7 && c >= COL_START[l] && c <= COL_END[l]);
}

uint64_t hashboard(bool board[7][7])
{
    uint64_t h = 0;
    int p = 0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = COL_START[i]; j <= COL_END[i]; j++)
        {
            if (board[i][j])
            {
                h += ((uint64_t)1 << p);
            }
            p++;
        }
    }
    return h;
}

void unhash(uint64_t h, bool board[7][7])
{
    int p = 0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = COL_START[i]; j <= COL_END[i]; j++)
        {
            board[i][j] = h & ((uint64_t)1 << p);
            p++;
        }
    }
}

// Make game from file
game makepb(char filename[])
{
    game thegame;
    char startname[100] = PBPATH;
    char endname[100] = PBPATH;
    bool endboard[7][7];
    strcat(startname, filename);
    strcat(startname, "I.txt");
    strcat(endname, filename);
    strcat(endname, "F.txt");
    FILE *reader1 = fopen(startname, "r");
    FILE *reader2 = fopen(endname, "r");
    if (reader1 == NULL || reader2 == NULL)
    {
        printf("Fichier absent\n");
        abort();
    }
    char rc;
    thegame.stone = 0;
    thegame.step = 0;
    thegame.ends = 0;
    thegame.exp = 0;
    // skip first line
    fseek(reader1, 10, SEEK_CUR);
    fseek(reader2, 10, SEEK_CUR);
    for (int i = 0; i < 7; i++)
    {
        fseek(reader1, 2, SEEK_CUR);
        fseek(reader2, 2, SEEK_CUR);
        for (int j = 0; j < 7; j++)
        {
            rc = fgetc(reader1);
            if (rc == 'x')
            {
                thegame.stone++;
            }
            thegame.state[i][j] = (COL_START[i] <= j && j <= COL_END[i] && rc == 'x');
            rc = fgetc(reader2);
            endboard[i][j] = (COL_START[i] <= j && j <= COL_END[i] && rc == 'x');
            if (rc == 'x')
            {
                thegame.ends++;
            }
        }
        fseek(reader1, 2, SEEK_CUR);
        fseek(reader2, 2, SEEK_CUR);
    }
    thegame.end = hashboard(endboard);
    return thegame;
}

// Display board
void display(bool board[7][7])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (j < COL_START[i] || j > COL_END[i])
            {
                printf(" ");
            }
            else
            {
                if (board[i][j])
                {
                    printf("x");
                }
                else
                {
                    printf(".");
                }
            }
        }
        printf("\n");
    }
}

// get possible moves
moves get_move(bool board[7][7])
{
    moves lm;
    lm.s = 0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = COL_START[i]; j <= COL_END[i]; j++)
        {
            if (board[i][j])
            {
                for (int k = 0; k < 4; k++)
                {
                    if (ingrid(i + 2 * ML[k], j + 2 * MC[k]) && board[i + ML[k]][j + MC[k]] && !board[i + 2 * ML[k]][j + 2 * MC[k]])
                    {
                        lm.m[lm.s].sl = i;
                        lm.m[lm.s].sc = j;
                        lm.m[lm.s].dir = k;
                        lm.s++;
                    }
                }
            }
        }
    }
    return lm;
}

// Display moves
void dispmoves(moves lm)
{
    for (int i = 0; i < lm.s; i++)
    {
        printf("De (%d,%d) en direction %d \n", lm.m[i].sl, lm.m[i].sc, lm.m[i].dir);
    }
}

// Write sol in file
void writesol(FILE *w, move lm[], int n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(w, "De (%d,%d) en direction %d \n", lm[i].sl, lm[i].sc, lm[i].dir);
    }
}

// Make move
void makemove(game *g, move m)
{
    g->history[g->step++] = m;
    g->state[m.sl][m.sc] = false;
    g->state[m.sl + ML[m.dir]][m.sc + MC[m.dir]] = false;
    g->state[m.sl + 2 * ML[m.dir]][m.sc + 2 * MC[m.dir]] = true;
    g->stone--;
}

void boardmove(bool board[7][7], move m)
{
    board[m.sl][m.sc] = false;
    board[m.sl + ML[m.dir]][m.sc + MC[m.dir]] = false;
    board[m.sl + 2 * ML[m.dir]][m.sc + 2 * MC[m.dir]] = true;
}

void boardundo(bool board[7][7], move m)
{
    board[m.sl][m.sc] = true;
    board[m.sl + ML[m.dir]][m.sc + MC[m.dir]] = true;
    board[m.sl + 2 * ML[m.dir]][m.sc + 2 * MC[m.dir]] = false;
}

// Undo move
void undomove(game *g)
{
    move m;
    m = g->history[--g->step];
    g->state[m.sl][m.sc] = true;
    g->state[m.sl + ML[m.dir]][m.sc + MC[m.dir]] = true;
    g->state[m.sl + 2 * ML[m.dir]][m.sc + 2 * MC[m.dir]] = false;
    g->stone++;
}

// Backtrack solving
int get_next(llist *previous, llist *next, uint64_t target)
{
    node *config;
    uint64_t bhash;
    bool board[7][7];
    moves lm;
    int total = 0;
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        config = previous[i];
        while (config != NULL)
        {
            unhash(config->value, board);
            lm = get_move(board);
            for (int i = 0; i < lm.s; i++)
            {
                boardmove(board, lm.m[i]);
                bhash = hashboard(board);
                if (!is_in_hashtable(next, bhash))
                {
                    total++;
                    if (bhash == target)
                    {
                        printf("Solution trouvée !\n");
                        return total;
                    }
                    insert_in_hashtable(next, bhash);
                }
                boardundo(board, lm.m[i]);
            }
            config=config->next;
        }
        destroy_linked_list(previous[i]);
    }
    return total;
}

int main()
{
    game test;
    char fname[42];
    float st, et;
    int cp;
    node **previous = malloc(sizeof(llist) * HASHTABLE_SIZE);
    node **next = malloc(sizeof(llist) * HASHTABLE_SIZE);
    FILE *writer = fopen("solutionsl.txt", "w");
    for (int i = 22; i <= 30; i++)
    {
        if (i < 10)
        {
            snprintf(fname, 42, "EL0%d", i);
        }
        else
        {
            snprintf(fname, 42, "EL%d", i);
        }
        test = makepb(fname);
        cp = test.stone - test.ends;
        printf("Nombre de coups pour ce problème = %d\n",cp);
        for (int i = 0; i < HASHTABLE_SIZE; i++)
        {
            previous[i] = NULL;
            next[i] = NULL;
        }
        insert_in_hashtable(previous, hashboard(test.state));
        printf("Résolution du problème n° %d (%s)\n", i, fname);
        printf("Nombre de coups pour ce problème = %d\n",cp);
        st = (float)clock() / CLOCKS_PER_SEC;
        for (int j=0;j<cp;j++)
        {
            printf("Position générées au niveau %d = %d\n",j+1, get_next(previous, next, test.end));
            for (int i = 0; i < HASHTABLE_SIZE; i++)
            {
                previous[i] = next[i];
                next[i] = NULL;
            }
        }
        et = (float)clock() / CLOCKS_PER_SEC;
        printf("Solution trouvée en %f secondes\n", et - st);
        printf("\n----------------\n");
        destroy_hash_table(previous);
        destroy_hash_table(next);
    }
    fclose(writer);
    free(previous);
    free(next);
}