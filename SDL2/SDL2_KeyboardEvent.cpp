#include <SDL2/SDL.h>
#include <iostream>

bool running = true; // Loop driver

int main(int argc, char* [])
{
    SDL_Window* window = NULL;                          // Create an instance of a window initialized to NULL
    SDL_Surface* windowSurface = NULL;                
    SDL_Surface* images[4] = {NULL, NULL, NULL, NULL};  // Array of surfaces that will eventually load images 
    SDL_Surface* currImage = NULL;                      // To keep tract of the current image being blit onto windowSurface


    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Error intializing window" << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("Keyboard Event", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        std::cout << "Window creation error: " << SDL_GetError() << std::endl;
        return 1;
    }

    windowSurface = SDL_GetWindowSurface(window);   // Create a surface using the dimensions of window
    if (windowSurface == NULL)
    {
        std::cout << "Surface Creation Error: " << SDL_GetError() << std::endl;
    }

    // Initialize the images with .bmp's
    images[0] = SDL_LoadBMP("textures/up.bmp");
    images[1] = SDL_LoadBMP("textures/right.bmp");
    images[2] = SDL_LoadBMP("textures/down.bmp");
    images[3] = SDL_LoadBMP("textures/left.bmp");

    currImage = windowSurface; // currImage will just be a black screen displayingwindowSurface
    SDL_Event movement;        // Create an event, this will track the WASD keys 

    while (running)
    {
        while(SDL_PollEvent(&movement) != 0) // Misleading because of the movement event, allows to close the loop when needed 
        {
            if(movement.type == SDL_QUIT)       
            {
                running = false;
                break;
            }
            if(movement.type == SDL_KEYDOWN)       // SLD_KEYDOWN tracks when a key is initially pressed down
            {
                switch(movement.key.keysym.sym)    // (movement.key) means the event has to be == to a keyboard event 
                {                                  // (keysym) containsdetails realated to the input (.sym) accepts a an SDL_KEY enum 
                case SDLK_w:                       // which decscribes which key was pressed. Each case below pertains to a certain key.
                    currImage = images[0];
                    break;
                
                case SDLK_d:
                    currImage = images[1];
                    break;
                
                case SDLK_s:
                    currImage = images[2];
                    break;
                
                case SDLK_a:
                    currImage = images[3];
                    break;
                }
            }
        }
        
        SDL_BlitSurface( currImage, NULL, windowSurface, NULL);
        SDL_UpdateWindowSurface(window);
    }

    for (int i = 0; i < 4; i++)     // For loop to free surface memory and avoid dangling pointers.
    {
        SDL_FreeSurface(images[i]);
        images[i] = NULL;
    }

    SDL_DestroyWindow(window);
    window = NULL;
    windowSurface = NULL;
    SDL_Quit();
}
