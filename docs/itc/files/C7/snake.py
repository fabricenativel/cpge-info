import curses
from random import randint
from time import sleep

#--8<-- [start:car]
SNAKE_HEAD = "O"
SNAKE_BODY = "o"
BORDER = "+"
EMPTY = ' '
FOOD = "*"
#--8<-- [end:car]

RIGHT, UP, LEFT, DOWN = 0, 1, 2, 3
GROW, COLLISION = 1, 2
DIR = {RIGHT : (0, 1), UP : (-1,0), LEFT : (0,-1), DOWN : (1,0)}

def draw_border(maxl, maxc):
    for c in range(0,maxc):
        terminal.addch(0,c,BORDER)
        terminal.addch(maxl,c,BORDER)
    for l in range(0,maxl):
        terminal.addch(l,0,BORDER)
        terminal.addch(l,maxc,BORDER)
    terminal.refresh()

def est_dans(x, lst):
    for elt in lst:
        if elt==x:
            return True
    return False

def init_snake(maxl, maxc, size):
    ls = maxl//2
    sn = []
    for c in range(maxc//2-size//2,maxc//2+size//2):
        sn.append((ls,c))
        terminal.addch(ls,c,SNAKE_BODY)
    sn.append((ls,maxc//2+size//2))
    terminal.addch(ls,maxc//2+size//2,SNAKE_BODY)
    terminal.refresh()
    return sn


def move_snake(pos_snake, dir_snake, maxl, maxc, fl, fc):
    # Ajouter la nouvelle position devant la tête
    hl, hc = pos_snake[-1]
    dl, dc = DIR[dir_snake]
    if hl+dl<1 or hl+dl>maxl or hc+dc<1 or hc+dc>maxc or est_dans((hl+dl,hc+dc),pos_snake):
        return COLLISION
    pos_snake.append((hl+dl,hc+dc))
    terminal.addch(hl,hc,SNAKE_BODY)
    terminal.addch(hl+dl,hc+dc,SNAKE_HEAD)
    terminal.refresh()
    if hl+dl==fl and hc+dc==fc:
        return GROW
    tl, tc = pos_snake.pop(0)
    terminal.addch(tl,tc,EMPTY)
    terminal.refresh()

def make_food(maxl, maxc, snake_pos):
    fl = randint(1,maxl-1)
    fc = randint(1,maxc-1)
    while est_dans((fl,fc),snake_pos):
        fl = randint(1,maxl-1)
        fc = randint(1,maxc-1)
    terminal.addch(fl,fc,FOOD)
    terminal.refresh()
    return fl,fc

def snake(terminal):
    #Vitesse du jeu
    delay = 0.2
    #Initialiser l'écran
    curses.cbreak()              #Désactiver la bufferisation de ligne
    curses.curs_set(0)           #Cacher le curseur
    curses.noecho()               #Ne pas afficher les touches tapées
    terminal.nodelay(1) #Rendre getch() non-bloquant
    terminal.keypad(True)
    terminal.clear()

    # Récupérer les dimensions du terminal
    maxl, maxc = terminal.getmaxyx()
    maxl = maxl-1
    maxc =  maxc - 1
    draw_border(maxl,maxc)
    pos_snake = init_snake(maxl, maxc, 5)
    dir_snake = RIGHT
    running = True
    fl,fc = make_food(maxl,maxc,pos_snake)
    while (running):
        event = move_snake(pos_snake,dir_snake, maxl, maxc, fl, fc)
        if event==GROW:
            fl,fc = make_food(maxl,maxc,pos_snake)
            delay = 0.9 * delay
        if event==COLLISION:
            running = False
        sleep(delay)
        kpress = terminal.getch()
        if (kpress == curses.KEY_UP):
            dir_snake = UP
        elif (kpress == curses.KEY_DOWN):
            dir_snake = DOWN
        elif (kpress == curses.KEY_LEFT):
            dir_snake =  LEFT
        elif (kpress == curses.KEY_RIGHT):
            dir_snake =  RIGHT
        


terminal = curses.initscr()
curses.wrapper(snake)
