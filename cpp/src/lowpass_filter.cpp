/*
 * CPS Utility Console - Low-Pass IIR Filter
 * Author: Dominik Żurek
 */

#include "../include/lowpass_filter.hpp"
#include <stdexcept>

std::vector<float> cps::lowpassFilter(const std::vector<float>& samples, float alpha) {
    if (samples.empty())
        throw std::invalid_argument("Samples list cannot be empty.");

    if (alpha < 0.0f || alpha > 1.0f)
        throw std::invalid_argument("Alpha must be in [0.0, 1.0].");

    std::vector<float> output;
    float y_prev = samples[0];

    for (float x : samples) {
        float y = alpha * x + (1.0f - alpha) * y_prev;
        output.push_back(y);
        y_prev = y;
    }

    return output;
}