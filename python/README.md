# CPS Utility Console — Python Implementation

Production-ready Python prototype with full test coverage.

## Installation
```bash
cd python
pip install -e . --break-system-packages
```

## Usage
```bash
python3 -m cps_utility_console.main
```

Or if installed:
```bash
cps-utility-console
```

## Testing
```bash
pytest tests/ -v
```

## Project Structure
```
python/
├── cps_utility_console/
│   ├── main.py              # Entry point
│   ├── menu.py              # Menu router
│   ├── validators.py        # Input validation
│   └── functions/
│       ├── sensor_stats.py
│       ├── unit_converter.py
│       ├── alarm_checker.py
│       └── lowpass_filter.py
└── tests/
    ├── test_sensor_stats.py
    ├── test_unit_converter.py
    ├── test_alarm_checker.py
    └── test_lowpass_filter.py
```

## Requirements

- Python 3.10+
- pytest (for testing)