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

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif 