#include <iostream>
#include "SDL2/SDL.h"
#include "../include/Face.h"
#include "../include/Sound.h"
#include "../include/State.h"
#include "../include/Vec2.h"
#include "../include/TileSet.h"
#include "../include/TileMap.h"
#include "../include/InputManager.h"
#include "../include/Camera.h"
#include "../include/CameraFollower.h"

using std::cout;
using std::endl;

State::State() : music("./assets/audio/stageState.ogg")
{
    quitRequested = false;
    music.Play(-1);

    GameObject *go = new GameObject();
    go->box.x = 0;
    go->box.y = 0;

    bg = new Sprite(*go, "assets/img/ocean.jpg");
    go->box.w = bg->GetWidth();
    go->box.h = bg->GetHeight();
    go->AddComponent(bg);

    CameraFollower *cf = new CameraFollower(*go);
    go->AddComponent(cf);

    objectArray.emplace_back(go);

    go = new GameObject();
    go->box.x = 0;
    go->box.y = 0;

    TileSet *tile_set = new TileSet(64, 64, "./assets/img/tileset.png");
    TileMap *tileMap = new TileMap(*go, "./assets/map/tileMap.txt", tile_set);
    go->AddComponent(tileMap);

    objectArray.emplace_back(go);
}

State::~State()
{
    objectArray.clear();
}

void State::LoadAssets() {}

void State::Update(float dt)
{
    Camera::Update(dt);
    InputManager &input_manager = InputManager::GetInstance();

    if (input_manager.IsKeyDown(ESCAPE_KEY) || (input_manager.QuitRequested()))
    {
        quitRequested = true;
    }

    if (input_manager.KeyPress(SDLK_SPACE))
    {
        Vec2 objPos = Vec2(200, 0).GetRotated((-PI + PI * (rand() % 1001) / 500.0)) + Vec2(input_manager.GetMouseX(), input_manager.GetMouseY());
        AddObject((int)objPos.x, (int)objPos.y);
    }

    unsigned int aux = objectArray.size();

    for (unsigned int i = 0; i < aux; i++)
    {
        objectArray[i]->Update(dt);
    }

    for (int unsigned i = 0; i < objectArray.size(); i++)
    {
        if (objectArray[i]->IsDead())
        {
            cout << "\n array size: ";
            cout << (objectArray.size()) << "\n";
            objectArray.erase(objectArray.begin() + i);
            i--;
            cout << i << " is dead \n";
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

void State::AddObject(int x_mouse, int y_mouse)
{
    GameObject *object = new GameObject();
    object->box.x = x_mouse + Camera::pos.x;
    object->box.y = y_mouse + Camera::pos.y;

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
