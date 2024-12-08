#include "game_loop.h"

SDL_Texture* player;    // Data Structure that represents textures in the GPU's memory. This struct will be passed into func arguments
SDL_Rect srcR, destR;   // Data structure that creates two instances of a rectangle to configure size and position

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) 
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)                                     
    {
        std::cout << "Error initializing: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }
    std::cout << "Intialization cleared..." << std::endl;

    window = SDL_CreateWindow(title, xPos, yPos, width, height, fullscreen);         
    if (window == nullptr)
    {
        std::cout << "Error creating window..." << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }
    std::cout << "Window successfully created..." << std::endl;

    renderer = SDL_CreateRenderer(window, -1, 0);                               
    if(!renderer)
    {
        std::cout << "Error creating renderer..."  << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }
    std::cout << "Renderer created..." << std::endl;
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);                     

    isRunning = true;    

    SDL_Surface* temp = IMG_Load("assets/Attack.png");      // Initialize and load sprite into a surface 
    player = SDL_CreateTextureFromSurface(renderer, temp);  // Copy sprite from surface into player Texture
    SDL_FreeSurface(temp);                                  // Clean the temp surface                  
}

void Game::eventHandler()
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
    std::cout << refresh << std::endl;
    refresh++;

    destR.h = 120; // NEW
    destR.w = 320; // NEW
}

void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, player, NULL, &destR); // Copies the texture and rectangle destination to render sprite
    SDL_RenderPresent(renderer);
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