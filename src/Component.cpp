#include "../include/Component.h"
#include "../include/GameObject.h"

Component::Component(GameObject &associated) : associated(associated) {}

Component::~Component() {}

bool Component::Is(string type) {
    return type == "Component";
}

void Component::Render() {}

void Component::Update(float dt) {}
