#pragma once
#include "EntitySystem/OnDestroyNotifyer.h"

class IUpdateSub : virtual public IOnDestroyNotifyer
{
public:
    virtual void Update() = 0;
};
