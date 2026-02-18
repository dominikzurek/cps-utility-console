"""
CPS Utility Console — Menu Router
Author: Dominik Żurek
"""

from cps_utility_console import validators


def run_sensor_stats() -> None:
    """Run Sensor Statistics function"""
    from cps_utility_console.functions.sensor_stats import compute_stats

    print("\n--- Sensor Statistics ---")
    n = validators.get_positive_int("How many samples? ")

    samples = []
    for i in range(n):
        value = validators.get_float(f"Sample {i+1}/{n}: ")
        samples.append(value)

    result = compute_stats(samples)
    print("\nResults:")
    print(f"  Mean:   {result['mean']:.4f}")
    print(f"  Min:    {result['min']:.4f}")
    print(f"  Max:    {result['max']:.4f}")
    print(f"  StdDev: {result['stddev']:.4f}")


def run_unit_converter() -> None:
    """Run Unit Converter function."""
    from cps_utility_console.functions.unit_converter import (
        convert_temperature,
        convert_pressure,
    )
    
    print("\n--- Unit Converter ---")
    conv_type = validators.get_choice(
        "Convert [T]emperature or [P]ressure? ", ["T", "P"]
    )
    
    if conv_type == "T":
        value = validators.get_float("Enter temperature value: ")
        from_unit = validators.get_choice("From unit [C/F/K]: ", ["C", "F", "K"])
        to_unit = validators.get_choice("To unit [C/F/K]: ", ["C", "F", "K"])
        
        try:
            result = convert_temperature(value, from_unit, to_unit)
            print(f"\nResult: {value} {from_unit} = {result:.2f} {to_unit}")
        except ValueError as e:
            print(f"  Error: {e}")
    
    else:  # P
        value = validators.get_float("Enter pressure value: ")
        from_unit = validators.get_choice("From unit [BAR/KPA/PSI]: ", ["BAR", "KPA", "PSI"])
        to_unit = validators.get_choice("To unit [BAR/KPA/PSI]: ", ["BAR", "KPA", "PSI"])
        
        try:
            result = convert_pressure(value, from_unit, to_unit)
            print(f"\nResult: {value} {from_unit} = {result:.4f} {to_unit}")
        except ValueError as e:
            print(f"  Error: {e}")

def run_alarm_checker() -> None:
    """Placeholder for Alarm Threshold Checker function."""
    print(">> Alarm Threshold Checker — not implemented yet")


def run_lowpass_filter() -> None:
    """Placeholder for Low-Pass IIR Filter function."""
    print(">> Low-Pass IIR Filter — not implemented yet")


MENU_OPTIONS: dict[str, tuple[str, callable]] = {
    "1": ("Sensor Statistics",        run_sensor_stats),
    "2": ("Unit Converter",           run_unit_converter),
    "3": ("Alarm Threshold Checker",  run_alarm_checker),
    "4": ("Low-Pass IIR Filter",      run_lowpass_filter),
}


def display_menu() -> None:
    """Print the main menu to stdout."""
    print("\n=== CPS Utility Console ===")
    for key, (label, _) in MENU_OPTIONS.items():
        print(f"[{key}] {label}")
    print("[5] Exit")


def handle_choice(choice: str) -> bool:
    """
    Execute the selected menu option.
    Returns False if user wants to exit, True otherwise.
    """
    if choice == "5":
        print("Goodbye!")
        return False

    if choice in MENU_OPTIONS:
        _, func = MENU_OPTIONS[choice]
        func()
        return True

    print("  Error: invalid option. Please select 1-5.")
    return True