#pragma once

#include <vector>

namespace cps {

/// Apply 1st-order IIR low-pass filter.
/// Formula: y[k] = alpha * x[k] + (1 - alpha) * y[k-1]
/// Throws std::invalid_argument if samples is empty or alpha not in [0.0, 1.0].
std::vector<float> lowpassFilter(const std::vector<float>& samples, float alpha);

} // namespace cps