#pragma once
#include <vector>
#include <memory>
#include "EntitySystem/Component.h"
#include "Utils/Delegate.h"
#include "EntitySystem/OnDestroyNotifyer.h"

class Entity : public OnDestroyNotyfier
{
public:
    Entity() {}

private:
    std::vector<Entity> childs;
    std::vector<std::unique_ptr<Component>> components;
};
