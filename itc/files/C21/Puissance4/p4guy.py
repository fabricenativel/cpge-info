import PySimpleGUI as sg
from time import sleep
from random import choice
from math import inf

NB_LIG = 6
NB_COL = 7
EMPTY = "empty.png"
ARROW = "arrow_white.png"
YELLOW = 1
RED = 2
PCOLOR = {YELLOW : 'yellow', RED : 'red'}
TO_WIN = 4
DIRECTIONS = [(1,0),(1,1),(0,1),(1,-1)]
TFONT = ('Courier',12,'bold')
RESET = chr(0x2691)
SWITCH = chr(0x2194)
UNDO = chr(0x21B6)
EXIT = chr(0x23FB)

class Puissance4:

    def __init__(self):
        self.init_model()
        self.view = sg.Window('Puissance4', self.init_layout(),finalize=True)

    def init_model(self):
        self.board = [[0]*NB_COL for _ in range(NB_LIG)]
        self.player = YELLOW
        self.empty = NB_LIG*NB_COL
        self.history = []
        self.ended = False

    def init_layout(self):
        top = [[sg.Button(image_filename=ARROW,key=f'{col}',pad=(0,0),border_width=0,button_color=PCOLOR[self.player]) for col in range(NB_COL)]]
        board_view = [[sg.Image(filename=self.get_img(self.board[lig][col],col),key=f'({lig},{col})',pad=(1,1)) for col in range(NB_COL)] for lig in range(NB_LIG)]
        ptext = sg.Text("Joueur",key='ptext',size=(15,1),justification='r',text_color=PCOLOR[YELLOW],font=TFONT)
        ctext = sg.Text("Ordinateur",key='ctext',size=(15,1),justification='r',text_color=PCOLOR[RED],font=TFONT)
        bottom =[[sg.Button(SWITCH,tooltip='Changer de côté',key='Switch'),sg.Button(UNDO,key="Undo"),sg.Button(RESET,key="Reset"),sg.Button(EXIT,key="Exit"),sg.Stretch(),ptext,ctext]]
        layout = [[top],[board_view],[sg.HSeparator()],[bottom]]
        return layout
    
    def play(self,col):
        lig = 0
        while lig<NB_LIG and self.board[lig][col] == 0:
            lig +=1
        lig -=1
        self.board[lig][col] = self.player
        self.empty -= 1
        self.history.append(col)        
        self.switch_player()
        self.update_view()
    
    def update_view(self):
        for c in range(NB_COL):
            self.view[f'{c}'].Update(button_color = PCOLOR[self.player])
            if self.board[0][c]!=0: 
                self.view[f'{c}'].Update(disabled = True)
            for l in range(NB_LIG):
                self.view[f'({l},{c})'].Update(filename = self.get_img(self.board[l][c]))
        if self.get_winner() is not None:
            self.ended = True
            self.show_winner(*self.get_winner())
            for col in range(NB_COL):
                self.view[f'{col}'].Update(disabled = True)

    def reset(self):
        self.init_model()
        self.update_view()
        self.get_value()

    def playable(self,col):
        return self.board[0][col]==0
        
    def switch_player(self):
        self.player = 3-self.player

        

    def undo(self):
            if len(self.history)!=0:
                lastcol = self.history.pop()
            lig = 0
            while self.board[lig][lastcol] == 0:
                lig +=1
            self.board[lig][lastcol] = 0
            self.empty+=1
            self.switch_player()
            self.update_view()
    
    def in_board(self,l,c):
        return 0<= l < NB_LIG and 0<= c < NB_COL

    def get_winner(self):
        for lig in range(NB_LIG):
            for col in range(NB_COL):
                for dl,dc in DIRECTIONS:
                    for p in (YELLOW,RED):
                        if all(self.in_board(lig+k*dl,col+k*dc) and self.board[lig+k*dl][col+k*dc]==p for k in range(TO_WIN)): return p,lig,col,dl,dc
        return None

    def show_winner(self,p,l,c,dl,dc):
            for k in range(TO_WIN):
                self.view[f'({l+k*dl},{c+k*dc})'].Update(filename=self.get_img(p,True))
    
    def show_board(self):
        for l in range(NB_LIG):
            for c in range(NB_COL):
                print(self.board[l][c],end='')
            print('\n')
    
    def get_img(self,p,win = False):
        if p==0:
            return EMPTY
        else:
            wins = ''
            if win:
                wins = '-win'
            return f"player{p}{wins}.png"
        

def conversion(event):
    return int(event[0])

if __name__=="__main__":
    game = Puissance4()
    exit = False
    while not exit:
        event, values = game.view.read()
        if event=='Exit' or event==sg.WIN_CLOSED:
            game.view.Close()
            exit = True
        elif event=='Reset':
            game.reset()
        elif event=='Undo':
            game.undo()
        elif event=='Switch':
            game.switch()
        else:
            game.play(conversion(event))
            
        