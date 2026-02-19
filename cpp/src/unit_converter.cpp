/*
 * CPS Utility Console - Unit Converter
 * Author: Dominik Żurek
 */

#include "../include/unit_converter.hpp"
#include <stdexcept>

float cps::convertTemperature(float value, const std::string& fromUnit, const std::string& toUnit) {
    if ((fromUnit != "C" && fromUnit != "F" && fromUnit != "K") ||
        (toUnit   != "C" && toUnit   != "F" && toUnit   != "K"))
        throw std::invalid_argument("Units must be one of: C, F, K.");

    // Convert to Celsius first (base unit)
    float celsius;
    if (fromUnit == "F") celsius = (value - 32.0f) * 5.0f / 9.0f;
    else if (fromUnit == "K") celsius = value - 273.15f;
    else celsius = value;

    // Convert from Celsius to target
    float result;
    if (toUnit == "F") result = celsius * 9.0f / 5.0f + 32.0f;
    else if (toUnit == "K") result = celsius + 273.15f;
    else result = celsius;

    // Check absolute zero
    if (toUnit == "K" && result < 0.0f)
        throw std::invalid_argument("Temperature below absolute zero (0K).");

    return result;
}

float cps::convertPressure(float value, const std::string& fromUnit, const std::string& toUnit) {
    if ((fromUnit != "BAR" && fromUnit != "KPA" && fromUnit != "PSI") ||
        (toUnit   != "BAR" && toUnit   != "KPA" && toUnit   != "PSI"))
        throw std::invalid_argument("Units must be one of: BAR, KPA, PSI.");

    if (value < 0.0f)
        throw std::invalid_argument("Pressure cannot be negative.");

    // Convert to bar first (base unit)
    float bar;
    if (fromUnit == "KPA") bar = value / 100.0f;
    else if (fromUnit == "PSI") bar = value / 14.5038f;
    else bar = value;

    // Convert from bar to target
    float result;
    if (toUnit == "KPA") result = bar * 100.0f;
    else if (toUnit == "PSI") result = bar * 14.5038f;
    else result = bar;

    return result;
}