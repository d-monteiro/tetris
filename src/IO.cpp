#include "IO.hpp"
#include <cstdlib>
#include <stdio.h>

// ------ Defines -----
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_Event event;
static bool windowClosed = false;

IO::IO() {
    InitGraph();
}

bool IO::IsWindowClosed() {
    return windowClosed;
}

int IO::InitGraph() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // Create window
    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                               SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return -1;
    }

    return 0;
}

void IO::DrawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC) {
    SDL_Rect rect;
    rect.x = pX1;
    rect.y = pY1;
    rect.w = pX2 - pX1 + 1;
    rect.h = pY2 - pY1 + 1;

    switch (pC) {
        case BLACK:
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            break;
        case RED:
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            break;
        case GREEN:
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            break;
        case BLUE:
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            break;
        case CYAN:
            SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
            break;
        case MAGENTA:
            SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
            break;
        case YELLOW:
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            break;
        case WHITE:
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            break;
    }
    
    SDL_RenderFillRect(renderer, &rect);
}

void IO::ClearScreen() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

int IO::GetScreenHeight() {
    return SCREEN_HEIGHT;
}

int IO::Pollkey() {
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN)
            return event.key.keysym.sym;
        if (event.type == SDL_QUIT) {
            windowClosed = true;
        }
    }
    return -1;
}

int IO::Getkey() {
    while (true) {
        if (SDL_WaitEvent(&event)) {
            if (event.type == SDL_KEYDOWN)
                return event.key.keysym.sym;
            // Check if window close button was pressed
            if (event.type == SDL_QUIT)
                exit(0);
        }
    }
}

int IO::IsKeyDown(int pKey) {
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    
    if (pKey == SDLK_ESCAPE && state[SDL_SCANCODE_ESCAPE]) {
        return 1;
    }
    
    return 0;
}

void IO::UpdateScreen() {
    SDL_RenderPresent(renderer);
}