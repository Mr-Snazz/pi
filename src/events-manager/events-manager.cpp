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
#include "core/should-terminate.hpp"

std::unordered_map<SPI::Pins, SPI::EventsManager::Event> Events;
std::mutex EventsMutex;

void ScanForEvents();

void SPI::EventsManager::Initialize()
{
    auto EventsScanThreadFunction = []() -> void
    {
        while (true)
        {
            ScanForEvents();

            std::this_thread::sleep_for(std::chrono::seconds(1u));

            if (SPI::Terminate.load()) break;
        }
    };

    std::filesystem::create_directory("./events");

    std::ofstream OutputFile("output.txt");

    std::thread EventsScanThread(EventsScanThreadFunction);
    EventsScanThread.detach();
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
    std::vector<SPI::EventsManager::Event> EventsToAdd;

    for (const auto& Entry : std::filesystem::directory_iterator("./events")) {
        if (!Entry.is_regular_file() || Entry.path().extension() != ".json") continue;

        std::ifstream EventFile(Entry.path());
        nlohmann::json Data = nlohmann::json::parse(EventFile);

        std::string Name = Data["event_name"].get<std::string>();

        std::vector<int> TriggerPins = Data["trigger_pins"].get<std::vector<int>>();
        SPI::Pins TriggerKey = SPI::GetPinsKey(TriggerPins);

        EventsToAdd.push_back(SPI::EventsManager::Event(Name, TriggerKey));
    }

    std::lock_guard<std::mutex> EventsLock(EventsMutex);
    for (size_t I = 0u; I < EventsToAdd.size(); ++I) {
        const SPI::EventsManager::Event Event = EventsToAdd[I];

        auto Iterator = Events.find(Event.TriggerPins);
        if (Iterator != Events.end()) continue;

        Events.insert_or_assign(Event.TriggerPins, Event);
    }
}