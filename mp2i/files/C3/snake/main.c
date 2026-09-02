#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "serpent.h"
#include <stdint.h>

struct color_s
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t opacity;
};
typedef struct color_s color;

const color SNAKE_COLOR = {.red = 0, .green = 255, .blue = 0, .opacity = 255};
const color VIDE_COLOR = {.red = 255, .green = 255, .blue = 255, .opacity = 255};
const color COCO_COLOR = {.red = 127, .green = 0, .blue = 127, .opacity = 255};
const color WALL_COLOR = {.red = 0, .green = 0, .blue = 0, .opacity = 255};
const color BG_COLOR = {.red = 127, .green = 127, .blue = 127, .opacity = 255};
const color COLOR[5] = {VIDE_COLOR, WALL_COLOR, COCO_COLOR, SNAKE_COLOR, BG_COLOR};

/* Construit une arène entièrement vide */
void init_arena(Arena mat)
{
    for (int x = 0; x < ARENA_W; x++)
    {
        for (int y = 0; y < ARENA_H; y++)
        {
            mat[x][y] = VIDE;
        }
    }
}

void mur_enceinte(Arena mat)
{
    for (int x = 0; x < ARENA_W; x++)
    {
        mat[x][0] = WALL;
        mat[x][ARENA_H - 1] = WALL;
    }
    for (int y = 0; y < ARENA_H; y++)
    {
        mat[0][y] = WALL;
        mat[ARENA_W - 1][y] = WALL;
    }
}

void draw_arena(SDL_Renderer *renderer, Arena mat)
{
    SDL_SetRenderDrawColor(renderer, COLOR[BG].red, COLOR[BG].green, COLOR[BG].blue, 255);
    SDL_RenderClear(renderer);
    for (int x = 0; x < ARENA_W; x++)
    {
        for (int y = 0; y < ARENA_H; y++)
        {
            SDL_Rect rect = {x * B_SIZE, y * B_SIZE, B_SIZE - 2, B_SIZE - 2};
            SDL_SetRenderDrawColor(renderer, COLOR[mat[x][y]].red, COLOR[mat[x][y]].green, COLOR[mat[x][y]].blue, COLOR[mat[x][y]].opacity);
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

void place_coco(Arena mat, int* cocox, int* cocoy)
{
    int cx = 0;
    int cy = 0;
    while (mat[cx][cy]!=VIDE)
    {
        cx = rand()%ARENA_W;
        cy = rand()%ARENA_H;
    }
    *cocox = cx;
    *cocoy = cy;
}

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *fenetre = SDL_CreateWindow("Snake974", WIN_X, WIN_Y, WIN_W, WIN_H, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    int coco_x;
    int coco_y;
    bool coco;
    Serpent *s = creer_serpent(3, 3, RIGHT);
    for (int k = 0; k < 5; k++)
    {
        grandir(s);
    }
    Arena mat;

    bool run = true;

    while (run)
    {
        init_arena(mat);
        mur_enceinte(mat);
        place_serpent(s, mat);
        if (!coco)
        {
            place_coco(mat,&coco_x,&coco_y);
            coco = true;
        }
        mat[coco_x][coco_y] = COCO;
        draw_arena(renderer, mat);
        SDL_RenderPresent(renderer);

        SDL_Delay(200);
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_KEYDOWN)
            {
                fprintf(stderr, "Touche pressée : %c \n", event.key.keysym.sym);
            }
            if (event.key.keysym.sym == 'x')
            {
                run = false; // touche pour quitter le jeu
            }
            if (event.key.keysym.sym == 'q')
            {
                s->direction = LEFT;
            }
            if (event.key.keysym.sym == 's')
            {
                s->direction = DOWN;
            }
            if (event.key.keysym.sym == 'd')
            {
                s->direction = RIGHT;
            }
            if (event.key.keysym.sym == 'z')
            {
                s->direction = UP;
            }
        }
        if (appartient(s, prochain_x(s), prochain_y(s)) || (mat[prochain_x(s)][prochain_y(s)] == WALL))
        {
            run = false;
        }
        if (mat[prochain_x(s)][prochain_y(s)] == COCO)
        {
            grandir(s);
            coco = false;
        }
        else
        {
            avancer(s);
        }
    }

    destroy_serpent(s);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();

    return EXIT_SUCCESS;
}