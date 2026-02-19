#include <gtest/gtest.h>
#include "alarm_checker.hpp"

TEST(AlarmChecker, OK) {
    EXPECT_EQ(cps::checkAlarm(5.0f, 0.0f, 10.0f), "OK");
}

TEST(AlarmChecker, AlarmLow) {
    EXPECT_EQ(cps::checkAlarm(-1.0f, 0.0f, 10.0f), "ALARM_LOW");
}

TEST(AlarmChecker, AlarmHigh) {
    EXPECT_EQ(cps::checkAlarm(11.0f, 0.0f, 10.0f), "ALARM_HIGH");
}

TEST(AlarmChecker, InvalidThresholdThrows) {
    EXPECT_THROW(cps::checkAlarm(5.0f, 10.0f, 0.0f), std::invalid_argument);
}

TEST(AlarmChecker, EqualThresholdsThrow) {
    EXPECT_THROW(cps::checkAlarm(5.0f, 5.0f, 5.0f), std::invalid_argument);
}