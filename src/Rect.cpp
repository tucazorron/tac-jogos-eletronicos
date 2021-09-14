#include "../include/Rect.h"

bool Rect::Contains(float mouseX, float mouseY)
{
    float width = x + w;
    float height = y + h;

    return mouseX >= x && mouseX <= width && mouseY >= y && mouseY <= height;
}