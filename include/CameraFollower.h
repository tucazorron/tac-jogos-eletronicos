#ifndef _CF_H_
#define _CF_H_

#include <chrono>
#include "Component.h"

class CameraFollower : public Component
{
public:
    CameraFollower(GameObject &go);
    void Update(float dt);
    void Render();
    bool Is(string type);
};

#endif