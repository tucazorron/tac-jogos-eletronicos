#include <cmath>
#include "../include/Vec2.h"

Vec2 Vec2::operator+(Vec2 b)
{
    Vec2 aux;
    aux.x = ((this->x) + (b.x));
    aux.y = ((this->y) + (b.y));

    return aux;
}

Vec2 Vec2::operator-(Vec2 b)
{
    Vec2 aux;
    aux.x = ((this->x) - (b.x));
    aux.y = ((this->y) - (b.y));

    return aux;
}

Vec2 Vec2::MultEscalar(Vec2 a, float escalar)
{
    Vec2 aux;
    aux.x = ((a.x) * (escalar));
    aux.y = ((a.y) * (escalar));

    return aux;
}

Vec2 Vec2::GetRotated(float angle)
{
    Vec2 aux;
    aux.x = (x * cos(angle)) - (y * sin(angle));
    aux.y = (y * cos(angle)) + (x * sin(angle));

    return aux;
}
