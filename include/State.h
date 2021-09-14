#ifndef _STATE_H_
#define _STATE_H_

#include <string>
#include <vector>
#include "Sprite.h"
#include "Face.h"

using std::string;

class State
{
public:
    State();
    ~State();
    bool QuitRequested();
    void LoadAssets();
    void Update();
    void Render();

private:
    void Input();
    void AddObject(int mousex, int mouseY);
    vector<std::unique_ptr<GameObject>> objectArray;
    Sprite bg;
    bool quitRequested;
};

#endif