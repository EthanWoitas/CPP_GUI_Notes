#ifndef game_object_h
#define game_object_h

#include "game_loop.h"
#include "texture_manager.h"

class GameObject{

public:
    GameObject(const char* textureSheet, SDL_Renderer* renderer, int x, int y); 
    ~GameObject();

    void Update();  // Func to update attributes of the object
    void Render();  // Func to render current update of the object

    int posX;       // Starting X and Y coordinates from GameObject arguments 
    int posY;

private:
    SDL_Texture* objTexture;    // Texture to be loaded in from textureSheet 
    SDL_Rect srcR, destR;       // Establish the source and destination rectangles 
    SDL_Renderer* renderer;     // Renderer to be used passed in from SDL_Renderer* render
};

#endif
