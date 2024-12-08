#include "Headers/game_loop.h"
#include "Headers/game_object.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y) 
{
    renderer = ren; // Renderer created
    objTexture = TextureManager::LoadTexture(textureSheet, ren); // Load texture 

    posX = x;   // Starting X and Y are arguments passed in
    posY = y;
}

void GameObject::Update() // Update the source and destination rectangle upon refresh
{
    srcR.h = 32;    
    srcR.w = 32;
    srcR.x = 0;
    srcR.y = 0;

    destR.h = srcR.h;
    destR.w = srcR.w;
    destR.x = posX;
    destR.y = posY;
}

void GameObject::Render()
{
    SDL_RenderCopy(renderer, objTexture, &srcR, &destR);
}