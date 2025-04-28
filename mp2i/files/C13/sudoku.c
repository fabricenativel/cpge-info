#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define GRIDPATH "./grilles/"

struct cell
{
    uint8_t l;
    uint8_t c;
};
typedef struct cell cell;
cell NGH[9][9][20];

struct sudoku
{
    bool grid[9][9][9];
    bool set[9][9];
    uint8_t poss[9][9];
    uint8_t filled;
    bool failed;
};
typedef struct sudoku sudoku;

void init_ngh(cell ngh[9][9][20])
{
    uint8_t idx, colstart, lstart;
    for (uint8_t i = 0; i < 9; i++)
    {
        for (uint8_t j = 0; j < 9; j++)
        {
            idx = 0;
            for (uint8_t k = 0; k < 9; k++)
            {
                if (k != j)
                {
                    ngh[i][j][idx].l = i;
                    ngh[i][j][idx].c = k;
                    idx++;
                }
                if (k != i)
                {
                    ngh[i][j][idx].l = k;
                    ngh[i][j][idx].c = j;
                    idx++;
                }
            }
            lstart = 3 * (i / 3);
            colstart = 3 * (j / 3);
            for (uint8_t k1 = 0; k1 < 3; k1++)
            {
                for (uint8_t k2 = 0; k2 < 3; k2++)
                {
                    if (lstart + k1 != i && colstart + k2 != j)
                    {
                        ngh[i][j][idx].l = lstart + k1;
                        ngh[i][j][idx].c = colstart + k2;
                        idx++;
                    }
                }
            }
        }
    }
}

void init_sudo(sudoku *s)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            s->poss[i][j] = 9;
            s->set[i][j] = false;
            for (int k = 0; k < 9; k++)
            {
                s->grid[i][j][k] = true;
            }
        }
    }
    s->filled = 0;
    s->failed = false;
}

void copysudo(sudoku *s, sudoku *d)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            d->poss[i][j] = s->poss[i][j];
            d->set[i][j] = s->set[i][j];
            for (int k = 0; k < 9; k++)
            {
                d->grid[i][j][k] = s->grid[i][j][k];
            }
        }
    }
    d->filled = s->filled;
    d->failed = s->failed;
}

void setcell(sudoku *s, int i, int j, int v)
{
    int nl, nc;
    for (int k = 0; k < 9; k++)
    {
        s->grid[i][j][k] = false;
    }
    s->grid[i][j][v] = true;
    s->poss[i][j] = 1;
    s->set[i][j] = true;
    s->filled++;
    for (int k = 0; k < 20; k++)
    {
        nl = NGH[i][j][k].l;
        nc = NGH[i][j][k].c;
        if (!s->set[nl][nc] && s->grid[nl][nc][v])
        {
            s->grid[nl][nc][v] = false;
            s->poss[nl][nc]--;
            if (s->poss[nl][nc] == 0)
            {
                s->failed = true;
            }
        }
    }
}

void affiche(sudoku *s)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("(%d,%d) : %d -> ", i, j, s->poss[i][j]);
            for (int k = 0; k < 9; k++)
            {
                if (s->grid[i][j][k])
                {
                    printf("%d", k);
                }
            }
            printf("\n");
        }
    }
}

sudoku make_sudoku(FILE *reader)
{
    char sc[81];
    sudoku ts;
    int v;
    fscanf(reader, "%s", sc);
    init_sudo(&ts);
    for (int i = 0; i < 81; i++)
    {
        v = (int)(sc[i]) - 48;
        if (v != 0)
        {
            setcell(&ts, i / 9, i % 9, v - 1);
        }
    }
    return ts;
}

void view(sudoku *s)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (s->set[i][j])
            {
                for (int k = 0; k < 9; k++)
                {
                    if (s->grid[i][j][k])
                    {
                        printf("%d", k+1);
                    }
                }
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}

bool solve(sudoku *s, int i, int j)
{
    if (s->failed)
    {
        return false;
    }
    if (s->filled==81)
    {
        return true;
    }
    int ni,nj;
    nj =  j +1;
    if (nj==9)
    {
        ni = i +1;
        nj=0;
    }
    else
    {
        ni =i;
    }
    sudoku *cs = malloc(sizeof(sudoku));
    if (!s->set[i][j])
    {
        copysudo(s,cs);
        for (int p = 0; p < 9; p++)
        {
            if (s->grid[i][j][p])
            {
                setcell(s, i, j, p);
                if (solve(s,ni,nj))
                {
                    return true;
                }
                else
                {   copysudo(cs, s);
                    s->grid[i][j][p]=false;
                }
            }
        }
        return false;
    }
    return solve(s,ni,nj);    
}

int main()
{
    char fname[100] = GRIDPATH;
    sudoku ms;
    init_ngh(NGH);
    strcat(fname, "g100.txt");
    FILE *reader = fopen(fname, "r");
    ms = make_sudoku(reader);
    view(&ms);
    solve(&ms,0,0);
    view(&ms);
}