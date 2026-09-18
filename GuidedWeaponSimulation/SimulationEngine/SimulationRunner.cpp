#include "SimulationRunner.h"
#include "WeaponState.h"
#include "ConsoleView.h"
#include "SampleStateGenerator.h"
#include "SimulationConfig.h"

#include <chrono>
#include <thread>
#include <cmath>
#include <iostream>

namespace
{
    SimulationResult validateConfig(const SimulationConfig& config)
    {
        if (config.sampleCount <= 0)
        {
            return SimulationResult::InvalidSampleCount;
        }

        if (!std::isfinite(config.timeStepSec) ||
            config.timeStepSec <= 0.0)
        {
            return SimulationResult::InvalidTimeStep;
        }

        if (config.objectId.empty())
        {
            return SimulationResult::EmptyObjectId;
        }

        if (!std::isfinite(config.initialTemperatureC))
        {
            return SimulationResult::InvalidInitialTemperature;
        }

        return SimulationResult::Success;
    }
}

SimulationResult runSimulation(const SimulationConfig& config)
{
    SimulationResult validationResult = validateConfig(config);


    if (validationResult != SimulationResult::Success)
    {
        return validationResult;
    }

    WeaponState sample{};
    sample.objectId = config.objectId;
    sample.position = Position{ 100.0, -200.0, 50.0 };
    sample.temperatureC = config.initialTemperatureC;

    printState(sample);

    sample.status = SimulationStatus::Running;

    for (int step = 1; step <= config.sampleCount; ++step)
    {
        std::this_thread::sleep_for(
            std::chrono::duration<double>(config.timeStepSec)
        );

        updateSampleState(sample, config.timeStepSec);

        if (step == config.sampleCount)
        {
            sample.status = SimulationStatus::Completed;
        }

        printState(sample);
    }

    return SimulationResult::Success;
}