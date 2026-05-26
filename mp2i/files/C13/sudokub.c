#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


#define GRIDPATH "./grilles/"

struct cell
{
    int l;
    int c;
};
typedef struct cell cell;
cell NGH[9][9][20];
typedef int sudoku[81];

void init_ngh(cell ngh[9][9][20])
{
    int idx, colstart, lstart;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            idx = 0;
            for (int k = 0; k < 9; k++)
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
            for (int k1 = 0; k1 < 3; k1++)
            {
                for (int k2 = 0; k2 < 3; k2++)
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


void view(sudoku s)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (s[i * 9 + j] == 0)
            {
                printf(".");
            }
            else
            {
                printf("%d", s[i * 9 + j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool setcell(sudoku s, int i, int v)
{
    int nl, nc;
    // printf("Essai : valeur %d en (%d,%d)\n", v, i / 9, i % 9);
    for (int k = 0; k < 20; k++)
    {
        nl = NGH[i / 9][i % 9][k].l;
        nc = NGH[i / 9][i % 9][k].c;
        if (s[nl * 9 + nc] == v)
        {
            return false;
        }
    }
    return true;
}

bool solve(sudoku s, int i)
{
    if (i == 81)
    {
        return true;
    }
    if (s[i] == 0)
    {
        for (int p = 1; p < 10; p++)
        {
            if (setcell(s, i, p))
            {
                s[i] = p;
                if (solve(s, i + 1))
                {
                    return true;
                }
                else
                {
                    s[i] = 0;
                }
            }
        }
        return false;
    }
    else
    {
        return solve(s, i + 1);
    }
}

int main()
{
    char fname[100] = GRIDPATH;
    sudoku ms;
    float st,et;
    init_ngh(NGH);
    strcat(fname, "Cent.txt");
    FILE *reader = fopen(fname, "r");
    for (int i=0;i<87;i++)
    {
    printf("Sudoku n° %d\n",i+1);
    for (int i=0;i<81;i++)
    {
        ms[i] = fgetc(reader)-48;
    }
    fgetc(reader);
    st = (float)clock() / CLOCKS_PER_SEC;
    solve(ms, 0);
    et = (float)clock() / CLOCKS_PER_SEC;
    printf("Résolut en %f secondes\n",et-st);
    view(ms);}
    fclose(reader);
}