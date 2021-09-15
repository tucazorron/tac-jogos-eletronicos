#include <iostream>
#include "../include/GameObject.h"

using std::cout;
using std::endl;

GameObject::GameObject()
{
    isDead = false;
}

GameObject::~GameObject()
{
    unsigned int sizeVector = components.size();
    
    for (unsigned int i = sizeVector; i < 0; i--)
    {
        components.erase(components.begin() + i);
    }
    components.clear();
}

void GameObject::Update(float dt)
{
    unsigned int sizeVector = components.size();

    for (unsigned int i = 0; i < sizeVector; i++)
    {
        components[i]->Update(0);
    }
}

void GameObject::Render()
{
    unsigned int sizeVector = components.size();

    for (unsigned int i = 0; i < sizeVector; i++)
    {
        components[i]->Render();
    }
}

bool GameObject::IsDead()
{
    return isDead;
}

void GameObject::RequestDelete()
{
    isDead = true;
}

void GameObject::AddComponent(Component *cpt)
{
    components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component *cpt)
{
    unsigned int sizeVector = components.size();
    bool found = false;

    for (unsigned int i = 0; i < sizeVector; i++)
    {
        if (components[i].get() == cpt)
        {
            found = true;
            components.erase(components.begin() + i);
        }
    }
    if (!found)
    {
        cout << "Component not found." << endl;
    }
}

Component *GameObject::GetComponent(string type)
{
    unsigned int sizeVector = components.size();

    for (unsigned int i = 0; i < sizeVector; i++)
    {
        if (components[i].get()->Is(type))
        {
            return components[i].get();
        }
    }
    return nullptr;
}
