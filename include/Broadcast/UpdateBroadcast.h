#pragma once
#include "Broadcast/Broadcast.h"
#include "Broadcast/Subscribers/IUpdateSub.h"

class UpdateBroadcast : public Broadcast<IUpdateSub>
{
    void CallOne(IUpdateSub *c) override
    {
        c->Update();
    }
};
