#ifndef game_object_h
#define game_object_h

#include "game_loop.h"

class GameObject{
public:
    GameObject(const char* textureSheet, SDL_Renderer* renderer, int x, int y);   // Constructor, accepts a texture sheets, the renderer and x and y coordinates
    ~GameObject();

    void Update();                                                  // Update gae obect upon refresh
    void Render();                                                  // Render current version of the Game Object

    int posX;                                                       // x and y positions of the Game Object 
    int posY;   

private:

    SDL_Texture* objTexture;                                        // Texture to be created from passed in textureSheet 
    SDL_Rect srcR, destR;                                           // Source and destinaion rectangle variable 
    SDL_Renderer* renderer;                                         // Renderer to be created from the passed in SDL_Renderer* renderer
};

#endif