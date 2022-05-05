#pragma once
#include <vector>
#include "Utils/cp_ptr.h"
#include "Utils/CpPtrContainer.h"

class Entity;

class EntityContainer : public utils::CpPtrContainer<Entity>
{
public:
    EntityContainer() {}
    EntityContainer(const EntityContainer &elements_)
    {
        Construct(elements_);
    }
    EntityContainer(const std::vector<std::unique_ptr<Entity>> &elements_)
    {
        Construct(elements_);
    }
    EntityContainer(const std::initializer_list<std::unique_ptr<Entity>> &elements_)
    {
        Construct(elements_);
    }
    EntityContainer(std::initializer_list<utils::ptr_wrap<Entity>> elements_)
    {
        Construct(elements_);
    }
    virtual ~EntityContainer();

protected:
    void OnAdd(Entity *) override;
};

class Component;

class ComponentContainer : public utils::CpPtrContainer<Component>
{
public:
    ComponentContainer() {}
    ComponentContainer(const ComponentContainer &elements_)
    {
        Construct(elements_);
    }
    ComponentContainer(const std::vector<std::unique_ptr<Component>> &elements_)
    {
        Construct(elements_);
    }
    ComponentContainer(const std::initializer_list<std::unique_ptr<Component>> &elements_)
    {
        Construct(elements_);
    }
    ComponentContainer(std::initializer_list<utils::ptr_wrap<Component>> elements_)
    {
        Construct(elements_);
    }
    virtual ~ComponentContainer();

protected:
    void OnAdd(Component *) override;
};
