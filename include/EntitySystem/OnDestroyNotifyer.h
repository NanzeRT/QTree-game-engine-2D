#pragma once
#include "Utils/Delegate.h"

class IOnDestroyNotifyer
{
public:
    virtual utils::Delegate<void()> &GetOnDestroyDelegate() = 0;
};

class OnDestroyNotyfier : virtual public IOnDestroyNotifyer
{
public:
    utils::Delegate<void()> &GetOnDestroyDelegate() override { return onDestroy; }
    virtual ~OnDestroyNotyfier() { onDestroy(); }

private:
    utils::Delegate<void()> onDestroy;
};