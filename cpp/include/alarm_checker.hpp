#pragma once

#include <string>

namespace cps {

/// Check if sensor value is within alarm thresholds.
/// Returns "OK", "ALARM_LOW", or "ALARM_HIGH".
/// Throws std::invalid_argument if low >= high.
std::string checkAlarm(float value, float low, float high);

} // namespace cps