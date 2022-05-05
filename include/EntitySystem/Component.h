#pragma once
#include "Utils/Delegate.h"
#include "EntitySystem/OnDestroyNotifyer.h"
#include "EntitySystem/EntityContainers.h"

class Entity;

class Component : public OnDestroyNotyfier
{
public:
    Component(){}
    Component(const Component &component){}
    void Init(Entity *entity_) { entity = entity_; Awake(); }

    // called immideatly after creation.
    // for local use only.
    virtual void Awake() {};

    // called before Start
    virtual void PreStart() {};
    
    // called before first Update
    virtual void Start() {};

    virtual Component *Clone() const = 0;
    void Destroy() { parent_container->Remove(this); }

protected:
    Entity *entity;

private:
    friend class ComponentContainer;
    ComponentContainer *parent_container;
};
