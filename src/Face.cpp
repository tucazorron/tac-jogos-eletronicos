#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "../include/Face.h"
#include "../include/Sound.h"

using std::cout;
using std::endl;

Face::Face(GameObject &associated) : Component(associated)
{
    hitpoints = 30;
}

void Face::Damage(int damage)
{
    hitpoints = hitpoints - damage;
    if (hitpoints < 0)
    {
        Sound *sound = reinterpret_cast<Sound *>(associated.GetComponent("Sound"));
        if (sound != nullptr)
        {
            sound->Play();
        }
        associated.RequestDelete();
    }
}

bool Face::Is(string type)
{
    return type == "Face";
}

void Face::Render() {}

void Face::Update(float dt) {}
