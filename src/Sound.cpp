#include <iostream>
#include "../include/Sound.h"

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
        cout << "Play music." << endl;
        channel = Mix_PlayChannel(channel, chunk, times);
    }
    else
    {
        cout << "Chunk is a null pointer." << endl;
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
    chunk = Mix_LoadWAV(file.c_str());

    if (!IsOpen())
    {
        cout << "Chunk error: " << SDL_GetError() << endl;
    }
}

Sound::~Sound()
{
    if (chunk != nullptr)
    {
        Stop();
        Mix_FreeChunk(chunk);
    }
}

void Sound::Render() {}

void Sound::Update(float dt) {}

bool Sound::Is(string type)
{
    return type == "Sound";
}
