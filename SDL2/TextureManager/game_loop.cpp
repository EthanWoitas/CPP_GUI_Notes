#include "game_loop.h"
#include "texture_manager.h"

SDL_Texture* Player;
SDL_Rect srcR, destR; // srcR is unused

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

    Player = TextureManager::LoadTexture("assets/filberton.png", renderer); // Object of the TextureManager class
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
    destR.h = 120;  // Currently static, displayed the x and y coordinates of the character sprite 
    destR.w = 320;
}

void Game::render()
{
    SDL_RenderClear(renderer);                       // Clears the current rendering target
    SDL_RenderCopy(renderer, Player, NULL, &destR);  // Copies the texture and the destination and passes it to the render to render it 
    SDL_RenderPresent(renderer);                     // Displays the frame
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