#include "../include/Component.h"

Component::Component(GameObject &associated) : associated(associated) {}

Component::~Component() {}

bool Component::Is(string type) {}

void Component::Render() {}

void Component::Update(float dt) {}
