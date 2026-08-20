#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

// Structure pour une position
typedef struct Position {
    int x;
    int y;
} Position;

// Noeud de la liste chaînée
typedef struct Node {
    Position pos;
    struct Node *next;
} Node;


// Liste chaînée du serpent
typedef struct Snake {
    Node *head;  // Tête du serpent (premier maillon)
    Node *tail;  // Queue du serpent (dernier maillon)
    int length;
} Snake;

// Directions
typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

// Fonctions de gestion de la liste chaînée
Snake* snake_init(int x, int y) {
    Snake *snake = malloc(sizeof(Snake));
    Node *node = malloc(sizeof(Node));
    node->pos.x = x;
    node->pos.y = y;
    node->next = NULL;
    snake->head = node;
    snake->tail = node;
    snake->length = 1;
    return snake;
}

// Ajouter après la queue - O(1)
void snake_add_tail(Snake *snake, int x, int y) {
    Node *new_node = malloc(sizeof(Node));
    new_node->pos.x = x;
    new_node->pos.y = y;
    new_node->next = NULL;
    snake->tail->next = new_node;
    snake->tail = new_node;
    snake->length++;
}

// Retirer depuis la tête - O(1)
void snake_remove_head(Snake *snake) {
    if (snake->length <= 1) return;
    
    Node *old_head = snake->head;
    snake->head = snake->head->next;
    free(old_head);
    snake->length--;
}

// Vérifier collision avec le serpent
int snake_collides_with_self(Snake *snake, int x, int y) {
    Node *current = snake->head;
    while (current != NULL) {
        if (current->pos.x == x && current->pos.y == y) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Dessiner le serpent
void snake_draw(Snake *snake) {
    Node *current = snake->head;
    while (current != NULL) {
        // La queue (tail) est la tête du serpent
        mvaddch(current->pos.y, current->pos.x, 
                (current == snake->tail) ? 'O' : 'o');
        current = current->next;
    }
}

// Libérer la mémoire
void snake_free(Snake *snake) {
    Node *current = snake->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(snake);
}

// Générer une pomme aléatoire
Position generate_apple(Snake *snake, int max_x, int max_y) {
    Position apple;
    do {
        apple.x = rand() % (max_x - 2) + 1;
        apple.y = rand() % (max_y - 2) + 1;
    } while (snake_collides_with_self(snake, apple.x, apple.y));
    return apple;
}

// Initialiser le terminal
void terminal_init() {
    initscr();              // Initialiser ncurses
    cbreak();               // Désactiver la bufferisation de ligne
    noecho();               // Ne pas afficher les touches tapées
    keypad(stdscr, TRUE);   // Activer les touches spéciales (flèches)
    nodelay(stdscr, TRUE);  // Rendre getch() non-bloquant
    curs_set(0);            // Cacher le curseur
}

// Nettoyer et restaurer le terminal
void terminal_cleanup() {
    endwin();               // Restaurer le terminal à son état normal
}

int main() {
    // Initialisation
    srand(time(NULL));
    terminal_init();
    
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    
    // Initialiser le serpent au centre
    Snake *snake = snake_init(max_x / 2, max_y / 2);
    Direction dir = RIGHT;
    Direction next_dir = RIGHT;
    
    // Générer la première pomme
    Position apple = generate_apple(snake, max_x, max_y);
    
    int game_over = 0;
    int score = 0;
    
    while (!game_over) {
        clear();
        
        // Dessiner les bordures
        for (int i = 0; i < max_x; i++) {
            mvaddch(0, i, '#');
            mvaddch(max_y - 1, i, '#');
        }
        for (int i = 0; i < max_y; i++) {
            mvaddch(i, 0, '#');
            mvaddch(i, max_x - 1, '#');
        }
        
        // Afficher le score
        mvprintw(0, 2, " Score: %d ", score);
        
        // Dessiner la pomme
        mvaddch(apple.y, apple.x, '*');
        
        // Dessiner le serpent
        snake_draw(snake);
        
        refresh();
        
        // Gérer l'entrée clavier
        int ch = getch();
        if (ch == 'q' || ch == 'Q') break;
        
        switch (ch) {
            case KEY_UP:
                if (dir != DOWN) next_dir = UP;
                break;
            case KEY_DOWN:
                if (dir != UP) next_dir = DOWN;
                break;
            case KEY_LEFT:
                if (dir != RIGHT) next_dir = LEFT;
                break;
            case KEY_RIGHT:
                if (dir != LEFT) next_dir = RIGHT;
                break;
        }
        
        dir = next_dir;
        
        // Calculer la nouvelle position de la tête
        int new_x = snake->head->pos.x;
        int new_y = snake->head->pos.y;
        
        switch (dir) {
            case UP:    new_y--; break;
            case DOWN:  new_y++; break;
            case LEFT:  new_x--; break;
            case RIGHT: new_x++; break;
        }
        
        // Vérifier collision avec les murs
        if (new_x <= 0 || new_x >= max_x - 1 || 
            new_y <= 0 || new_y >= max_y - 1) {
            game_over = 1;
            continue;
        }
        
        // Vérifier collision avec soi-même
        if (snake_collides_with_self(snake, new_x, new_y)) {
            game_over = 1;
            continue;
        }
        
        // Ajouter la nouvelle position en queue
        snake_add_tail(snake, new_x, new_y);
        
        // Vérifier si on mange la pomme
        if (new_x == apple.x && new_y == apple.y) {
            score++;
            apple = generate_apple(snake, max_x, max_y);
        } else {
            // Retirer la tête si pas de pomme mangée
            snake_remove_head(snake);
        }
        
        usleep(100000); // 100ms de délai
    }
    
    // Game Over
    clear();
    mvprintw(max_y / 2, max_x / 2 - 10, "GAME OVER!");
    mvprintw(max_y / 2 + 1, max_x / 2 - 10, "Score: %d", score);
    mvprintw(max_y / 2 + 2, max_x / 2 - 15, "Appuyez sur une touche...");
    refresh();
    nodelay(stdscr, FALSE);
    getch();
    
    // Nettoyage
    snake_free(snake);
    terminal_cleanup();
    
    return 0;
}

/* 
 * Compilation:
 * gcc -o snake snake.c -lncurses
 * 
 * Exécution:
 * ./snake
 * 
 * Contrôles:
 * - Flèches directionnelles pour diriger le serpent
 * - 'q' pour quitter
 */