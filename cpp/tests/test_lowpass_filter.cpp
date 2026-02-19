#include <gtest/gtest.h>
#include "lowpass_filter.hpp"

TEST(LowpassFilter, SameAsInputWhenAlphaOne) {
    std::vector<float> samples = {1.0f, 5.0f, 1.0f, 5.0f};
    std::vector<float> result = cps::lowpassFilter(samples, 1.0f);
    for (int i = 0; i < (int)samples.size(); i++)
        EXPECT_FLOAT_EQ(result[i], samples[i]);
}

TEST(LowpassFilter, ConstantWhenAlphaZero) {
    std::vector<float> samples = {3.0f, 5.0f, 7.0f, 9.0f};
    std::vector<float> result = cps::lowpassFilter(samples, 0.0f);
    for (float v : result)
        EXPECT_FLOAT_EQ(v, 3.0f);
}

TEST(LowpassFilter, OutputSameLength) {
    std::vector<float> samples = {1.0f, 2.0f, 3.0f};
    EXPECT_EQ(cps::lowpassFilter(samples, 0.5f).size(), samples.size());
}

TEST(LowpassFilter, EmptyThrows) {
    EXPECT_THROW(cps::lowpassFilter({}, 0.5f), std::invalid_argument);
}

TEST(LowpassFilter, InvalidAlphaThrows) {
    EXPECT_THROW(cps::lowpassFilter({1.0f}, 1.5f), std::invalid_argument);
}