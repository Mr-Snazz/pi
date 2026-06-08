#pragma once

#include <atomic>

namespace SPI
{
    void Initialize();

    void MainLoop();

    void FreeResources();
}