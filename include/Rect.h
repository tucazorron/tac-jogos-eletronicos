#ifndef _RECT_H_
#define _RECT_H_

class Rect
{
public:
    Rect();
    bool Contains(float mouseX, float mouseY);
    float x, y, w, h;
};

#endif
