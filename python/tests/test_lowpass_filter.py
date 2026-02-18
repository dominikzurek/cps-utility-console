"""
Tests for Low-Pass Filter module
"""

import pytest
from cps_utility_console.functions.lowpass_filter import lowpass_filter


def test_filter_alpha_1():
    """Test alpha=1.0 (no filtering)."""
    samples = [1, 5, 1, 5]
    result = lowpass_filter(samples, alpha=1.0)
    assert result == samples


def test_filter_alpha_0():
    """Test alpha=0.0 (maximum smoothing)."""
    samples = [1, 5, 10]
    result = lowpass_filter(samples, alpha=0.0)
    assert result == [1, 1, 1]  # All equal to first sample


def test_filter_empty_list():
    """Test empty list raises error."""
    with pytest.raises(ValueError, match="cannot be empty"):
        lowpass_filter([], alpha=0.5)


def test_filter_alpha_out_of_range():
    """Test alpha outside [0,1] raises error."""
    with pytest.raises(ValueError, match="must be in"):
        lowpass_filter([1, 2, 3], alpha=1.5)