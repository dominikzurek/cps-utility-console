"""
CPS Utility Console - Main Entry Point
Author: Dominik Żurek
"""

from cps_utility_console import menu


def main() -> None:
    """Main application loop."""
    while True:
        menu.display_menu()
        choice = input("\nSelect option: ").strip()
        if not menu.handle_choice(choice):
            break


if __name__ == "__main__":
    main()