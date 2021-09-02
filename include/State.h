#ifndef _STATE_H_
#define _STATE_H_

#include "Sprite.h"

class State
{
public:
    State();
    bool QuitRequested();
    void LoadAssets();
    void Update();
    void Render();

private:
    Sprite bg;
    bool quitRequested;
};

#endif