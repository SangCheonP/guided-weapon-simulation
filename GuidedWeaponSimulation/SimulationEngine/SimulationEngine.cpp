#include "SimulationRunner.h"
#include "SimulationConfig.h"

int main()
{
    SimulationConfig config{};
    config.sampleCount = 5;
    config.timeStepSec = 0.5;

    if (!runSimulation(config))
    {
        return 1;
    }

    return 0;
}