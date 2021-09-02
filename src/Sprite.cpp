#include <iostream>
#include <SDL2/SDL_image.h>
#include "../include/Sprite.h"
#include "../include/Game.h"

using std::cout;
using std::endl;

Sprite::Sprite()
{
    texture = nullptr;
}

Sprite::Sprite(string file) : texture(IMG_LoadTexture(
                                  Game::GetInstance().GetRenderer(),
                                  file.c_str()))
{

    Open(file);
}

Sprite::~Sprite()
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
    }
}

void Sprite::Open(string file)
{

    if (texture == nullptr)
    {
        cout << "Error while creating image: " << SDL_GetError() << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) == 0)
        {
            SetClip(0, 0, width, height);
        }
        else
        {
            cout << "Error on QueryTexture: " << SDL_GetError() << endl;
        };
    }
}

void Sprite::SetClip(int x, int y, int w, int h)
{
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

int Sprite::GetWidth()
{
    return clipRect.w;
}
int Sprite::GetHeight()
{
    return clipRect.h;
}
void Sprite::Render(int x, int y)
{

    SDL_Renderer *renderer = Game::GetInstance().GetRenderer();

    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = clipRect.w;
    dst.h = clipRect.h;

    if (texture != nullptr)
    {
        if (SDL_RenderCopy(renderer, texture, &clipRect, &dst) != 0)
        {
            cout << "Error while rendering copy: " << SDL_GetError() << endl;
        }
    }
}

bool Sprite::IsOpen()
{
    if (texture != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    };
}