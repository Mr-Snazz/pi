#include <array>

#include <wiringPi.h>

#include "core/core.hpp"
#include "pins.hpp"
#include "utilities/bit-manipulation.hpp"
#include "events-manager/events-manager.hpp"

void SPI::MainLoop()
{
    while (true)
    {
        uint16_t PinStates{};
        for (uint8_t I = 0u; I < SPI::TotalPins; ++I) SPI::SetBitInInteger(PinStates, I);

        SPI::EventsManager::ScanForEvents();
        system("clear"); return;
    }
}