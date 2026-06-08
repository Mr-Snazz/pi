#pragma once

#include <stdint.h>

namespace SPI
{
    constexpr int32_t InputPins[] = 
    {
        4, 5, 6, 17, 22, 23, 24, 25, 26, 27
    };

    constexpr uint8_t TotalPins = sizeof(InputPins) / sizeof(InputPins[0]);
}