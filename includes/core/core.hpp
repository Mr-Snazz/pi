#pragma once

#include <atomic>

namespace SPI
{
    extern std::atomic<bool> Terminate;

    void Initialize();

    void MainLoop();

    void FreeResources();
}