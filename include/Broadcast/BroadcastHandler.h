#pragma once
#include <memory>
#include <vector>
#include "Broadcast/Broadcast.h"
#include "Broadcast/UpdateBroadcast.h"
#include "Broadcast/DrawBroadcast.h"
#include "EntitySystem/Component.h"

class GameEngine;

class GameBroadcastsHandler
{
public:
    GameBroadcastsHandler(GameEngine *eng)
        : engine(eng), draw(engine)
    {
    }

    UpdateBroadcast update;
    DrawBroadcast draw;

    void Add(Component *component)
    {
        update.Add(component);
        draw.Add(component);
    }

private:
    GameEngine *engine;
};