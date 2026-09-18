#include "SimulationRunner.h"
#include "WeaponState.h"
#include "ConsoleView.h"
#include "SampleStateGenerator.h"
#include "SimulationConfig.h"

#include <chrono>
#include <thread>
#include <cmath>
#include <iostream>

bool runSimulation(const SimulationConfig& config)
{
    if (config.sampleCount <= 0)
    {
        std::cerr << "Sample count must be greater than 0.\n";
        return false;
    }

    if (!std::isfinite(config.timeStepSec) || config.timeStepSec <= 0.0)
    {
        std::cerr << "Time step must be finite and greater than 0.\n";
        return false;
    }


    WeaponState sample{};
    sample.objectId = "SIM001";
    sample.position = Position{ 100.0, -200.0, 50.0 };
    sample.temperatureC = 20.0;

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

    return true;
}