#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Component.h"
#include "Rect.h"

using std::string;
using std::vector;

class Component;

class GameObject
{
public:
    GameObject();
    ~GameObject();
    void Update(float dt);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component *cpt);
    void RemoveComponent(Component *cpt);
    Component *GetComponent(string type);
    Rect box;

private:
    vector<std::unique_ptr<Component>> components;
    bool isDead;
};

#endif
