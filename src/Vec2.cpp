#include <cmath>
#include "../include/Vec2.h"

Vec2::Vec2(float xvalue, float yvalue)
{
    x = xvalue;
    y = yvalue;
}

Vec2 Vec2::operator+(Vec2 b)
{
    Vec2 position;
    position.x = x + b.x;
    position.y = y + b.y;

    return position;
}

Vec2 Vec2::operator-(Vec2 b)
{
    Vec2 position;
    position.x = x - b.x;
    position.y = y - b.y;

    return position;
}

Vec2 Vec2::MultEscalar(Vec2 a, float escalar)
{
    Vec2 position;
    position.x = a.x * escalar;
    position.y = a.y * escalar;

    return position;
}

Vec2 Vec2::GetRotated(float angle)
{
    Vec2 position;
    position.x = x * cos(angle) - y * sin(angle);
    position.y = y * cos(angle) + x * sin(angle);

    return position;
}
