#include "EntitySystem/EntityContainers.h"
#include "EntitySystem/Entity.h"
#include "EntitySystem/Component.h"

void EntityContainer::OnAdd(Entity *entity)
{
    entity->parent_container = this;
    static int i = 0;
    i++;
    if (i > 10)
    {
        i++;
    }
}
void ComponentContainer::OnAdd(Component *component) { component->parent_container = this; }

ComponentContainer::~ComponentContainer() {}
EntityContainer::~EntityContainer() {}
