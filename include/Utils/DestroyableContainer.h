#pragma once
#include "Utils/Delegate.h"
#include "EntitySystem/OnDestroyNotifyer.h"

namespace utils
{
    template <class T = OnDestroyNotyfier>
    struct DestroyableContainer
    {
        DestroyableContainer(T &obj_) : DestroyableContainer(*obj_)
        {
        }

        DestroyableContainer(T *obj_)
            : obj(obj_)
        {
            on_destroy_handle = obj->GetOnDestroyDelegate() += [this]()
            {
                this->is_alive = false;
            };
        }

        DestroyableContainer(const DestroyableContainer &a) : DestroyableContainer(a.obj)
        {
        }

        T *Get()
        {
            if (is_alive)
                return obj;
            return nullptr;
        }

        bool IsAlive() { return is_alive; }
        ~DestroyableContainer()
        {
            if (is_alive)
                obj->GetOnDestroyDelegate() -= on_destroy_handle;
        }

    private:
        T *obj;
        bool is_alive = true;

        Delegate<void()>::handle on_destroy_handle;
    };
}