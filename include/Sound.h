#ifndef _SOUND_H_
#define _SOUND_H_

#include <SDL2/SDL.h>
#include "SDL2/SDL_mixer.h"
#include "Component.h"

using std::string;

class Sound : public Component
{
public:
    Sound(GameObject &associated);
    
    Sound(GameObject &associated, string file);
    
    ~Sound();
    
    bool Is(string type);

    bool IsOpen();
    
    void Open(string file);
    
    void Play(int times = 1);
    
    void Render();
    
    void Stop();
    
    void Update(float dt);
    
private:
    int channel;
    
    Mix_Chunk *chunk;
};

#endif
