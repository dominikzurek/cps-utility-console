#include <gtest/gtest.h>
#include "unit_converter.hpp"

TEST(UnitConverter, CelsiusToFahrenheit) {
    EXPECT_NEAR(cps::convertTemperature(0.0f, "C", "F"), 32.0f, 0.001f);
    EXPECT_NEAR(cps::convertTemperature(100.0f, "C", "F"), 212.0f, 0.001f);
}

TEST(UnitConverter, CelsiusToKelvin) {
    EXPECT_NEAR(cps::convertTemperature(0.0f, "C", "K"), 273.15f, 0.001f);
}

TEST(UnitConverter, InvalidUnitThrows) {
    EXPECT_THROW(cps::convertTemperature(0.0f, "X", "C"), std::invalid_argument);
}

TEST(UnitConverter, BelowAbsoluteZeroThrows) {
    EXPECT_THROW(cps::convertTemperature(-300.0f, "C", "K"), std::invalid_argument);
}

TEST(UnitConverter, BarToKpa) {
    EXPECT_NEAR(cps::convertPressure(1.0f, "BAR", "KPA"), 100.0f, 0.001f);
}

TEST(UnitConverter, NegativePressureThrows) {
    EXPECT_THROW(cps::convertPressure(-1.0f, "BAR", "KPA"), std::invalid_argument);
}