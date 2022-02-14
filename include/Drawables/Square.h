#pragma once
#include "Base/IDrawable.h"
#include "Base/Transformable.h"

class Square : public IDrawable
{
public:
    Square(Transformable *obj_, int size_);
    void Draw(Display *dis, Window &win, GC &gc) override;

private:
    Transformable *obj;
    int size;
};