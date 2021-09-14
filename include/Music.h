#ifndef _MUSIC_H_
#define _MUSIC_H_

#include <string>
#include <SDL2/SDL.h>
#include "SDL2/SDL_mixer.h"

using std::string;

class Music
{
public:
    Music();
    Music(string file);
    ~Music();
    void Play(int times = -1);
    void Stop(int msToStop = 1500);
    void Open(string file);
    bool IsOpen();

private:
    Mix_Music *music;
};

#endif