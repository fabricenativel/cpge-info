#include <ncurses.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define YELLOW COLOR_PAIR(1)
#define CYAN COLOR_PAIR(2)
#define RED COLOR_PAIR(3)
#define GREEN COLOR_PAIR(4)
#define WHITE COLOR_PAIR(5)
#define INVIS COLOR_PAIR(6)
#define EMPTY "                                                                      "

#define SIZE 8
#define LINE_LENGHT (2*SIZE)


struct position
{
    int row;
    int col;
};
typedef struct position position;

struct lpos
{
    int n;
    position poss[8];
};
typedef struct lpos lpos;

struct solution
{
    position start;
    int path[SIZE][SIZE];
    int pathlen;
};
typedef struct solution solution;

bool ingrid(position p)
{
    return (p.row >= 0 && p.row < SIZE && p.col >= 0 && p.col < SIZE);
}

void view(solution s)
{
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            if (s.path[r][c] == 0)
            {
                printf(" . ");
            }
            else
            {
                if (s.path[r][c] < 10)
                {
                    printf(" %d ", s.path[r][c]);
                }
                else
                {
                    printf("%d ", s.path[r][c]);
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

lpos getpos(solution s)
{
    int mx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int my[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    position cpos;
    lpos res;
    res.n = 0;
    for (int i = 0; i < 8; i++)
    {
        cpos.row = s.start.row + mx[i];
        cpos.col = s.start.col + my[i];
        if (ingrid(cpos) && s.path[cpos.row][cpos.col] == 0)
        {
            res.poss[res.n++] = cpos;
        }
    }
    return res;
}

bool search(solution *s)
{
    lpos possibilites;
    position old = s->start;
    // view(*s);
    if (s->pathlen < SIZE * SIZE)
    {
        possibilites = getpos(*s);
        for (int i = 0; i < possibilites.n; i++)
        {
            s->pathlen++;
            s->path[possibilites.poss[i].row][possibilites.poss[i].col] = s->pathlen;
            s->start = possibilites.poss[i];
            if (search(s))
            {
                return true;
            }
            else
            {
                s->pathlen--;
                s->path[possibilites.poss[i].row][possibilites.poss[i].col] = 0;
                s->start = old;
            }
        }
        return false;
    }
    else
    {
        return true;
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
    // move(LINES-3,0);
    // clrtoeol();
    attron(INVIS);
    mvprintw(LINES - 3, COLS / 2 - strlen(EMPTY) / 2, "%s", EMPTY);
    attroff(INVIS);
    attron(WHITE);
    attron(CYAN);
    attron(A_BOLD);
    mvprintw(LINES - 3, COLS / 2 - strlen(s) / 2, "%s", s);
    attroff(A_BOLD);
    attroff(CYAN);
    move(1, 1);
}

void putnum(int l, int c, int n, bool r)
{
    int sl = LINES / 2 - 9;
    int sc = COLS / 2 - 9;
    if (n != 0)
    {
        mvaddch(sl + l * 2, sc + c * 2, (char)n + 48);
    }
    else
    {
        mvaddch(sl + l * 2, sc + c * 2, 32);
    }
    if (r)
    {
        refresh();
    }
}

void setboard()
{
    int sl = (LINES - SIZE)/2;
    int sc = (COLS - SIZE)/2;
    for (int l=0;l<SIZE;l++) {
        for (int c=0;c<SIZE;c++) {
            if ((l+c)%2==0)
            {
                attron(CYAN);
            }
            else
            {
                attron(YELLOW);
            }
            mvaddch(sl+l,sc+c,ACS_BOARD);
        }
    }
    refresh();
}

void empty()
{
    attron(INVIS);
    for (int i = 0; i < 81; i++)
    {
        putnum(i / 9, i % 9, 0, false);
    }
    refresh();
}
int main(int argc, char *argv[])
{
    solution s;
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            s.path[r][c] = 0;
        }
    }
    s.start.row = atoi(argv[1]);
    s.start.col = atoi(argv[2]);
    s.path[s.start.row][s.start.col] = 1;
    s.pathlen = 1;
    initscr();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_YELLOW);
    init_pair(2, COLOR_BLACK, COLOR_CYAN);
    init_pair(3, COLOR_BLACK, COLOR_RED);
    init_pair(4, COLOR_BLACK, COLOR_GREEN);
    init_pair(5, COLOR_BLACK, COLOR_WHITE);
    init_pair(5, COLOR_BLACK, COLOR_BLACK);
    curs_set(0);
    setwindow();
    setboard();
    message("Appuyer sur une touche pour démarrer la recherche");
    getch();
    if (search(&s))
    {
        view(s);
    };
}