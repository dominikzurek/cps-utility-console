#pragma once

#include <string>

namespace cps {

void runSensorStats();
void runUnitConverter();
void runAlarmChecker();
void runLowpassFilter();
void displayMenu();
bool handleChoice(const std::string& choice);

} // namespace cps