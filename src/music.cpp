#include <iostream>
#include "../include/music.hpp"

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
    if (music == nullptr)
    {
        cout << "Erro ao carregar musica: " << SDL_GetError() << endl;
    }
    else
    {
        Mix_LoadMUS(file.c_str());
    }
}

bool Music::IsOpen()
{
    if (music != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Music::~Music()
{
    Stop(0);
    Mix_FreeMusic(music);
}