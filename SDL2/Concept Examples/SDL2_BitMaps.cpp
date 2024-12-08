#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* [])
{
    SDL_Window* window = NULL;
    SDL_Surface* windowSurface = NULL; // SDL_Surface is a 2d image or rectanguar area of pixels stored in memory.
    SDL_Surface* imageSurface = NULL;  // It is used to to manipulate the windows image before rendering happens on the screen. 

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Video Initializatino Error: " << SDL_GetError() << std::endl;
    }

    else
    {
        window = SDL_CreateWindow("Bit Maps", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

        if (window == NULL)
        {
            std::cout << "Window Creation Error: " << SDL_GetError() << std::endl;
        }

        else
        {

            windowSurface = SDL_GetWindowSurface(window); // Creating a surface from the address pointed to by window. This represents the drawable area.
            imageSurface = SDL_LoadBMP("textures/Untitled.bmp");   // This loads a .bmp from the project dir.

            if (imageSurface == NULL)
            {
                std::cout << "Image Failed to load: " << SDL_GetError() << std::endl; // Error checking
            }

            else
            {
                SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL); // Blits (Copies pixel data) from one surface, to the other.   
                SDL_UpdateWindowSurface(window);
                SDL_Delay(5000);
            }
        }
    }

    SDL_FreeSurface(imageSurface); // Free the memory that was written onto the surface from the .bmp.
    imageSurface = NULL;           // Avoid a dangling pointer. 
    SDL_DestroyWindow(window);
    window = NULL;
    windowSurface = NULL;          // Avoid a dangling pointer. This does not need to be freed as it was just a pointer* to window.
    SDL_Quit();

    return 0;
}
