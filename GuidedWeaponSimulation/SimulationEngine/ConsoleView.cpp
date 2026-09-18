#include "ConsoleView.h"
#include <iostream>

namespace
{
    const char* toString(SimulationStatus status)
    {
        switch (status)
        {
        case SimulationStatus::Ready:
            return "Ready";
        case SimulationStatus::Running:
            return "Running";
        case SimulationStatus::Completed:
            return "Completed";
        case SimulationStatus::Error:
            return "Error";
        default:
            return "Unknown";
        }
    }
}

void printState(const WeaponState& state) 
{
    std::cout << "ID: " << state.objectId << '\n';
    std::cout << "Time: " << state.simulationTimeSec << " s\n";

    std::cout << "Position: ("
        << state.position.x << ", "
        << state.position.y << ", "
        << state.position.z << ") m\n";

    std::cout << "Speed: " << state.speedMps << " m/s\n";
    std::cout << "Temperature: " << state.temperatureC << " C\n";
    std::cout << "Status: " << toString(state.status) << "\n\n";
}