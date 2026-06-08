#pragma once

#include <stdint.h>

#include <string>

namespace SPI::EventsManager
{
    class Event
    {
    public:
        std::string Name;
        uint32_t TriggerPins;

        Event(const std::string& IName, uint32_t ITriggerPins);

        void OnTrigger() const;

    private:


    };
}