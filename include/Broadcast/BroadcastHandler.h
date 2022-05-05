#pragma once
#include <memory>
#include <vector>
#include "Broadcast/Broadcast.h"
#include "Broadcast/UpdateBroadcast.h"
#include "Broadcast/DrawBroadcast.h"
#include "Broadcast/PointerBroadcast.h"
#include "EntitySystem/Component.h"

class GameEngine;

class GameBroadcastsHandler
{
public:
    GameBroadcastsHandler(GameEngine *eng)
        : engine(eng), draw(eng)
    {
    }

    UpdateBroadcast update;
    DrawBroadcast draw;
    PointerBroadcast pointer;

    void Add(Component *component)
    {
        update.Add(component);
        draw.Add(component);
        pointer.Add(component);
    }

private:
    GameEngine *engine;
};