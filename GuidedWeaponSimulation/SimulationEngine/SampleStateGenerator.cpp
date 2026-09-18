#include "SampleStateGenerator.h"

void updateSampleState(WeaponState& state, double timeStepSec)
{
    state.simulationTimeSec += timeStepSec;

    state.temperatureC += 0.5 * timeStepSec;
}