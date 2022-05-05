#pragma once
#include "EntitySystem/Component.h"
#include "EntitySystem/Entity.h"
#include "Components/Transform.h"
#include "Broadcast/Subscribers/IUpdateSub.h"
#include "Broadcast/Subscribers/IPointerSub.h"
#include "Types.h"

#include <cmath>

class MouseFollower : public Component, virtual public IUpdateSub, virtual public IPointerSub
{
public:
    MouseFollower() {}
    MouseFollower(const MouseFollower &mf) : pos(mf.pos) {}

    void Start() override
    {
        transform = entity->GetComponent<Transform>();
    }

    void Update() override
    {
        static float t = 0;
        t += 1/60.0 * M_PI * 2;
        Vector2Int delta = pos - transform->GetPosition() + Vector2Int{(int)(cos(t) * 100), (int)(sin(t) * 100)};
        if (delta)
        {
            transform->SetPosition(transform->GetPosition() + (delta * 5) / abs(delta));
        }
    }

    void OnPointer(const PointerEventData &event_data) override
    {
        pos = event_data.position;
    }

    Component *Clone() const override { return new MouseFollower(*this); }

private:
    Transform *transform;
    Vector2Int pos = {0, 0};
};
