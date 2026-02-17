"""
CPS Utility Console — Menu Router
Author: Dominik Żurek
"""

from cps_utility_console import validators


def run_sensor_stats() -> None:
    """Placeholder for Sensor Statistics function."""
    print(">> Sensor Statistics — not implemented yet")


def run_unit_converter() -> None:
    """Placeholder for Unit Converter function."""
    print(">> Unit Converter — not implemented yet")


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