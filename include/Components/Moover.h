#pragma once
#include "EntitySystem/Component.h"
#include "EntitySystem/Entity.h"
#include "Components/Transform.h"
#include "Broadcast/Subscribers/IUpdateSub.h"
#include "Types.h"

class Moover : public Component, virtual public IUpdateSub
{
public:
    Moover() {}
    Moover(Vector2Int speed_) : speed(speed_) {}
    Moover(const Moover &mv) : speed(mv.speed) {}

    void Start() override
    {
        transform = entity->GetComponent<Transform>();
    }

    void Update() override
    {
        transform->SetPosition(transform->GetPosition() + speed);
    }

    Component *Clone() const override { return new Moover(*this); }
    Vector2Int speed = {0, 0};

private:
    Transform *transform;
};
