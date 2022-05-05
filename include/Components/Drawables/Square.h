#pragma once
#include "EntitySystem/Component.h"
#include "EntitySystem/Entity.h"
#include "Components/Transform.h"
#include "Broadcast/Subscribers/IDrawSub.h"
#include "Types.h"

class Square : public Component, virtual public IDrawSub
{
public:
    Square() {}
    Square(int size_)
        : size(size_)
    {
    }

    void Start() override
    {
        transform = entity->GetComponent<Transform>();
    }

    void Draw(Display *dis, Window &win, GC &gc) override
    {
        const Vector2Int &pos = transform->GetPosition();
        XFillRectangle(dis, win, gc, pos.x - size / 2, pos.y - size / 2, size, size);
    }

    Component *Clone() const override { return new Square(size); }

    ~Square()
    {
        size = 1;
    }
private:
    Transform *transform;
    int size = 10;
};
