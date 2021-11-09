#ifndef _STATE_H_
#define _STATE_H_

#include <string>
#include <vector>
#include "Face.h"
#include "Music.h"
#include "Sprite.h"

using std::string;
using std::unique_ptr;

class State
{
public:
    State();
    ~State();
    void LoadAssets();
    bool QuitRequested();
    void Render();
    void Update(float dt);

private:
    void AddObject(int mousex, int mouseY);
    void Input();
    Sprite *bg;
    Music music;
    vector<unique_ptr<GameObject>> objectArray;
    bool quitRequested;
};

#endif