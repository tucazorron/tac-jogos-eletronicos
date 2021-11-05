#ifndef _FACE_H_
#define _FACE_H_

#include "Component.h"
#include "Sound.h"
#include <chrono>

use namespace std::chrono;

class Face : public Component
{
public:
    Face(GameObject &associated);

    void Damage(int damage);

    bool Is(string type);

    void Render();

    void Update(float dt);

private:
    int hitpoints;
    bool destroyed = false;
    float interval;
    float timer;
    chrono::steady_clock::time_point first_hit;
};

#endif
