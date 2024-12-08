#include "texture_manager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* renderer)
{
    SDL_Surface* temp = IMG_Load(texture);
    SDL_Texture* loadedTexture = SDL_CreateTextureFromSurface(renderer, temp);
    SDL_FreeSurface(temp);
}