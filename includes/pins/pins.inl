#include "pins/pins.hpp"
#include "utilities/bit-manipulation.hpp"

inline uint16_t SPI::GetPinsKey(const std::vector<int>& Pins)
{
    uint16_t Key{};

    for (const int& Pin : Pins) {
        SPI::SetBitInInteger(Key, Pin);
    }

    return Key;
}