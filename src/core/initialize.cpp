#include <stdexcept>

#include <wiringPi.h>

#include "core/core.hpp"

void SPI::Initialize()
{
    if (wiringPiSetupGpio() == -1) throw std::runtime_error("Failed to initialize wiringPi");

   
}