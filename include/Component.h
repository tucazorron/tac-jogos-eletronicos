#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <iostream>
#include <string>
#include "GameObject.h"

using std::string;

class GameObject;

class Component
{
public:
    Component(GameObject &associated);
    virtual ~Component();
    virtual bool Is(string type);
    virtual void Render();
    virtual void Update(float dt);

protected:
    GameObject &associated;
};

#endif
