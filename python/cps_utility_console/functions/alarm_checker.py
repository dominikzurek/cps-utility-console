"""
CPS Utility Console - Alarm Threshold Checker
Author: Dominik Żurek
"""


def check_alarm(value: float, low: float, high: float) -> str:
    """
    Chcek if sensor value is within alarm threshold.

    Args:
        value: Sensor reading to check.
        low: Low alarm threshold.
        high: High alarm threshold.

    Returns:
        "OK" if value is within [lov, high],
        "ALARM_LOW" if value < low,
        "ALARM_HIGH" if value > high.

    Raises:
        ValueError: If low >= high.
    """
    if low >= high:
        raise ValueError(f"Low threshold ({low}) must be less than high threshold ({high}).")
    
    if value < low:
        return "ALARM_LOW"
    elif value > high:
        return "ALARM_HIGH"
    else:
        return "OK"