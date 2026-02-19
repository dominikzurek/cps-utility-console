/*
 * CPS Utility Console - Input Validators
 * Author: Dominik Żurek
 */

#include "../include/validators.hpp"
#include <iostream>
#include <limits>
#include <algorithm>
#include <cctype>

float cps::getFloat(const std::string& prompt) {
    float value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout << "  Error: invalid number. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

float cps::getFloatInRange(const std::string& prompt, float min, float max) {
    while (true) {
        float value = cps::getFloat(prompt);
        if (value >= min && value <= max) return value;
        std::cout << "  Error: value must be between " << min << " and " << max << ". Try again.\n";
    }
}

int cps::getPositiveInt(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        int value;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (value >= 1) return value;
            std::cout << "  Error: value must be a positive integer. Try again.\n";
        } else {
            std::cout << "  Error: not a valid integer. Try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

std::string cps::getChoice(const std::string& prompt, const std::vector<std::string>& valid) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        for (char& c : input) c = toupper(c);
        if (std::find(valid.begin(), valid.end(), input) != valid.end()) return input;
        std::cout << "  Error: invalid choice. Try again.\n";
    }
}