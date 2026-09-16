#include <iostream>
#include <chrono>
#include <thread>
#include "WeaponState.h"

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

void printState(const WeaponState& state) {
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

int main()
{
    WeaponState sample{};

    sample.objectId = "SIM001";
    sample.position = Position{ 100.0, -200.0, 50.0 };
    sample.temperatureC = 20.0;

    constexpr int sampleCount = 10;
    constexpr double timeStepSec = 1.0;

    sample.status = SimulationStatus::Running;

    for (int step = 1; step <= sampleCount; ++step)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        sample.simulationTimeSec = step * timeStepSec;

        if (step == sampleCount)
        {
            sample.status = SimulationStatus::Completed;
        }

        printState(sample);
    }

    
    return 0;
}