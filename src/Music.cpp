#include <iostream>
#include "../include/Music.h"

using std::cout;
using std::endl;

Music::Music()
{
    music = nullptr;
}

Music::Music(string file)
{
    music = nullptr;
    Open(file);
}

void Music::Play(int times)
{
    if (music != nullptr)
    {
        Mix_PlayMusic(music, times);
    }
}

void Music::Stop(int msToStop)
{
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file)
{
    if (music != nullptr)
    {
        Mix_LoadMUS(file.c_str());
    }
    else
    {
        cout << "Music loading error: " << SDL_GetError() << endl;
    }
}

bool Music::IsOpen()
{
    return music != nullptr;
}

Music::~Music()
{
    Stop(0);
    Mix_FreeMusic(music);
}