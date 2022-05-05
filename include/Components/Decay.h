#pragma once
#include "EntitySystem/Component.h"
#include "EntitySystem/Entity.h"
#include "Components/Transform.h"
#include "Broadcast/Subscribers/IUpdateSub.h"
#include "Types.h"
#include "Components/Moover.h"

#include <iostream>

class Decay : public Component, virtual public IUpdateSub
{
public:
    Decay() {}
    Decay(float time_) : time(time_) {}
    Decay(const Decay &dc) : time(dc.time) {}

    void Update() override
    {
        passed += 1.0/60;
        if (passed >= time)
        {
            entity->Destroy();
            std::cout << "ded\n";
        }
    }

    Component *Clone() const override { return new Decay(*this); }
    float time = 1;

private:
    float passed = 0;
};
