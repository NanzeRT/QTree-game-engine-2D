#pragma once
#include "Components/Transform.h"
#include "Components/Shooter.h"
#include "Components/Drawables/Square.h"
#include "EntitySystem/Entity.h"

const EntityContainer init_state = {
    Entity
    {
        {
            Transform({50, 250}),
            Shooter(),
            Square(50)
        },
        {}
    }
};
