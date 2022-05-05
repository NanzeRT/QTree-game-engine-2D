#pragma once
#include "Types.h"

enum PointerState
{
    down,
    drag,
    up,
};

struct PointerEventData
{
    PointerState state;
    Vector2Int position;
};
