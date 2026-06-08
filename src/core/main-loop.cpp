#include <array>

#include <wiringPi.h>

#include "core/core.hpp"
#include "core/should-terminate.hpp"
#include "pins/pins.hpp"
#include "utilities/bit-manipulation.hpp"
#include "events-manager/events-manager.hpp"

void SPI::MainLoop()
{
    while (true)
    {
        SPI::Pins PinStates;
        SPI::SetBitInInteger(PinStates, 26);
        SPI::SetBitInInteger(PinStates, 27);

        //for (int32_t Pin : SPI::InputPins) {
        //    bool RecievingInput = digitalRead(Pin);
        //    if (!RecievingInput) continue;

        //    SPI::SetBitInInteger(PinStates, Pin);
        //}

        SPI::EventsManager::NotifyEvents(PinStates); 

        bool ShouldTerminate = SPI::Terminate.load();
        if (ShouldTerminate) break;
    }
}