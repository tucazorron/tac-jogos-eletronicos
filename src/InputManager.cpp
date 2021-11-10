#include "../include/InputManager.h"
#include "SDL2/SDL.h"
#include <iostream>

using std::cout;

InputManager::InputManager()
{
  quitRequested = false;

  for (int i = 0; i < 6; i++)
  {
    mouseState[i] = false;
    mouseUpdate[i] = 0;
  }

  updateCounter = 0;

  cout << "input manager criado\n";
}

InputManager::~InputManager()
{
}

InputManager &InputManager::GetInstance()
{
  static InputManager inputManager;
  return inputManager;
}

void InputManager::Update()
{

  SDL_Event event;
  SDL_GetMouseState(&mouseX, &mouseY);
  quitRequested = false;
  updateCounter++;

  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      quitRequested = true; /* constant-expression */
      /* code */
      break;
    case SDL_MOUSEBUTTONDOWN:
    {
      int but = event.button.button;
      mouseState[but] = true;
      mouseUpdate[but] = updateCounter;
    }
    break;

    case SDL_MOUSEBUTTONUP:
    {
      int but = event.button.button;
      mouseState[but] = false;
      mouseUpdate[but] = updateCounter;
    }
    break;
    case SDL_KEYDOWN:
    {
      if (event.key.repeat != 1)
      { 
        SDL_Keycode keyd = event.key.keysym.sym;
        keyState[keyd] = true;
        keyUpdate[keyd] = updateCounter;
      }
    }

    break;

    case SDL_KEYUP:
    {
      SDL_Keycode keyU = event.key.keysym.sym;
      keyState[keyU] = false;
      keyUpdate[keyU] = updateCounter;
    }

    break;
    }
  }
}

bool InputManager::KeyPress(int key)
{

  return ((keyState[key]) && (keyUpdate[key] == updateCounter));
}

bool InputManager::KeyRelease(int key)
{

  return ((!keyState[key]) && (keyUpdate[key] == updateCounter));
}

bool InputManager::MousePress(int button)
{

  return ((mouseState[button]) && (mouseUpdate[button] == updateCounter));
}

bool InputManager::MouseRelease(int button)
{

  return ((!mouseState[button]) && (mouseUpdate[button] == updateCounter));
}

bool InputManager::IsKeyDown(int key)
{

  return keyState[key];
}

bool InputManager::IsMouseDown(int button)
{

  return mouseState[button];
}

int InputManager::GetMouseX()
{
  return mouseX;
}

int InputManager::GetMouseY()
{
  return mouseY;
}

bool InputManager::QuitRequested()
{
  return quitRequested;
}