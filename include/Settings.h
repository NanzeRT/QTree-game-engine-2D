#pragma once
#include <X11/X.h>

struct Settings
{
    long input_mask = ExposureMask | ButtonPressMask | KeyPressMask | ButtonMotionMask;
    std::pair<int, int> window_size = {500, 500};
    int FPS = 60;
};
