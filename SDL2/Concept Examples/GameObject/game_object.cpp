#include "Headers/game_object.h"
#include "Headers/texture_manager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y)
{
    renderer = ren;
    objTexture = TextureManager::LoadTexture(textureSheet, ren);

    posX = x;
    posY = y;
}

void GameObject::Update()
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