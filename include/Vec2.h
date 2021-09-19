#ifndef _VEC2_H_
#define _VEC2_H_

#define PI 3.141592

#include <cmath>

class Vec2
{
public:
    float x, y;

    Vec2(float xvalue = 0, float yvalue = 0);

    Vec2 GetRotated(float angle);

    Vec2 MultEscalar(Vec2 a, float escalar);

    Vec2 operator+(Vec2 b);

    Vec2 operator-(Vec2 b);
};

#endif
