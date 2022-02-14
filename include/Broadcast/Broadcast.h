#pragma once
#include <deque>
#include "EntitySystem/Entity.h"
#include "EntitySystem/Component.h"
#include "Utils/DestroyableContainer.h"

class IBroadcast
{
public:
    virtual void Add(Component *) = 0;
    virtual void Call() = 0;
};

template<class T>
class Broadcast : virtual public IBroadcast
{
public:
    Broadcast();
    void Add(Component *) override;
    void Call() override;

private:
    std::deque<DestroyableContainer<T>> components;

    virtual void CallOne(T *) = 0;
};
