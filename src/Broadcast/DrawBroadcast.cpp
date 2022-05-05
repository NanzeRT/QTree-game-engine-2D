#include "Broadcast/DrawBroadcast.h"
#include "GameEngine.h"

DrawBroadcast::DrawBroadcast(GameEngine *ge)
    : engine(ge)
{
}

void DrawBroadcast::CallOne(IDrawSub *sub)
{
    engine->Draw(sub);
}
