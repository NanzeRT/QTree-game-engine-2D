#pragma once
#include "X11.h"

class IDrawable
{
public:
    virtual void Draw(Display *dis, Window &win, GC &gc) = 0;
};
