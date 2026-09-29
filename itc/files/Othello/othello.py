import tkinter as tk
from tkinter import messagebox

# Configuration du jeu
BOARD_SIZE = 6  # Taille simplifiée 6x6
CELL_SIZE = 80
EMPTY = 0
BLACK = 1
WHITE = 2

class ReversiGame:
    def __init__(self, size=6):
        self.size = size
        self.board = [[EMPTY for _ in range(size)] for _ in range(size)]
        self.current_player = BLACK
        self.initialize_board()
    
    def initialize_board(self):
        """Place les 4 pions initiaux au centre"""
        mid = self.size // 2
        self.board[mid-1][mid-1] = WHITE
        self.board[mid-1][mid] = BLACK
        self.board[mid][mid-1] = BLACK
        self.board[mid][mid] = WHITE
    
    def is_valid_move(self, row, col):
        """Vérifie si un coup est valide"""
        if self.board[row][col] != EMPTY:
            return False
        
        directions = [(-1,-1), (-1,0), (-1,1), (0,-1), (0,1), (1,-1), (1,0), (1,1)]
        opponent = WHITE if self.current_player == BLACK else BLACK
        
        for dr, dc in directions:
            r, c = row + dr, col + dc
            found_opponent = False
            
            while 0 <= r < self.size and 0 <= c < self.size:
                if self.board[r][c] == opponent:
                    found_opponent = True
                elif self.board[r][c] == self.current_player and found_opponent:
                    return True
                else:
                    break
                r, c = r + dr, c + dc
        
        return False
    
    def get_valid_moves(self):
        """Retourne la liste des coups valides"""
        moves = []
        for row in range(self.size):
            for col in range(self.size):
                if self.is_valid_move(row, col):
                    moves.append((row, col))
        return moves
    
    def make_move(self, row, col):
        """Effectue un coup et retourne les pions"""
        if not self.is_valid_move(row, col):
            return False
        
        self.board[row][col] = self.current_player
        directions = [(-1,-1), (-1,0), (-1,1), (0,-1), (0,1), (1,-1), (1,0), (1,1)]
        opponent = WHITE if self.current_player == BLACK else BLACK
        
        for dr, dc in directions:
            r, c = row + dr, col + dc
            to_flip = []
            
            while 0 <= r < self.size and 0 <= c < self.size:
                if self.board[r][c] == opponent:
                    to_flip.append((r, c))
                elif self.board[r][c] == self.current_player:
                    for flip_r, flip_c in to_flip:
                        self.board[flip_r][flip_c] = self.current_player
                    break
                else:
                    break
                r, c = r + dr, c + dc
        
        self.current_player = WHITE if self.current_player == BLACK else BLACK
        return True
    
    def count_pieces(self):
        """Compte les pions de chaque joueur"""
        black_count = sum(row.count(BLACK) for row in self.board)
        white_count = sum(row.count(WHITE) for row in self.board)
        return black_count, white_count
    
    def is_game_over(self):
        """Vérifie si la partie est terminée"""
        if len(self.get_valid_moves()) > 0:
            return False
        # Passe le tour
        self.current_player = WHITE if self.current_player == BLACK else BLACK
        if len(self.get_valid_moves()) > 0:
            self.current_player = WHITE if self.current_player == BLACK else BLACK
            return False
        return True

class ReversiGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Reversi 6x6")
        self.root.resizable(False, False)
        
        self.game = ReversiGame(BOARD_SIZE)
        
        # Couleurs
        self.color_dark = "#2d8659"
        self.color_light = "#238b57"
        self.color_valid = "#ffeb3b"
        
        # Frame principal
        main_frame = tk.Frame(root, bg="#1a1a1a", padx=20, pady=20)
        main_frame.pack()
        
        # Titre
        title_label = tk.Label(main_frame, text="REVERSI 6x6", 
                              font=("Arial", 24, "bold"),
                              bg="#1a1a1a", fg="white")
        title_label.grid(row=0, column=0, columnspan=BOARD_SIZE, pady=(0, 10))
        
        # Info joueur et score
        info_frame = tk.Frame(main_frame, bg="#1a1a1a")
        info_frame.grid(row=1, column=0, columnspan=BOARD_SIZE, pady=(0, 10))
        
        self.turn_label = tk.Label(info_frame, text="Tour: Noir ●", 
                                   font=("Arial", 14, "bold"),
                                   bg="#1a1a1a", fg="white")
        self.turn_label.pack(side=tk.LEFT, padx=20)
        
        self.score_label = tk.Label(info_frame, text="Noir: 2 | Blanc: 2",
                                    font=("Arial", 14),
                                    bg="#1a1a1a", fg="white")
        self.score_label.pack(side=tk.LEFT, padx=20)
        
        # Canvas pour le plateau
        self.canvas = tk.Canvas(main_frame, 
                               width=BOARD_SIZE * CELL_SIZE,
                               height=BOARD_SIZE * CELL_SIZE,
                               bg="#1a1a1a", highlightthickness=0)
        self.canvas.grid(row=2, column=0, columnspan=BOARD_SIZE, pady=10)
        self.canvas.bind("<Button-1>", self.on_canvas_click)
        
        # Boutons
        button_frame = tk.Frame(main_frame, bg="#1a1a1a")
        button_frame.grid(row=3, column=0, columnspan=BOARD_SIZE, pady=(10, 0))
        
        tk.Button(button_frame, text="Nouvelle Partie", 
                 command=self.new_game,
                 font=("Arial", 12),
                 bg="#4CAF50", fg="white",
                 padx=20, pady=5).pack(side=tk.LEFT, padx=5)
        
        tk.Button(button_frame, text="Passer",
                 command=self.pass_turn,
                 font=("Arial", 12),
                 bg="#FF9800", fg="white",
                 padx=20, pady=5).pack(side=tk.LEFT, padx=5)
        
        tk.Button(button_frame, text="Quitter",
                 command=root.quit,
                 font=("Arial", 12),
                 bg="#f44336", fg="white",
                 padx=20, pady=5).pack(side=tk.LEFT, padx=5)
        
        self.draw_board()
    
    def draw_board(self):
        """Dessine le plateau de jeu"""
        self.canvas.delete("all")
        valid_moves = self.game.get_valid_moves()
        
        for row in range(BOARD_SIZE):
            for col in range(BOARD_SIZE):
                x1 = col * CELL_SIZE
                y1 = row * CELL_SIZE
                x2 = x1 + CELL_SIZE
                y2 = y1 + CELL_SIZE
                
                # Couleur de la case
                color = self.color_dark if (row + col) % 2 == 0 else self.color_light
                self.canvas.create_rectangle(x1, y1, x2, y2, fill=color, outline="#1a5c3a")
                
                cell = self.game.board[row][col]
                center_x = x1 + CELL_SIZE // 2
                center_y = y1 + CELL_SIZE // 2
                radius = CELL_SIZE // 3
                
                # Dessiner les pions
                if cell == BLACK:
                    self.canvas.create_oval(center_x - radius, center_y - radius,
                                          center_x + radius, center_y + radius,
                                          fill="black", outline="white", width=2)
                elif cell == WHITE:
                    self.canvas.create_oval(center_x - radius, center_y - radius,
                                          center_x + radius, center_y + radius,
                                          fill="white", outline="black", width=2)
                elif (row, col) in valid_moves:
                    # Indicateur de coup valide
                    small_radius = CELL_SIZE // 8
                    self.canvas.create_oval(center_x - small_radius, center_y - small_radius,
                                          center_x + small_radius, center_y + small_radius,
                                          fill=self.color_valid, outline="")
        
        self.update_info()
    
    def update_info(self):
        """Met à jour les informations de jeu"""
        black_count, white_count = self.game.count_pieces()
        self.score_label.config(text=f"Noir: {black_count} | Blanc: {white_count}")
        
        player_text = "Noir ●" if self.game.current_player == BLACK else "Blanc ○"
        self.turn_label.config(text=f"Tour: {player_text}")
    
    def on_canvas_click(self, event):
        """Gère les clics sur le plateau"""
        col = event.x // CELL_SIZE
        row = event.y // CELL_SIZE
        
        if 0 <= row < BOARD_SIZE and 0 <= col < BOARD_SIZE:
            if self.game.make_move(row, col):
                self.draw_board()
                
                # Vérifier si le joueur suivant peut jouer
                if len(self.game.get_valid_moves()) == 0:
                    if self.game.is_game_over():
                        self.show_game_over()
                    else:
                        player_name = "Blanc" if self.game.current_player == WHITE else "Noir"
                        messagebox.showinfo("Tour passé", 
                                          f"Le joueur {player_name} n'a pas de coup valide.\nLe tour passe.")
                        self.game.current_player = WHITE if self.game.current_player == BLACK else BLACK
                        self.draw_board()
            else:
                messagebox.showwarning("Coup invalide", "Ce coup n'est pas valide!")
    
    def pass_turn(self):
        """Passe le tour"""
        valid_moves = self.game.get_valid_moves()
        if len(valid_moves) == 0:
            self.game.current_player = WHITE if self.game.current_player == BLACK else BLACK
            self.draw_board()
            
            if self.game.is_game_over():
                self.show_game_over()
        else:
            messagebox.showwarning("Attention", "Vous ne pouvez pas passer, des coups sont possibles!")
    
    def show_game_over(self):
        """Affiche le résultat final"""
        black_count, white_count = self.game.count_pieces()
        
        if black_count > white_count:
            winner = "Noir gagne!"
        elif white_count > black_count:
            winner = "Blanc gagne!"
        else:
            winner = "Égalité!"
        
        message = f"Partie terminée!\n\nNoir: {black_count}\nBlanc: {white_count}\n\n{winner}"
        messagebox.showinfo("Fin de partie", message)
    
    def new_game(self):
        """Démarre une nouvelle partie"""
        self.game = ReversiGame(BOARD_SIZE)
        self.draw_board()

def main():
    root = tk.Tk()
    app = ReversiGUI(root)
    root.mainloop()

if __name__ == '__main__':
    main()