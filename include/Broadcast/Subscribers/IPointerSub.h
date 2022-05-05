#pragma once
#include "EntitySystem/OnDestroyNotifyer.h"
#include "EventData/PointerEventData.h"

class IPointerSub : virtual public IOnDestroyNotifyer
{
public:
    virtual void OnPointer(const PointerEventData &event_data) = 0;
};
