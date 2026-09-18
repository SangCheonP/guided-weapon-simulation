#pragma once

#include "WeaponState.h"

#include <ostream>

void writeCsvHeader(std::ostream& output);
void writeCsvState(std::ostream& output, const WeaponState& state);