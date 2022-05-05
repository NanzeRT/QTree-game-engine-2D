#pragma once
#include "Broadcast/Broadcast.h"
#include "EventData/PointerEventData.h"
#include "Broadcast/Subscribers/IPointerSub.h"

class PointerBroadcast : public Broadcast<IPointerSub, PointerEventData>
{
public:
    void CallOne(IPointerSub *sub, PointerEventData event_data) override
    {
        sub->OnPointer(event_data);
    }
};