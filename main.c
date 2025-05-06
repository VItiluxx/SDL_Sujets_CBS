#include <SDL3/SDL.h>

int main(int argc, char* argv[]) {
    // Initialisation SDL3
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Erreur SDL init: %s", SDL_GetError());
        return 1;
    }

    // Création fenêtre (API différente en SDL3)
    SDL_Window* window = SDL_CreateWindow("Portail Mobile", 800, 600, 0);
    if (!window) {
        SDL_Log("Erreur création fenêtre: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Création renderer (API simplifiée)
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        SDL_Log("Erreur création renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Affichage pendant 3 secondes
    SDL_Delay(3000);

    // Nettoyage (identique à SDL2)
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}