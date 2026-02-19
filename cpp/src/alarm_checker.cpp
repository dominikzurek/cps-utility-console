/*
 * CPS Utility Console - Alarm Threshold Checker
 * Author: Dominik Żurek
 */

#include "../include/alarm_checker.hpp"
#include <stdexcept>

std::string cps::checkAlarm(float value, float low, float high) {
    if (low >= high)
        throw std::invalid_argument("Low threshold must be less than high threshold.");

    if (value < low) return "ALARM_LOW";
    if (value > high) return "ALARM_HIGH";
    return "OK";
}