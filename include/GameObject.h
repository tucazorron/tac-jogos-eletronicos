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

    void AddComponent(Component *cpt);

    Rect box;

    Component *GetComponent(string type);

    bool IsDead();

    void RemoveComponent(Component *cpt);

    void Render();

    void RequestDelete();

    void Update(float dt);

private:
    vector<std::unique_ptr<Component>> components;

    bool isDead;
};

#endif
