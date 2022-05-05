#pragma once
#include <X11/X.h>
#include <iostream>

struct Settings
{
    long input_mask = ExposureMask | ButtonPressMask | KeyPressMask | ButtonMotionMask | ButtonReleaseMask;
    std::pair<int, int> window_size = {500, 500};
    int FPS = 60;
};
