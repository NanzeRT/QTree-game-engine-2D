#pragma once
#include "EntitySystem/Component.h"
#include "EntitySystem/Entity.h"
#include "Types.h"

class Transform : public Component
{
public:
    Transform() {}
    Transform(Vector2Int vec) : local_position(vec) {}
    void PreStart() override
    {
        if (entity->GetParent())
            parent_transform = entity->GetParent()->GetComponent<Transform>();
    }
    Vector2Int GetPosition() { return (parent_transform != nullptr ? local_position + parent_transform->GetPosition() : local_position); }
    void SetPosition(Vector2Int pos) { local_position = pos - (parent_transform != nullptr ? parent_transform->GetPosition() : Vector2Int{0, 0}); }
    Component *Clone() const override { return new Transform(local_position); }
    Vector2Int local_position = {0, 0};

private:
    Transform *parent_transform = nullptr;
};
