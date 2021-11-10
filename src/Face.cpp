#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include "SDL2/SDL.h"
#include "../include/Face.h"
#include "../include/Sound.h"
#include "../include/InputManager.h"
#include "../include/Camera.h"

using std::cout;
using std::endl;

Face::Face(GameObject &associated) : Component(associated)
{
    hit_points = 30;
    timer = 2;
}

void Face::Damage(int damage)
{
    hit_points -= damage;
    if (hit_points <= 0)
    {
        Sound *sound = (Sound *)(associated.GetComponent("Sound"));
        if (sound != nullptr)
        {
            sound->Play(1);
            SDL_Delay(300);
        }
        destroyed = true;
    }
}

void Face::Update(float dt)
{
    interval = interval + dt;
    if (destroyed == true)
    {
        if (interval > timer)
        {
            associated.RequestDelete();
        }
    }
    else
    {
        InputManager &Iman = InputManager::GetInstance();
        if (Iman.MousePress(SDL_BUTTON_LEFT))
        {
            int x_aux = Iman.GetMouseX() + Camera::pos.x;
            int y_aux = Iman.GetMouseY() + Camera::pos.y;
            if (associated.box.Contains((float)x_aux, (float)y_aux))
            {
                Damage(std::rand() % 10 + 10);
            }
        }
    }
}

bool Face::Is(string type)
{
    return type == "Face";
}

void Face::Render() {}