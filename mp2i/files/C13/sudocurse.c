#include <ncurses.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define LINE_LENGHT 18
#define YELLOW COLOR_PAIR(1)
#define CYAN COLOR_PAIR(2)
#define RED COLOR_PAIR(3)
#define GREEN COLOR_PAIR(4)
#define WHITE COLOR_PAIR(5)
#define INVIS COLOR_PAIR(6)
#define EMPTY "                                                                      "
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

void setwindow()
{
    noecho();
    wborder(stdscr, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    attron(RED);
    mvprintw(0, COLS / 2 - 3, "%s", "SUDOKU");
    attroff(RED);
    refresh();
}

void message(char *s)
{
    //move(LINES-3,0);
    //clrtoeol();
    attron(INVIS);
    mvprintw(LINES-3,COLS/2-strlen(EMPTY)/2,"%s",EMPTY);
    attroff(INVIS);
    attron(WHITE);
    attron(CYAN);
    attron(A_BOLD);
    mvprintw(LINES-3,COLS/2-strlen(s)/2,"%s",s);
    attroff(A_BOLD);
    attroff(CYAN);
    move(1,1);
}

void putnum(int l, int c, int n, bool r)
{
    int sl = LINES/2 - 9;
    int sc = COLS/2 -9;
    if (n!=0)
    {mvaddch(sl+l*2,sc+c*2,(char)n+48);}
    else
    {mvaddch(sl+l*2,sc+c*2,32);}
    if (r) {refresh();}
}

void setboard()
{
    for (int i = 0; i < 10; i++)
    {
        if (i % 3 == 0)
        {
            attroff(A_DIM);
            attron(A_STANDOUT);
            attron(YELLOW);
        }
        else
        {
            attroff(YELLOW);
            attroff(A_STANDOUT);
            attron(A_DIM);
        }
        move((LINES / 2 - 10) + 2 * i, (COLS - LINE_LENGHT) / 2);
        hline(ACS_HLINE, LINE_LENGHT);
        move((LINES - LINE_LENGHT) / 2, (COLS / 2 - 10) + 2 * i);
        vline(ACS_VLINE, LINE_LENGHT);
    }
    attron(A_STANDOUT);
    attron(YELLOW);
    mvaddch((LINES / 2) - 10, (COLS / 2 - 10), ACS_ULCORNER);
    mvaddch((LINES / 2) - 10, (COLS / 2 + 8), ACS_URCORNER);
    mvaddch((LINES / 2) + 8, (COLS / 2 - 10), ACS_LLCORNER);
    mvaddch((LINES / 2) + 8, (COLS / 2 + 8), ACS_LRCORNER);
    mvaddch((LINES / 2) -4 , (COLS / 2 - 10), ACS_LTEE);
    mvaddch((LINES / 2) +2 , (COLS / 2 - 10), ACS_LTEE);
    mvaddch((LINES / 2) -4 , (COLS / 2 + 8), ACS_RTEE);
    mvaddch((LINES / 2) +2 , (COLS / 2 + 8), ACS_RTEE);

    for (int i = -8; i < 8; i = i + 2)
    {
        mvaddch((LINES / 2) - 10, (COLS / 2 + i), ACS_TTEE);
    }
    for (int j = -8; j < 8; j = j + 2)
    {
        for (int i = -8; i < 8; i = i + 2)
        {
            if (i == -4 || i == 2 || j==-4 || j==2)
            {
                attroff(A_DIM);
                attron(A_STANDOUT);
                attron(YELLOW);
            }
            else
            {
                attroff(YELLOW);
                attroff(A_STANDOUT);
                attron(A_DIM);
            }
            mvaddch((LINES / 2) + j, (COLS / 2 + i), ACS_PLUS);
        }
    }
    attroff(A_DIM);
    attron(A_STANDOUT);
    attron(YELLOW);
    for (int i = -8; i < 8; i = i + 2)
    {
        mvaddch((LINES / 2) + 8, (COLS / 2 + i), ACS_BTEE);
    }
    refresh();
}

void empty()
{
    attron(INVIS);
    for (int i=0;i<81;i++)
    {
        putnum(i/9,i%9,0,false);
    }
    refresh();
}


bool setcell(sudoku s, int i, int v)
{
    int nl, nc;
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
                attron(GREEN);
                attron(A_BOLD);
                putnum(i/9,i%9,p,true);
                attroff(GREEN);
                attroff(A_BOLD);
                if (solve(s, i + 1))
                {
                    return true;
                }
                else
                {
                    s[i] = 0;
                    attron(INVIS);
                    putnum(i/9,i%9,0,true);
                    attroff(INVIS);
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
    initscr();
    start_color();
    init_pair(1,  COLOR_BLACK,COLOR_YELLOW);
    init_pair(2,  COLOR_BLACK,COLOR_CYAN);
    init_pair(3, COLOR_BLACK, COLOR_RED);
    init_pair(4, COLOR_BLACK, COLOR_GREEN);
    init_pair(5, COLOR_BLACK, COLOR_WHITE);
    init_pair(5, COLOR_BLACK, COLOR_BLACK);
    curs_set(0);
    setwindow();
    setboard();
    for (int i=0;i<87;i++)
    {
        empty();
    message("Appuyer sur une touche pour charger la prochaine grille ");
    getch();
    for (int i=0;i<81;i++)
    {
        ms[i] = fgetc(reader)-48;
        if(ms[i]!=0)
        {   
            attron(RED);
            attron(A_BOLD);
            putnum(i/9,i%9,ms[i],false);
            attroff(RED);
            attroff(A_BOLD);
        }
    }
    refresh();
    fgetc(reader);
    message("Appuyer sur une touche pour résoudre la grille ");
    getch();
    st = (float)clock() / CLOCKS_PER_SEC;
    solve(ms, 0);
    et = (float)clock() / CLOCKS_PER_SEC;
    message("Résolu ! ");
    getch();
    }
    fclose(reader);
    endwin();
}