#include "Drawables/Square.h"

Square::Square(Transformable *obj_, int size_)
    : obj(obj_), size(size_)
{
}

void Square::Draw(Display *dis, Window &win, GC &gc)
{
    XFillRectangle(dis, win, gc, obj->X() - size / 2, obj->Y() - size/2, size, size);
}