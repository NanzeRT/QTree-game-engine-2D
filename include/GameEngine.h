#pragma once
#include <vector>
#include "EntitySystem/Component.h"
#include "EntitySystem/ComponentStarter.h"
#include "EntitySystem/EntityContainers.h"
#include "Base/IDrawable.h"
#include "Broadcast/BroadcastHandler.h"
class App;

class GameEngine
{
public:
    EntityContainer scene;

    GameEngine(App *);
    void Update();
    void DrawAll();
    void OnMouseDown(int x, int y);
    void OnMouseDrag(int x, int y);
    void OnMouseUp(int x, int y);
    //void KeyboardEvent();

    void AddComponent(Component *);
    void Draw(IDrawable *drawable);
private:
    GameBroadcastsHandler broadcasts;
    ComponentStarter component_starter;
    App *app;
};

#include "EntitySystem/Entity.h"
#include "EntitySystem/Component.h"
