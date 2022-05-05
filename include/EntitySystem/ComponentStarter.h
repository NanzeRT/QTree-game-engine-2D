#pragma once
#include <vector>
#include "EntitySystem/Component.h"
#include "Utils/DestroyableContainer.h"

class ComponentStarter
{
public:
    void Add(Component *);
    void Call();

private:
    std::vector<utils::DestroyableContainer<Component>> components;

};
