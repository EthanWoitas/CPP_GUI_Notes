#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* [])
{
    SDL_Window* window = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) // Sets up subsystems, initializing the SDL library. returns 0 on pass and -1 on failure
    {
        std::cout << "Video initialization error" << SDL_GetError() << std::endl;
    }

    window = SDL_CreateWindow("Button Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    bool running = true; // Create a driver for the window loop
    SDL_Event ev;        // Creates a variable called ev that is used to store event dat such as
                         //    user inputs or windows events. 

    while (running)      // While loop to continuously loop the window
    {
        while(SDL_PollEvent(&ev) != 0) // Creates a que that checks for events every frame, if there is an event, it will no longer
        {                              //    be equal to zero and execute the code within its loop.
            if(ev.type == SDL_QUIT)    // If the event that was processed was SDL_QUIT (Clicking the 'X' button)  
            {                          //    then thh driver boolen will be turned off, killing the application.
                running = false;
            }
        }

        SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();

    return 0;
}