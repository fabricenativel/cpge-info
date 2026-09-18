#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define SIZE 37
#define PBPATH "./solitaire/"
#define HASHTABLE_SIZE 100000000

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
typedef node* llist;

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

uint64_t hasboard(bool board[7][7])
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
    thegame.end = hasboard(endboard);
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

// Display solution
// void disp_sol(game g)
// {
//     bool board[7][7];
//     move m;
//     for (int i = 0; i < 7; i++)
//     {
//         for (int j = COL_START[i]; j <= COL_END[i]; j++)
//         {
//             board[i][j] = g.start[i][j];
//         }
//     }
//     for (int i = 0; i < g.step; i++)
//     {
//         display(board);
//         m = g.history[i];
//         printf("Pierre en (%d,%d) en direction %d \n", m.sl, m.sc, m.dir);
//         board[m.sl][m.sc] = false;
//         board[m.sl + ML[m.dir]][m.sc + MC[m.dir]] = false;
//         board[m.sl + 2 * ML[m.dir]][m.sc + 2 * MC[m.dir]] = true;
//     }
//     display(board);
// }

// Write sol in file
void writesol(FILE *w, move lm[], int n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(w, "De (%d,%d) en direction %d \n", lm[i].sl, lm[i].sc, lm[i].dir);
    }
}



// Undo move


// Backtrack solving
bool solve(game *g, llist *seen)
{
    moves lm;
    move m;
    uint64_t chash;
    if (g->stone <= g->ends)
    {
        return false;
    }
    lm = get_move(g->state);
    for (int i = 0; i < lm.s; i++)
    {
        g->history[g->step++] = lm.m[i];
        g->state[lm.m[i].sl][lm.m[i].sc] = false;
        g->state[lm.m[i].sl + ML[lm.m[i].dir]][lm.m[i].sc + MC[lm.m[i].dir]] = false;
        g->state[lm.m[i].sl + 2 * ML[lm.m[i].dir]][lm.m[i].sc + 2 * MC[lm.m[i].dir]] = true;
        g->stone--;
        chash = hasboard(g->state);
        if (chash == g->end)
        {
            return true;
        }
        if (!is_in_hashtable(seen, chash))
        {
            insert_in_hashtable(seen, chash);
            g->exp++;
            if (solve(g,seen))
            {
                return true;
            }
            else
            {
                m = g->history[--g->step];
                g->state[m.sl][m.sc] = true;
                g->state[m.sl + ML[m.dir]][m.sc + MC[m.dir]] = true;
                g->state[m.sl + 2 * ML[m.dir]][m.sc + 2 * MC[m.dir]] = false;
                g->stone++;
            }
        }
        else
        {
                m = g->history[--g->step];
                g->state[m.sl][m.sc] = true;
                g->state[m.sl + ML[m.dir]][m.sc + MC[m.dir]] = true;
                g->state[m.sl + 2 * ML[m.dir]][m.sc + 2 * MC[m.dir]] = false;
                g->stone++;
        }
    }
    return false;
}

int main()
{

    game test;
    char fname[42];
    float st, et;
    node **seen = malloc(sizeof(llist)*HASHTABLE_SIZE);
    FILE *writer = fopen("solutions-swap.txt", "w");
    for (int i = 27; i <= 30; i++)
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
        for (int i = 0; i < HASHTABLE_SIZE; i++)
        {
        seen[i] = NULL;
        }
        printf("Résolution du problème n° %d (%s)\n", i, fname);
        // printf(" > Position de départ\n");
        // display(test.start);
        // printf(" > Position d'arrivée\n");
        // display(test.end);
        st = (float)clock() / CLOCKS_PER_SEC;
        bool res = solve(&test,seen);
        et = (float)clock() / CLOCKS_PER_SEC;
        destroy_hash_table(seen);
        if (res)
        {
            fprintf(writer,"Solution trouvée en %f secondes (%d motifs explorés) \n", et - st, test.exp);
            printf("Solution trouvée en %f secondes (%d motifs explorés) \n", et - st, test.exp);
            fprintf(writer, "Solution pb %d\n", i);
            writesol(writer, test.history, test.step);
            fflush(writer);
            fprintf(writer, "\n\n");
            // disp_sol(test);
        }
        else
        {
            printf("Pas de solution (%f sec)\n", et - st);
        }
    }
    fclose(writer);
    free(seen);
}