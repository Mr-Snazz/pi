#pragma once

#include <stdint.h>

#include <vector>

namespace SPI
{
    constexpr int32_t InputPins[] = 
    {
        4, 5, 6, 17, 22, 23, 24, 25, 26, 27
    };

    constexpr uint8_t TotalPins = sizeof(InputPins) / sizeof(InputPins[0]);

    inline uint16_t GetPinsKey(const std::vector<int>& Pins);
}

#include "pins/pins.inl"

