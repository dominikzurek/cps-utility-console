"""
Tests for Sensor Statistics module
"""

import pytest
from cps_utility_console.functions.sensor_stats import compute_stats


def test_compute_stats_normal():
    """Test with normal input."""
    result = compute_stats([1.0, 2.0, 3.0, 4.0, 5.0])
    assert result["mean"] == 3.0
    assert result["min"] == 1.0
    assert result["max"] == 5.0
    assert abs(result["stddev"] - 1.4142) < 0.01  # approximate


def test_compute_stats_single_value():
    """Test with single sample."""
    result = compute_stats([42.0])
    assert result["mean"] == 42.0
    assert result["min"] == 42.0
    assert result["max"] == 42.0
    assert result["stddev"] == 0.0


def test_compute_stats_all_equal():
    """Test with all identical values."""
    result = compute_stats([5.0, 5.0, 5.0])
    assert result["mean"] == 5.0
    assert result["stddev"] == 0.0


def test_compute_stats_empty_list():
    """Test that empty list raises ValueError."""
    with pytest.raises(ValueError, match="cannot be empty"):
        compute_stats([])