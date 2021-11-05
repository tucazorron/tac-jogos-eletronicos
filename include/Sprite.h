#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <string>
#include <SDL2/SDL.h>
#include "Component.h"
#include "GameObject.h"

using std::string;

class Sprite : public Component
{
public:
    Sprite(GameObject &associated);
    Sprite(GameObject &associated, string file);
    ~Sprite();
    int GetHeight();
    int GetWidth();
    bool Is(string type);
    bool IsOpen();
    void Open(string file);
    void Render();
    void Render(float a, float b);
    void SetClip(int x, int y, int w, int h);
    void Update(float dt);

private:
    int width, height;
    SDL_Rect clipRect;
    SDL_Texture *texture;
};

#endif