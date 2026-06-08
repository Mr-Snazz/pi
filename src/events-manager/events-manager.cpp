#include <filesystem>
#include <string>
#include <fstream>

#include "nlohmann/json.hpp"

#include "events-manager/events-manager.hpp"

void SPI::EventsManager::ScanForEvents()
{
    for (const auto& Entry : std::filesystem::directory_iterator("./events")) {
        if (!Entry.is_regular_file() || Entry.path().extension() != ".json") continue;

        std::ifstream EventFile(Entry.path());
        nlohmann::json Data = nlohmann::json::parse(EventFile);


    }
}