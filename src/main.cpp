#include "core/core.hpp"

int main(int ArgC, char* ArgV[])
{
    SPI::Initialize();
    SPI::MainLoop();
    SPI::FreeResources();

    return 0;
}