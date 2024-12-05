#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[])
{
    SDL_Window* window = NULL; //SDL_Window is a data type that represents a window on the screen. Initialized to NULL to start

    if (SDL_Init(SDL_INIT_VIDEO) < 0) // Sets up subsystems, initializing the SDL library. returns 0 on pass and -1 on failure
    {
        std::cout << "Video initialization error" << SDL_GetError() << std::endl;
    }
    else
    {
        window = SDL_CreateWindow(  // Creates the window, passing it to SDL_Window window
            "Window demonstration",     // Title of the window
            SDL_WINDOWPOS_CENTERED,     // X position of the window
            SDL_WINDOWPOS_CENTERED,     // Y position of the window
            640,                        // Width of the window
            480,                        // Height of the window
            SDL_WINDOW_SHOWN);          // Makes the window visible after creation. Many other flags can be used here to influence how the window is shown

        if (window = NULL)          // Returns NULL if window creation failed
        {
            std::cout << "Window creation error" << SDL_GetError() << std::endl;
        }
        else
        {
            SDL_UpdateWindowSurface(window); // Updates the window displaying the current state of "window"
            SDL_Delay(5000);                 // Pauses for a moment to display the window for 5000 milliseconds
        }
    }

    SDL_DestroyWindow(window); // Frees up the memory that was initilaized by SDL_Window* window
    SDL_Quit();                // Properly frees up resources and shuts down anything initialied by SDL_Init()

    return 1;
}