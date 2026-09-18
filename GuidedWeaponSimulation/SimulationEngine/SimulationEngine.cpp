#include "SimulationConfig.h"
#include "SimulationResult.h"
#include "SimulationRunner.h"
#include "ConsoleView.h"
#include "CsvStateWriter.h"
#include "WeaponState.h"

#include <iostream>

int main()
{
    WeaponState testState{};
    testState.objectId = "SIM003";
    testState.position = Position{ 100.0, -200.0, 50.0 };
    testState.temperatureC = 10.0;

    writeCsvHeader(std::cout);
    writeCsvState(std::cout, testState);

    SimulationConfig config{};
    config.sampleCount = 4;
    config.timeStepSec = 0.25;
    config.objectId = "SIM003";
    config.initialTemperatureC = 10.0;

    const SimulationResult result = runSimulation(config);

    printSimulationResult(result);

    if (result != SimulationResult::Success)
    {

        return 1;
    }

    return 0;
}