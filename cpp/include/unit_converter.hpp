#pragma once

#include <string>

namespace cps {

/// Convert temperature between "C", "F", "K".
float convertTemperature(float value, const std::string& fromUnit, const std::string& toUnit);

/// Convert pressure between "bar", "kPa", "psi".
float convertPressure(float value, const std::string& fromUnit, const std::string& toUnit);

} // namespace cps