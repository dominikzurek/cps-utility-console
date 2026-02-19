cmake_minimum_required(VERSION 3.16)
project(cps_utility_console VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/validators.cpp
    src/sensor_stats.cpp
    src/unit_converter.cpp
    src/alarm_checker.cpp
    src/lowpass_filter.cpp
    src/menu.cpp
    src/main.cpp
)

include_directories(include)
add_executable(cps_utility_console ${SOURCES})
install(TARGETS cps_utility_console DESTINATION bin)

# Tests
enable_testing()
find_package(GTest REQUIRED)

add_executable(cps_tests
    tests/test_sensor_stats.cpp
    tests/test_unit_converter.cpp
    tests/test_alarm_checker.cpp
    tests/test_lowpass_filter.cpp
    src/sensor_stats.cpp
    src/unit_converter.cpp
    src/alarm_checker.cpp
    src/lowpass_filter.cpp
)

target_include_directories(cps_tests PRIVATE include)
target_link_libraries(cps_tests GTest::GTest GTest::Main)
add_test(NAME cps_tests COMMAND cps_tests)