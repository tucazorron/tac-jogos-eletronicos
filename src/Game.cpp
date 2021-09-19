#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_mixer.h>
#include "../include/Game.h"

using std::cout;
using std::endl;

#ifdef INCLUDE_SDL_IMAGE
#ifdef _WIN32
#include <SDL2/SDL_image.h>
#elif __APPLE__
#include "TargetConditionals.h"
#include <SDL2/SDL_image.h>
#elif __linux__
#include <SDL2/SDL_image.h>
#else
#error "Unknown compiler"
#endif
#undef INCLUDE_SDL_IMAGE
#endif

#ifdef INCLUDE_SDL_MIXER
#ifdef _WIN32
#include <SDL2/SDL_mixer.h>
#elif __APPLE__
#include "TargetConditionals.h"
#include <SDL2/SDL_mixer.h>
#elif __linux__
#include <SDL2/SDL_mixer.h>
#else
#error "Unknown compiler"
#endif
#undef INCLUDE_SDL_MIXER
#endif

Game *Game::instance;

Game &Game::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new Game(GAME_NAME, GAME_WIDTH, GAME_HEIGHT);
    }
    return *instance;
}

Game::Game(string title, int width, int height)
{
    if (instance == nullptr)
    {
        instance = this;
    }
    else
    {
        exit(EXIT_FAILURE);
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER))
    {
        cout << "Error while initializing SDL: " << SDL_GetError() << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "SDL Successfull!" << endl
             << "Initializing..." << endl;

        if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF))
        {
            cout << "Error while rendering image." << SDL_GetError() << endl;
        };
        Mix_Init(MIX_INIT_MP3);
        Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
        Mix_AllocateChannels(32);
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

        if (window != nullptr)
        {
            cout << "Window created." << endl;
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        }
        else
        {
            cout << "Error while creating window: " << SDL_GetError() << endl;
        }

        if (renderer != nullptr)
        {
            cout << "Render created." << endl;
            state = new State();
        }
        else
        {
            cout << "Error while creating render: " << SDL_GetError() << endl;
        }
    }
}
Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

State &Game::GetState()
{
    return *state;
}

SDL_Renderer *Game::GetRenderer()
{
    return renderer;
}

void Game::Run()
{
    while (!(state->QuitRequested()))
    {
        state->Update(0);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}