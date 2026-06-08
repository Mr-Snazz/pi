#pragma once

#include <stdint.h>

#include <string>

namespace SPI::EventsManager
{
    class Event
    {
    public:
        std::string Name;
        uint32_t TriggerKey;

        Event(const std::string& Name, uint32_t TriggerKey);

        void OnTrigger() const;

    private:


    };
}