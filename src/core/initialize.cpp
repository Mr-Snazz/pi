#include <stdexcept>

#include <wiringPi.h>

#include "core/core.hpp"
#include "pins.hpp"

void SPI::Initialize()
{
    if (wiringPiSetupGpio() == -1) throw std::runtime_error("Failed to initialize wiringPi");

    for (uint8_t I = 0u; I < SPI::TotalPins; ++I) {
        pinMode(SPI::InputPins[I], INPUT);
        pullUpDnControl(SPI::InputPins[I], PUD_UP);
    }
}