#include <iostream>
#include "SDL2/SDL.h"
#include "../include/Face.h"
#include "../include/Sound.h"
#include "../include/State.h"
#include "../include/Vec2.h"

using std::cout;
using std::endl;

State::State()
{
    quitRequested = false;

    GameObject *GO = new GameObject();
    GO->box.x = 0;
    GO->box.y = 0;

    bg = new Sprite(*GO, "assets/img/ocean.jpg");
    GO->box.w = bg->GetWidth();
    GO->box.h = bg->GetHeight();
    GO->AddComponent(bg);
    objectArray.emplace_back(GO);
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
                GameObject *GO = (GameObject *)objectArray[i].get();

                if (GO->box.Contains((float)mouseX, (float)mouseY))
                {
                    cout << "Contained." << endl;

                    Face *face = (Face *)GO->GetComponent("Face");
                    if (nullptr != face)
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
                Vec2 objPos = Vec2(200, 0).GetRotated((-PI + PI * (rand() % 1001) / 500.0)) + Vec2(mouseX, mouseY);
                AddObject((int)objPos.x, (int)objPos.y);
            }
        }
    }
}

void State::LoadAssets() {}

void State::Update(float dt)
{
    Input();

    unsigned int aux = objectArray.size();

    for (unsigned int i = 0; i < aux; i++)
    {
        objectArray[i]->Update(0);
    }

    for (int unsigned i = 0; i < objectArray.size(); i++)
    {
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
    unsigned int aux = objectArray.size();

    for (unsigned int i = 0; i < aux; i++)
    {
        objectArray[i]->Render();
    }
}

void State::AddObject(int mouseX, int mouseY)
{
    cout << "Adding object" << endl;
    GameObject *firstEnemy = new GameObject();
    firstEnemy->box.x = mouseX;
    firstEnemy->box.y = mouseY;

    Sprite *penguin = new Sprite(*firstEnemy, "assets/img/penguinface.png");
    firstEnemy->box.w = penguin->GetWidth();
    firstEnemy->box.h = penguin->GetHeight();
    firstEnemy->AddComponent(penguin);
    Sound *dieSound = new Sound(*firstEnemy, "assets/audio/boom.wav");
    firstEnemy->AddComponent(dieSound);
    Face *penguinFace = new Face(*firstEnemy);
    firstEnemy->AddComponent(penguinFace);

    objectArray.emplace_back(firstEnemy);
}
