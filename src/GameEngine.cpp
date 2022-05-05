#include "GameEngine.h"
#include "App.h"
#include "GameData.h"

GameEngine::GameEngine(App *app_)
    : app(app_), broadcasts(this)
{
    scene = init_state;
    for (auto &e : scene)
        e->Attach(this);
}

void GameEngine::Update()
{
    component_starter.Call();
    broadcasts.update.Call();
}

void GameEngine::DrawAll()
{
    broadcasts.draw.Call();
}

void GameEngine::OnMouseDown(int x, int y)
{
    broadcasts.pointer.Call({PointerState::down, x, y});
}

void GameEngine::OnMouseDrag(int x, int y)
{
    broadcasts.pointer.Call({PointerState::drag, x, y});
}

void GameEngine::OnMouseUp(int x, int y)
{
    broadcasts.pointer.Call({PointerState::up, x, y});
}

void GameEngine::AddComponent(Component *component)
{
    component_starter.Add(component);
    broadcasts.Add(component);
}

void GameEngine::Draw(IDrawable *drawable) { app->Draw(drawable); }