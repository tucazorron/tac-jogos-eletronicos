#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <string>
#include <SDL2/SDL.h>
#include "Component.h"
#include "GameObject.h"

using std::string;

class Sprite
{
public:
    Sprite(GameObject &associated);

    Sprite(GameObject &associated, string file);

    ~Sprite();

    void Open(string file);

    bool IsOpen();

    void SetClip(int x, int y, int w, int h);

    void Render(int x, int y);

    int GetWidth();

    int GetHeight();

    void Update(float dt);

    bool Is(string type);

private:
    SDL_Texture *texture;

    SDL_Rect clipRect;

    int width;

    int height;
};

#endif