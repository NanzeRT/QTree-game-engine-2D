#pragma once
#include "Broadcast/Broadcast.h"
#include "Broadcast/Subscribers/IDrawSub.h"

class GameEngine;

class DrawBroadcast : public Broadcast<IDrawSub>
{
public:
    DrawBroadcast(GameEngine *ge);

    void CallOne(IDrawSub *sub) override;

private:
    GameEngine *engine;
};