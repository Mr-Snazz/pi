#pragma once

namespace SPI::EventsManager
{
    void Initialize();

    void NotifyEvents(uint16_t PinsStates);
}