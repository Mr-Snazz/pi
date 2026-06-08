#include "pins/pins.hpp"
#include "utilities/bit-manipulation.hpp"

inline SPI::Pins SPI::GetPinsKey(const std::vector<int>& Pins)
{
    SPI::Pins Key{};

    for (const int& Pin : Pins) {
        SPI::SetBitInInteger(Key, static_cast<uint8_t>(Pin));
    }
    
    return Key;
}