#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include "SDL2/SDL.h"
#include "../include/Face.h"
#include "../include/Sound.h"

using std::cout;
using std::endl;

Face::Face(GameObject &associated) : Component(associated)
{
    hit_points = 30;
    timer = 2000;
}

void Face::Damage(int damage)
{
    hit_points -= damage;
    if (hit_points <= 0)
    {
        Sound *sound = (Sound *)(associated.GetComponent("Sound"));
        if (sound != nullptr)
        {
            sound->Play();
            SDL_Delay(300);
        }
        destroyed = true;
    }
}

void Face::Update(float dt)
{
    auto current_time = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - first_hit).count();

    while (diff < timer)
    {
        current_time = std::chrono::steady_clock::now();
        diff = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - first_hit).count();
    }
    interval = interval + dt;
    if (destroyed == true)
    {
        if (interval > timer)
        {
            associated.RequestDelete();
        }
    }
}

bool Face::Is(string type)
{
    return type == "Face";
}

void Face::Render() {}