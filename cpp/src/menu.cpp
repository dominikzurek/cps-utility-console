/*
 * CPS Utility Console - Menu Router
 * Author: Dominik Żurek
 */

#include "../include/menu.hpp"
#include "../include/validators.hpp"
#include "../include/sensor_stats.hpp"
#include "../include/unit_converter.hpp"
#include "../include/alarm_checker.hpp"
#include "../include/lowpass_filter.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>

void cps::runSensorStats() {
    std::cout << "\n--- Sensor Statistics ---\n";
    int n = cps::getPositiveInt("How many samples? ");

    std::vector<float> samples;
    for (int i = 0; i < n; i++) {
        float v = cps::getFloat("Sample " + std::to_string(i + 1) + "/" + std::to_string(n) + ": ");
        samples.push_back(v);
    }

    cps::SensorStats result = cps::computeStats(samples);
    std::cout << "\nResults:\n";
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "  Mean:   " << result.mean   << "\n";
    std::cout << "  Min:    " << result.min    << "\n";
    std::cout << "  Max:    " << result.max    << "\n";
    std::cout << "  StdDev: " << result.stddev << "\n";
}

void cps::runUnitConverter() {
    std::cout << "\n--- Unit Converter ---\n";
    std::string convType = cps::getChoice("Convert [T]emperature or [P]ressure? ", {"T", "P"});

    if (convType == "T") {
        float value = cps::getFloat("Enter temperature value: ");
        std::string fromUnit = cps::getChoice("From unit [C/F/K]: ", {"C", "F", "K"});
        std::string toUnit   = cps::getChoice("To unit [C/F/K]: ",   {"C", "F", "K"});
        try {
            float result = cps::convertTemperature(value, fromUnit, toUnit);
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "\nResult: " << value << " " << fromUnit << " = " << result << " " << toUnit << "\n";
        } catch (const std::invalid_argument& e) {
            std::cout << "  Error: " << e.what() << "\n";
        }
    } else {
        float value = cps::getFloat("Enter pressure value: ");
        std::string fromUnit = cps::getChoice("From unit [BAR/KPA/PSI]: ", {"BAR", "KPA", "PSI"});
        std::string toUnit   = cps::getChoice("To unit [BAR/KPA/PSI]: ",   {"BAR", "KPA", "PSI"});
        try {
            float result = cps::convertPressure(value, fromUnit, toUnit);
            std::cout << std::fixed << std::setprecision(4);
            std::cout << "\nResult: " << value << " " << fromUnit << " = " << result << " " << toUnit << "\n";
        } catch (const std::invalid_argument& e) {
            std::cout << "  Error: " << e.what() << "\n";
        }
    }
}

void cps::runAlarmChecker() {
    std::cout << "\n--- Alarm Threshold Checker ---\n";
    float value = cps::getFloat("Enter sensor value: ");
    float low   = cps::getFloat("Enter LOW threshold: ");
    float high  = cps::getFloat("Enter HIGH threshold: ");

    try {
        std::string status = cps::checkAlarm(value, low, high);
        if (status == "OK")
            std::cout << "Status: " << status << ".\n";
        else if (status == "ALARM_LOW")
            std::cout << "Status: " << status << " (value below minimum).\n";
        else
            std::cout << "Status: " << status << " (value above maximum).\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "  Error: " << e.what() << ".\n";
    }
}

void cps::runLowpassFilter() {
    std::cout << "\n--- Low-Pass IIR Filter ---\n";
    std::cout << "Formula: y[k] = a*x[k] + (1-a)*y[k-1]\n";

    int n     = cps::getPositiveInt("How many samples? ");
    float alpha = cps::getFloatInRange("Enter alpha [0.0-1.0]: ", 0.0f, 1.0f);

    std::vector<float> samples;
    for (int i = 0; i < n; i++) {
        float v = cps::getFloat("Sample " + std::to_string(i + 1) + "/" + std::to_string(n) + ": ");
        samples.push_back(v);
    }

    try {
        std::vector<float> filtered = cps::lowpassFilter(samples, alpha);
        std::cout << "\nResults:\n";
        std::cout << "Index | Input    | Filtered\n";
        std::cout << "------|----------|----------\n";
        std::cout << std::fixed << std::setprecision(4);
        for (int i = 0; i < (int)filtered.size(); i++) {
            std::cout << std::setw(5) << i
                      << " | " << std::setw(8) << std::setprecision(2) << samples[i]
                      << " | " << std::setw(8) << std::setprecision(4) << filtered[i] << "\n";
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "  Error: " << e.what() << "\n";
    }
}

void cps::displayMenu() {
    std::cout << "\n=== CPS Utility Console ===\n";
    std::cout << "[1] Sensor Statistics\n";
    std::cout << "[2] Unit Converter\n";
    std::cout << "[3] Alarm Threshold Checker\n";
    std::cout << "[4] Low-Pass IIR Filter\n";
    std::cout << "[5] Exit\n";
}

bool cps::handleChoice(const std::string& choice) {
    if (choice == "5") { std::cout << "Goodbye!\n"; return false; }
    if (choice == "1") { cps::runSensorStats();    return true; }
    if (choice == "2") { cps::runUnitConverter();  return true; }
    if (choice == "3") { cps::runAlarmChecker();   return true; }
    if (choice == "4") { cps::runLowpassFilter();  return true; }
    std::cout << "  Error: invalid option. Please select 1-5.\n";
    return true;
}