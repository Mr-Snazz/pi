#include <stdexcept>

#include "utilities/bit-manipulation.hpp"

template <typename T>
requires std::integral<T>
inline void SPI::SetBitInInteger(T& Integer, uint8_t Position)
{
    constexpr uint8_t Cap = sizeof(T) * 8u;
    if (Position >= Cap) throw std::out_of_range("Invalid bit position for given integer type");
    Integer |= (static_cast<T>(1) << Position);
}

template <typename T>
requires std::integral<T>
inline void SPI::ClearBitInInteger(T& Integer, uint8_t Position)
{
    constexpr uint8_t Cap = sizeof(T) * 8u;
    if (Position >= Cap) throw std::out_of_range("Invalid bit position for given integer type");
    Integer &= ~(static_cast<T>(1) << Position);
}

template <typename T>
requires std::integral<T>
inline void SPI::FlipBitInInteger(T& Integer, uint8_t Position)
{
    constexpr uint8_t Cap = sizeof(T) * 8u;
    if (Position >= Cap) throw std::out_of_range("Invalid bit position for given integer type");
    Integer ^= (static_cast<T>(1) << Position);
}