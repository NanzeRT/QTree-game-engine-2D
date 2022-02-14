#pragma once
#include "X11.h"
#include <chrono>
#include <iostream>
#include <thread>
#include "Settings.h"
#include "GameEngine.h"
#include "Base/IDrawable.h"

class GDrawable;

class App
{
public:
    App();
    App(Settings);
    void StartLoop();
    void Draw(IDrawable *);

private:
    Display *dis;
    int screen;
    Window win;
    GC gc;

    Settings settings;
    GameEngine game_engine;

    void InitX();
    void Loop();
    void HandleXEvents();
    void Redraw();
    void Close();
};
