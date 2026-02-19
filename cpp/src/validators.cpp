/*
 * CPS Utility Console - Input Validators
 * Author: Dominik Żurek
 */

#include "../include/validators.hpp"
#include <iostream>
#include <limits>
#include <algorithm>

float cps::getFloat(const std::string& prompt) {
    float value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    std::cout << "  Error: '" << "invalid" <<"' is not a valid number.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

float cps::getFloatInRange(const std::string& prompt, float min, float max){
    while (true) {
        float value = cps::getFloat(prompt);
        if (value >= min && value <= max) return value;
        std::cout << "  Error: value must be in [" << min << ", " << max << "].\n";
    }
}

int cps::getPositiveInt(const std::string& prompt) {
    while (true) {
        float value = cps::getFloat(prompt);
        int i = static_cast<int>(value);
        if (i > 0 && static_cast<float>(i) == value) return i;
        std::cout << "  Error: must be a positive integer.\n";
    }
}

std::string cps::getChoice(const std::string& prompt, const std::vector<std::string>& valid) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        if (std::find(valid.begin(), valid.end(), input) != valid.end()) return input;
        std::cout << "  Error: invalid choice.\n";
    }
}