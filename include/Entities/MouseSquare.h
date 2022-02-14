#pragma once
#include "../Drawables/Square.h"

class MouseSquare : Transformable
{
    Square sqr{this, 40};

public:
    IDrawable *GetDrawable() { return &sqr; };
    void Move(int x_, int y_)
    {
        x = x_;
        y = y_;
    }
};