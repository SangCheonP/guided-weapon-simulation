#pragma once

#include <string>
#include "Position.h"

enum class SimulationStatus
{
    Ready,
    Running,
    Completed,
    Error
};

struct WeaponState
{
    std::string objectId;
    double simulationTimeSec = 0.0;
    Position position{};
    double speedMps = 0.0;
    double temperatureC = 0.0;
    SimulationStatus status = SimulationStatus::Ready;
};