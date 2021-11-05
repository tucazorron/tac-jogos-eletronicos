#include <iostream>
#include "../include/GameObject.h"
#include "../include/Sound.h"
#include "../include/Resources.h"

using std::cout;
using std::endl;

Sound::Sound(GameObject &associated) : Component(associated)
{
    chunk = nullptr;
}

Sound::Sound(GameObject &associated, string file) : Component(associated)
{
    Open(file);
}

void Sound::Play(int times)
{
    if (chunk != nullptr)
    {
        channel = Mix_PlayChannel(-1, chunk, times);
        if (channel == -1)
        {
            cout << "Error playing channel: " << Mix_GetError() << endl;
        }
        Mix_Volume(channel, MIX_MAX_VOLUME);
    }
}

void Sound::Stop()
{
    if (chunk != nullptr)
    {
        Mix_HaltChannel(channel);
    }
}

bool Sound::IsOpen()
{
    return chunk != nullptr;
}

void Sound::Open(string file)
{
    chunk = Resources::GetSound(file);

    if (!IsOpen())
    {
        cout << "Sound loading error: " << SDL_GetError() << endl;
    }
}

Sound::~Sound()
{
    if (chunk != nullptr)
    {
        Stop();
    }
}

void Sound::Render() {}

void Sound::Update(float dt) {}

bool Sound::Is(string type)
{
    return type == "Sound";
}
