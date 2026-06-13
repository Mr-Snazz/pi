#include <filesystem>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

#include "nlohmann/json.hpp"

#include "events-manager/events-manager.hpp"
#include "events-manager/event.hpp"
#include "core/core.hpp"

std::unordered_map<SPI::Pins, SPI::EventsManager::Event> Events;
std::mutex EventsMutex;

void ScanForEvents();

void SPI::EventsManager::Initialize()
{

}

void SPI::EventsManager::NotifyEvents(SPI::Pins PinStates)
{
    std::lock_guard<std::mutex> EventsLock(EventsMutex);

    auto Iterator = Events.find(PinStates);
    if (Iterator == Events.end()) return;

    Iterator->second.OnTrigger();
}

void ScanForEvents()
{

}