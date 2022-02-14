#include "GameEngine.h"
#include "App.h"
#include "Entities/MouseSquare.h"

GameEngine::GameEngine(App *app_)
    : app(app_)//, broadcasts(this)
{

}

void GameEngine::Update() 
{

}


MouseSquare ms;

void GameEngine::DrawAll()
{
    app->Draw(ms.GetDrawable());
}

void GameEngine::OnMouseDown(int x, int y)
{
    ms.Move(x, y);
}

void GameEngine::OnMouseDrag(int x, int y)
{
    ms.Move(x, y);
}

void GameEngine::OnMouseUp(int x, int y)
{

}

void GameEngine::Draw(IDrawable *drawable) { app->Draw(drawable); }