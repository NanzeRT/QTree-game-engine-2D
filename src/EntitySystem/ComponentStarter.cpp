#include "EntitySystem/ComponentStarter.h"
#include "EntitySystem/Entity.h"

void ComponentStarter::Add(Component *component)
{
    components.emplace_back(component);
}

void ComponentStarter::Call()
{
    if (components.empty())
        return;

    for (utils::DestroyableContainer<Component> &component : components)
    {
        if (component.IsAlive())
            component.Get()->PreStart();
    }
    for (utils::DestroyableContainer<Component> &component : components)
    {
        if (component.IsAlive())
            component.Get()->Start();
    }
    components.clear();
}
