#include <iostream>
#include "Headers/texture_manager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* renderer)
{
    SDL_Surface* temp = IMG_Load(texture);  // Create a temporary surface
    SDL_Texture* loadedTexture = SDL_CreateTextureFromSurface(renderer, temp); // Copy that surface into a texture
    if (loadedTexture == NULL) // Error checking
    {
        std::cout << "Error creating texture: " << texture << std::endl;
    }
    SDL_FreeSurface(temp); // Free the temp surface 

    return loadedTexture; // Return the texture 
}