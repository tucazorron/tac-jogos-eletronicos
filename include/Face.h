#ifndef _FACE_H_
#define _FACE_H_

#include "Component.h"
#include "Sound.h"

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
};

#endif
