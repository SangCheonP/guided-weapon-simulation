#pragma once

#include <string>

struct SimulationConfig
{
	int sampleCount = 10;
	double timeStepSec = 1.0;

	std::string objectId = "SIM001";
	double initialTemperatureC = 20.0;
};