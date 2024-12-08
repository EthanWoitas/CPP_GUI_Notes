#ifndef texture_manager_h
#define texture_manager_h

#include "game_loop.h"

class TextureManager{

public:
    static SDL_Texture* LoadTexture(const char* filename);
};

#endif