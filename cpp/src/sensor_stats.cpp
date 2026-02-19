/*
 * CPS Utility Console - Sensor Statistics
 * Author: Dominik Żurek
 */

#include "../include/sensor_stats.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>

cps::SensorStats cps::computeStats(const std::vector<float>& samples) {
    if (samples.empty())
        throw std::invalid_argument("Samples list cannot be empty.");

    float mean = 0.0f;
    for (float x : samples) mean += x;
    mean /= static_cast<float>(samples.size());

    float min = *std::min_element(samples.begin(), samples.end());
    float max = *std::max_element(samples.begin(), samples.end());

    float variance = 0.0f;
    for (float x : samples) variance += (x - mean) * (x - mean);
    variance /= static_cast<float>(samples.size());

    return {mean, min, max, std::sqrt(variance)};
}