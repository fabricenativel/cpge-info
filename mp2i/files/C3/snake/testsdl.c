#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Erreur lors de l'initialisation : %s \n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Window *fenetre = SDL_CreateWindow("Snake974", 50, 50, 640, 480, 0);
    if (fenetre == NULL) {
        fprintf(stderr, "Erreur lors de la création de la fenêtre : %s \n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Delay(5000); // Attendre 5 sec
    SDL_DestroyWindow(fenetre);
    SDL_Quit();

    return EXIT_SUCCESS;
}