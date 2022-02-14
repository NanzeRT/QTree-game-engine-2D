#pragma once
#include <vector>
#include "EntitySystem/Entity.h"
#include "Base/IDrawable.h"
//#include "Broadcast/BroadcastHandler.h"
class App;

class GameEngine
{
public:
    std::vector<Entity> scene;
    //GameBroadcastsHandler const broadcasts;

    GameEngine(App *);
    void Update();
    void DrawAll();
    void OnMouseDown(int x, int y);
    void OnMouseDrag(int x, int y);
    void OnMouseUp(int x, int y);
    //void KeyboardEvent();

    void Draw(IDrawable *drawable);
private:
    App *app;
};
