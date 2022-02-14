#pragma once
#include "EntitySystem/OnDestroyNotifyer.h"
#include "Base/IDrawable.h"

class IDrawSub : virtual public IOnDestroyNotifyer, virtual public IDrawable
{
};
