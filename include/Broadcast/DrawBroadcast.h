#pragma once
#include "Broadcast/Broadcast.h"
#include "Broadcast/Subscribers/IDrawSub.h"
#include "GameEngine.h"

class DrawBroadcast : public Broadcast<IDrawSub>
{
public:
    DrawBroadcast(GameEngine *ge)
        : engine(ge)
    {
    }

    void CallOne(IDrawSub *sub) override
    {
        engine->Draw(sub);
    }

private:
    GameEngine *engine;
};