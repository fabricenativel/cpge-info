#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#define HEAD 'O'
#define BODY '*'
#define EMPTY ' '
#define FOOD '@'
#define BORDER '+'

#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3

#define GROW 1
#define COLLISION 2

const int DIRL[4] = {0, -1, 0, 1};
const int DIRC[4] = {1, 0, -1, 0};

// --8<-- [start:lpos]
// Liste chainée des positions occupées par le serpent
struct pos_s
{
    int lig;
    int col;
    struct pos_s *next;
};
typedef struct pos_s pos;
// --8<-- [end:lpos]

// --8<-- [start:snake]
struct snake_s
{
    pos *head; 
    pos *tail; 
    int dir;
};
typedef struct snake_s snake;
// --8<-- [end:snake]

bool in_screen(int l, int c, int maxl, int maxc)
{
    return ((0 < l) && (l < maxl) && (0 < c) && (c < maxc));
}

void add_head(snake *ms, int l, int c)
{
    pos *np = malloc(sizeof(pos));
    np->lig = l;
    np->col = c;
    np->next = NULL;
    if (ms->head == NULL)
    {
        ms->head = np;
    }
    else
    {
        ms->head->next = np;
        ms->head = np;
    }
    if (ms->tail == NULL)
    {
        ms->tail = ms->head;
    }
}

void remove_tail(snake *ms, int *l, int *c)
{
    pos *del = ms->tail;
    *l = (ms->tail)->lig;
    *c = (ms->tail)->col;
    ms->tail = ms->tail->next;
    free(del);
}

snake init_snake(int size, int maxl, int maxc)
{
    int l = maxl / 2;
    snake mysnake;
    mysnake.head = NULL;
    mysnake.tail = NULL;
    mysnake.dir = RIGHT;
    for (int c = maxc / 2 - size / 2; c < maxc / 2 + size / 2; c++)
    {
        add_head(&mysnake, l, c);
        mvaddch(l, c, BODY);
    }
    add_head(&mysnake, l, maxc / 2 + size / 2);
    mvaddch(l, maxc / 2 + size / 2, HEAD);

    return mysnake;
}

bool in_snake(snake ms, int l, int c)
{
    pos *p = ms.tail;
    while (p != NULL)
    {
        if (p->lig == l && p->col == c)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

void make_food(snake ms, int *pl, int *pc, int maxl, int maxc)
{
    *pl = 1 + rand() % (maxl-1);
    *pc = 1 + rand() % (maxc-1);
    while (in_snake(ms, *pl, *pc))
    {
        *pl = 1 + rand() % (maxl-1);
        *pc = 1 + rand() % (maxc-1);
    }
    mvaddch(*pl, *pc, FOOD);
}

int move_snake(snake *ms, int pl, int pc, int maxl, int maxc)
{
    int ql, qc;
    int hl, hc;
    mvaddch(ms->head->lig, ms->head->col, BODY);
    hl = ms->head->lig + DIRL[ms->dir];
    hc = ms->head->col + DIRC[ms->dir];
    if (!in_screen(hl, hc, maxl, maxc) || (in_snake(*ms, hl, hc)))
    {
        return COLLISION;
    }
    add_head(ms, hl, hc);
    mvaddch(hl, hc, HEAD);
    if (hl != pl || hc != pc)
    {
        remove_tail(ms, &ql, &qc);
        mvaddch(ql, qc, EMPTY);
    }
    else
    {
        return GROW;
    }
    return 0;
}

// --8<-- [start:init_term]
// Initialiser le terminal
void terminal_init(int *maxl, int *maxc)
{
    initscr();             // Initialiser ncurses
    cbreak();              // Désactiver la bufferisation de ligne
    noecho();              // Ne pas afficher les touches tapées
    keypad(stdscr, TRUE);  // Activer les touches spéciales (flèches)
    nodelay(stdscr, TRUE); // Rendre getch() non-bloquant
    curs_set(0);           // Cacher le curseur
    getmaxyx(stdscr, *maxl, *maxc);
    *maxl = *maxl - 1;
    *maxc = *maxc - 1;
}
// --8<-- [end:init_term]

void make_border(int maxl, int maxc)
{
    for (int c = 0; c < maxc; c++)
    {
        mvaddch(0, c, BORDER);
        mvaddch(maxl, c, BORDER);
    }
    for (int l = 0; l < maxl; l++)
    {
        mvaddch(l, 0, BORDER);
        mvaddch(l, maxc, BORDER);
    }
    refresh();
}

int main()
{
    srand(time(NULL));
    int delay = 100000;
    int maxlig, maxcol;
    int plig, pcol;
    terminal_init(&maxlig, &maxcol);
    make_border(maxlig,maxcol);
    snake ms = init_snake(5, maxlig, maxcol);
    init_fruit(ms, &plig, &pcol, maxlig, maxcol);
    refresh();
    bool running = true;
    bool paused = false;
    int kpress;
    int event;
    while (running)
    {
        usleep(delay);
        kpress = getch();
        if (kpress == 'q' || kpress == 'Q')
        {
            running = false;
        }
        if (kpress == 'p' || kpress == 'P')
        {
            paused = !paused;
        }
        else if (kpress == KEY_UP)
        {
            ms.dir = UP;
        }
        else if (kpress == KEY_DOWN)
        {
            ms.dir = DOWN;
        }
        else if (kpress == KEY_LEFT)
        {
            ms.dir = LEFT;
        }
        else if (kpress == KEY_RIGHT)
        {
            ms.dir = RIGHT;
        }
        if (!paused)
        {
            event = move_snake(&ms, plig, pcol, maxlig, maxcol);
            if (event == COLLISION)
            {
                running = false;
            }
            if (event == GROW)
            {
                init_fruit(ms, &plig, &pcol, maxlig, maxcol);
                delay = delay - delay / 10;
            }
        }
    }
    endwin();
}