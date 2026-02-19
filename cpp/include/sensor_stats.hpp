#pragma once

#include <vector>

namespace cps {

    struct SensorStats {
        float mean;
        float min;
        float max;
        float stddev;
    };

    /// Compute mean, min, max and stddev from samples.
    SensorStats computeStats(const std::vector<float>& samples);

} // namespace cps