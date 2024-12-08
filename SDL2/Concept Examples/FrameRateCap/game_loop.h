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

    bool running();

    int refresh = 0; // Counts every time the loop iterates
    int FPS = 60;   // The current frame rate
    int frameDelay = 1000 / FPS;    // Milliseconds per frame

    Uint32 frameStart;
    int frameTime;

    void startFrame() {
        frameStart = SDL_GetTicks(); // Get the current time in milliseconds
    }

    void endFrame() {
        frameTime = SDL_GetTicks() - frameStart; // Time taken for the frame
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime); // Delay to maintain constant FPS
        }
    }

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif 