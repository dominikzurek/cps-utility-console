"""
CPS Utility Console - Sensor Statistics
Author: Dominik Żurek
"""


import math


def compute_stats(samples: list[float]) -> dict[str, float]:
    """
    Compute descriptive statistics for a list of sensor samples.

    Args:
        samples: Non-empty list of float values.

    Returns:
        Dictionary with keys: mean, min, max, stddev.

    Raises:
        ValueError: If samples list is empty.    
    """
    if len(samples) == 0:
        raise ValueError("Samples list cannot be empty.")
    
    mean = sum(samples) / len(samples)
    min_val = min(samples)
    max_val = max(samples)
    variance = sum((x - mean) ** 2 for x in samples) / len(samples)
    stddev = math.sqrt(variance)

    return {
        "mean": mean,
        "min": min_val,
        "max": max_val,
        "stddev": stddev,
    }