"""
CPS Utility Console - Unit Converter
Author: Dominik Żurek
"""


def convert_temperature(value: float, from_unit: str, to_unit: str) -> float:
    """
    Convert temperature between Celsius, Fahrenheit and Kelvin.

    Args:
        value: Temperature value.
        from_unit: Source unit ("C", "F", "K").
        to_unit: Target unit ("C", "F", "K").

    Returns:
        Converted temperature value.

    Raises:
        ValueError: If units are invalid or result is below absolute zero.
    """
    valid_units = ["C", "F", "K"]
    if from_unit not in valid_units or to_unit not in valid_units:
        raise ValueError(f"Units must be one of {valid_units}.")
    
    # Convert to Celsius first (base unit)
    if from_unit == "F":
        celsius = (value - 32) * 5 / 9
    elif from_unit == "K":
        celsius = value - 273.15
    else:
        celsius = value

    # Convert from Celsius to target
    if to_unit == "F":
        result = celsius * 9 / 5 + 32
    elif to_unit == "K":
        result = celsius + 273.15
    else: 
        result = celsius

    # Check absolute zero
    if to_unit == "K" and result < 0:
        raise ValueError("Temperature below absolute zero (0K).")
    
    return result


def convert_pressure(value: float, from_unit: str, to_unit: str) -> float:
    """
    Convert pressure between bar, kPa and psi.

    Args:
        value: Pressure value.
        from_unit: Source unit ("BAR", "KPA", "PSI").
        to_unit: Target unit ("BAR", "KPA", "PSI").

    Returns:
        Converted pressure value.

    Raises:
        ValueError: If units are invalid or value is negative.
    """
    valid_units = ["BAR", "KPA", "PSI"]
    if from_unit not in valid_units or to_unit not in valid_units:
        raise ValueError(f"Units must be on of {valid_units}.")
    
    if value < 0:
        raise ValueError("Pressure cannot be negative")
    
    # Convert to bar first (base unit)
    if from_unit == "KPA":
        bar = value / 100
    elif from_unit == "PSI":
        bar = value / 14.5038
    else:
        bar = value

    # Convert from bar to target
    if to_unit == "KPA":
        result = bar * 100
    elif to_unit == "PSI":
        result = bar * 14.5038
    else:
        result = bar
    
    return result