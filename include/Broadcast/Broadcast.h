#pragma once
#include <list>
#include "EntitySystem/Component.h"
#include "Utils/DestroyableContainer.h"

class IBroadcast
{
public:
    virtual void Add(Component *) = 0;
};

template <class T, typename... Args>
class Broadcast : virtual public IBroadcast
{
public:
    void Add(Component *) override;
    void Call(Args...);

private:
    std::list<utils::DestroyableContainer<T>> components;

    virtual void CallOne(T *, Args...) = 0;
};

template <class T, typename... Args>
void Broadcast<T, Args...>::Add(Component *component)
{
    if (T *t = dynamic_cast<T *>(component))
        components.emplace_back(t);
}

template <class T, typename... Args>
void Broadcast<T, Args...>::Call(Args... args)
{
    for (auto it = components.begin(); it != components.end(); it++)
    {
        if (!it->IsAlive())
        {
            auto quick_erase_it = it; // daft punk's "technologic" starts to play
            it--;
            components.erase(quick_erase_it);
            continue;
        }

        CallOne(it->Get(), args...);
    }
}
