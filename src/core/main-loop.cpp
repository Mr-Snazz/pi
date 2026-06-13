#include <array>

#include <wiringPi.h>

#include "core/core.hpp"
#include "pins/pins.hpp"
#include "utilities/bit-manipulation.hpp"
#include "events-manager/events-manager.hpp"

#include <iostream>
void SPI::MainLoop()
{
    return;
    while (true)
    {
        SPI::Pins PinStates{};
        //SPI::SetBitInInteger(PinStates, 26);
        //SPI::SetBitInInteger(PinStates, 27);

        //for (int32_t Pin : SPI::InputPins) {
        //    bool RecievingInput = digitalRead(Pin);
        //    if (!RecievingInput) continue;

        //    SPI::SetBitInInteger(PinStates, Pin);
        //}

        SPI::EventsManager::NotifyEvents(PinStates); 

        if (SPI::Terminate.load()) break; 
    }
}