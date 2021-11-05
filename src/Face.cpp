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
    hitpoints = 30;
    timer = 2000;
}

void Face::Damage(int damage)
{
    hitpoints -= damage;
    if (hitpoints <= 0)
    {
        Sound *sound = (Sound *)(associated.GetComponent("Sound"));
        if (sound != nullptr)
        {
            sound->Play();
            SDL_Delay(300);
        }
        associated.RequestDelete();
        destroyed = true;
    }
}

void Face::Update(float dt)
{
    auto currentframe = std::chrono::steady_clock::now(); //pega o tempo de agora
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(currentframe - firstHit).count();

    while (diff < total_time)
    {
        currentframe = std::chrono::steady_clock::now();
        diff = std::chrono::duration_cast<std::chrono::milliseconds>(currentframe - firstHit).count();
    }
    interval = interval + dt;
    // cout<<"face: "<<dt<<"\n";
    if (destroy == true)
    {
        // cout<<"destruir \n";
        // cout<<dt<<" total:"<<total_time<<"\n";

        if (interval > total_time)
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