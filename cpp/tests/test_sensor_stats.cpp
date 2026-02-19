#include <gtest/gtest.h>
#include "sensor_stats.hpp"

TEST(SensorStats, BasicMean) {
    cps::SensorStats r = cps::computeStats({1.0f, 2.0f, 3.0f, 4.0f, 5.0f});
    EXPECT_FLOAT_EQ(r.mean, 3.0f);
}

TEST(SensorStats, MinMax) {
    cps::SensorStats r = cps::computeStats({1.0f, 2.0f, 3.0f, 4.0f, 5.0f});
    EXPECT_FLOAT_EQ(r.min, 1.0f);
    EXPECT_FLOAT_EQ(r.max, 5.0f);
}

TEST(SensorStats, StdDev) {
    cps::SensorStats r = cps::computeStats({2.0f, 4.0f, 4.0f, 4.0f, 5.0f, 5.0f, 7.0f, 9.0f});
    EXPECT_NEAR(r.stddev, 2.0f, 0.0001f);
}

TEST(SensorStats, SingleSample) {
    cps::SensorStats r = cps::computeStats({42.0f});
    EXPECT_FLOAT_EQ(r.mean, 42.0f);
    EXPECT_FLOAT_EQ(r.stddev, 0.0f);
}

TEST(SensorStats, EmptyThrows) {
    EXPECT_THROW(cps::computeStats({}), std::invalid_argument);
}