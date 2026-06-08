#include <ctime>

#include <filesystem>
#include <string>
#include <fstream>

#include "events-manager/event.hpp"

SPI::EventsManager::Event::Event(const std::string& IName, uint32_t ITriggerPins)
    : Name(IName), TriggerPins(ITriggerPins)
{

}

void SPI::EventsManager::Event::OnTrigger() const
{
    time_t CurrentTime = time(nullptr);
    std::string TimeString = ctime(&CurrentTime);
    TimeString.pop_back(); // Remove the newline character added by ctime

    std::ofstream OutputFile("output.txt", std::ios::app);
    OutputFile << this->Name << " triggered at " << TimeString << std::endl;
    OutputFile.close();
}

