#pragma once

#include <string>
#include <vector>

namespace cps {

    /// Prompt the user until a valid float is entered.
    float getFloat(const std::string& prompt);

    /// Prompt the user until a float in [min, max] is entered.
    float getFloatInRange(const std::string& prompt, float min, float max);

    /// Prompt the user until a positive integer (>0) is entered.
    int getPositiveInt(const std::string& prompt);

    /// Prompt the user until one of the valid choices is entered.
    std::string getChoice(const std::string& prompt, const std::vector<std::string>& valid);

} // namespace cps