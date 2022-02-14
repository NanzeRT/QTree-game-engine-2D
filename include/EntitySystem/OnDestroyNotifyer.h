#pragma once
#include "Utils/Delegate.h"

class IOnDestroyNotifyer
{
public:
    virtual Delegate<void()> &GetOnDestroyDelegate() = 0;
};

class OnDestroyNotyfier : virtual public IOnDestroyNotifyer
{
public:
    Delegate<void()> &GetOnDestroyDelegate() override { return onDestroy; }
    virtual ~OnDestroyNotyfier() { onDestroy(); }

private:
    Delegate<void()> onDestroy;
};