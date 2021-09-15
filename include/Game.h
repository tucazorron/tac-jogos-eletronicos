#ifndef _GAME_H_
#define _GAME_H_

#ifdef INCLUDE_SDL
#ifdef _WIN32
#include <SDL2/SDL.h>
#elif __APPLE__
#include "TargetConditionals.h"
#include <SDL2/SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#else
#error "Unknown compiler"
#endif
#undef INCLUDE_SDL
#endif

#include <string>
#include "State.h"

using std::string;

class Game
{
public:
    ~Game();

    static Game &GetInstance();

    SDL_Renderer *GetRenderer();

    State &GetState();

    void Run();

private:
    Game(string mytitle, int mywidth, int myheight);

    int width, height;

    static Game *instance;

    SDL_Renderer *renderer;

    State *state;

    string title;

    SDL_Window *window;
};

#endif