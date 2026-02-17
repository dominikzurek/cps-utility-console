"""
CPS Utility Console - Main Entry Point
Author: Dominik Żurek
"""


def main() -> None:
    """Main application loop."""
    while True:
        # Display menu
        print("\n=== CPS Utility Console ===")
        print("[1] Sensor Statistics")
        print("[2] Unit Converter")
        print("[3] Alarm Threshold Checker")
        print("[4] Low-Pass IIR Filter")
        print("[5] Exit")

        # Get user choice
        choice = input("\nSelect option: ")

        if choice == "1":
            print(">> Sensor Statistics — not implemented yet")
        elif choice == "2":
            print(">> Unit Converter — not implemented yet")
        elif choice == "3":
            print(">> Alarm Threshold Checker — not implemented yet")
        elif choice == "4":
            print(">> Low-Pass IIR Filter — not implemented yet")
        elif choice == "5":
            print("Goodbye!")
            break
        else:
            print("Invalid option. Please select 1-5.")


if __name__ == "__main__":
    main()