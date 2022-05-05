#pragma once
#include <vector>
#include <memory>
#include "EntitySystem/Component.h"
#include "EntitySystem/OnDestroyNotifyer.h"
#include "Utils/Delegate.h"
#include "Utils/cp_ptr.h"
#include "Utils/CpPtrContainer.h"
#include "EntitySystem/EntityContainers.h"

class GameEngine;

class Entity : public OnDestroyNotyfier
{
public:
    Entity() {}
    Entity(const Entity &);
    Entity(const ComponentContainer &components_, const EntityContainer &childs_);

    void Attach(GameEngine *ge);

    Entity *GetParent();

    const std::vector<std::unique_ptr<Entity>> &GetChilds();
    Entity *AddEntity();
    Entity *AddEntity(const Entity &);

    template<class T>
    T *GetComponent();
    template<class T>
    std::vector<T *> GetComponents();
    template<class T>
    T *AddComponent();

    Entity *Clone() const;
    void Destroy();

    utils::Delegate<void()> OnInited;

    bool dest = false;

    ~Entity()
    {
        dest = true;
    }

private:
    friend class EntityContainer;
    EntityContainer childs;
    ComponentContainer components;
    Entity *parent = nullptr;
    EntityContainer *parent_container;
    GameEngine *engine = nullptr;
};

#include "GameEngine.h"
#include "EntitySystem/Component.h"

template <class T>
T *Entity::GetComponent()
{
    T *obj;
    for (auto &c : components)
    {
        if (obj = dynamic_cast<T *>(c.get()))
            break;
    }
    return obj;
}

template <class T>
std::vector<T *> Entity::GetComponents()
{
    std::vector<T *> objs;
    for (auto &c : components)
    {
        if (T *obj = dynamic_cast<T *>(c.get()))
            objs.emplace_back(obj);
    }
    return objs;
}

template <class T>
T *Entity::AddComponent()
{
    T *component = components.Add(std::make_unique<T>()).get();
    ((Component *)component)->Init(this);
    if (engine)
        engine->AddComponent(component);
    return component;
}
