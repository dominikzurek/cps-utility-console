"""
CPS Utility Console - Input Validators
Author: Dominik Żurek
"""


def get_float(prompt: str) -> float:
    """
    Prompt user for a float value.
    Keeps asking until valid input is provided.
    """
    while True:
        raw = input(prompt).strip()
        try:
            return float(raw)
        except ValueError:
            print(f"  Error: '{raw}' is not a valid number. Try again.")


def get_float_in_range(prompt: str, min_val: float, max_val: float) -> float:
    """
    Prompt user for a float value within [min_val, max_val].
    Keeps asking until valid input is provided.
    """
    while True:
        value = get_float(prompt)
        if min_val <= value <= max_val:
            return value
        print(f"  Error: value must be between {min_val} and {max_val}. Try again.")


def get_positive_int(prompt: str) -> int:
    """
    Prompt user for a positive integer (>= 1).
    Keeps asking until valid input is provided.
    """
    while True:
        raw = input(prompt).strip()
        try:
            value = int(raw)
            if value >= 1:
                return value
            print(f"  Error: value must be a positive integer. Try again.")
        except ValueError:
            print(f"  Error: '{raw}' is not a valid integer. Try again.")


def get_choice(prompt: str, valid: list[str]) -> str:
    """
    Prompt user to select from a list of valid string choices.
    Keeps asking until valid input is provided.
    """
    while True:
        raw = input(prompt).strip().upper()
        if raw in valid:
            return raw
        print(f"  Error: choose one of {valid}. Try again.")