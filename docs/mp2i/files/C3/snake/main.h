#ifndef MAIN_H
#define MAIN_H

// Position et dimensions de la fenetre
#define WIN_W 640
#define WIN_H 480
#define WIN_X 50
#define WIN_Y 50

// Dimensions de l'arene 
#define ARENA_W 20
#define ARENA_H 10
#define B_SIZE 20

// Types de blocs
#define VIDE 0
#define WALL 1
#define COCO 2
#define SNAKE 3
#define BG 4

/* L'arene est définie comme une matrice
   de blocs */
typedef int Arena[ARENA_W][ARENA_H];

#endif