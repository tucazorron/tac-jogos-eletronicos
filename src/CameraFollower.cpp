#include "../include/Camera.h"
#include "../include/CameraFollower.h"

CameraFollower::CameraFollower(GameObject &game_object) : Component(game_object) {}

void CameraFollower::Update(float dt)
{
  associated.box.x = Camera::pos.x;
  associated.box.y = Camera::pos.y;
}

void CameraFollower::Render() {}

bool CameraFollower::Is(string type)
{
  return type == "CameraFollower";
}