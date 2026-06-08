#include <wiringPi.h>

#include "core/core.hpp"
#include "pins.hpp"

#include <iostream>
void SPI::MainLoop()
{
    while (true)
    {
        for (uint8_t I = 0u; I < SPI::TotalPins; ++I) {
            int32_t Pin = SPI::InputPins[I];
            
            if (digitalRead(Pin) == LOW) {
                std::cout << "Activity detected on pin " << Pin << std::endl;
            }
        }
    }
}