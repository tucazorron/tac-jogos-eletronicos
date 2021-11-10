#include "SDL2/SDL.h"
#include "../include/Camera.h"
#include "../include/InputManager.h"

using std::cout;

GameObject *Camera::focus;
Vec2 Camera::pos;
Vec2 Camera::speed;

void Camera::Follow(GameObject *new_focus)
{
  focus = new_focus;
}

void Camera::Unfollow()
{
  focus = nullptr;
}

void Camera::Update(float dt)
{
  if (focus == nullptr)
  {
    InputManager &input_manager = InputManager::GetInstance();

    speed.x = 100;
    speed.y = 100;

    if (input_manager.IsKeyDown(RIGHT_ARROW_KEY))
    {
      pos.x += speed.x * dt;
    }
    else if (input_manager.IsKeyDown(LEFT_ARROW_KEY))
    {
      pos.x -= speed.x * dt;
    }
    else if (input_manager.IsKeyDown(UP_ARROW_KEY))
    {
      pos.y -= speed.y * dt;
    }
    else if (input_manager.IsKeyDown(DOWN_ARROW_KEY))
    {
      pos.y += speed.y * dt;
    }
  }
  else
  {
    pos.x = 512 + focus->box.x;
    pos.y = 300 + focus->box.y;
  }
}