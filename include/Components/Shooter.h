#pragma once
#include "EntitySystem/Component.h"
#include "EntitySystem/Entity.h"
#include "Components/Transform.h"
#include "Components/Drawables/Square.h"
#include "Components/Moover.h"
#include "Components/Decay.h"
#include "Broadcast/Subscribers/IUpdateSub.h"
#include "Broadcast/Subscribers/IPointerSub.h"
#include "Types.h"

#include <cmath>

const static Entity bullet_pref = {
    {
        Transform(),
        Square(5),
        Decay(0.5),
        Moover()
    },
    {}
};

class Shooter : public Component, virtual public IPointerSub
{
public:
    Shooter() {}
    Shooter(const Shooter &mf) {}

    void Start() override
    {
        transform = entity->GetComponent<Transform>();
    }

    void OnPointer(const PointerEventData &event_data) override
    {
        if (event_data.state != PointerState::down)
            return;

        Vector2Int delta = (event_data.position - transform->GetPosition());
        
        Entity *bullet = entity->AddEntity(bullet_pref);
        bullet->GetComponent<Moover>()->speed = {(delta * 10) / abs(delta)};
    }

    Component *Clone() const override { return new Shooter(*this); }

private:
    Transform *transform;
};
