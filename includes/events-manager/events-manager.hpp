#pragma once

#include "pins/pins.hpp"

namespace SPI::EventsManager
{
    void Initialize();

    void NotifyEvents(SPI::Pins PinStates);
}