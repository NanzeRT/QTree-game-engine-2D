#include "EntitySystem/Entity.h"
#include <stdexcept>
#include "GameEngine.h"

Entity::Entity(const Entity &entity)
    : childs(entity.childs),
      components(entity.components)
{
    for (auto &e : childs)
        e->parent = this;
    for (auto &c : components)
        c->Init(this);
    OnInited();
    OnInited.Clear();
}

Entity::Entity(const ComponentContainer &components_, const EntityContainer &childs_)
    : components(components_), childs(childs_)
{
    for (auto &component : components)
    {
        ((Component *)component.get())->Init(this);
    }
    OnInited();
    OnInited.Clear();
}

void Entity::Attach(GameEngine *ge)
{
    if (ge == engine)
        return;
    if (engine)
        throw std::logic_error("multiple GameEngines attached to same entity");
    engine = ge;

    for (auto &c : components)
    {
        auto *a = c.get();
        engine->AddComponent(a);
    }
    for (auto &child : childs)
        child->Attach(engine);
}

Entity *Entity::GetParent() { return parent; }
const std::vector<std::unique_ptr<Entity>> &Entity::GetChilds() { return childs.GetAll(); }

Entity *Entity::AddEntity()
{
    Entity *child = childs.Add();
    child->parent = this;
    if (engine)
        child->Attach(engine);
    return child;
}

Entity *Entity::AddEntity(const Entity &e)
{
    Entity *child = childs.Add(e);
    child->parent = this;
    if (engine)
        child->Attach(engine);
    return child;
}

Entity *Entity::Clone() const { return new Entity(*this); }
void Entity::Destroy() { parent_container->Remove(this); }
