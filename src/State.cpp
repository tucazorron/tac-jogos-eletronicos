#include <iostream>
#include "SDL2/SDL.h"
#include "../include/Face.h"
#include "../include/Sound.h"
#include "../include/State.h"
#include "../include/Vec2.h"
#include "../include/TileSet.h"
#include "../include/TileMap.h"

using std::cout;
using std::endl;

State::State() : music("./assets/audio/bensound-dubstep.mp3")
{
    quitRequested = false;
    LoadAssets();
    music.Play();

    GameObject *GO = new GameObject();
    GO->box.x = 0;
    GO->box.y = 0;
    GO->box.w = bg->GetWidth();
    GO->box.h = bg->GetHeight();
    GO->AddComponent(bg);
    objectArray.emplace_back(GO);
    GO = new GameObject();
    GO->box.x = 0;
    GO->box.y = 0;
    TileSet *tileSet = new TileSet(64, 64, "./assets/img/tileset.png");
    TileMap *tileMap = new TileMap(*GO, "./assets/map/tileMap.txt", tileSet);
    GO->AddComponent(tileMap);
    objectArray.emplace_back(GO);

    bg = new Sprite(*GO, "assets/img/ocean.jpg");
}

State::~State()
{
    objectArray.clear();
}

void State::Input()
{
    SDL_Event event;
    int mouseX, mouseY;

    SDL_GetMouseState(&mouseX, &mouseY);

    while (SDL_PollEvent(&event))
    {

        if (event.type == SDL_QUIT)
        {
            quitRequested = true;
        }

        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            for (int i = objectArray.size() - 1; i >= 0; i--)
            {
                GameObject *object = (GameObject *)objectArray[i].get();

                if (object->box.Contains((float)mouseX, (float)mouseY))
                {
                    Face *face = (Face *)object->GetComponent("Face");
                    if (face != nullptr)
                    {
                        face->Damage(std::rand() % 10 + 10);
                        break;
                    }
                }
            }
        }
        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                quitRequested = true;
            }
            else
            {
                Vec2 position = Vec2(200, 0).GetRotated((-PI + PI * (rand() % 1001) / 500.0)) + Vec2(mouseX, mouseY);
                AddObject((int)position.x, (int)position.y);
            }
        }
    }
}

void State::LoadAssets()
{
    GameObject *object = new GameObject();
    object->box.x = 0;
    object->box.y = 0;
    object->box.w = bg->GetWidth();
    object->box.h = bg->GetHeight();

    bg = new Sprite(*object, "assets/img/ocean.jpg");
    object->AddComponent(bg);

    objectArray.emplace_back(object);

    music = *new Music("assets/audio/stageState.ogg");
}

void State::Update(float dt)
{
    Input();

    for (unsigned int i = 0; i < objectArray.size(); i++)
    {
        objectArray[i]->Update(dt);
        if (objectArray[i]->IsDead())
        {
            objectArray.erase(objectArray.begin() + i);
            i--;
        }
    }
}

bool State::QuitRequested()
{
    return quitRequested;
}

void State::Render()
{
    for (unsigned int i = 0; i < objectArray.size(); i++)
    {
        objectArray[i]->Render();
    }
}

void State::AddObject(int mouseX, int mouseY)
{
    GameObject *object = new GameObject();
    object->box.x = mouseX;
    object->box.y = mouseY;

    Sprite *penguin = new Sprite(*object, "assets/img/penguinface.png");
    object->AddComponent(penguin);

    object->box.w = penguin->GetWidth();
    object->box.h = penguin->GetHeight();

    Sound *sound = new Sound(*object, "assets/audio/boom.wav");
    object->AddComponent(sound);

    Face *penguinFace = new Face(*object);
    object->AddComponent(penguinFace);

    objectArray.emplace_back(object);
}
