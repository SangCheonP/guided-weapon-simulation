#include "CsvStateWriter.h"

namespace
{
	const char* statusText(SimulationStatus status)
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

    void writeCsvText(std::ostream& output, const std::string& text)
    {
        output << '"';

        for (char ch : text)
        {
            if (ch == '"')
            {
                output << '"';
            }

            output << ch;
        }

        output << '"';
    }
}

void writeCsvHeader(std::ostream& output)
{
    output << "objectId,simulationTimeSec,x,y,z,"
              "speedMps,temperatureC,status\n";
}

void writeCsvState(std::ostream& output, const WeaponState& state)
{
    writeCsvText(output, state.objectId);

    output << ',' << state.simulationTimeSec
           << ',' << state.position.x
           << ',' << state.position.y
           << ',' << state.position.z
           << ',' << state.speedMps
           << ',' << state.temperatureC
           << ',' << statusText(state.status)
           << '\n';
}