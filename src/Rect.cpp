#include "../include/Rect.h"

Rect::Rect()
{
    x = 0;
    y = 0;
    w = 0;
    h = 0;
}

bool Rect::Contains(float mouseX, float mouseY)
{
    float width = x + w;
    float height = y + h;

    return mouseX >= x && mouseX <= width && mouseY >= y && mouseY <= height;
}