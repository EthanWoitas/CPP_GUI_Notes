#ifndef game_loop_h
#define game_loop_h

#include <SDL2/SDL.h>
#include <iostream>

class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
    void eventHandler();
    void update();
    void render();
    void clean();

    int refresh = 0; // Amount of time the loop has executed 
    int FPS = 60;   // The current frame rate
    int frameDelay = 1000 / FPS;    // Milliseconds per frame

    Uint32 frameStart; // Accepts SDL_GetTicks to determine the current time in milliseconds
    int frameTime; // Used in an equation to determine how long the past frame time was

    // Function to obtain the current time at the start of the loop
    void startFrame() {
        frameStart = SDL_GetTicks();
    }

    // Function that determines how long the frame time was and delays it to meet the established FPS
    void endFrame() {
        frameTime = SDL_GetTicks() - frameStart; // Time taken for the frame
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime); // Delay to maintain constant FPS
        }
    }
    
    bool running();

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif 