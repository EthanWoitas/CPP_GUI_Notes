#include "game_loop.h"

Game* game = nullptr;

int main(int argc, const char* argv[])
{
    game = new Game();

    game->init("LoremIpsum", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);
    while (game->running())
    {
        game->eventHandler();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}