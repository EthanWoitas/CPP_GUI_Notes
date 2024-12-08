#include "Headers/game_loop.h"
#include "Headers/game_object.h"
#include "Headers/texture_manager.h"

GameObject* Player; // Instance of a game object

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
    
    Player = new GameObject("Assets/U_Walk.png", renderer, 0, 0); // Creating the game object                                                  
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

    Player->Update(); // Updating the game object
}

void Game::render()
{
    SDL_RenderClear(renderer);      
    Player->Render(); // Rendering the game object 
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