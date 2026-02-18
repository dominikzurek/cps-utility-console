"""
Tests for Unit Converter module
"""

import pytest
from cps_utility_console.functions.unit_converter import convert_temperature, convert_pressure


def test_temperature_c_to_f():
    """Test Celsius to Fahrenheit."""
    assert convert_temperature(0, "C", "F") == 32.0
    assert convert_temperature(100, "C", "F") == 212.0


def test_temperature_k_to_c():
    """Test Kelvin to Celsius."""
    assert convert_temperature(273.15, "K", "C") == 0.0


def test_temperature_invalid_unit():
    """Test invalid unit raises error."""
    with pytest.raises(ValueError, match="Units must be one of"):
        convert_temperature(100, "C", "X")


def test_pressure_bar_to_kpa():
    """Test bar to kPa."""
    assert convert_pressure(1, "BAR", "KPA") == 100.0


def test_pressure_negative():
    """Test negative pressure raises error."""
    with pytest.raises(ValueError, match="cannot be negative"):
        convert_pressure(-5, "BAR", "KPA")