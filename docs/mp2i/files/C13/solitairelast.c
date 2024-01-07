#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define PBPATH "./solitaire/"
 
#define HASHTABLE_SIZE 25000000

// Les debuts et fin de colonne utilisées sur le plateau de jeu
const int COL_START[7] = {2, 1, 0, 0, 0, 1, 2};
const int COL_END[7] = {4, 5, 6, 6, 6, 5, 4};
// Les mouvements possibles (4 directions)
const int ML[4] = {0, -1, 0, 1};
const int MC[4] = {1, 0, -1, 0};

// Un déplacement = un pion (coordonnées sl,sc) et une direction parmi les 4 possibles
struct move
{
    int sl;
    int sc;
    int dir;
};
typedef struct move move;
// Pour stocker la liste des mouvements possibles depuis une configuration de jeu
struct moves
{
    move m[100];
    int s;
};
typedef struct moves moves;

// Tentative pour limiter l'espace mais gros fail : ce struct a une taille de 8 octets (comme un uint64_t) alors que j'espérais 5 octets
struct int40
{
    uint8_t h;
    uint32_t t;
};
typedef struct int40 int40;

// Les listes chainées de la table de hachage
struct node
{
    int40 value;
    struct node *next;
};
typedef struct node node;
typedef node *llist;

// Pour réprésenter un pb (etat du plateau, hash de la configuration de fin, ...)
struct game
{
    bool state[7][7]; //etat du plateau
    int40 end; //hash de la configuration finale
    move history[100]; //liste des mouvements
    int step; //nombre de mouvements
    int stone; //nombre de pierre
    int ends; //nombre de pierre sur la config de fin
    int exp; //nombre de motifs explorés
};
typedef struct game game;

// Gestion des listes chainées (la liste situés dans le bucket d'indice i contient les configs valant i modulo la taille de la table de hahchage)
bool is_in_list(node *linked_list, int40 val)
{
    while (linked_list != NULL)
    {
        if (linked_list->value.h == val.h &&linked_list->value.t == val.t)
            return true;
        linked_list = linked_list->next;
    }
    return false;
}

void insert_in_list(node **linked_list, int40 val)
{
    node *new_node = malloc(sizeof(node));
    new_node->value = val;
    new_node->next = *linked_list;
    *linked_list = new_node;
}

int get_hash(int40 value)
{
    uint64_t v = ((uint64_t)value.h << 32) + (uint64_t)value.t;
    return (int)(v % HASHTABLE_SIZE);
}


bool is_in_hashtable(node **hashtable, int40 val)
{
    int bucket_number = get_hash(val);
    return is_in_list(hashtable[bucket_number], val);
}

void insert_in_hashtable(node **hashtable, int40 val)
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

// Pour calculer le hash d'un configuration
int40 hasboard(bool board[7][7])
{
    uint8_t h = 0;
    uint32_t t = 0;
    int p = 1;
    int40 r;
    for (int i = 0; i < 7; i++)
    {
        if (i==2)
        { p=1;}
        for (int j = COL_START[i]; j <= COL_END[i]; j++)
        {
            if (board[i][j])
            {
                if (i < 2)
                {
                    h += p;
                }
                else
                {
                    t+= p;
                }
            }
            p = p*2;
        }
    }
    r.h = h;
    r.t = t;
    return r;
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

// Ended
// bool is_solved(game g)
// {
//     for (int i = 0; i < 7; i++)
//     {
//         for (int j = COL_START[i]; j <= COL_END[i]; j++)
//         {
//             if (g.end[i][j] != g.state[i][j])
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// Backtrack solving
bool solve(game *g, llist *seen)
{
    moves lm;
    move m;
    int40 chash;
    // Si il reste moins de pierre que dans la config de fin alors la résolution est impossible
    if (g->stone <= g->ends)
    {
        return false;
    }
    lm = get_move(g->state);
    for (int i = 0; i < lm.s; i++)
    {
        // Faire un mouvement
        g->history[g->step++] = lm.m[i];
        g->state[lm.m[i].sl][lm.m[i].sc] = false;
        g->state[lm.m[i].sl + ML[lm.m[i].dir]][lm.m[i].sc + MC[lm.m[i].dir]] = false;
        g->state[lm.m[i].sl + 2 * ML[lm.m[i].dir]][lm.m[i].sc + 2 * MC[lm.m[i].dir]] = true;
        g->stone--;
        chash = hasboard(g->state);
        // si cela aboutit a la solution alors renvoyer true
        if (chash.h == g->end.h && chash.t == g->end.t) 
        {
            return true;
        }
        // Sinon ajouter la config à celle déjà parcourue et relancer
        if (!is_in_hashtable(seen, chash))
        {
            insert_in_hashtable(seen, chash);
            g->exp++;
            if (solve(g, seen))
            {
                return true;
            }
            // Si on est bloqué alors revenir en arrière 
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
    node **seen = malloc(sizeof(llist) * HASHTABLE_SIZE);
    FILE *writer = fopen("solutionslast27.txt", "w");
    printf("Taille d'un uint64 : %ld\n",sizeof(uint64_t));
    printf("Taille d'un int40 : %ld\n",sizeof(int40));
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
        //printf("Hash du board : (%d,%d) \n",hasboard(test.state).h,hasboard(test.state).t);
        // printf(" > Position de départ\n");
        // display(test.start);
        // printf(" > Position d'arrivée\n");
        // display(test.end);
        st = (float)clock() / CLOCKS_PER_SEC;
        bool res = solve(&test, seen);
        et = (float)clock() / CLOCKS_PER_SEC;
        destroy_hash_table(seen);
        if (res)
        {
            fprintf(writer, "Solution trouvée en %f secondes (%d motifs explorés) \n", et - st, test.exp);
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