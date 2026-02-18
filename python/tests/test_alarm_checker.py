"""
Tests for Alarm Checker module
"""

import pytest
from cps_utility_console.functions.alarm_checker import check_alarm


def test_alarm_ok():
    """Test value within range."""
    assert check_alarm(15, 10, 20) == "OK"


def test_alarm_low():
    """Test value below low threshold."""
    assert check_alarm(5, 10, 20) == "ALARM_LOW"


def test_alarm_high():
    """Test value above high threshold."""
    assert check_alarm(25, 10, 20) == "ALARM_HIGH"


def test_alarm_invalid_thresholds():
    """Test low >= high raises error."""
    with pytest.raises(ValueError, match="must be less than"):
        check_alarm(15, 20, 10)