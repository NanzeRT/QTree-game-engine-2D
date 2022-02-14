#pragma once
#include <vector>
#include <memory>
#include "EntitySystem/Component.h"
#include "Utils/Delegate.h"
#include "EntitySystem/OnDestroyNotifyer.h"
#include "Utils/cp_ptr.h"

class Entity : public OnDestroyNotyfier
{
public:
    Entity() {}

    template<class T>
    T *GetComponent();
    template<class T>
    std::vector<T *> GetComponents();
    template<class T>
    T *AddComponent();

private:
    std::vector<Entity> childs;
    std::vector<utils::cp_ptr<Component>> components;
};
