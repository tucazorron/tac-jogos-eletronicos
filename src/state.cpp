#include "../include/state.hpp"
#include "SDL2/SDL.h"
#include <iostream>

using std::cout;

State::State() : bg("assets/background.jpg")
{
    quitRequested = false;
}

void State::LoadAssets() {}

void State::Update()
{
    if (SDL_QuitRequested())
    {
        quitRequested = true;
    }
}

bool State::QuitRequested()
{
    return quitRequested;
}

void State::Render()
{
    bg.Render(0, 0);
}
