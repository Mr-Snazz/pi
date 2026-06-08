#pragma once

#include <stdint.h>

#include <concepts>

namespace SPI
{
    template <typename T>
    requires std::integral<T>
    inline void SetBitInInteger(T& Integer, uint8_t Position);

    template <typename T>
    requires std::integral<T>
    inline void ClearBitInInteger(T& Integer, uint8_t Position);

    template <typename T>
    requires std::integral<T>
    inline void FlipBitInInteger(T& Integer, uint8_t Position);
}

#include "utilities/bit-manipulation.inl"
