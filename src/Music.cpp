#include <iostream>
#include "../include/Music.h"
#include "../include/Resources.h"

using std::cout;
using std::endl;

Music::Music()
{
    music = nullptr;
}

Music::Music(string file)
{
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
    music = Resources::GetMusic(file);
    if (music == nullptr)
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