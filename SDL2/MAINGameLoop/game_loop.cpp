#include "Headers/game_loop.h"

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) // Check here if error is thrown because of flags
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)                                     // Initialize Timers, Video, Audio, Joystick, Game Controllers, Haptic, Events, and Sensors
    {
        std::cout << "Error initializing: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }
    std::cout << "Intialization cleared..." << std::endl;

    window = SDL_CreateWindow(title, xPos, yPos, width, height, fullscreen);         // Create a window instance and initialize with arguments
    if (window == nullptr)
    {
        std::cout << "Error creating window..." << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }
    std::cout << "Window successfully created..." << std::endl;

    renderer = SDL_CreateRenderer(window, -1, 0);                               // Create a renderer, passes window as an argument to render textures
    if(!renderer)
    {
        std::cout << "Error creating renderer..."  << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }
    std::cout << "Renderer created..." << std::endl;
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);                     

    isRunning = true;                                                           // Sets the game loop driver to all systems go *Puts on sunglasses*
}

void Game::eventHandler()   // Event handler that upon every loop cheacks for events such as player input
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
    }
    
}

void Game::update()
{
    std::cout << refresh << std::endl;  // Prints each iteration of a loop while game->running
    refresh++;
}

void Game::render()
{
    SDL_RenderClear(renderer);      // Clears the current rendering target
    
    SDL_RenderPresent(renderer);    // Displays the frame
}

void Game::clean() 
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit;
    std::cout << "Everything has been destroyed..." << std::endl;
}

bool Game::running()
{
    return isRunning;
}