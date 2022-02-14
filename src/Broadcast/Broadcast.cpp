#include "Broadcast/Broadcast.h"

template <class T>
Broadcast<T>::Broadcast() {}

template <class T>
void Broadcast<T>::Add(Component *component)
{
    if (T *t = dynamic_cast<T *>(component))
        components.emplace_back(t);
}

template <class T>
void Broadcast<T>::Call()
{
    for (auto it = components.begin(); it < components.end(); ++it)
    {
        if (!it->IsAlive())
        {
            auto quick_erase_it = it; // daft punk's "technologic" starts to play
            components.erase(quick_erase_it);
            continue;
        }

        CallOne(it->Get());
    }
}
