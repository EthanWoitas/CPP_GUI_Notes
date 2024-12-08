#include "texture_manager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* renderer)
{
    SDL_Surface* temp = IMG_Load(texture);  // Creates a temporary surface and oads it with a .PNG
    SDL_Texture* loadedTexture = SDL_CreateTextureFromSurface(renderer, temp); // Creates a texture from the loaded surface
    SDL_FreeSurface(temp);  // Deletes the temp surface

    return loadedTexture;
}