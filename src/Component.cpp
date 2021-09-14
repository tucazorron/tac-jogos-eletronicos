#include "../include/Component.h"

Component::Component(GameObject &associated) : associated(associated) {}

Component::~Component() {}

void Component::Render() {}

void Component::Update(float dt) {}

bool Component::Is(string type) {}
