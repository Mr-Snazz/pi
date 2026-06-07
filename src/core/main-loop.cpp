#include <wiringPi.h>

#include "core/core.hpp"

void SPI::MainLoop()
{
    while (true)
    {
        digitalWrite(17, HIGH);
        delay(500);
        digitalWrite(17, LOW);
        delay(500);
    }
}