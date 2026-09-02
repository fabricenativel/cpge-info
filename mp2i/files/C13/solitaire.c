#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 37
#define PBPATH "./solitaire/"

const int COL_START[7] = {2,1,0,0,0,1,2};
const int COL_END[7] = {4,5,6,6,6,5,4};
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

struct game
{
    bool start[7][7];
    bool state[7][7];
    bool end[7][7];
    move history[100];
    int step;
    int stone;
    int ends;
};
typedef struct game game;

bool ingrid(int l, int c)
{
    return (l>=0 && l<7 && c>=COL_START[l] && c<=COL_END[l]);
}


// Make game from file
game makepb(char filename[])
{
    game thegame;
    char startname[100] = PBPATH;
    char endname[100] = PBPATH;
    strcat(startname,filename);
    strcat(startname,"I.txt");
    strcat(endname,filename);
    strcat(endname,"F.txt");
    FILE* reader1 = fopen(startname,"r");
    FILE* reader2 = fopen(endname,"r");
    if (reader1==NULL || reader2==NULL) {printf("Fichier absent\n"); abort();}
    char rc;
    thegame.stone = 0;
    thegame.step = 0;
    thegame.ends = 0;
    //skip first line
    fseek(reader1,10,SEEK_CUR);
    fseek(reader2,10,SEEK_CUR);
    for (int i=0;i<7;i++)
    {
        fseek(reader1,2,SEEK_CUR);
        fseek(reader2,2,SEEK_CUR);
        for (int j=0;j<7;j++)
        {
            rc = fgetc(reader1);
            if (rc=='x') {thegame.stone++;}
            thegame.start[i][j] = (COL_START[i]<=j && j<=COL_END[i] && rc=='x');
            thegame.state[i][j] = thegame.start[i][j];
            rc = fgetc(reader2); 
            thegame.end[i][j] = (COL_START[i]<=j && j<=COL_END[i] && rc=='x');
            if (rc=='x') {thegame.ends++;}
        }
        fseek(reader1,2,SEEK_CUR);
        fseek(reader2,2,SEEK_CUR);
    }
    return thegame;
}

// Display board
void display(bool board[7][7])
{   
    for (int i=0;i<7;i++)
    {
        for (int j=0;j<7;j++)
        {
            if (j<COL_START[i] || j>COL_END[i])
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
moves get_move(game g)
{
    moves lm;
    lm.s = 0;
    for (int i=0;i<7;i++)
    {
        for (int j=COL_START[i];j<=COL_END[i];j++)
        {
            if (g.state[i][j])
            {
                for (int k=0;k<4;k++)
                {
                    if (ingrid(i+ML[k],j+MC[k]) && g.state[i+ML[k]][j+MC[k]])
                    {
                        if (ingrid(i+2*ML[k],j+2*MC[k]) && !g.state[i+2*ML[k]][j+2*MC[k]])
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
    }
    return lm;
}

// Display moves
void dispmoves(moves lm)
{
    for (int i=0;i<lm.s;i++)
    {
        printf("De (%d,%d) en direction %d \n",lm.m[i].sl,lm.m[i].sc,lm.m[i].dir);
    }
}


// Display solution
void disp_sol(game g)
{
    bool board[7][7];
    move m;
    for (int i=0;i<7;i++)
    {
        for (int j=COL_START[i];j<=COL_END[i];j++)
        {
            board[i][j]=g.start[i][j];
        }
    }
    for (int i=0;i<g.step;i++)
    {   
        display(board);
        m=g.history[i];
        printf("Pierre en (%d,%d) en direction %d \n",m.sl,m.sc,m.dir);
        board[m.sl][m.sc] = false;
        board[m.sl+ML[m.dir]][m.sc+MC[m.dir]]=false;
        board[m.sl+2*ML[m.dir]][m.sc+2*MC[m.dir]]=true;
    }
    display(board);
}

// Make move 
void makemove(game *g, move m)
{
    g->history[g->step++] = m;
    g->state[m.sl][m.sc] = false;
    g->state[m.sl+ML[m.dir]][m.sc+MC[m.dir]]=false;
    g->state[m.sl+2*ML[m.dir]][m.sc+2*MC[m.dir]]=true;
    g->stone--;
}

// Undo move
void undomove(game *g)
{   move m;
    if (g->step!=0)
    {
        m=g->history[--g->step];
        g->state[m.sl][m.sc] = true;
        g->state[m.sl+ML[m.dir]][m.sc+MC[m.dir]]=true;
        g->state[m.sl+2*ML[m.dir]][m.sc+2*MC[m.dir]]=false;
        g->stone++;

    }
}

// Ended
bool is_solved(game g)
{
    for (int i=0;i<7;i++)
    {
        for (int j=COL_START[i];j<=COL_END[i];j++)
        {
            if (g.end[i][j]!=g.state[i][j])
            { return false;}
        }
    }
    return true;
}

// Backtrack solving
bool solve(game *g)
{   
    moves lm;
    if (is_solved(*g))
    { 
        return true;}
    if (g->stone<=g->ends)
    {
        return false;
    }
    lm = get_move(*g);
    for (int i=0;i<lm.s;i++)
    {
        makemove(g,lm.m[i]);
        if (solve(g))
        {
            return true;
        }
        else
        {
            undomove(g);
        }
    }
    return false;
}

int main()
{

    game test;
    char fname[42];
    float st,et;
    for (int i=11;i<=30;i++)
    {
    if (i<10)
    {snprintf(fname, 42,  "EL0%d", i);}
    else
    {snprintf(fname, 42,  "EL%d", i);}
    test = makepb(fname);
    printf("Résolution du problème n° %d (%s)\n",i,fname);
    // printf(" > Position de départ\n");
    // display(test.start);
    // printf(" > Position d'arrivée\n");
    // display(test.end);
    st = (float)clock()/CLOCKS_PER_SEC;
    bool res = solve(&test);
    et = (float)clock()/CLOCKS_PER_SEC;
    if (res)
    {printf("Solution trouvée en %f secondes \n",et-st);
    //disp_sol(test);
    }
    else
    {printf("Pas de solution (%f sec)\n",et-st);}
    }
}